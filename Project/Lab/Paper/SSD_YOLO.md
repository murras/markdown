# [이 페이지를 번역했습니다](https://medium.com/@jonathan_hui/what-do-we-learn-from-single-shot-object-detectors-ssd-yolo-fpn-focal-loss-3888677c5f4d)

## Single Shot Detectors
Faster R-CNN은 전용 Region Proposal 네트워크에 이어 Classifier가 있다.

Region-based Detector는 정확하지만 Cost가 있다.

Faster R-CNN은 PASCAL VOC 2007 테스트 세트를 7 FPS로 처리한다.

R-FCN과 같이 연구자들은 각 ROI의 작업량을 줄여 프로세스를 간소화하고 있다.

```py
feature_maps = process(image)
ROIs = region_proposal(feature_maps)
for ROI in ROIs
    patch = roi_align(feature_maps, ROI)
    results = detector2(patch)    
    # Reduce the amount of work here!
```

대안으로 우리는 별도의 Region Proposal 단계가 필요한가? Boundary boxes 및 Classes를 Feature Map에서 한번에 직접 추출할 수 있습니까?

```py
feature_maps = process(image)
results = detector3(feature_maps) 
# No more separate step for ROIs
```

슬라이딩 윈도우 감지기를 다시 살펴보겠습니다. 

Feature Map 위로 윈도우를 밀어 물체를 감지할 수 있다. 

서로 다른 개체 유형에 대해 서로 다른 윈도우 모양을 사용한다. 

이전 슬라이딩 윈도우의 치명적인 오점은 창을 최종 Boundary box로 사용한다는 것이다. 

그 부분에서 대부분의 물체를 cover하기 위해 너무 많은 모양이 필요하다. 

좀 더 효과적인 해결책은 윈도우를 초기 추측으로 정하는 것이다. 

그러면 현재 슬라이딩 윈도우로부터 class와 boundary box를 동시에 예측하는 탐지기를 갖는다.

