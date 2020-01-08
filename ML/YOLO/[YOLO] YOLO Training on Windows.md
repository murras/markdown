# YOLO Training on Windows.
## 명령어 사용법
- `-ext_output` : output coordinate of objects
- `-save_labels < data/test.txt` : test.txt에 적힌 경로의 이미지에 label 적힌 txt 저장.(Marking 좌표 저장)
    - ex) `darknet.exe detector test .data .cfg .weights -dont_show -ext_output -save_labels < data/train.txt`
  
- 이미지 예시
    - `darknet.exe detector test datafile.data cfgfile.cfg weightsfile.weights -i 0`(`-thresh 0.25`) (`output.jpg -ext_output`)

- 동영상 예시
    - `darknet.exe detector demo datafile.data cfgfile.cfg  weightsfile.weights test.mp4 -i 0`
(`-out_filename output.avi`)

- net-videocam 
    - `darknet.exe detector demo datafile.data cfgfile.cfg  weightsfile.weights http://192.168.0.80:8080/video?dummy=param.mjpg -i 0`
- WebCamera 
    - `darknet.exe detector demo datafile.data cfgfile.cfg weightsfile.weights  -c 0`

- `darknet.exe detector demo datafile.data cfgfile.cfg weightsfile.weights -dont_show -ext_output < data/train.txt > result.txt`

- webcam에 관한 내용
1. Download for Android phone mjpeg-stream soft: IP Webcam / Smart WebCam

    * Smart WebCam - preferably: https://play.google.com/store/apps/details?id=com.acontech.android.SmartWebCam2
    * IP Webcam: https://play.google.com/store/apps/details?id=com.pas.webcam

2. Connect your Android phone to computer by WiFi (through a WiFi-router) or USB
3. Start Smart WebCam on your phone
4. Replace the address below, on shown in the phone application (Smart WebCam) and launch:


* 194 MB COCO-model: `darknet.exe detector demo data/coco.data yolo.cfg yolo.weights http://192.168.0.80:8080/video?dummy=param.mjpg -i 0`
* 194 MB VOC-model: `darknet.exe detector demo data/voc.data yolo-voc.cfg yolo-voc.weights http://192.168.0.80:8080/video?dummy=param.mjpg -i 0`

## 학습하는 법
1. `yolov3.cfg`를 복사해서 `yolo-obj.cfg` 이름으로 바꾼 뒤 다음 내용으로 수정한다.
    - `batch=64`
    - `subdivision=8`
    - Line 610, 696, 783에서 `class=N`(N은 내 클래스 수)
    - Line 603, 689, 776에서 `filters=(N+5)x3`
2. `obj.names` 파일을 만든 후 `build\darkent\x64\data\`에 저장한다.
    - 내용은 내 클래스 이름들을 각 줄에 적는다.
3. `obj.data` 파일을 `build\darknet\x64\data\`에 다음과 같은 내용을 입력후 저장한다.
    ```
    classes = 1
    train = data/train.txt
    valid = data/test.txt
    names = data/obj.names
    backup = backup/
    ```
4. 학습시킬 이미지 파일들을 `build\darknet\x64\data\obj\`에 저장한다.

5. 이미지 파일들은 [Yolo_mark](https://github.com/AlexeyAB/Yolo_mark)를 통해 bounding box marking을 해줘야한다.

6. `train.txt` 파일을 `build\darknet\x64\data\`에 넣는다. 내용은 이미지 파일의 상대경로를 적어주어야한다.
    ```c
    data/obj/img1.jpg
    data/obj/img2.jpg
    data/obj/img3.jpg
    ...
    ```

7. [미리 학습된 weights](https://pjreddie.com/media/files/darknet53.conv.74)를 다운로드 받는다.

8. 학습을 시작한다.

    `darknet.exe detector train mydata.data mycfg.cfg darknet53.conv.74`

9. 학습이 끝나면 `build\darknet\x64\backup\`에서 `yolo-obj_final.weights`를 얻을 수 있다. 또 `backup\`에 100번째 반복마다 저장이 된다.

10. 주의사항
    - cfg 파일에 width와 height는 32로 나누어 떨어지는 수가 들어가야 한다.
    - 학습 후 사용 방법 `darknet.exe detector test data/obj.data yolo-obj.cfg yolo-obj_8000.weights`
    - `Out of memory` 오류가 발생할 경우 cfg 파일에서 `subdivision`을 `16`, `32`나 `64`로 고친다.

## 학습을 멈추는 시점
보통 class 마다 2000번의 반복정도가 적당하다. 구체적인 학습 중단 시점은 아래와 같다.
1. 학습 도중, 0.XXXXXXX avg가 감소하지 않는다면 중단해야한다.

    여러번을 반복해도 avg loss가 감소하지 않으면 중단해야한다.

2. 학습을 중단시키고, `darknet\build\darknet\x64\backup` 폴더에서 `.weights` 파일을 얻을 수 있는데, 그 중 가장 좋은 것을 골라야한다.

    예를 들어 9000번의 반복을 했을때, 가장 좋은 것(Overfitting이 덜한 것)은 7000, 8000번째에 있을 수 있다. (Early Stopping Point로부터 얻어낸다.)

![Image](https://i.imgur.com/TF0x4Cg.png)

2.1. Early Stopping Point로부터 weights를 얻어내려면 `obj.data`에서 validation dataset을 명시해줘야한다. `valid` 경로를 지정해준다. validation 이미지가 따로 없다면, train과 같은 파일을 사용한다.

2.2 아래 명령어로 어떤 weights가 더 좋은 성능을 보이는지 알 수 있다.

```c
darknet.exe detector map data/obj.data yolo-obj.cfg backup\yolo-obj_7000.weights
darknet.exe detector map data/obj.data yolo-obj.cfg backup\yolo-obj_8000.weights
darknet.exe detector map data/obj.data yolo-obj.cfg backup\yolo-obj_9000.weights
```

- `-map` flag를 통해 train 시킬수도 있다.

`darknet.exe detector train data/obj.data yolo-obj.cfg darknet53.conv.74 -map`


## 학습 효과 올리기
- 학습 전
    - cfg 파일 맨 아래 `random=1`로 수정.
    (다른 해상도에 대해 정확도를 높여준다.)
    - 작은 객체 탐지를 위해서 cfg 파일 Line 717 `stride=4`, Line 720 `layers=-1,11`로 수정.
    - 좌우 구별 감지를 원하면 Line 17에서 `flip=0` 입력.
    - 빠른 학습을 위해서 Line 548 `stopbackward=1` 입력.
    - anchors 크기 재계산해서 더 정확하게 계산하기 : `darknet.exe detector calc_anchors data/obj.data -num_of_clusters 9 -width 416 -height 416`
- 학습 후
    - cfg 파일에서 `height`와 `width`를 `608` 혹은 `832`로 수정.
    - `Out of Memory` 오류가 생기면 `subdivision`을 `16`, `32`, `64`로 수정.