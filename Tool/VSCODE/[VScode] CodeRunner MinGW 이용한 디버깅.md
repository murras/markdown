# Visual Studio Code에서 CodeRunner와 MinGW를 이용해서 C,C++ 컴파일, 디버깅하기 on Windows

- *Visual Studio Code, MinGW가 이미 설치되어 있다는 가정하에서 진행합니다.*
- 관련 포스팅
> - [MinGW로 gcc, g++ 이용하기 on Windows](http://murra.tistory.com/35)
> - [Visual Studio Code에서 터미널을 git bash로 사용하기 on Windows](http://murra.tistory.com/36)



- VScode extension에서 CodeRunner를 설치합니다.
    - [설치링크](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner)

## CodeRunner 설치
- 설치를 한 후에 `다시 로드`를 눌러서 vscode를 껐다가 켜줍니다.

- `Ctrl` + `,`를 눌러 설정에 들어가고, 우측 메뉴바에서 setting.json을 열어줍니다.
    ![Image](https://i.imgur.com/CoMllu3.png)
- 우측을 통해 설정을 덮어 쓸수 있는데, 다음을 입력합니다.
    - C와 CPP만 다룬다면 밑에 `"c"`, `"cpp"` 부분만 입력해도 됩니다.
    - 맨 밑줄을 입력해야 `scanf`, `cin`과 같이 입력을 할 수 있습니다.
    ```json
    "code-runner.executorMap": {
        "javascript": "node",
        "java": "cd $dir && javac $fileName && java $fileNameWithoutExt",
        "c": "cd $dirWithoutTrailingSlash gcc $fileName -g -o $fileNameWithoutExt && ./$fileNameWithoutExt.exe",
        
        // 데이터값 바로 입력원할때.
        "cpp": "cd $dirWithoutTrailingSlash && g++ $fileName -g -o $fileNameWithoutExt && ./$fileNameWithoutExt.exe < d.dat",

        // 직접 입력할때
        //"cpp": "cd $dirWithoutTrailingSlash && g++ $fileName -g -o $fileNameWithoutExt && ./$fileNameWithoutExt.exe",
        "objective-c": "cd $dir && gcc -framework Cocoa $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",
        "php": "php",
        "python": "python",
        "perl": "perl",
        "perl6": "perl6",
        "ruby": "ruby",
        "go": "go run",
        "lua": "lua",
        "groovy": "groovy",
        "powershell": "powershell -ExecutionPolicy ByPass -File",
        "bat": "cmd /c",
        "shellscript": "bash",
        "fsharp": "fsi",
        "csharp": "scriptcs",
        "vbscript": "cscript //Nologo",
        "typescript": "ts-node",
        "coffeescript": "coffee",
        "scala": "scala",
        "swift": "swift",
        "julia": "julia",
        "crystal": "crystal",
        "ocaml": "ocaml",
        "r": "Rscript",
        "applescript": "osascript",
        "clojure": "lein exec",
        "haxe": "haxe --cwd $dirWithoutTrailingSlash --run $fileNameWithoutExt",
        "rust": "cd $dir && rustc $fileName && $dir$fileNameWithoutExt",
        "racket": "racket",
        "ahk": "autohotkey",
        "autoit": "autoit3",
        "dart": "dart",
        "pascal": "cd $dir && fpc $fileName && $dir$fileNameWithoutExt",
        "d": "cd $dir && dmd $fileName && $dir$fileNameWithoutExt",
        "haskell": "runhaskell",
        "nim": "nim compile --verbosity:0 --hints:off --run"
    },
    "code-runner.runInTerminal": true,
    ```
    ![Image](https://i.imgur.com/QjO2bKU.png)

- 일단 CodeRunner 설정이 끝났고, 테스트를 합니다.
    - 테스트할 코드를 적고, 우클릭-Run Code(혹은 `Ctrl`+`Alt`+`N`)를 하면 됩니다.

    ![Image](https://i.imgur.com/jfd6aOy.png)png)    ![uploading...](http://i.imgur.com/uploading.png)

    - 하단 혹은 우측에 터미널이 나오고, 아래와 같이 결과가 나옵니다. 입력값이 필요한 코드였으면 입력을 할 수 있습니다.

    ![Image](https://i.imgur.com/vHDIKHI.png)

## Debugging 방법
- MinGW가 이미 설치 되어있다고 가정하고 진행하겠습니다.
    - MinGW 설치는 다음에 기회가 되면 포스팅하겠습니다.

- Vscode 좌측 메뉴에 디버그를 누릅니다.(`Ctrl`+`Shfit`+`D`)

    ![Image](https://i.imgur.com/GjxZu0E.png)

- 톱니바퀴 버튼을 누르고, 환경은 `C++(GDB/LLDB)`를 선택합니다.
- launch.json 파일이 열리는데, 다음을 입력합니다.
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
                "program": "${workspaceFolder}/test.exe",
                "args": [],
                "stopAtEntry": false,
                "cwd": "${workspaceFolder}",
                "environment": [],
                "externalConsole": true,
                "MIMode": "gdb",
                //
                // MinGW 경로가 같은지 확인 !
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
- 코드의 원하는 부분에 중단점을 넣고, `F5`를 눌러 디버깅을 진행합니다.
- `F11`을 눌러 한단계씩 진행하며 디버깅을 한다.
    ![Image](https://i.imgur.com/uANlCJ2.png)

#### 이 방법에서 주의할 점은 디버깅을 하기 전에 한번 Run Code를 해줘야하는 것과 디버깅 경로를 그때 그때 맞게 정해야 한다는 것입니다. 혹시 더 좋은 방법이 있으면 알려주세요.