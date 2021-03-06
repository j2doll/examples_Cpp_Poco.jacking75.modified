# POCO 라이브러리 사용하기

> C++ 프로그래밍을 더 즐겁게!

- :kr: This article is written in Korean. 
- 저자 : 최흥배 https://jacking75.github.io/ 
- 일부 내용은 j2doll이 수정하였습니다. https://github.com/j2doll/examples_Cpp_Poco.jacking75.modified

## Overview

> "좋은 라이브러리 없이 C++을 즐겁게 하는 것은 아주 어렵다. 그러나 좋은 라이브러리가 있다면 대부분은 간단하게 할 수 있다." - Bjarne Stroustrup (Designer and original implementor of C++)

## POCO 라이브러리는...

- Java의 클래스 라이브러리나.NET Framework, Cocoa(Apple)과 비슷한 C++ 라이브러리.
- "인터넷 시대"의 네트워크가 중심인 애플리케이션에 초점을 맞추고 있다.
- 최신 ANSI/ISO 표준 C++과 STL에 기초를 두고, 효율적으로 쓰여 있다.
- 이식성이 높고, 다양한 플랫폼에서 사용할 있다. (iOS, Android도 지원)
- 오픈 소스이며 Boost 소프트웨어 라이센스를 채용하고 있다.
- 그래서 완전하게 무료로 사용할 수 있다.

## 특징

