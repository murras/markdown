# Jekyll을 이용한 GitHub Blog 만들기

- [이재열님](https://github.com/malkoG)의 강의를 토대로 만들어진 매뉴얼입니다.

### 목차
1. [Git 설치](#Git-설치)
2. [Ruby 설치](#Ruby-설치)
3. [Visual Studio Code 설치](#Visual-Studio-Code-설치)
4. [Jekyll 설치 및 설정](#Jekyll-설치-및-설정)

### [Git 설치](#목차)
[Git 설치 링크](https://git-scm.com/)에 들어갑니다.

![Image](https://i.imgur.com/T56GzYB.png)

- 재열님은 아래 이외에는 모두 Next 하셨습니다. 
    - Use Git from Git bash only.     
    - Unix Style line endings.
    - Enable Symbolic Link 체크

### [Ruby 설치](#목차)
[Ruby 설치 링크](https://www.ruby-lang.org/ko/)에 들어갑니다.

![Image](https://i.imgur.com/GMJU4R8.png)

- `RubyInstaller`를 누릅니다.
  
![Image](https://i.imgur.com/Dorau1u.png)

- 맨 위 `2.5.3-1` 버전을 설치합니다.
  
![Image](https://i.imgur.com/mNUSgcY.png)

- 모두 체크 후 설치 진행합니다.

![Image](https://i.imgur.com/AyEyTvl.png)

- 커맨드 창이 나오는데, 3을 입력해서 설치하면 됩니다.

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


### [Jekyll 설치 및 설정](#목차)
#### Jekyll Install
- 다시 터미널을 열고 `gem install jekyll`을 입력한다.

![Image](https://i.imgur.com/2bRiBaJ.png)

- Jekyll 설치가 다 됐으면 `bundle install`을 입력한다.

#### Repository 생성
- jekyll이 설치되는 동안 자신의 GitHub에 들어가서 Repository를 만든다.

 ![Image](https://i.imgur.com/g4xeus3.png)

- Repo Name을 `자신의 GitHub 계정명.github.io`로 정해야한다.

![Image](https://i.imgur.com/j92swJn.png)

- 만든 후 VS Code로 돌아와서 `F1`을 누르고 `git clone`을 적는다.

![Image](https://i.imgur.com/BR9Lqci.png)

- `https://github.com/계정명/계정명.github.io`을 적고 원하는 위치를 지정한다.

![Image](https://i.imgur.com/QRDdrP1.png)

#### Jekyll Install (이어서)

![Image](https://i.imgur.com/jH2hprj.png)

- `jekyll new blog`을 입력한다.

- 터미널에 나온 경로의 `blog` 폴더에 들어가서 모든 항목을 위에서 다운받은 Repository의 폴더에 넣는다.

![Image](https://i.imgur.com/iM7Pljj.png)

> 항목 잘라내기 후 Repo에 붙여넣기.

![Image](https://i.imgur.com/x29DaJZ.png)

![Image](https://i.imgur.com/SCiziqK.png)

- VS Code의 상단 메뉴 `파일(File)` - `폴더 열기(Open Folder)`에서 다운로드한 Repo 폴더를 연다.

![Image](https://i.imgur.com/Y2TQDY0.png)

- 아래와 같이 열려야 한다.

![Image](https://i.imgur.com/oJ5f2hI.png)

- 터미널을 연 뒤(`Ctrl` + ``` ` ```), `jekyll serve`를 입력한다.

![Image](https://i.imgur.com/UvfTJsZ.png)

- 컨트롤 키를 누르고 링크(`http://127.0.0.1:4000/`)를 클릭하면 기본 세팅된 블로그를 로컬에서 볼 수 있다.

![Image](https://i.imgur.com/4T0wQSh.png)

- 아까 그 터미널에서 `Ctrl` + `C`를 누르면 서버를 멈출 수 있다.
  
#### Publishing
- VS Code는 터미널 없이 git에 push가 가능하다.
- 왼쪽 3번째 아이콘(`Ctrl`+`Shift`+`G`)를 누른다.
  
![Image](https://i.imgur.com/UkL34XN.png)

- 변경 내용에서 +를 누르고 위의 메시지에 아무 메시지나 적는다(Publishing Blog라고 적겠습니다).

![Image](https://i.imgur.com/qb8QNYs.png)

- 상단의 v표를 누르면 Commit이 된다.

![Image](https://i.imgur.com/RI2V0tj.png)

- v표 우측에 ... 버튼을 누른 뒤 `푸시(Push)` 버튼을 누르면 Push가 된다.

![Image](https://i.imgur.com/zIvbEMa.png)

- Push가 된다면 아까 만들었던 Repo 이름을 주소창에 넣어봅시다.
    - `자신의 github 계정명.github.io`

![Image](https://i.imgur.com/ddjMyH5.png)

- 이제 본인의 블로그가 완성이 됐습니다.
  
#### 댓글 기능 추가하기
- Jekyll의 기본 테마는 Minima이다. 댓글 기능을 추가하기 위해서 layout을 수정해야 한다.
- 일단 `_layouts` 폴더와 그 안에 `post.html`을 만들어야한다.

![Image](https://i.imgur.com/63Wchsc.png)

![Image](https://i.imgur.com/XDMDtkc.png)

- 우측에 `post.html`을 작성해야한다.
- [minima theme의 GitHub Page의 post.html](https://github.com/jekyll/minima/blob/master/_layouts/post.html)을 들어가서 코드를 복사해서 넣는다.

![Image](https://i.imgur.com/LDnkOpG.png)

- 댓글 기능을 추가하기 위해 [utteranc](https://utteranc.es/)에 들어간다.

- `계정명/계정명.github.io`를 적고, 그 다음 항목에선 3번째를 선택한다.
  
![Image](https://i.imgur.com/BnOIVeq.png)

- 더 내리면 우측 하단의 `Copy` 버튼이 있다.
  
![Image](https://i.imgur.com/hpt0Z9f.png)

- 복사한 코드를 `post.html`의 하단에 넣는다.

![Image](https://i.imgur.com/oxgP8JB.png)

- 모두 저장한 뒤, 위에서 했던 Commit, Push를 한다.

- 자신의 블로그에 들어간뒤, 게시글에 들어가서 최하단을 보면, 댓글 기능이 추가됐다.

![Image](https://i.imgur.com/JVF1kqR.png)

- 현재는 댓글이 달리지 않는데, 우측 하단 초록색 버튼을 눌러 GitHub에 로그인해야한다.
- 물론 로그인을 한 뒤 댓글을 달려고 시도해도 댓글이 달리지 않는다.

![Image](https://i.imgur.com/24UbAzf.png)

- 빨간 박스에 `Install the app` 버튼을 눌러야한다.
- `Install` 버튼을 누른다.

![Image](https://i.imgur.com/pMihr3c.png)

- `Only select repositories`의 선택 항목에서 내 블로그 Repository를 선택하고 `Install` 버튼을 누른다.
- 다시 들어가서 댓글을 달아보면 댓글을 달 수 있다.

![Image](https://i.imgur.com/Dl2zR6z.png)

#### 포스팅하기
- 포스팅은 `_post` 폴더 안에 `md` 파일로 해야한다.
    - md(markdown) 파일 문법은 배우기 매우매우매우매우 쉬워서 생산성을 높일 수 있으니 배워보는 것을 추천드립니다. 이 글도 markdown으로 작성되었습니다.
- 파일 이름의 형식이 중요한데, `yyyy-mm-dd-file-name.md`꼴로 되어야합니다.
    - 예를 들면 `2018-12-01-hi-hiarc.md`로 입력하면 됩니다.
- 글 내용은, 아래와 같이 되어야합니다.
    - `title`, `date` 수정에 유의합시다.
```markdown
---
layout: post
title:  "Hello My Blog!"
date:   2018-12-01 11:26:30 +0900
categories: jekyll update
---
내  용 
```

![Image](https://i.imgur.com/4XLBVzU.png)