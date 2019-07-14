# Object recognition을 위한 선택적 검색
 
### Summarize

- Segmentation과 Exhaustive Search 방법을 조합하여 Selective Search를 수행한다. 

Segmentation은 이미지의 구조적인 특징(색상, 무늬, 크기, 모양)을 사용하여 후보 영역을 추출하는 것을 말하며, Exhaustive Search는 모든 가능한 후보 영역을 검색하는 것이다.

![Image](https://i.imgur.com/Rw71AeS.png)
1. Efficient Graph-Based Image Segmentation(Felzenszwalb)을 사용하여 초기 후보 영역을 다양한 크기와 비율로 생성한다.
2. 그리디 알고리즘을 통해 비슷한 영역을 반복적으로 통합한다.
    - 처음에 모든 영역에 대해 유사도를 계산하여 similarity set S를 생성한다.
    - S에서 가장 큰 유사도 값을 가진 r<sub>i</sub>, r<sub>j</sub>에 대해 통합한다.
    - ri, rj의 유사도 값은 S로부터 제거한다.
    - 통합된 새로운 영역(r<sub>t</sub>)과 인접한 영역들에 대해 유사도(S<sub>t</sub>)를 계산한다.
    - S와 R에 유사도(S<sub>t</sub>)와 통합된 새로운 영역(r<sub>t</sub>)을 추가한다.
3. 최종적으로 하나의 영역이 만들어질 때까지 2번을 반복한다.

Selective Search는 후보 영역 추출 과정에서 CNN과 별도로 동작해서 bottleneck 현상이 발생한다. 이것은 실시간 처리에 어려움을 갖는다. 

Exhaustive search는 후보가 될만한 모든 영역을 샅샅이 조사하는 것이다. 후보가 될만한 대상의 크기가 일정하지도 않고, 가로 세로 비율도 일정하지 않은 상황에서 모두 찾는 것은 사실상 불가능하다.

Segmentation 방법은 Exhaustive search와 같이 영상의 특성을 고려하지 않고 찾는것이 아니라 영상 데이터의 특성에 기반하는 방식이다. 색상, 모양, 무늬 등 다양한 기준에 따라 segmentation이 가능하지만, 모든 경우에 동일하게 적용할 수 있는 segmentation 방식을 찾는 것은 불가능하다.

data-driven Selective Search: segmentation에 가능한 방법을 활용하여 seed를 설정하고, 그 seed에 대해 exhaustive한 방식으로 찾는것을 목표로 한다.


---

## Abstract

이 논문은 물체 인식에 사용할 수 있는 물체 위치를 생성하는 문제를 다룬다. 철저한 검색과 세분화의 장점을 결합한 Selective Search를 소개한다. 세분화와 마찬가지로, 샘플 프로세스를 guide하기 위해 이미지 구조를 사용한다. 철저한 검색과 마찬가지로 모든 가능한 객체 위치를 캡처하는 것을 목표로 한다. 가능한 객체 위치를 생성하는 단일 기술 대신, 우리는 검색을 다양화하고 가능한 많은 이미지 조건을 처리하기 위해 다양한 상호보완적인 이미지 파티셔닝을 사용한다. 우리의 Selective Search는 10,097개의 위치에서 99%의 Recall과 Mean Average Best Overlap 0.879의 성과를 내는 데이터 기반, 클래스 독립적, 고품질 위치의 작은 셋을 생성한다. 철저한 검색에 비해 위치 수가 줄어들어 대상 인식에 보다 강한 외형 모델을 사용할 수 있다. 이 논문에서는 Selective Search를 통해 강력한 Bag of Word 모델을 인식에 사용할 수 있음을 보여준다. Selective Search Software는 공개적으로 사용할 수 있다. (ttp://disi.unitn.it/~uijlings/MyHomepage/index.php)


---

## [2. Related Work](#목차)

우리는 관련 작업을 물체 인식 영역으로 한정하고 이를 세가지 범주로 나눈다. Exhaustive search, segmentation, 두가지 범주에 속하지 않는 다른 샘플링 전략이다.

### 2.1 Exhaustive Search

물체는 이미지에서 어떤 위치에도 존재할 수 있고, 크기도 다양하다. 그렇기 때문에 모든 곳을 검색하는 것이 당연하다.[8, 16, 36] 그러나 시각적인 검색 공간은 엄청나므로 ESearch 계산 비용이 크다. 이것은 위치당 평가비용 and/or 고려되는 위치의 수에 제약을 만든다. 따라서 이런 슬라이딩 윈도우 기술의 대부분은 weak 분류기와 HOG와 같은 경제적인 이미지 feature를 사용하여 coarse search grid와 고정된 종횡비를 사용한다[8, 16, 36]. 이 방법은 종종 분류기의 cascade에서 사전 선택 단계로 사용된다.

슬라이딩 윈도우 기술과 관련하여 Felzenszwalb의 매우 성공적인 부분 기반 객체 위치 파악 방법이 있다.[12] 또한 이 방법은 선형 SVM 및 HOG 기능을 사용하여 ESearch를 수행한다. 그러나 객체와 객체의 부분을 검색하며 그 조합은 인상적인 객체 탐지 성능을 제공한다.

Lampert[17]는 검색을 guide 하기 위해 appearance model 사용을 제안했다. 이는 regular grid, 고정된 비율, 고정된 종횡비를 사용하는 제약을 완화하는 동시에 방문한 위치의 수를 줄인다. 이는 branch 및 bound 기술을 사용하여 이미지 내에서 최적의 윈도우를 직접 검색하여 수행한다. 선형 분류기에 대한 인상적인 결과를 얻는 동안 비선형 분류기의 경우 실제로 이 방법은 이미지당 100,000개의 창을 방문하는 것으로 나타났다.

blind Exhaustive S 또는 branch와 bound 검색 대신 Selective S를 제안한다. 객체 위치를 생성하기 위해 기본 이미지 구조를 사용한다. 논의된 방법과 달리, 이것은 완전히 클래스 독립적인 위치 집합을 산출한다. 게다가 우리는 고정된 종횡비를 사용하지 않기 때문에 우리의 방법은 물체에만 국한되지 않고 잔디와 모래같은 것을 찾을 수 있어야한다([17]에서도 마찬가지이다). 마지막으로 샘플의 가변성이 낮아짐에 따라 문제를 더 쉽게 만들어야하는 위치를 더 적게 생성하기를 바란다. 더 중요한 것은 강력한 머신 러닝 기술과 강력한 appearance model에 사용할 수 있는 계산 능력을 확보할 수 있다는 것이다.

### 2.2 Segmentation

