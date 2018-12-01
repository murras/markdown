## 5.9 SIGCHLD 신호 처리
- Zombie state의 목적
    - 나중에 Parent가 가져갈 Child에 대한 정보를 유지하는 것.
    - Process ID와 종료 상태, Child의 자원 이용률(CPU time, memory 등) 정보가 있다.
## 5.10 wait와 waitpid 함수
- `wait`와  `waitpid`는 두 개의 값을 반환한다.
    - 종료된 Child의 pid
    - Child의 종료 상태
- `wait`
    - 하나 이상의 수행 중인 Child가 있으나 종료된 Child가 없으면 종료될 때까지 block된 상태이다.
- `waitpid`
    - 어느 process를 기다릴지 정할 수 있다.
    - -1로 설정하면 아무 Child가 종료되기를 기다린다.
    - options에 WNOHANG을 넣으면 종료된 Child가 없을 때 block 하지 않는다.
## 5.11 `accept` return전에 연결 종료
- (POSIX) `ECONNABORTED` 오류를 발생시켜야 한다.
    - `EPROTO`를 돌려주면 Server가 다시 `accept`를 호출해야 할지 판단할 수 없게 한다.

## 5.12 Server Process 종료
1. Server를 종료시키면 Server는 Client에게 FIN 메시지를 보낸다.
2. Client는 ACK를 보내고 두 연결은 half-close 상태가 된다.
3. `SIGCHLD` 신호가 Parent에게 보내져 알맞게 처리된다.
4. 이 때 Client는 ACK를 보냈지만 `fgets` 상태에 block 되어 있다.
5. `fgets`에 입력을 넣으면, Client는 Server에 `writen`을 한다.
   - *FIN을 받는다고 Server가 닫혔다는 정보를 알지는 못한다.*
6. Server는 소켓을 열었던 Process가 종료되어서 Client에게 RST로 응답한다.
7. Client는 RST를 받기 전에 와있던 FIN 메시지가 있기 때문에 `readline` 상태에서 EOF를 반환한다.
8. 이에 Client는 예상치못한 EOF로 err_quit(모든 open descriptor를 닫음)와 `server terminated prematurely`를 출력하고 종료한다.(Figure 5.5)

- RST가 `readline`보다 먼저 도착하면 `readline`이 `ECONNRESET` 오류를 반환한다.

## 5.13 SIGPIPE 신호
```c
#include "unp.h"
void str_cli(FILE *fp, int sockfd) {
    char sendline[MAXLINE], recvline[MAXLINE];

    while (Fgets(sendline, MAXLINE, fp) != NULL) {
        Writen(sockfd, sendline, 1); 
        sleep(1);
        Writen(sockfd, sendline + 1, strlen(sendline) - 1); // readline 전에 두번 전송

        if (Readline(sockfd, recvline, MAXLINE) == 0)
            err_quit("str_cli: server terminated prematurely");

        Fputs(recvline, stdout);
    }
}
```
- RST를 받은 소켓에 데이터를 쓰면, 그 Process에게 `SIGPIPE` 신호를 보낸다.
- `SIGPIPE`에 대한 Default action은 프로세스를 종료시킨다.
- 이 신호를 무시하고 `write`를 하면 `EPIPE` 오류를 반환한다.
- `EPIPE`에 대해 특별한 처리 동작이 필요하면 `SIG_IGN`으로 설정하면 된다.
- 하지만 여러 소켓을 사용할 때 어느 소켓이 이 오류를 발생시켰는지 알 수 없다.
- 알기 위해서는 signal을 무시하거나 signal handler return 뒤에 write로부터의 `EPIPE`를 처리해야한다.

## 5.14  Crashing of Sever Host
- 1번 상황 : Server host가 갑자기 정지했을 때
- 2번 상황 : 중간 라우터의 고장으로 데이터가 host까지 도달할 수 없는 경우 일어나는 과정이다.
1. Client가 Server에게 데이터를 보내면 Client는 `writen`을 한 뒤 `readline`에서 block된다.
2. Client는 Server로부터 ACK를 받기 위해 데이터를 계속해서 재전송한다.
    - 버클리 구현에선 12회 재전송을 하며 약 9분을 기다린다.
3. 오류를 return한다.
    1. 1번 상황에서는 `ETIMEOUT` 오류를 return한다.
    2. 2번 상황에서는 중간 라우터로부터 ICMP를 받으면 `EHOSTUNREACH` 또는 `ENETUNREACH` 오류를 return한다.

## 5.15 Rebooting Server
- 5.14의 상황처럼 Server가 Crashing된 다음 다시 Rebooting 되었을때, Server는 연결에 관한 모든 정보를 잃은 상태이다.
- 따라서 Clinet가 메시지를 보내면, Server는 RST로 응답한다.
- RST를 받은 Client는 `ECONRESET` 오류를 return한다.