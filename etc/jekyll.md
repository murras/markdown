# Jekyll을 이용한 GitHub Blog 만들기

- [이재열님](https://github.com/malkoG)의 강의를 토대로 만들어진 매뉴얼입니다.

### 목차
1. [GitHub 설치]()
2. [Ruby 설치]()
3. [Visual Studio Code 설치]()
4. [Jekyll 설치]()
5. 

### [GitHub 설치](#목차)
[Git 설치 링크](https://git-scm.com/)에 들어갑니다.

![Image](https://i.imgur.com/T56GzYB.png)

- 재열님은 아래 이외에는 모두 Next 하셨습니다.
    - Use Git from Git bash only.     
    - Unix Style line endings.
    - Enable Symbolic Link 체크

### [Ruby 설치](#목차)
[Ruby 설치 링크](https://www.ruby-lang.org/ko/)에 들어갑니다.

![Image](https://i.imgur.com/GMJU4R8.png)

- RubyInstaller를 누릅니다.
  
![Image](https://i.imgur.com/Dorau1u.png)

- 맨 위 `2.5.3-1` 버전을 설치합니다.
  
![Image](https://i.imgur.com/mNUSgcY.png)

- 모두 체크 후 설치 진행합니다.

![Image](https://i.imgur.com/AyEyTvl.png)

- 커맨드 창이 나오는데, 3을 입력해서 설치한다.

![Image](https://i.imgur.com/sBHd7nJ.png)

### [Visual Studio Code 설치](#목차)
- 설치 파일을 다운 받고, 설치를 진행합니다.
    - [VS Code 설치 링크](https://code.visualstudio.com/)
  
    ![Image](https://i.imgur.com/EajUIz4.png)

    ![Image](https://i.imgur.com/CgkCoyn.png)

#### git bash로 terminal 열기
- `Ctrl` + `,`를 누르면 설정 창이 나옵니다. 쓸 일이 많으니 외우세요.(`F1` 누르고 `setting` 검색해도 됩니다.)
- 검색창에 `shell:windows`를 검색하면 아래와 같이 나오는데, 그 부분을 위에서 설치한 `Git 경로\bin\bash.exe`를 적어야 합니다.
    - `C:\Program Files\Git\bin\bash.exe` 기본값으로 설치하셨으면 이거 복사해서 쓰세요.

![Image](https://i.imgur.com/fJR8CMs.png)

- 수정 후 저장을 하고 `Ctrl` + `Shift` + ``` ` ``` (물결) 입력하면 하단에 bash가 나와야합니다.

![Image](https://i.imgur.com/qXZtIwr.png)


### [Jekyll 설치](#목차)

- 다시 터미널을 열고 `gem install jekyll`을 입력한다.

![Image](https://i.imgur.com/2bRiBaJ.png)

- 설치가 다 됐으면 `jekyll new 자신의 블로그 이름`을 입력한다.

- `bundle install`을 입력한다.

![Image](https://i.imgur.com/jH2hprj.png)

- `jekyll serve`를 입력한다.

![Image](https://i.imgur.com/UvfTJsZ.png)

- 컨트롤 키를 누르고 링크를 클릭하면 기본 세팅된 블로그를 볼 수 있다.

![Image](https://i.imgur.com/4T0wQSh.png)
