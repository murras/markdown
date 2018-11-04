# Visual Studio Code에서 터미널을 git bash로 사용하기 on Windows

- *git이 설치되어 있다고 가정하고 진행합니다.*
- 관련 포스팅
> - [MinGW로 gcc, g++ 이용하기 on Windows](http://murra.tistory.com/35)
> - [Visual Studio Code에서 CodeRunner와 MinGW를 이용해서 C,C++ 컴파일, 디버깅하기 on Windows](http://murra.tistory.com/28)
  
## git bash로 변경하는 법

- VS code를 실행해서 `ctrl` + `,`를 눌러 설정에 들어갑니다.
    ![Image](https://i.imgur.com/jwO0p8P.png)
- 검색창에 `terminal.integrated.shell.windows`를 검색합니다.
    ![Image](https://i.imgur.com/BO2kCTJ.png)
- 위와 같이 뜰텐데, 저 경로에 `자신의 Git 설치 경로\bin\bash.exe\`를 입력합니다.
- VSCode를 한번 껐다가 켭니다.
- 일단 터미널이 git bash로 바뀌었습니다.

## 터미널
- `ctrl` + `K` `ctrl` + `S`를 눌러 단축키 설정에 들어갑니다.
- 터미널을 검색합니다.
    ![Image](https://i.imgur.com/WRYVVOH.png)
- 터미널에 포커스 단축키를 지정해서 사용하거나(더블 클릭을 누르면 수정이 가능합니다) 새 통합 터미널 만들기 단축키를 입력합니다.
![Image](https://i.imgur.com/ihDV6b2.png)
- 위와 같이 git bash가 실행되면 성공입니다.