# Yolo-mark로 Image에 bounding box 그리기 on Windows
- [Yolo_mark github](https://github.com/AlexeyAB/Yolo_mark) 페이지를 참고했습니다.
- OpenCV, VS 2017을 사용합니다.
  
### 빌드
- 먼저 OpenCV를 다운받습니다.
- [OpenCV Download 링크](https://opencv.org/releases.html)에서 들어가서 다운받습니다.
  - 저는 2.4.13.6 버전을 다운받았습니다.
- OpenCV를 설치한 경로는 환경변수에 아래와 같이 등록해줘야합니다.
![Image](https://i.imgur.com/8b2n8yy.png)

- 위 github에서 repository를 Downlaoad 받습니다.

- `yolo_mark.sln`을 실행합니다.

- 프로젝트 속성에서 아래를 수정합니다.
  
![Image](https://i.imgur.com/JMLaWX6.png)
- `opencv\build\include` 추가
  
![Image](https://i.imgur.com/PdKkz4J.png)
- 링커에 `opencv\build\x64\vc14\lib` 추가

- Debug -> Release 모드로 바꾼뒤 빌드를 합니다.

- `\x64\Release\yolo_mark.cmd`를 실행합니다.

- Box를 그릴 Image를 `\x64\Release\data\img` 폴더에 넣고, Own Dataset을 위해`\x64\Release\data\obj.names`를 수정해야합니다.