- Any와 DynamicAny 클래스
- 캐시 프레임워크
- 암호 기술(암호 해시, OpenSSL에 토대를 둔 암호화）
- 날짜와 시간 클래스
- 이벤트(시그널/슬롯)와 통지 프레임워크
- 파일 전송을 위한 FTP 클라이언트
- 플랫폼에 의존하지 않는 path 조작과 파일 리스팅을 할 수 있는 파일 시스템 클래스
- HTML 조작
- HTTP 서버와 클라이언트(안전함), C++ 서버 페이지 컴파일러
- 로깅 프레임워크
- 멀티스레딩: 스레드, 동기, 편리 기능(스레드 풀, 비동기 메시지, 지연 처리 등)
- 메일 수신용 POP3 클라이언트
- 플랫폼 추상화: 한번의 코딩으로 다양한 플랫폼에서 컴파일하고 동작 시킬 수 있다
- 프로세스 간 통신
- Reactor 프레임워크
- PCRE를 기초한 정규 표현
- 메일 송신용 SMTP 클라이언트
- SQL 데이터베이스 조작 (SQLite, MySQL, ODBC)
- OpenSSL에 기초한 SSL/TLS를 지원
- 공유 라이브러리와 클래스 로더
- 스마트 포인터와 메모리 관리
- 소켓과 RAW 소켓
- 스트림: Base64와 바이너리 엔코드/디코드, 압축 (zlib), 개행 코드 변환, 메모리 읽기/쓰기
- 문자열 처리
- TCP 서버 프레임워크(멀티스레드)
- 텍스트 엔코딩과 변환
- Tuples
- URI 처리
- UTF-8과 Unicode 지원
- UUID 처리와 생성
- XML 파서(SAX2, DOM)와 XML 생성
- Zip 파일 조작

## POCO와 목표와 미션

- POCO는 애플리케이션을 빌드할 플랫폼에서 간단하게 사용할 수 있으며 강력하다.
- POCO를 사용하면 높은 이식성을 가진 애플리케이션을 만들 수 있다.
- POCO는 임베디드 소프트웨어서 기업 애플리케이션까지 사용할 수 있는 모듈이다.
- POCO는 불변이며 포괄적이며 사용하기 쉬운 인터페이스를 제공한다.
- POCO는 C++로 효율적으로 만들었다.
- POCO에서는 복잡한 것보다 간단함을 좋아한다.
- POCO에서는 일관된 디자인, 코딩 스타일, 문서를 지향한다.
- POCO에서는 소스 코드 질, 가독성, 쉬운 이해, 일관성을 가진 스타일과 테스트를 중요시 한다.
- POCO는 C++ 팬이 되돌아 오는 것을 목표로 한다

## 기본 이념

- **코드 퀄리티, 스타일, 일관성, 가독성**을 중시한다. 모든 코드는 코딩 스타일 가이드를 따른다.
- **테스트**를 중시한다.
- 모든 문제를 해결하기 보다 **실용적이며 우아한 디자인**을 좋아한다.  
- 튼튼한 기반 위에 만든다. 필요한 곳에 기존의 경험 있는 C 라이브러리를 사용한다（예를 들면 expat, zlib, PCRE, SQLite）.

## 역사

- 2004년 여름 : Günter Obiltschnig가 개발을 시작
- 2005년 2월: 처음 릴리즈를 SourceForge에 했었다. (Release 0.91 Sleepycat 라이센스)
- 2005년 5월: Aleksandar Fabijanic가 개발에 참가하였다.
- 2006년 1월: Release 1.0
- 2006년 3월: Release 1.1
- 2006년 7월: Boost 라이센스로 변경. POCO 커뮤니티 웹사이트 개설
- 2006년 8월: Release 1.2
- 2007년 5월: Release 1.3
- 2010년 7월: Release 1.3.7(안정판), 20인 정도의 개발자가 있으며, 수백개의 프로젝트에서 사용되고 있다.

## 지원 플랫폼

- Microsoft Windows
- Linux
- Mac OS X
- HP-UX, Solaris, AIX(패치 필요)
- Embedded Linux (uClibc、glibc)
- iOS
- Android
- Windows Embedded CE
- QNX

## 사용 예

- 빌딩 자동 시스템 미들웨어나 디바이스
- 공장 자동화나 산업 설비
- 교통 정리 시스템
- 의료용 애플리케이션
- 데이터 계측, 수집, 테스트 시스템
- 가정용 전화 제품, 홈 오토메이션
- 스마트 그리드
- 항공 제어 시스템
- VoIP
- 표 판매기나 입장 게이트 시스템
- 상용 애플리케이션

## POCO를 사용하고 있는 기업

- 454 Life Sciences (Roche)
  - 새로운 고속 게놈 분석기에서 POCO 사용 중
- ACTIA Automotive
  - 자동차 진단 시스템에서 POCO와 OSP를 사용 중
- Appcelerator Titanium
  - 웹베이스 데스크탑 애플리케이션용 플랫폼에서 POCO를 사용 중
- CACE Technologies
  - 네트워크 모니터/해석 시작품에서 POCO를 사용 중
- CodeLathe Tonido
  - 웹 애플리케이션 플랫폼 Tonido 등에서 POCO를 사용 중
- Comact Optimisation
  - QNX에서 동작하는 자제 설비나, e 러닝 플랫폼에서 POCO를 사용 중
- HORIBA
  - 자동 테스트 시스템에서 POCO를 사용 중
- Novonics Corporation
  - 미국 국방성이나 국토안전보호청에서 사용하고 있는 분산 시뮬레이션 라이브러리에서 POCO를 사용 중
- Nucor Steel
  - 빔 압연기의 자동 애플리케이션에서 POCO를 사용 중
- Schneider Electric Buildings Business (TAC)
  - 빌딩 자동화용 플랫폼(Embedded Linux 디바이스와 Windows/Linux 서버)에서 POCO 사용 중
- StreamUnlimited
  - 텔레비전 셋탑박스에서 POCO를 사용 중
- Starticket
  - 티켓/입장 관리 시스템(Xscale 상에서 OpenEmbedded)에서 POCO를 사용 중

## POCO의 임베디드 분야에서의 확장성

- POCO는 Embedded Linux, Windows Embedded CE, QNX 등에서 동작하는 임베디드 시스템에 적합하다.
- POCO를 사용한 애플리케이션（POCO 웹 서버를 사용）는 75MHz ARM9, 8MB RAM, 4MB Flash의 Linux 시스템(uClibc)에서 동작한다.
- POCO 웹 서버를 사용한 전형적인 애플리케이션에서는 2MB의 정적 링크를 가지고, RAM 2-3MB를 사용한다.
- 전형적인 미들렌지 임베디드 플랫폼(32-64MB RAM, 16-64MB Flash, 180MHz ARM9)는 복잡한 애플리케이션(OSP 사용이나 리모트 앱)에도 풍부한 리소스를 제공한다.

## POCO에 의한 이익과 특징

- 포괄적으로 안전하고 성숙한 C++ 프레임워크는 대부분의 일에 도움이 되고, 제품을 빠르게 시장에 출시한다.
- 직감적으로 간단하게 학습 할 수 있다. 일관성이 있고 알기 쉬운 인터페이스, 많은 샘플 코드와 좋은 문서.
- 네이티브 C++ 성능(VM 오버헤드 등이 없는), 작은 메모리
- 플랫폼에 의존하지 않는다: 한번 코드를 만들면 어디에서라도 컴파일 해서 동작 시킬 수 있다.
- 대부분의 경우 특정 하드웨어에 접근이 필요하지 않은 애플리케이션에서는 개발에 사용하고 있는 환경에서도 테스트와 디버깅 할 수 있다.
- 애플리케이션은 다른 플랫폼에 간단하게 이식할 수 있다.

## 윈도우즈 빌드

### 빌드 스크립트 사용하기

- VS2010, x64, static lib 으로 빌드
  - ```buildwin.cmd 100 build static_mt both x64 samples tests devenv```
  - 이렇게 빌드하면 PocoFoundation 만 빌드 된다. 그래서 Util, XML, Net, MongoDB 등을 직접 빌드해야 한다.
  - Util 등의 라이브러리 디렉토리에 VS 버전, 32 or 64 플랫폼별 VS 프로젝트 파일이 있다.
  - 모두 빌드가 완료되면 lib64 디렉토리에 만들어져 있다.

- VS2015, static mt, debug/release, x64 로 빌드
  - ```buildwin.cmd 140 rebuild static_mt both x64```

- VS2015, static md, debug/release, x64 로 빌드
  - ```buildwin.cmd 140 rebuild static_md both x64```

- VS2017, static md, debug/release, x64 로 빌드* 
  - ```buildwin.cmd 150 rebuild static_md both x64```

- OpenSSL 빌드
  - openssl-1.0.2을 플랫폼 별로 빌드한다. ```D:/Libraries/openssl-1.0.2-x86``` 와 ```D:/Libraries/openssl-1.0.2-x64```
  - components 파일을 열어서 OpenSSL 관련 디렉토리를 위의 디렉토리로 변경한다. ```set OPENSSL_DIR=D:\Libraries\openssl-1.0.2-x64```
  
 - http://stackoverflow.com/questions/30374503/building-poco-c-libraries-on-windows-from-commandline 


```
buildwin.cmd 150 rebuild all both Win32
buildwin.cmd 150 rebuild static_md both x64
buildwin.cmd 150 rebuild static_mt both x64
```

- 빌드를 하면 32비트 버전은 lib 디렉토리에, 64비트 버전은 lib64 디렉토리에 lib 파일을 생성한다

- Visual Studio 최신 버전을 지원하지 않을 때는 각 라이브러리 디렉토리(Foundation, Net, Xml, Util)에서 VS 솔류션 파일을 열어서 직접 빌드한다.

### 정적 라이브러리 사용하기

- POCO는 default로 동적 라이브러리를 사용한다.
  - 정적 라이브러리로 사용하기 위해서는 #define POCO_STATIC 을 선언해야 한다.

- POCO를 바로 exe 프로젝트에서 사용하는 경우 '런타임 라이브러리'가 MD(MDD) 혹은 MT(MTD) 무엇이든 상관 없지만.

- POCO를 사용하는 또 다른 정적 라이브러리를 만들고. 
  - 이 라이브러리를 사용하는 exe 프로젝트는 '런타임 라이브러리'가 MT(MTD)이어야 한다. 
  - 만약 MD로 하면 exe 프로젝트 빌드 시에 동적 DLL을 요구한다.

### Poco 라이브러리 빌드 하기

- Poco Library 빌드 하기 (windows)
  - https://neodreamer-dev.blogspot.com/2016/05/poco-library.html 

- Poco 라이브러리 Visual Studio 2017 에서 빌드 하기
  - https://jacking75.github.io/cpp_poco_build_vs2017/ 

## 리눅스 빌드

- https://jira.gamevilcom2us.com/wiki/display/CCentralServerGUIDE/poco 

```
$ tar xzvf poco-[version].tar.gz
$ cd poco-[version]/

$ export OSARCH_64BITS=1
$ ./configure --static --no-tests --no-samples
```

### (일어) 빌드하기

- (일어) linux에서 POCO 사용하기
  - http://poco-ben.blogspot.kr/2012/01/poco.html  

- (일어) Ubuntu Linux Poco(C++라이브러리) 설치
  - http://scriptlabo.blog26.fc2.com/blog-entry-48.html  

- (일어) iOS에서 Poco 사용하기
  - http://qiita.com/nasu_st/items/30788c8723e9b207f7dd 

## 개요 (Overview)

- Poco::Util::IniFileConfiguration
- Poco::Stopwatch
- Poco::SingletonHolder
- Poco::Cache
- Poco::Checksum
- Poco::DynamicFactory
- Poco::Random
- Poco::DigestEngine, Poco::HMACEngine, Poco::SHA1Engine
- Poco::DataTime
- Poco::Threading
- Poco::ThreadPool
- Poco::Mutex
- Poco::RWLock
- Poco::SynchronizedObject
- Poco::ThreadLocal
- Poco::NotificationQueue, Poco::PriorityNotificationQueue
- Poco::Timer
- Poco::Util::Timer 
- Poco::TimedNotificationQueue
- Poco::Text, Poco::format, Poco::StringTokenizer, - Poco::NumberFormatter, Poco::NumberParser
- Poco::BasicEvent
- Poco::NotificationCenter
- Poco::Process
- Poco::Environment
- Poco::Util::SystemConfiguration
- Poco::NDC
- Poco::Util::ServerApplication

### 설정 정보

- 유연한 서버를 만들기 위해서는 서버의 동작을 설정 파일로 바꿀 수 있어야 하는데....
  - 유명한 .ini 파일에서 설정 정보를 얻고 싶은데...

- Poco::Util::IniFileConfiguration
  - https://pocoproject.org/docs/Poco.Util.IniFileConfiguration.html 

- 예제) Sample_iniReader()

