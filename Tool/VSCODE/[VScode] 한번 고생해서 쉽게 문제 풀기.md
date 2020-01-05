#### Windows 10 환경에서 Git, GitHub, Visual Studio Code, MinGW를 사용합니다.

### 목차

1. [Visual Studio Code 설치](#Visual-Studio-Code-설치)
2. [Git](#Git)
3. [Visual Studio Code 설정](#Visual-Studio-Code-설정)
4. [MinGW 설치](#MinGW-설치)
5. [Code Runner로 편하게 문제 풀기](#Code-Runner로-편하게-문제-풀기)
6. [Code Runner로 디버깅하기](#Code-Runner로-디버깅하기)

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

- 수정 후 저장을 하고 `Ctrl` + `Shift` + ``` ` ``` (물결) 입력하면 하단에 bash가 나와야합니다.

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
    - *어느 부분인지 잘 기억이 안나는데 GitHub 아이디와 패스워드 입력하는 부분이 있습니다.*
    - 변경 내용을 확인하고, + 버튼을 눌러 변경 내용을 스테이징합니다.
    
    ![Image](https://i.imgur.com/6C3UcPY.png)
    
    - 커밋 메시지를 입력하고, 위에 v 버튼을 누릅니다.
    
    ![Image](https://i.imgur.com/vB0JifJ.png)
    
    - `...` 버튼을 눌러 `Push` 혹은 `푸시`를 클릭합니다.
- 자신의 GitHub Page로 가봅시다.(`https://github.com/자신의 username/Repository name`)

![Image](https://i.imgur.com/LvLBXwX.png)

![Image](https://i.imgur.com/TqEINdF.png)

- 방금 그 파일이 업로드 된걸 확인할 수 있습니다.


#### Extension 설치
- 이 글의 과정에서 필요한 Extension들입니다. 검색, 설치 후 다시 로드 버튼을 누릅니다.
    - C/C++ : 설치하면 `Shift` + `Alt` + `F`로 코드 정렬(Format)이 가능합니다.
    - Code Runner : 밑에서 설명합니다.

![Image](https://i.imgur.com/Ezvdi4j.png)

- (선택) 추천 Extension 
    - 각종 Theme : 감성.
        - BlueDawn Theme
        - Panda Theme
    - vscode-icons : 감성.
    - Rainbow Brackets : 괄호에 색을 정해줘서 덜 헷갈립니다.
    - Active File In StatusBar : 파일 경로 쉽게 알고 복사 가능합니다.
    - Markdown 작성에 유용한 Extension
        - Markdown Preview Github Styling : `Ctrl` + `K`, `V`를 누를때 나오는 Markdown Preview를 Github 스타일로 보여줍니다.
        - Markdown PDF : 작성한 md 파일을 PDF로 한번에 변환해줍니다.
        - vscode-imgur : markdown 작성할때 이미지를 올리기 참 번거로운데, 이게 진짜 편하게 해줍니다. 대신 초기 설정이 살짝 귀찮은데, [imgur 사이트](https://imgur.com/)에 가입한 후 설정을 해줘야합니다. 이건 찾아보시면 쉬울거에요. 이미지를 복사 후(클립보드 안에 이미지를 두고), 단축키(기본이 아마 `Ctrl` + `Alt` + `V`)만 누르면 몇초 내에 이미지가 업로드 되고, md 파일에 바로 나타납니다.
    - Setting Sync : 나중에 직접 한번 찾아보세요. 다른 기기에서 동기화할 때 아주 아주 아주 아주 편합니다.
    - 그 외 각 언어별로 편리한 Extension이 있습니다.

#### (선택) Code Format (코드 정렬) 형식
- Format(`Shift` + `Alt` + `F`) 종류를 바꾸고 싶을 때가 있다.
- 이건 개인 선호도 차이라서 기본 설정이 좋다면 그냥 해도 되는데, 저는 바꿨습니다.
- `Ctrl` + `,`를 눌러 설정에 들어간 후, `C_Cpp.clang_format`을 검색합니다.
  
![Image](https://i.imgur.com/kDtLYZm.png)

- 빨간 네모 박스 부분을 수정하면 됩니다.(전 fallback이 뭐가 다른지 잘 모르겠어서 둘다 바꿉니다.)
    - `{ BasedOnStyle: ??????, IndentWidth: 4, ColumnLimit: 0}`
    - ?????? : `Visual Studio`, `LLVM`, `Google`, `Chromium`, `Mozilla`, `WebKit`
- 정확한 차이는 저도 잘 모르니까 하나하나 바꾸고 예시 코드 가서 `Shift` + `Alt` + `F` 눌러보세요.
- 예시 코드
```cpp
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    bool check = true;
    int arr[3][2] = {{1, 2},    
    {3, 4},
    {5, 6}};
    if (check){

        int example = 0;
        for (int i = 0; i < 10; i++){
            example++;
        }
    }
}
```
- Google 
```cpp
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    bool check = true;
    int arr[3][2] = {{1, 2},
                     {3, 4},
                     {5, 6}};
    if (check) {
        int example = 0;
        for (int i = 0; i < 10; i++) {
            example++;
        }
    }
}
```

- Mozilla
```cpp
#include <algorithm>
#include <iostream>
using namespace std;
int
main()
{
    bool check = true;
    int arr[3][2] = { { 1, 2 },
                      { 3, 4 },
                      { 5, 6 } };
    if (check) {
        int example = 0;
        for (int i = 0; i < 10; i++) {
            example++;
        }
    }
}
```

- Webkit
```cpp
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    bool check = true;
    int arr[3][2] = { { 1, 2 },
        { 3, 4 },
        { 5, 6 } };
    if (check) {
        int example = 0;
        for (int i = 0; i < 10; i++) {
            example++;
        }
    }
}
```

- LLVM
```cpp
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    bool check = true;
    int arr[3][2] = {{1, 2},
                     {3, 4},
                     {5, 6}};
    if (check) {
        int example = 0;
        for (int i = 0; i < 10; i++) {
            example++;
        }
    }
}
```
- 하나하나 해보시면서 편한걸로 하시면 되겠습니다.
 
### [MinGW 설치](#목차)
- Windows에는 gcc와 g++가 없어서 직접 설치해야합니다.
- MinGW로 gcc와 g++을 사용할 수 있습니다.
- [MinGW 다운로드 링크](https://sourceforge.net/projects/mingw/)를 눌러 MinGW를 다운받읍시다.
- 다운받은 파일을 실행해서 설치를 진행합시다. 경로는 그대로 하는 것이 좋은 것 같은데 원하면 바꿔도 됩니다. 이 글에서는 그대로 하는 것으로 진행할게요.

    ![Image](https://i.imgur.com/nUIjOc6.png)

    ![Image](https://i.imgur.com/wzBWelc.png)

    ![Image](https://i.imgur.com/JSxZvXf.png)

    - 위와 같이 체크하고 좌측위 탭에서 Installation - Apply Change를 누릅시다.

    ![Image](https://i.imgur.com/1piq4QF.png)

- 설치를 진행하는 동안 환경 변수를 설정해야 합니다.
    - 시작 버튼을 누르고 `환경 변수`나 `sysdm.cpl`을 검색합니다.
     
    ![Image](https://i.imgur.com/Bf1E18u.png)
    
    - 고급 탭의 환경 변수에 들어가서 사용자 변수 - Path 경로에 추가하기 위해 더블 클릭 혹은 편집을 누릅니다.

    ![Image](https://i.imgur.com/g0lDllA.png)

    - 아래와 같이 새로 만들기를 눌러서 아까 설치했던 MinGW의 bin 디렉토리 경로를 입력합니다.

    ![Image](https://i.imgur.com/XL8T4Jn.png)

- cmd 창에서 `gcc -v`나 `g++ -v`를 입력해서 제대로 설치되었는지 확인해보고, 만약 제대로 따라 했는데도 없는 명령이라고 나온다면 재부팅을 한번 해줍니다.(환경 변수 적용을 위해)
  
```
C:\Users\Murra>gcc -v
Using built-in specs.
COLLECT_GCC=gcc
COLLECT_LTO_WRAPPER=c:/mingw/bin/../libexec/gcc/mingw32/6.3.0/lto-wrapper.exe
Target: mingw32
Configured with: ../src/gcc-6.3.0/configure --build=x86_64-pc-linux-gnu --host=mingw32 --target=mingw32 --with-gmp=/mingw --with-mpfr --with-mpc=/mingw --with-isl=/mingw --prefix=/mingw --disable-win32-registry --with-arch=i586 --with-tune=generic --enable-languages=c,c++,objc,obj-c++,fortran,ada --with-pkgversion='MinGW.org GCC-6.3.0-1' --enable-static --enable-shared --enable-threads --with-dwarf2 --disable-sjlj-exceptions --enable-version-specific-runtime-libs --with-libiconv-prefix=/mingw --with-libintl-prefix=/mingw --enable-libstdcxx-debug --enable-libgomp --disable-libvtv --enable-nls
Thread model: win32
gcc version 6.3.0 (MinGW.org GCC-6.3.0-1)
```

```
C:\Users\Murra>g++ -v
Using built-in specs.
COLLECT_GCC=g++
COLLECT_LTO_WRAPPER=c:/mingw/bin/../libexec/gcc/mingw32/6.3.0/lto-wrapper.exe
Target: mingw32
Configured with: ../src/gcc-6.3.0/configure --build=x86_64-pc-linux-gnu --host=mingw32 --with-gmp=/mingw --with-mpfr=/mingw --with-mpc=/mingw --with-isl=/mingw --prefix=/mingw --disable-win32-registry --target=mingw32 --with-arch=i586 --enable-languages=c,c++,objc,obj-c++,fortran,ada --with-pkgversion='MinGW.org GCC-6.3.0-1' --enable-static --enable-shared --enable-threads --with-dwarf2 --disable-sjlj-exceptions --enable-version-specific-runtime-libs --with-libiconv-prefix=/mingw --with-libintl-prefix=/mingw --enable-libstdcxx-debug --with-tune=generic --enable-libgomp --disable-libvtv --enable-nls
Thread model: win32
gcc version 6.3.0 (MinGW.org GCC-6.3.0-1)
```

### [Code Runner로 편하게 문제 풀기](#목차)
- 위에서 설치한 Code Runner 사용법입니다.
- `Ctrl` + `,`를 눌러 설정에 들어가고, 우측 메뉴바에서 setting.json을 열어줍니다.
    ![Image](https://i.imgur.com/CoMllu3.png)
- 우측에 다음으로 덮어씌웁니다. bash 경로 다르게 하신 분은 알맞게 변경해주세요.
    - 주석 쪽은 한번 읽어 보시면 이해가 되실거에요. BOJ 문제 푸는 목적으로 하실거면 그대로 사용하시면 됩니다.
```json
{
    "terminal.integrated.shell.windows": "C:\\Program Files\\Git\\bin\\bash.exe",
    "code-runner.executorMap": {
        "c": "cd $dirWithoutTrailingSlash gcc $fileName -g -o $fileNameWithoutExt && ./$fileNameWithoutExt.exe",        
        // input.txt로 바로 입력.
        "cpp": "cd $dirWithoutTrailingSlash && g++ $fileName -g -o $fileNameWithoutExt && ./$fileNameWithoutExt.exe < input.txt",
        // 직접 실행후 입력할때.
        //"cpp": "cd $dirWithoutTrailingSlash && g++ $fileName -g -o $fileNameWithoutExt && ./$fileNameWithoutExt.exe", 
    },
    "code-runner.runInTerminal": true,
}
```
- 입력을 받는 cpp 파일과 input.txt를 생성합니다.
    - 사진에`#include <string>` 추가해주세요.

![Image](https://i.imgur.com/AQcbV66.png)


- cpp 파일에 우클릭 - Run Code 혹은 cpp 파일에 포커스를 두고 `Ctrl` + `Alt` + `N`을 누르고 밑의 터미널을 확인해봅시다.

![Image](https://i.imgur.com/CGrPx0R.png)

- 이런 식이면 백준 문제 풀 때 하나하나 입력하지 않고 입력 예제를 복사해서 input.txt에 저장, 명령어 한번이면 바로 결과값을 얻을 수 있습니다.

#### (선택)이지만 많은 분들이 하실거 같은 설정
- GitHub에 .exe 파일은 올리고 싶지 않은데, 자꾸 변경 내역에 올라와서 번거로울 때가 있습니다. 그럴땐 repo 최상위 경로에 `.gitignore` 파일을 만들고, 아래와 같이 입력합니다.

    ```
    *.exe
    ```
    
- 확장자가 exe인 파일은 수정된 리스트에 나오지 않습니다.
- input.txt 파일 업로드를 원하지 않는 경우엔 `*.txt`를 하면 됩니다.


### [Code Runner로 디버깅하기](#목차)
- Vscode 좌측 메뉴에 디버그를 누릅니다.(`Ctrl`+`Shfit`+`D`)

    ![Image](https://i.imgur.com/GjxZu0E.png)

- 톱니바퀴 버튼을 누르고, 환경은 `C++(GDB/LLDB)`를 선택합니다.
- launch.json 파일이 열리는데, 다음을 입력합니다.
    - 주석 부분은 읽어보시고 하실 때마다 수정하셔야 해요. 이게 약간 번거로워요.
    ```json
    {
        "version": "0.2.0",
        "configurations": [
            
            {
                "name": "(gdb) Launch",
                "type": "cppdbg",
                "request": "launch",
                // 
                // 이 밑 부분 파일경로, 파일명을 맞게 고쳐야합니다!
                // 저는 절대 경로가 편해서 절대 경로로 씁니다.
                // 
                // 예)  D:/Git/algorithm/BOJ/2606.exe
                // 혹은 D:\\Git\\algorithm\\BOJ\\2606.exe
                "program": "${workspaceFolder}/test.exe",
                "args": [],
                "stopAtEntry": false,
                "cwd": "${workspaceFolder}",
                "environment": [],
                "externalConsole": true,
                "MIMode": "gdb",
                //
                // MinGW 경로가 같은지 확인 !
                // MinGW 설치경로/bin/gdb.exe 입니다.
                "miDebuggerPath": "C:/MinGW/bin/gdb.exe",
                "setupCommands": [
                    {
                        "description": "Enable pretty-printing for gdb",
                        "text": "-enable-pretty-printing",
                        "ignoreFailures": true
                    }
                ]

            }
        ]
    }
    ```
- 코드의 원하는 부분에 **중단점을 넣고**, `F5`를 눌러 디버깅을 진행합니다.
- `F11`을 눌러 한단계씩 진행하며 디버깅을 하면 됩니다.
    ![Image](https://i.imgur.com/uANlCJ2.png)
- 사실 디버깅은 제가 자주 사용하지는 않아서 상세한 기능은 잘 모르지만 간단한 디버깅에선 쓸만합니다.
#### 이 방법에서 주의할 점은 디버깅을 하기 전에 한번 Run Code(컴파일 하기 위해)를 해줘야하는 것과 디버깅 경로를 실행 파일이 달라질때마다 다시 설정해야한다는 것입니다. 혹시 더 편한 방법이 있으면 알려주세요.**