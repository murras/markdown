# 정확한 개체 탐지 및 Semantic segmentation을 위한 Rich feature 계층 구조

---
Canonical PASCAL VOC 데이터셋에서 측정한 바와 같이 Object Detection 성능이 지난 몇년동안 정체기에 있다. 가장 좋은 방법은 일반적으로 여러개의 low-level 이미지 feature와 high-level context를 결합하는 복잡한 emsemble 시스템이다. 이 논문에서는 평균 정확도(mAP)를 30% 이상 향상시켜 53.3% mAP를 달성하는 간단하고 확장 가능한 detection 알고리즘을 제안한다. 우리의 접근 방식은 두가지 key insight를 결합한다. 하나는 물체를 localize하고 분할하기 위해 bottom-up region proposal을 high-capacity CNN에 적용할 수 있는 것이고, 다른 하나는 label 되어있는 training data가 부족할때, 보조 작업을 위해 pre-training된 모델을 해당 도메인에 맞게 fine-tuning을 적용하는 것은 상당한 성능 향상을 가져온다는 것이다. Region proposal을 CNN과 합치기 때문에 우리는 이 방법을 R-CNN(Region-CNN)이라고 부른다. 우리는 R-CNN을 CNN 아키텍쳐를 기반으로 최근에 제안된 sliding-window detector인 OverFeat과 비교한다. 우리는 R-CNN이 OverFeat보다 200-class ILSVRC2013 detection 데이터셋에서 큰 차이를 보이는 성능을 가짐을 발견했다. 소스 코드는 http://www.cs.berkeley.edu/˜rbg/rcnn 에 있다.
---

## 목차

## [1. Introduction](#목차)
Feature는 중요하다. 다양한 시각적 인식 작업에 대한 지난 10년간의 연구는 SIFT[29]와 HOG[7]의 사용에 상당히 의존했다. 그러나 canonical 시각 인식 작업인 PASCAL VOC object detection[15]에서 성능을 살펴보면, 일반적으로 ensemble 시스템을 구축하고 성공적인 방법으로 얻은 작은 variant들을 사용함으로써 얻어지는 작은 이득은 2010-2012년 동안 진행 속도가 느린 것으로 알려져있다.

SIFT와 HOG는 블록 단위 방향 히스토그램으로, 영장류 시각 경로의 첫번째 피질 영역인 V1에서 복잡한 세포와 대략적으로 연관시킬 수 있는 표현이다. 그러나 우리는 인식이 여러 단계의 downstream에서 발생한다는 것을 알고 있다. 시각적 인식을 위해 더 유익한 기능을 계산하기 위한 다단계 프로세스가 계층적으로 있다는 것을 의미한다.

생물학적으로 영감을 받은 패턴 인식을 위한 계층적이고 shift-invariant 모델인 후쿠시마의 "neocognitron"[19]은 그러한 과정을 위한 초기 시도였다. 그러나 neocognitron에는 supervised training 알고리즘이 없었다. Rumelhart[33], LeCun[26]을 바탕으로 역전파(back propagation)를 활용한 확률적인 Gradient descent는 neocognitrond을 확장하는 모델인 CNN을 훈련하는데 효과적이었음을 보여줬다. CNN은 1990년대에 과도하게 사용되었다(e.g.[27]). 하지만 support vector machine의 등장으로 유행에서 벗어났다. 2012년에 Krizhevsky[25]는 ImageNet Large Scale Visual Recognition Challenge(ILSVRC)[9, 10]에 비해 훨씬 더 높은 이미지 classification 정확도를 가짐으로써 다시 CNN에 관심을 가졌다. 그들의 성공은 대형 CNN을 120만개의 label된 이미지와 함께 LeCun의 CNN(e.g.max(x, 0) 정류 비선형성 및 dropout 정규화)와 함께 몇가지 twists와 함께 교육한 결과이다.