### 시간 측정

- 이 함수를 실행하면 어느 정도 시간이 걸릴까?
  - 시간을 측정했으면 좋겠네....

- Poco::Stopwatch
  - https://pocoproject.org/docs/Poco.Stopwatch.html  

- 예제) Sample_StopWatch()
 
### 싱글톤

- Network 클래스는 1개만 생성해서 사용해야 하는데...
  - 그러면 싱글톤이 좋겠군....
  - 싱글톤 쉽게 만드는 방법 없나?

- Poco::SingletonHolder
  - https://pocoproject.org/docs/Poco.SingletonHolder.html 

- 예제) Sample_SingletonHolder()

### 캐쉬

- memcached 같은 걸 만들어야 하는데....
  - 메모리를 절약하기 위해 컨테이너의 크기는 고정, 
  - 공간이 부족한 경우 최근에 사용하지 않는 공간을 재 사용 하고 싶은데...
  - 또 특정 시간까지 사용하지 않은 것들은 지워졌으면 좋겠네....

- Poco::Cache
  - https://pocoproject.org/docs/package-Foundation.Cache.html 

- 예제) Sample_LRUCache(), Sample_ExpireCache()

### 체크섬

- 클라이언트에서 받은 데이터가 잘못된 것은 아닌지 알아보고 싶은데.... 
  - checkSum으로 확인하면 좋을 듯....

