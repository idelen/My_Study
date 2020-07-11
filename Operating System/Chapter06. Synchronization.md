<h1> Chapter06. Synchronization</h1>

<h2>Background</h2>

---

- **경쟁 상태(Race Condition)**

  : 프로세스가 어떤 순서로 데이터에 접근하느냐에 따라 결과 값이 달라질 수 있는 상황

  ex) 두 프로세스가 동시에 어떤 변수의 값을 바꾼다면 의도와는 다른 결과가 나올 수 있다.



<h2> The Criticla-Section Problem</h2>

---

- **임계 영역(Critical Section)**

  : 코드상에서 **경쟁 조건**이 발생할 수 있는 특정 부분

- Critical Section Problem을 해결하기 위한 조건

  ```markdown
  1. 상호 배제 (Mutual Exclution)
   : 이미 한 프로세스가 Critical Section에서 작업중일 때 다른 프로세스는 Critical Section에 진입해서는 안 된다.
  
  2. 진행 (Progress)
   : Critical Section에서 작업중인 프로세스가 없다면 다른 프로세스가 Critical Section에 진입할 수 있어야 한다.
   
  3. 한정 대기 (Bounded Waiting)
   : Critical Section에 진입하려는 프로세스가 무한하게 대기해서는 안 된다.
  ```



<h2>Peterson's Solution </h2>

---

- `flag` : 임계 영역에서 **프로세스가 작업중인지 저장하는 변수**
- `turn` : **Critical Section에 진입하고자 하는 프로세스를 가리키는 변수**
- 어떤 프로세스가 임계 영역에 진입하면 `flag`를 `lock`하고, 나오면 `unlock`하는 방식으로 임계 영역 문제를 해결

```c++
do {
    flag[i] = true;
    turn = j;
    while (flag[j] && turn == j);
    // Critical Section
    flag[i] = false;
    // Reminder Section
} while(ture);
```



<h2> Mutex Locks</h2>

---

- <u>여러 스레드</u>가 공통 리소스에 접근하는 것을 제어하는 기법
- `lock`이 하나만 존재할 수 있는 locking 매커니즘을 따른다.
- **이미 하나의 스레드가 Critical  Section에서 작업중인 `lock` 상태에서 다른 스레드들은 Critical Section에 진입할 수 없도록 한다.**



<h2>Semaphores</h2>

---

- <u>여러 개의 프로세스나 스레드</u>가 Critical Section에 진입할 수 있는 locking 매커니즘

- 세마포어는 **카운터**를 이용해 동시에 리소스에 접근할 수 있는 프로세스를 제한한다.

  -> 물론 한 프로세스가 값을 변경할 때는 다른 프로세스가 동시에 값을 변경하지는 못한다.

- 세마포어는 P와 V라는 명령으로 접근할 수 있다.

  -> P, V 는 try 와 increment를 뜻하는 네덜란드어 Proberen과 Verhogen의 머릿글자이다.

<h3>Semaphore Usage</h3>

- 세마포어의 카운터가 <u>한 개</u>인 경우 **바이너리 세마포어(Binary Semaphore)**  -> 사실상 mutex와 동일
- 세마포어의 카운터가 <u>두 개</u> 이상인 경우 **카운팅 세마포어(Counting Semaphore)**

<h3> Deadlocks and Strvation</h3>

- **데드락(Deadlock)**

  : 두 프로세스가 리소스를 점유하고 놓아주지 않거나, 어떠한 프로세스도 리소스를 점유하지 못하는 상태가 되어 프로그램이 멈추는 현상

  ex) 서로 종료될 때까지 대기하는 프로그램을 실행하는 두 프로세스가 있을 때, 프로세스 A는 B가 종료될 때까지, 프로세스 B는 A가 종료될 때까지 작업을 하지 않기 때문에 프로그램은 어떤 동작도 하지 못한다.



<h2> Classic Problem of Synchronization</h2>

---

- **철학자들의 만찬 문제(Dining-Philosophers Problem)**

  : 철학자 5명이 식탁 가운데 음식을 두고 철학자들은 사색과 식사를 반복한다. 포크는 총 5개, 단 음식을 먹으려면 2개의 포크를 사용해야 한다. 즉, 동시에 음식을 먹을 수 있는 사람은 두 명뿐이다. 운이 좋으면 5명의 철학자들이 돌아가면서 사색과 식사를 이어갈 수 있다. 하지만 **모두가 포크를 하나씩 들고 식사를 하려하면 누구도 식사를 할 수 없는 상태**, 즉 데드락에 빠진다.