![Image](https://i.imgur.com/okDPbco.png)
- 슬라이딩 윈도우에 상대적인 예측을 한다.

이 개념은 R-CNN의 anchor와 매우 유사하다.

단, Single Shot Detector는 Boundary box와 class를 동시에 예측한다.

간단히 요약해보자. 예를 들어 `8x8` Feature Map이 있으며 각 위치에서 K 예측을 한다. 즉 `8x8xK` 예측을 한다.

![Image](https://i.imgur.com/QXASIPJ.png)

각각의 위치마다 K개의 anchors(anchor: 고정된 초기의 추측 boundary box)가 있다. 우리는 anchors를 신중히 결정하고 모든 장소에 같은 anchor 모양들을 사용한다.

![Image](https://i.imgur.com/ebTnqcC.png)
- location마다 4개의 예측을 하기 위해 4개의 anchor를 사용한다.

여기에 각각 하나의 특정한 anchor와 관련된 4개의 예측(파란색)과 4개의 anchor(초록색)가 있다.

![Image](https://i.imgur.com/ipDmBai.png)
- anchor에 관련된 4개의 예측.

Faster R-CNN에서 우리는 5개의 매개변수를 예측하기 위해 하나의 Convolution filter를 사용한다.(anchor와 관련된 예측된 box에 대한 4개의 매개변수와 objectness confidence에 대한 1개의 매개변수)

따라서 `3x3xDx5` Conv fitler는 `8x8xD`에서 `8x8x5`까지 Feature map을 변환한다.

Single Shot Detector에서 Conv filter는 분류에 대한 C 클래스의 확률도 예측한다.(클래스당 1개)

따라서 Feature map을 `3x3xDx25` Conv filter를 적용하여 C=20일때 `8x8xD`에서 `8x8x25`으로 변환한다.

![Image](https://i.imgur.com/Ng3GtLt.png)
- 각 위치에서 k개의 예측에 각각 25개의 매개변수가 있다.

Single Shot Detector는 보통 실시간 처리 속도로 정확성을 교환한다.

또한 너무 가깝거나 너무 작은 물체를 감지하는데 문제가 있는 경향이 있다.

아래 그림의 경우 왼쪽 하단에 9개의 산타가 있지만 SSD는 5개만 감지합니다.

![Image](https://i.imgur.com/4AsLMb0.png)

## SSD
SSD는 VGG19 네트워크를 Feature 추출기로 사용하는 Single Shot Detector이다.(Faster R-CNN의 CNN과 동일)

그런 다음 나중에 사용자 정의 Conv Layer(청색)를 나중에 추가하고 Conv filter(녹색)을 사용하여 예측한다.

![Image](https://i.imgur.com/IrsakmW.png)
- 분류와 위치 모두에 대한 Single Shot 예측

그러나 Conv Layer는 공간 차원과 해상도를 줄인다.

따라서 위의 모델은 대형 객체만 탐지할 수 있다.

이를 해결하기 위해 우리는 Multiple Feature map에서 독립적인 개체 탐지를 한다.

![Image](https://i.imgur.com/P6Tobu2.png)
- 탐지를 위해 multi-scale Feature map을 사용한다.

다음은 Feature map의 크기를 보여주는 다이어그램이다.

![Image](https://i.imgur.com/XpespFi.png)

SSD는 개체를 감지하기 위해 Conv 네트워크에 이미 있는 레이어를 사용한다.

다이어그램을 scale에 가깝게 다시 그리면 공간 해상도가 크게 떨어졌고, 저해상도에서 감지하기에는 너무 어려운 작은 물체를 찾는 기회를 놓치고 있다는 것을 알아야 한다.

이런 문제가 있으면 입력 이미지의 해상도를 높여야 한다.

![Image](https://i.imgur.com/6N8uzU4.png)

## YOLO
YOLO는 DarkNet을 사용하여 Feature 감지를 수행한 다음 Conv Layer를 만든다.

![Image](https://i.imgur.com/YXiJLz6.png)

그러나 Multi-scale feature map을 사용하여 독립적으로 탐지하지는 않는다.

대신 부분적으로 평평하게 만들고(flatten) 다른 저해상도 map과 연결한다.

예를 들어 YOLO는 `28x28x512` Layer를 `14x14x2048`로 reshape한다.

그런 다음 `14x14x1024` Feature map과 연결된다.

그 후에 YOLO는 새로운 `14x14x3072` Layer에 Conv filter를 적용하여 예측한다.

YOLO(v2)는 첫번째 release의 경우 mAP를 63.4에서 78.6까지 구현을 향상시켜줬다.

YOLO9000은 9000개의 다른 범주의 개체를 탐지할 수 있다.

![Image](https://i.imgur.com/hXNzPJJ.png)

다음은 YOLO 논문에서 보고한 다양한 detector에 대한 mAP와 FPS 비교이다.

YOLOv2는 다른 입력 이미지 해상도를 가질 수 있다.

해상도가 낮은 입력 이미지는 더 높은 FPS를 갖지만 mAP는 더 낮다.

![Image](https://i.imgur.com/DKQU4Gv.png)

## YOLOv3

YOLOv3는 Feature 추출을 위해 더 복잡한 백본으로 변경된다.

Darknet-53은 주로 ResNet의 잔여 네트워크와 같이 건너뛰는 연결을 사용하는 `3x3` 및 `1x1` 필터로 구성된다.

Darknet-53은 ResNet-152보다 BFLOP(Billion Floating Point OPerations)이 적지만 2배 빠른 속도로 같은 분류 정확도를 갖는다.

![Image](https://i.imgur.com/tDnLLUp.png)

YOLOv3는 작은 피사체를 더 잘 감지하기 위해 Feature Pyramid를 추가했다.

서로 다른 감지기에 대한 정확도와 속도간의 tradeoff가 있다.

![Image](https://i.imgur.com/OzYCCZW.png)

## FPN(Feature Pyramid Networks)
특히 작은 Object에서 다른 scale일때 object를 탐지하는 것이 어렵다.

FPN은 정확성과 속도를 향상시키기 위해 피라미드 개념으로 설계된 Feature 추출기이다.

Faster R-CNN과 같은 감지기의 Feature 추출기를 대체하고 고품질 Feature map pyramid를 생성한다.

### Data Flow
![Image](https://i.imgur.com/q5Svkve.png)

FPN은 Bottom-up과 Top-down 경로로 구성된다. Bottom-up은 Feature 추출을 위한 일반적인 Conv Network이다. 올라갈수록 공간 해상도는 떨어진다. 더 높은 수준의 구조가 감지되면 각 계층의 semantic value가 증가한다.

![Image](https://i.imgur.com/YyNlG2m.png)

SSD는 여러 Feature map에서 탐지한다.

그러나 Object detection에 대해서는 bottom layers는 선택되지 않는다.

그것들은 해상도가 높지만 속도가 느려지기 때문에 의미적 가치가 높지 않다.

따라서 SSD는 상위 계층만 감지하기 때문에 작은 개체에 대해서는 성능이 훨씬 떨어진다.

![Image](https://i.imgur.com/SbgmEOb.png)

FPN은 Semantic rich layer로부터 더 높은 해상도를 생성하는 Top-down 방식을 제공한다.

![Image](https://i.imgur.com/HSPrSkt.png)

재구성된 레이어는 큰 의미가 있지만 Object의 위치는 모든 다운샘플링 및 업샘플링 후에 정확하지 않다.

재구성된 레이어와 해당 feature map 사이에 측면 연결을 추가하여 detector가 위치를 더 잘 예측할수 있게 도와준다.

![Image](https://i.imgur.com/hFl1ehM.png)

다음은 bottom-up 및 top-down 경로에 대한 세부 다이어그램이다. P2, P3, P4, P5는 물체 감지를 위한 feature map의 피라미드이다.

![Image](https://i.imgur.com/byRrtmr.png)

## FPN with RPN

FPN은 자체적으로 Object Detector가 아니다. 
