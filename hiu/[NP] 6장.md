## 6.2 I/O Models
- Unix에선 5가지 I/O Model이 있다.
    - blocking I/O
    - nonblocking I/O
    - I/O multiplexing(select와 poll)
    - signal driven I/O(SIGIO)
    - asynchronous I/O(aio_ 함수)

### blocking I/O

### nonblocking I/O
- system call에서 돌려줄 데이터가 없으면 `EWOULDBLOCK`을 RETURN한다.
- 반복문 속에서 준비 되었는지 계속해서 확인한다.(Busy waiting, polling)

### I/O multiplexing
- `select`에서 block된 상태: 소켓이 readable하면 `recvfrom`을 호출한다.
- 두 개(`select`, `recvfrom`)의 system call을 하기 때문에 단점이 된다.
- `select`를 사용하면 하나 이상의 descriptor가 준비되는 것을 기다릴 수 있다.

### signal driven I/O
- descriptor가 ready되면 `SIGIO`로 커널에게 알린다.

### asynchronous I/O
- 위의 signal driven I/O는 입출력 작업이 시작될때 커널에서 신호를 보내지만 asynchronous I/O는 입출력 작업이 끝날 때 신호를 보낸다.

- ~ Figure 6.6까지 봅시다.

## 6.3 select fucntion
```c
int select(int maxfdp1, fd_set *readset, fd_set *writeset, fd_set *exceptset, const struct timeval *timeout)
```

- `timeout`에 3가지 경우가 있다.
    - `NULL` : 올 때 까지 기다린다.
    - `0` : 기다리지 않고 바로 return 한다. `polling`이라고 부른다.
    - 0 이외의 숫자 : 지정된 숫자만큼 기다린다.
- `readset`, `writeset`, `exceptset`에 descriptor 번호를 지정할 수 있다.
    - `exceptset`: out of band 데이터 도착시 해당 시퀀스 옵션에 상관 없이 제일 먼저 보낸다.

```c 
void FD_ZERO(fd_set *fset);             // clear all
void FD_SET(int fd, fd_set *fset);      // turn on
void FD_CLR(int fd, fd_set *fset);      // turn off
int FD_ISSET(int fd, fd_set *fset);     // checking
```

- `maxfdp1`은 test할 descriptor의 개수를 설정하는데, 최대 수 +1 이다. 보통 1024이다.