![Image](https://i.imgur.com/1u81P49.png)
- Figure 1. Object detion system overview
    - (1) input image.
    - (2) bottom-up region proposal 2000건 추출.
    - (3) 대형 CNN을 사용하여 각각의 proposal에 대한 feature 계산.
    - (4) class-specific 선형 SVM을 사용하여 각 region을 분류한다.

R-CNN은 PASCAL VOC 2010에서 53.7%의 mAP를 가진다. 비교를 위해 [39]는 동일한 region proposal을 사용하면서 35.1% mAP를 갖지만, 공간 피라미드와 시각적 단어 접근법을 사용한다. 인기 있는 변형 가능한 부품 모델은 33.4%로 수행한다. 200-클래스 ILSVRC2013 detection 데이터셋에서 R-CNN의 mAP는 31.4%로 OverFeat[34]보다 큰 개선이며 이전의 best는 24.3%이다.


ImageNet 결과의 중요성은 ILSVRC 2012 워크샵에서 활발하게 논의됐다. 중심 이슈는 다음과 같다. ImageNet에서의 CNN 분류 결과는 Pascal VOC Challenge에서 object detection 결과에 대해어느정도까지 일반화되는가? 우리는 이미지 분류와 물체 감지 사이의 간격을 메워 이 질문에 답한다. 이 논문은 CNN이 단순한 HOG와 유사한 특징을 기반으로 하는 시스템에 비해 Pascal VOC에서 훨씬 더 높은 Object detection 성능을 이끌 수 있다는 것을 보여주는 첫번째 논문이다. 이 결과를 달성하기 위해 우리는 두가지 문제에 초점을 맞춘다. 깊은 네트워크를 개체로 localizing하고 소량의 주석처리된 탐지 데이터로 대용량 모델을 교육한다. 이미지 분류와 달리, 이미지 내에서(많은 경우) 객체의 위치를 파악해야한다. 하나의 접근법은 Regression 문제로 localization frame을 씌우는 것이다. 그러나 Szegedy[38]의 연구 결과는 이 전략이 실제로 실행되지 않을수도 있음을 나타낸다. VOC 2007의 경우 우리의 방법은 58.5%를 가지지만 그것은 30.5%의 mAP를 가진다. 또 다른 방법은 sliding window detector를 만드는 것이다. CNN은 적어도 20년동안 얼굴과 보행자와 같이 제한된 개체 카테고리에서 일반적으로 사용됐다. 높은 공간 해상도를 유지하기 위해, 이 CNN들은 전형적으로 단지 2개의 Conv 및 Pooling 계층만을 갖는다. 우리는 sliding window 방식을 채택하는 것도 고려했다. 그러나 우리의 네트워크에서 5개의 Conv를 가지는 high unit은 입력 이미지에서 매우 많은 receptive field(195x195 픽셀)와 stride(32x32 픽셀)을 가지고 있다. 이것은 sliding window 패러다임 내에서 정확한 위치파악을 기술적인 도전이 된다. 

대신 우리는 CNN 지역화 문제를 객체 인식과 의미론적 세분화에 성공적이었던 "인식을 사용하는 영역" 패러다임[21] 안에서 작동시킴으로써 해결한다. 테스트 시간에 우리의 방법은 입력 이미지에 대해 약 2000개의 카테고리 독립적인 region proposal을 생성하고 CNN을 사용하여 각 제안에서 고정 길이의 특징 벡터를 추출한 다음 각 영역을 카테고리별 선형 SVM으로 분류한다. 지역의 모양에 관계 없이 각 지역 제안에서 고정된 크기의 CNN 입력을 계산하는 간단한 기술을 사용한다. 그림 1은 우리의 방법에 대한 개요를 제시하고 일부 결과를 강조 표시한다. Google 시스템은 Region Proposal을 CNN과 결합하므로 R-CNN 이라는 제목을 붙였다.

OverFeat은 탐지를 위해 Sliding WindowCNN을 사용하며 지그까지 ILSVRC2013 탐지에서 가장 좋은 수행방법이었다. 우리는 R-CNN이 OverFeat을 능가하는 것으로 나타났으며 mAP는 31.4%였다. OverFeat은 24.3%이다.

Detection에 있어 두번째 과제는 labeled 데이터가부족하고 현재 사용가능한 양이 CNN을 교육하기에는 충분하지 않다는 것이다.
이 문제에 대한 해결책은 unsupervised pre-training을 사용하고 supervised fine-tuning을 사용하는 것이다[35]. 이 논문의 두번째 원칙은 데이터가 부족할 때 대규모 보조 데이터 세트(ILSVRC)에 대한 supervised pre-training과 작은 데이터 세트(Pascal)에 대해 도메인 특유의 미세 조정은 대용량 CNN을 학습하는 효과적인 패러다임을 보여준다. 우리의 실험에서 탐지를 위한 미세 조정은 mAP 성능을 8% 햐상시킨다. 미세 조정 후, 우리 시스템은 고도로 조율된 HOG 기반 변형 가능 부품 모델의 경우 33%와 비교하여 54%의 mAP를 달성한다(VOC 2010)[17,20]. 우리는 또한 Krizhevsky의 CNN이 블랙박스 feature 추출기로 사용될 수 있음을 보여주는 Donahue[12]의 동시 작업을 독자들에게 알려줌으로써 장면 분류, 세분화된 하위 카테고리화 및 도메인 적응을 포함한 여러 인식 작업에서 탁월한 성능을 제공한다. 

우리 시스템은 또한 매우 효율적이다. Class별 계산은 합리적으로 작은 행렬-벡터 곱과 greedy non-maximum suppression이다. 이 계산 특성은 모든 범주에서 공유되고 이전에 사용된 영역 features보다 2차원 크기가 더 작은 피쳐에서 따른다([39]).

우리의 접근 방식의 실패 모드를 이해하는 것은 그것을 개선하는데 중요하다. 그래서 Hoiem[23]의 탐지 분석 도구의 결과를 쓴다. 이 분석의 즉각적인 결과로 간단한 경계 상자  회귀 방법이 우세한 오류 모드인 mis-localization을 상당히 감소시키는 것으로 나타났다.

기술적 세부사항을 개발하기 전에 R-CNN이 지역에서 운영되기 때문에 의미론적 세분화 작업으로 확장하는 것이 당연하다. 사소한 수정을 통해 VOC 2011 테스트 세트에서 평균 세분화 정확도가 47.9%인 파스칼 VOC 세분화 작업에 대한 경쟁력 있는 결과도 얻는다.


## [5. Semantic segmentation](#목차)
지역 분류는 Semantic segmentation을 위한 표준 기법으로 Pascal VOC segmentation challenge에 R-CNN을 손쉽게 적용할 수 있다. 현재의 Semantic segmentation 시스템(O<sub>2</sub>P: second-order pooling이라고 불린다)[4]과 직접적인 비교를 돕기 위해 우리는 오픈 소스 framework 내에서 작업한다. O<sub>2</sub>P는 CPMC(Constrained Parametric Min-cuts)를 사용하여 이미지당 150개의 Region proposal을 생성한 다음 Support Vector Regression을 사용하여 각 클래스에 대해 각 지역의 품질을 예측한다. 그들의 접근 방식의 높은  성능은 CPMC 영역의 품질과 여러 feature 유형(SIFT와 LBP의 풍부한 변종)의 강력한 2차 순서 풀링으로 인한 것이다. 또한 Farabet[16]은 CNN을 다중 픽셀 단위의 분류 기준으로 사용하여 여러 조밀한 장면 labeling dataset(PASCAL을 포함하지 않은)에서 조은 결과를 나타냈다.


- Figure 1의 (1)에서 region proposal 2000개를 만든다. 
- region proposal의 사이즈가 랜덤해서, 입력 이미지의 크기가 고정되어있는 CNN에 쓰려면 transformation 해줘야한다.
- 이 논문에서는 tightest square with context, warp 방법
- 2000개 region proposal 각각에 대해 CNN feature vector 추출(N images * 2000)한다.
1. CNN을 통한 feature vector 추출
2. SVM Classfier를 통한 Image Classification
3. Bounding Box Regression

### Summarize
1. 이미지 분류 작업에 대한 CNN 네트워크 Pre-training: 예를 들어 ImageNet Dataset에서 교육된 VGG또는 ResNet, Classification task엔 N개의 Class가 포함된다.

    참고: Caffe Model Zoo에서 pre-trained AlexNet을 찾을 수 있다. Tensorflow에서 찾을수 없지만 Tensorflow-slim model library는 pre-trained RestNet, VGG 등을 제공한다.
    
2. 
##