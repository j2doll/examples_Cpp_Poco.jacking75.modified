//��ó: https://codezine.jp/article/detail/2626?p=2

#pragma once

#include <Poco/Notification.h>
#include <Poco/NotificationQueue.h>
#include <Poco/ThreadPool.h>
#include <Poco/Thread.h>
#include <Poco/Runnable.h>
#include <Poco/Mutex.h>
#include <Poco/Random.h>

#include <Poco/AutoPtr.h>

#include <iostream>

/*
�켱 ���� �۾��� ������(�۾� ������)�� ����gks��.
�� ������� ���� �ڿ��� ���� "��"�� ���Ϸ� ����.
���� ������ �� �۾��� �����ϰ� ������ �� ���� ã�� ������ ��ٸ���.
���� ���ҽ��� �۾��� �߰��Ϸ� ����.
���������� �۾��� �����尡 �д��ؼ� ó���Ѵ�.
���� �߰��� �Ϸ��ϸ� ��� ���� ó�� �� ������ ��ٸ���.
*/

// ��Ŀ �����忡 ���� Ŭ����
class WorkNotification : public Poco::Notification
{
	// ���� ��ȣ
	int    _ix;

public:
	WorkNotification(int i) : _ix(i)
	{
	}

	// ������ �ִ� ��ȣ�� ��ȯ
	int ix() const
	{
		return _ix;
	}

	// ��ɾ� ó��
	void execute()
	{
		// ���� Ŭ����
		Poco::Random  rnd;

		rnd.seed();

		// ������ Sleep �Ѵ٣�0��199�и��ʣ�
		Poco::Thread::sleep(rnd.next(200));
	}
};

// ��Ŀ ������ Ŭ����
// ���� queue���� ���� ������Ʈ�� �����ϰ�, �����Ѵ�.
class Worker : public Poco::Runnable
{
	// ������ �ĺ���
	std::string         _name;

	// ���� queue
	Poco::NotificationQueue&  _queue;

	// ��Ÿ ó���� Mutex
	static Poco::FastMutex    _mutex;

public:
	Worker(const std::string& name, Poco::NotificationQueue& queue) :
		_name(name), _queue(queue)
	{
	}

	// �������� ���� ó��
	void run()
	{
		for (;;) {
			// ���� queue���� �����͸� ���� ������ ���
			Poco::AutoPtr<Poco::Notification> pNf(_queue.waitDequeueNotification());
			if (pNf) {
				WorkNotification* pWorkNf = dynamic_cast<WorkNotification*>(pNf.get());
				if (pWorkNf) {
					{
						Poco::FastMutex::ScopedLock lock(_mutex);
						std::cout << _name << " excute No." << pWorkNf->ix() << std::endl;
					}
					// ��� ����
					pWorkNf->execute();
				}
			}
			else
				break;  // ��ȯ ���� NULL�̸� �����带 ����
		}
	}
};
Poco::FastMutex Worker::_mutex; // static ������ ��ü

void Sample_WorkerThread()
{
	// ���� ������Ʈ queue
	Poco::NotificationQueue queue;

	// ��Ŀ �����带 �����
	Worker worker1("Worker-1", queue);
	Worker worker2("Worker-2", queue);
	Worker worker3("Worker-3", queue);

	// ������ Ǯ
	Poco::ThreadPool pool;

	// �� ��Ŀ ������ ��ϰ� ����
	pool.start(worker1);
	pool.start(worker2);
	pool.start(worker3);

	// ���� ������Ʈ 50���� queue�� �ִ´�
	for (int i = 0; i < 50; ++i) {
		queue.enqueueNotification(new WorkNotification(i));
	}

	// queue�� �� ������ ���ν������ ���
	while (!queue.empty()) {
		Poco::Thread::sleep(200);
	}

	// ��� ��Ŀ �����尡 ó�� ���� ������ Sleep �� �д�
	Poco::Thread::sleep(200);

	// ��� ��Ŀ �����忡 ���Ḧ ����
	queue.wakeUpAll();

	// ��� ��Ŀ �������� ���� ���
	pool.joinAll();
}