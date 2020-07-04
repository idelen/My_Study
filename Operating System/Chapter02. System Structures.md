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



