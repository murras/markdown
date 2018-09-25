### Bounding box prediction

YOLO9000에 이어 우리 시스템은 anchor box를 dimension cluster를 anchor box로 사용하여 bounding box를 예측한다.

네트워크는 각 경계 상자의 4개의 좌표를 예측한다.(x,y,w,h)

셀이 상단 왼쪽 (cx,cy)에 위치하고 앞에 있는 BBox에 너비와 높이가 pw, ph라면 다음과 일치한다.

![uploading...](http://i.imgur.com/uploading.png)

![Image](https://i.imgur.com/3UwwCb2.png)