- Poco::Checksum
  - https://pocoproject.org/docs/Poco.Checksum.html 

- 예제) Sample_Checksum()

- 체크썸 방식에는 CRC-32 방식과 Adler-32 방식 2가지 있음. 
  - 이중 Poco에서는 Adler-32 방식이 성능이 더 좋다고 하지만 OS에 따라서 달라질 수 있음.

### 팩토리

- 클래스 생성을 추상화 하고 싶네....
  - factory method 패턴을 사용하면 좋을 듯...
  - 그런데 좀 더 편하게 사용하고 싶은데...

- Poco::DynamicFactory
  - https://pocoproject.org/docs/Poco.DynamicFactory.html

- 예제) Sample_DynamicFactory()

- 클래스 이름에서 그 오브젝트를 만들 수 있는 Factory

### 랜덤

- 게임에서 보상 및 가챠 시스템을 만들려면 난수가 필요한데...

- Poco::Random
  - https://pocoproject.org/docs/Poco.Random.html 

- POCO는 의사 난수 생성기(PRNG)를 가지고 있다. 상태 정보 256bit와 최대 269까지의 숫자를 사용한 비선형 가법 피드백 알고리즘을 사용한다.
- PRNG는 31bit의 의사 난수를 생성 할 수 있다
- UInt32 char, bool, float, double의 난수를 생성 할 수 있다
- 또한 랜덤 바이트를 생성하는 스트림 클래스도 있다. (/ dev / random이나 Windows의 Cryptographic API를 사용하는)

