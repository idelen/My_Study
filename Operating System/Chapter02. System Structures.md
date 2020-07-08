<h1>Chapter02. System Structures</h1>

<h2> Operating-System Services</h2>

---

![운영체제 서비스 시스템 구조.](https://t1.daumcdn.net/cfile/tistory/99C28E475ACA0D3E2D)

- 운영체제는 사용자와 시스템에게 다양한 서비스를 제공한다.

- UI(User Interface)  : 사용자와 컴퓨터 시스템이 만나는 지점

  ```markdown
  - CLI(Command-Line Interface) : 사용자가 텍스트 명령을 통해 명령을 내리는 인터페이스
  	-> 셸(Shell) : 이러한 인터페이스를 제공하는 프로그램
  	-> 과거 MS-DOS 나 애플소프트 베이직
  - GUI(Graphical User Interface) : 다양한 방법으로 화면의 그래픽을 조작하여 명령을 내리는 인터페이스
  - 배치 인터페이스(Batch Interface)
  ```

- 프로그램 실행 (Program Execution)

  : 시스템은 프로그램을 메모리에 로드하고 이를 실행할 수 있어야 한다. 또한, 프로그램은 정상적으로든 그렇지 않든 실행을 끝낼 수 있어야 한다.

- 입출력 명령(I/O Operations) : 입출력이 필요할 경우, 운영체제는 입출력 명령을 수행해야 한다.

  -> 이 때, 효율과 보안을 위해 운영체제는 사용자가 직접 입출력 장치를 조작하지 않고, 자신을 거치도록 한다.

- 파일 시스템 조작(File-System Manipulation)

  : 파일을 쓰고, 읽고, 만들고, 지운다. 또한 사용자가 파일에 접근하지 못하도록 막기도 한다.

- 통신(Communications)

  : 어떤 프로세스가 다른 프로세스와 정보를 교환해야 할 때, 운영체제는 공유 메모리(Shared Memory) 나 메세지 패싱(Message Passing) 방법을 사용

  - **공유 메모리(Shared Memory)** : 여러개의 프로세스가 메모리의 한 부분을 공유하도록 하는 것
  - **메세지 패싱(Message Passing)** : 프로세스 간에 정보 패킹을 주고받는 것

  -> 공유 메모리 방식보다 메세지 패싱 방식의 속도가 더 느리다.

- 에러 탐지(Error Detection)

  : 운영체제는 CPU나 메모리와 같은 하드웨어, 입출력장치, 그리고 사용자 프로그램 등에서 일어나는 에러를 탐지하고, 바로 잡아야 한다.

-운영체제는 사용자에게 직접적인 도움은 안 되지만, 시스템을 위한 작업도 수행한다.

- 자원할당(Resource Allocation)

  : 여러 사용자나 여러 작업을 동시에 처리해야 한다면, 컴퓨팅 자원은 각각 잘 배분되어야 한다.

- 회계(Accounting)

  : 시스템은 어떤 유저가 어떤 종류의 자원을 얼마나 사용하고 있는지 계속 추적해야 한다. 이 기록은 회계나 사용량 통계를 위해 사용될 수 있다.

- 보호와 보안(Protection and Security)



<h2> System Call</h2>

---

![사용자 어플리케이션에서 open() 시스템 콜을 호출해 파일을 여는 과정.](https://user-images.githubusercontent.com/6410412/54861485-d9f48c00-4d6c-11e9-8eb6-f1bd59fa582d.png)

- **시스템 콜 테이블(System Call Table)** == 인터럽트 벡터(Interrupt Vector)

  : 어떤 동작들이 할당된 메모리의 특정 주소 범위

  ex) `fopen()` 함수를 호출하면, 운영체제는 파일을 여는 함수를 찾기 위해 시스템 콜 테이블을 참조

- **인터럽트 서비스 루틴(Interrupt Service Routine)**

  : 시스템 콜 테이블의 주소가 가리키는 것???

- 사용자 프로그램이 운영체제에게 매개변수를 넘기는 방법

  ```markdown
  1. Call by value : 매개변수의 값 자체를 복사해서 CPU 레지스터에 전달한다.
  2. Call by reference : 값의 메모리 주소를 전달한다. 많은 값을 전달한다면 이렇게 하는 것이 효율적이다.
  3. 프로그램을 통해 스택(Stack)에 매개변수를 추가하고, 운영체제를 통해 값을 뺀다.
  ```



<h2> Types of System Calls </h2>

---

```markdown
1. 프로세스 제어 : end, abort, load, execute
2. 파일 관리 : create, delete, open, close, read, write
3. 장치 관리 : read, write, request, release
4. 정보 유지 : get/set time or date
5. 통신 : send/receive messages, transfer status
6. 보호
```



<h2>Operating System Structure</h2>

---

<h3> Simple Structure</h3>

- 과거에는 계층이 구분되어 있지 않아 사용자 프로그램에 문제가 생기면 전체 시스템에 문제가 생겼다.
- UNIX 시스템 구조는 MS-DOS에 비해 기능이 분리되었지만, 하나의 계층이 너무 많은 일을 했다.

<H3> Layered Approach</h3>

![레이어드 운영체제 구조.](https://t1.daumcdn.net/cfile/tistory/994A513C5ADF038824)

- 가장 아래에 있는 계층(레이어 0)은 하드웨어고, 가장 높은 계층(레이어 N)은 사용자 인터페이스
- 하나의 계층에만 신경쓰면 다른 계층에는 아무런 신경을 쓰지 않아도 되기에 유지보수가 아주 편하다.

<h3> Microkernels</h3>

- 커널에서 핵심적인 요소만 남긴 가벼운 커널
- 커널이 커질수록 문제가 생길 가능성이 높기에, 유지보수를 위해 커널을 가볍게 만들 필요가 있음
- OS X의 커널(Darwin)의 일부가 마이크로커널 Mach를 기반으로 만들어졌으며, IoT에도 마이크로커널이 사용

<h3> Modules</h3>

- 커널을 확장하는 기술
- 프로세스에 실시간으로 모듈을 붙여 작동시킬 수 있고, 각 기능들을 독립적으로 관리할 수 있어 효과적으로 시스템 유지가 가능
- 장치 드라이버는 모두 모듈로 구현 / 윈도우에서 .dll 파일이 모듈

<h3> Hybrid Systems</h3>

- 커널의 핵심만 남기고 나머지는 따로 구현한 시스템
- OS X의 경우 BSD가 핵심이지만 나머지는 모두 애플이 자체 구현
- 안드로이드는 리누슥 커널위에 자체 구현한 라이브러리를 올린 시스템

