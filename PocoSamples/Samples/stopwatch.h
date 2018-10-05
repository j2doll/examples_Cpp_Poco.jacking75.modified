//��ó: http://poco.roundsquare.net/2010/04/29/pocostopwatch/

#pragma once
#include <thread>

#include <Poco/Stopwatch.h>


void Sample_StopWatch()
{
	Poco::Stopwatch watch;

	std::cout << "�ð� ���� ����" << std::endl;

	watch.start();
	
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	watch.stop();

	// microseconds, seconds �����θ� ���� ����
	printf("[%s] �ɸ� �ð� (%I64d)microseconds, (%d)seconds", __FUNCTION__, watch.elapsed(), watch.elapsedSeconds());
}