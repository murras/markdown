# YOLO Build on Windows
- CUDA, cuDNN, OpenCV, VS 2017을 사용합니다.
- [AlexyAB의 darknet](https://github.com/AlexeyAB/darknet)을 이용했습니다.

### 빌드하기 전 준비사항
- VS 2017은 설치되어있다는 가정하에 진행하겠습니다.
- 위 github에서 repository를 Downlaoad 받습니다. 이 경로를 `darknet`이라고 부르겠습니다.
- CUDA와 cuDNN을 설치하셔야 하는데, 버전을 기억해두셔야 합니다.
    - CUDA : https://developer.nvidia.com/cuda-downloads
      - Visual Studio Integration 체크 해서 설치해야합니다.
![Image](https://i.imgur.com/eQ4hez1.png)
      - 자신의 CUDA 버전에 맞는 cuDNN을 다운받고, 환경변수 등록까지 마쳐야합니다.

- 다음으로 OpenCV를 다운받습니다.
  - [OpenCV Download 링크](https://opencv.org/releases.html)에서 들어가서 다운받습니다.
  - 저는 2.4.13.6 버전을 다운받았습니다.
- OpenCV를 설치한 경로는 환경변수에 아래와 같이 등록해줘야합니다.
  - 제 opencv 경로는 `C:\opencv\opencv2.4.13.6\`으로 시작합니다.
![Image](https://i.imgur.com/8b2n8yy.png)

![Image](https://i.imgur.com/P1bwWJK.png)


### 빌드
- `darknet\build\darknet\darknet.sln`을 실행한다.
- 상단의 메뉴에서 `Release`, `x64`로 바꾼다.
![Image](https://i.imgur.com/1CLCjKl.png)
- 프로젝트 속성 - C/C++ - 일반 - 추가 포함 디렉터리에서 opencv 경로를 자신의 경로에 맞게 수정한다.

![Image](https://i.imgur.com/m2v1w7I.png)
- 프로젝트 속성 - 링커 - 일반 - 추가 라이브러리 디렉터리에서 opencv 경로를 수정한다.

![Image](https://i.imgur.com/8WhB9qZ.png)

- 빌드 종속성을 자신의 CUDA 버전에 맞게 수정한다.

![Image](https://i.imgur.com/e0oeWW2.png)

![Image](https://i.imgur.com/DIYl6Jg.png)

- 빌드(F7)를 누르면 성공합니다.