#### Random 클래스

- POCO :: Random에 PRNG가 구현 되어 있다.
  -  ```#include "Poco/Random.h"``` 로 사용할 수 있다.
  
- ```void seed (Poco::UInt32 seed)```
  - PRNG는 인수 seed 값을 시드로 사용한다.

- ```void seed ()```
  - PRNG는 (RandomInputStream에서) 임의의 값을 시드로 한다.

- (주의!) 생성자는 PRNG의 시드에 현재의 데이터와 시간을 사용할 뿐이다.
  - 더 나은 시드를 사용하려면 명확하게 seed() 함수를 호출해야 한다.
  
- ```UInt321 next ()```
  - 0 이상 2의 31성 이하의 난수를 반환

- ```UInt32 next (UInt32 n)```
  - 0 이상 n 미만의 난수를 반환

- ```char nextChar ()```
  - char의 난수를 반환

- ```bool nextBool ()```
  - boolean의 난수를 반환

- ```float nextFloat ()``` ```double nextDouble ()```
  - 0 이상 1 이하의 부동 소수점 난수를 반환

### 암호화

- Poco::DigestEngine
- Poco::HMACEngine
- Poco::SHA1Engine

- https://pocoproject.org/docs/package-Foundation.Crypt.html 

#### 암호 해시

- 암호화 해시 함수는 인증과 메시지 무결성 등 다양한 정보 보안 응용 프로그램의 기본으로 사용하기에 적절한 보안 특성이 추가된 해시 함수이다. 

- 해시 함수는 입력으로서 임의의 길이의 긴 문자열 (또는 메시지)를 받고, 출력으로 정해진 길이의 문자열을 생성한다. a message digest (메시지 요약) 및 a digital fingerprint (전자 지문) 이라고도 불린다.

-  POCO는 일부 넓게 사용할 수 있는 암호화 해시 함수의 구현을 제공한다.
  - MD2, MD4, MD5, SHA1
  
- HMAC 메시지 인증 알고리즘 (RFC 2104) 의 구현과 동등하게 사용할 수 있다.

- 모든 해시 함수와 HMAC의 구현은 DigestEngine 클래스의 서브 클래스로 되어 있다.

- 만약 자신의 해쉬 함수를 만들고 싶다면, 마찬가지로 DigestEngine 클래스를 상속하면 좋다.

#### DigestEngine 클래스

- Poco::DigestEngine 은 모든 메시지 요약 알고리즘의 구현을 위해 공통의 인터페이스를 정의하고 있다.

- ```#include "Poco/DigestEngine.h"``` 로 사용할 수 있다.

- 요약 메시지의 길이는 사용하는 알고리즘에 의존한다.

- 그래서 POCO는 Digest(요약 메시지)는 ```std::vector<unsigned char>``` 로 하고 있다.

- 요약 계산을 위해 데이터에 대해서 DigestEngine의 update () 함수를 반복적으로 호출해라.

- 모든 데이터를 DigestEngine에 전달했다면 Digest를 얻기 위해 digest() 함수를 호출해라.

- void update (const void * data, unsigned length)
  - 데이터 블록에 대해서 요약을 업데이트 한다

-  void update (char data)
  - 1byte의 데이터에 대해서 요약을 업데이트 한다

- · void update (const std :: string & data)
  - 문자열 데이터에 대해서 요약을 업데이트 한다.

- · const Digest & digest ()
  - 요약 계산을 완료하고, 요약에 대한 참조를 반환한다.






 




