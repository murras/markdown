## Detection algorithm

### Object Localization
![Image](https://i.imgur.com/9kldi3E.png)
- 이미지 분류와 더불어서 인식된 물체의 위치까지 박스 처리 해주는 것.
- 여러개의 물체가 있는 사진을 분류해야할 수도 있지만 일단은 한개의 물체만 있는 사진부터 다룬다.
![Image](https://i.imgur.com/aFShJop.png)
- bounding box를 parameterize한 b<sub>x</sub>, b<sub>y</sub>, b<sub>h</sub>, b<sub>w</sub>.
![Image](https://i.imgur.com/lTVPlkQ.png)
- p<sub>c</sub> : 객체가 있으면 1, background라면 0.
- 객체가 있으면 boungding box에 관한 4개의 parameter.
- 어떤 class가 있는지에 대한 정보 c.
- 객체가 하나만 잇다고 가정한 상태이다.
- Lost function에서 y는 8개의 값을 가지고 있다.
    - y<sub>1</sub>이 1인 경우(p<sub>c</sub>=1)의 식과 0인 경우(p<sub>c</sub>=0)인 경우의 식이 다르다.
- p<sub>c</sub>를 얼마나 잘 예측하는지가 가장 중요하다.

### Landmark Detection
![Image](https://i.imgur.com/9vJUiiP.png)
- 입력: 이미지
- 출력: 객체가 있는지?, 있다면 landmark의 좌표(64개), 129개의 출력이 있다.
- 얼굴 표정 인식, 사람의 포즈가 어떤 자세인지 인식.

### Object Detection
![Image](https://i.imgur.com/7ojU1lg.png)
- Sliding windows detection.
- 크기를 키워가며 box를 한칸씩 input으로 넣는다.
- 이미지를 잘라내어 하나씩 실행하는 과정은 계산 비용이 크다.
- stride가 작을수록 비용이 커지지만 정확도가 올라간다.

### Convolutional Implementation of Sliding Windows
![Image](https://i.imgur.com/SWGwyOJ.png)
![Image](https://i.imgur.com/HF1m22r.png)
- 마지막 2x2x4에서 파란부분은 기존 14x14의 결과이고, 나머지칸은 각각 우측 상단, 좌측 하단, 우측 하단의 결과이다.
- 독립적인 입력 이미지를 하나의 계산 형식으로 결합한다. 겹치는 부분의 계산을 공유한다.
![Image](https://i.imgur.com/beMz0Rs.png)
- 이 방법에는 바운딩 박스의 위치가 정확하지 않은 문제가 있다.

### Bounding box predictions
- 완전히 박스 안에 없을 수 있고, 사각형이라는 틀이 제한적이다.
#### YOLO(You Only Look Once) Algorithm
![Image](https://i.imgur.com/btAzVNn.png)
- 그리드를 나눠서 각각 학습한다.
- 객체의 중간점이 어느 그리드 셀에 있는지에 따라 p<sub>c</sub>값을 결정한다.
- 3x3의 그리드에 각각 8개의 출력값이 있다.</br>3x3x8의 Output.
- 신경망의 출력에 정확한 바운딩 박스가 나온다.
- 그리드 셀 내에 하나에 객체만 있으면 정상적으로 작동한다.
- 그리드 셀을 더 촘촘하게 하면 셀 내에 여러개 객체가 있을 확률이 줄어든다.

- 바운딩 박스에 관한 수치는 각각의 그리드 셀을 기준으로 한다.
- 중간점은 셀 내에 있어야하므로 x, y값은 0과 1 사이지만, 박스 자체는 셀을 넘어가는 범위일수도 있으므로 1보다 클수도 있다.

### Intersection over union
![Image](https://i.imgur.com/IhcPxQu.png)
- 빨간색 : 실측된 박스
- 보라색 : 알고리즘의 결과, Output
- 두 박스의 겹치는 부분과 합한 부분을 구해서 나눈다.

### Non-max Suppression
![Image](https://i.imgur.com/7yo5lic.png)
- 자동차 하나를 여러개의 셀이 탐지해서 여러개의 박스가 나타날 수가 있다.
#### Non-max suppression
![Image](https://i.imgur.com/RBBgzuD.png)
- 가장 높은 p<sub>c</sub>값을 갖고 있는 것을 고른다.
- 높은 IoU를 가진 다른 것들을 지워버린다.
![Image](https://i.imgur.com/Nny5GFm.png)
- Output되는 클래스당 1번씩 수행한다.

### Anchor Boxes
![Image](https://i.imgur.com/qExRDSi.png)
![Image](https://i.imgur.com/i88H2RZ.png)
- 두 객체가 동일한 그리드에 속하는 경우.
- Anchor Box를 이용한다.
- 객체의 모양과 가장 높은 IoU를 갖는 Anchor Box를 고른다.
![Image](https://i.imgur.com/Cfe2DO4.png)
- 하나의 셀 안에 세개의 객체가 있을때 문제가 생긴다.
- 셀 안에 두 객체가 같은 Anchor Box를 가지는 경우에도 문제가 생긴다.

### YOLO Algorithm
![Image](https://i.imgur.com/6XED3k7.png)
- Grid Size(3x3), #anchors(2), p+box+#class(1+4+3)
![Image](https://i.imgur.com/5xuv0LC.png)
![Image](https://i.imgur.com/z2Q2qCC.png)
- Non-max를 class별로(3번).