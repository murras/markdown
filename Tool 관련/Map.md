
Windows 10 환경에서 Git, GitHub, Visual Studio Code, MinGW를 사용합니다.
### 목차


1. [Visual Studio Code 설치](#Visual-Studio-Code-설치)
2. [Git](#Git)
    - GitHub 가입 및 repository 생성
3. [Visual Studio Code 설정](#Visual-Studio-Code-설정)
4. [MinGW 설치]
5. [CodeRunner 설치]


### [Visual Studio Code 설치](#목차)
- 설치 파일을 다운 받고, 설치를 진행합니다.
    - [VS Code 설치 링크](https://code.visualstudio.com/)
  
    ![Image](https://i.imgur.com/EajUIz4.png)

    - 전 Stable을 사용합니다.
    - 밑 사진만 변경하고 Next 했습니다. 바꾸고 싶은 부분은 바꾸세요.
    ![Image](https://i.imgur.com/CgkCoyn.png)
    
---    

### [Git](#목차)
#### 설치
- 일단 Git을 먼저 다운 받습니다.
    - [Git 링크](https://git-scm.com/)
    ![Image](https://i.imgur.com/yPxhmhW.png)
    - 우측 하단 Download 클릭.
- 설치를 하는데, 밑에 나온 사진 이외에는 저는 다 `Next` 했습니다. 바꿀거 있으시면 바꾸시면 됩니다.(Git 설치 경로 바꾸셨으면 기억해두세요.)
    - 버전에 따라 설치할때 창이 달라지는거 같으니 하나하나 직접 찾아보시면서 설치하셔도 되겠습니다.
    ![Image](https://i.imgur.com/4oqgquX.png)
  
#### GitHub 가입 및 repository 생성
- 설치하면 시간이 좀 걸리는데(걸려야하는데), 그 때 GitHub을 가입하러 갑시다.
    - [GitHub 링크](https://github.com/)
    ![Image](https://i.imgur.com/AqvelWZ.png)
    - 가입은.. 혼자 하실수 있을거라고 믿습니다.
- 가입하셨으면 로그인하시고, 우측 상단에 +▼ 버튼을 누르고 `New repository`를 누릅니다.
![Image](https://i.imgur.com/Zmj3QIS.png)
- Repository name을 알아서 정하시고, Create repository를 누르면 새 repository가 생성됩니다.
![Image](https://i.imgur.com/s56BgzQ.png)
    - 제 경우엔 예시로 Repo name을 `ALGORITHM_`으로 적었습니다.
    - Private은 돈 내야되니 Public으로 합시다.
  
---

### [Visual Studio Code 설정](#목차)     
#### 한글 설정
- 제 경우엔 처음 설정했을때 영어로 되어 있어서 한글로 바꿨습니다. 하고 싶은 분만 하세요.
    - `F1`을 누르고 `Configure Display Language`를 입력합니다.
    - `"locale":"ko"`로 수정합니다.
    - 좌측 5번째 아이콘(EXTENSION)을 클릭합니다.
    - `korean`을 검색하면 `Korean Language Pack ~`이 나오는데 `Install`을 누르고, Install 후 우측 하단에 restart 하겠냐는 알림창이 나오면 `Yes` 누르면 됩니다.
![Image](https://i.imgur.com/VxoGLY6.png)  

#### git bash로 terminal 열기
- `Ctrl` + `,`를 누르면 설정 창이 나옵니다. 쓸 일이 많으니 외우세요.(`F1` 누르고 `setting` 검색해도 됩니다.)
- 검색창에 `shell:windows`를 검색하면 아래와 같이 나오는데, 그 부분을 위에서 설치한 `Git 경로\bin\bash.exe`를 적어야 합니다.
    - `C:\Program Files\Git\bin\bash.exe` 기본값으로 설치하셨으면 이거 복사해서 쓰세요.
![Image](https://i.imgur.com/fJR8CMs.png)
- 수정 후 저장을 하고 `Ctrl` + `Shift` + ` ` `(물결) 입력하면 하단에 bash가 나와야합니다.
![Image](https://i.imgur.com/qXZtIwr.png)

#### Repository clone, commit, push
- `F1`을 누르고 `git clone`을 입력합니다.
![Image](https://i.imgur.com/g9eP3Jj.png)
- `https://github.com/가입 때 Username/아까 만든 Repository name`을 입력합니다.
    - 제 경우엔 `https://github.com/murras/ALGORITHM_`입니다.
    ![Image](https://i.imgur.com/pGkEgKQ.png)
- 원하는 경로를 정합니다. 제 경우엔 `Git`이라는 폴더를 하나 만들어서 관리합니다.
![Image](https://i.imgur.com/WV0CRJ6.png)
- 다운로드가 되면 상단에 `파일(F) - 폴더 열기(F)`로 다운로드 된 폴더를 엽니다.
- 한 번 아무 파일이나 만들고 저장해봅시다.
![Image](https://i.imgur.com/QWYT6vQ.png)
![Image](https://i.imgur.com/J9j2vCm.png)
- 그러면 왼쪽 3번째 아이콘에 불이 들어오는데, 눌러봅시다.
    - 변경 내용을 확인하고, + 버튼을 눌러 변경 내용을 스테이징합니다.
    - ![uploading...](http://i.imgur.com/uploading.png)
    - 커밋 메시지를 입력하고, 위에 v 버튼을 누릅니다.
    - ![Image](https://i.imgur.com/vB0JifJ.png)
- 자신의 GitHub Page로 가봅시다.(`https://github.com/자신의 username/Repositry name`)