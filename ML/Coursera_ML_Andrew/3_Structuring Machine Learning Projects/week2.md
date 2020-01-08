## Error Analysis

### Carrying out error analysis

- 알고리즘이 Human-level 성능에 미치지 못하는 경우 수동으로 개선하는 방법에 대해 얘기한다.
#### 오류분석
> 고양이 분석기 90% Accuracy, 10% Error의 상태
- 강아지를 고양이로 인식하는 경우
    - 강아지에 대한 알고리즘을 강화하는 방법은 좋지 않을 수 있다.
    - 오류 분석의 방법
        - 100개의 mislabeled dev set 샘플을 가지고 와서 수동으로 검사한다.
        - 그 중 강아지 사진의 개수를 센다.
        - 5%가 강아지 이미지라고 가정한다면, 완벽히 수정하는 경우 10%의 Error가 9.5%로 줄어든다.
        - Ceiling on performance
        - 100개 중 50장이 강아지 이미지인 경우, 50%가 줄어든다. 10%의 Error가 5%까지 줄어들 수 있다.
        - 적은 노력으로 어느정도 까지 줄어들 수 있는지 판단할 수 있다.
</br></br>
- 스프레드 시트 형식으로 오류를 정리한다.
- 어떤 사항을 개선해야 오류 개선에 큰 효과를 보는지 판단할 수 있다.
- 적은 시간 투자로 우선순위를 정하는데 도움을 준다.
![Image](https://i.imgur.com/OMyrQV6.png)

### Cleaning up incorrectly labeled data

#### train set
- 데이터에 레이블 자체가 잘못 매칭된 경우(mislabeled example)
- 전체 Data set의 크기가 충분히 크고 실제 오류율이 너무 크지 않다면 오류를 수정하지 않아도 괜찮을 수 있다.
- 딥러닝 알고리즘이 random error에 강하지만 systemic error에는 덜 강하다.
- 흰색의 강아지를 계속해서 고양이로 레이블한 경우 문제가 된다.
</br>
#### dev / test set
![Image](https://i.imgur.com/7tswC26.png)
- 수정해야 할지 결정하기 위해서 세가지를 생각해야한다.
    - Overall dev set error (10%)
    - Errors due incorrect labels (6% * 10% = 0.6%)
    - Errors due to other causes (9.4%)
    - 어떤 것을 수정하는 것에 집중해야할지 판단할 수 있다.
![Image](https://i.imgur.com/aahDfVO.png)
### Build your first system quickly, then iterate
![Image](https://i.imgur.com/GG58BSy.png)

## Mismatched training and dev/test set

### Training and testing on different distrubutions
![Image](https://i.imgur.com/xFDm0Hc.png)
- distribution이 다른 경우의 문제.
- Option 1: 두 데이터를 합치고 섞은 후 train, dev, test
    - webpage data에 초점을 맞추는 것은 원하지 않은 것.
- Option 2: dev, test data를 모두 mobile app data를 쓴다.
</br></br>
![Image](https://i.imgur.com/lYkLHqP.png)

### Bias and Variance with mismatched data distributions

- 다른 분포로 이루어진 경우에는 dev 과정에서 train에서 보지 못한 데이터를 보고, 데이터의 분포도가 다르다.
- 해결하기 위해 Training-dev set이라는 새로운 개념을 정의한다.
- training set을 무작위로 섞은 후 일부를 train-dev set로 정한다.
- train / training-dev set은 dev / test set 처럼 동일한 분포를 가진다.
- train error 와 train-dev error의 차이가 크면 Variance 문제가 있음을 알 수 있다.
- 차이가 크지 않은 경우 data missmatch 문제이다.
- Avoidalbe bias, Variance, Data mismatch 구분하기.
![Image](https://i.imgur.com/mhCcS95.png)
- Overfit이 일어날 수 있기 때문에 Test set에서는 개발을 진행하지 않는 것이 좋다.
- 하지만 dev error와 test error의 차이가 크면 dev set을 overtune했다는 의미일 수 있다.
- 내려갈수록 숫자가 올라가야 한다.
![Image](https://i.imgur.com/pNrNJ6E.png)
![Image](https://i.imgur.com/xarHaeI.png)

### Addressing data mismatch
![Image](https://i.imgur.com/ZCYlg8G.png)
- 인공 데이터 합성도 효과가 있다.

## Learning from multiple tasks

### Transfer learning

#### pre-training과 fine-tuning

![Image](https://i.imgur.com/EzIqnZM.png)
- 이미지 인식 - 방사선 이미지 인식
- 다른 층의 값은 그대로 두고 마지막 층의 w[l], b[l]값만을 초기화시킨다.
- 방사선 데이터 셋의 양이 많지 않으면 마지막 층만 다시 train시킨다.
- 데이터가 충분하다면 모든 층을 train 시킨다.
- 이미지 인식에서 배우는 지식들이 옮겨지기 때문에 방사선 부문에서 많은 데이터가 없더라도 도움이 된다.
</br></br>
- 음성 인식 - Wakeword/Trigger Word
- 마지막 층을 없애고 새로운 여러개의층을 만들 수도 있다.
</br></br>
- Transfer learning을 쓰는 경우
    - A에서 B로 넘기려고 하는 경우 같은 입력값을 가질 때
    - B보다 A에 대한 데이터가 훨씬 많을 때
    - A의 low level 특징들이 B에 도움이 된다고 판단될 때

### Multi-task learning

![Image](https://i.imgur.com/nfEXbMC.png)

## End-to-end deep learning

### What is end-to-end deep learning?
![Image](https://i.imgur.com/ec0tpJp.png)
- 큰 규모의 Data set이 있는 경우 pipeline으로 train 된것보다 end-to-end가 더 잘 작동을 하는 경우가 생긴다.
- 하위 작업에 대한 데이터가 더 많다.
- 얼굴 위치를 찾는 작업, 같은 사람인지 확인하는 작업 두개로 쪼개는 게 데이터가 더 많다.

### Whether to use end-to-end deep learning

![Image](https://i.imgur.com/6SxVTpn.png)