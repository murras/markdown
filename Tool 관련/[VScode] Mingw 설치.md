# MinGW로 gcc, g++ 이용하기 on Windows

- 관련 포스팅
> - [Visual Studio Code에서 터미널을 git bash로 사용하기 on Windows](http://murra.tistory.com/36)
> - [Visual Studio Code에서 CodeRunner와 MinGW를 이용해서 C,C++ 컴파일, 디버깅하기 on Windows](http://murra.tistory.com/28)

## MinGW 설치하기

- [MinGW 다운로드 링크](https://sourceforge.net/projects/mingw/)를 눌러 MinGW를 다운받는다.

- 다운받은 파일을 실행해서 설치를 진행한다. 경로는 그대로 하는 것이 좋은 것 같은데 원하면 바꿔도 된다. 이 글에서는 그대로 하는 것으로 진행한다.

    ![Image](https://i.imgur.com/nUIjOc6.png)

    ![Image](https://i.imgur.com/wzBWelc.png)

    ![Image](https://i.imgur.com/JSxZvXf.png)

    - 위와 같이 체크하고 좌측위 탭에서 Installation - Apply Change를 누른다.

    ![Image](https://i.imgur.com/1piq4QF.png)

- 설치를 진행하는 동안 환경 변수를 설정해야 한다.
    - 시작 버튼을 누르고 `환경 변수`나 `sysdm.cpl`을 검색한다.
     
    ![Image](https://i.imgur.com/Bf1E18u.png)
    
    - 고급 탭의 환경 변수에 들어가서 사용자 변수 - Path 경로에 추가하기 위해 더블 클릭 혹은 편집을 누른다.

    ![Image](https://i.imgur.com/g0lDllA.png)

    - 아래와 같이 새로 만들기를 눌러서 아까 설치했던 MinGW의 bin 디렉토리 경로를 입력한다.

    ![Image](https://i.imgur.com/XL8T4Jn.png)

- cmd 창에서 `gcc -v`나 `g++ -v`를 입력해서 제대로 설치되었는지 확인한다. 만약 제대로 따라 했는데도 없는 명령이라고 나온다면 재부팅을 한번 해준다.(환경 변수 적용)
  
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
