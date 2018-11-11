## Introduction to ML Strategy

### Why ML Strategy

- Collect more data
- Collect more diverse training set
- longer gradient descent
- Adam instead of gradient descent
- bigger, smaller network
- dropout
- L2 regularization
- change activation functions
- #hidden units

### Orthogonalization(직교화)

- Fit training set well on cost function
  - human-level performance에 준하게.
  - bigger network, 다른 최적화 알고리즘(Adam)
- Fit dev set
  - training set 에서는 잘 작동하지만 dev set에서는 잘 작동하지 않는다면 Regularization
  - bigger training set
- Fit test set
  - bigger dev set : dev set을 과하게 튜닝했을 확률이 크기 때문에 더 큰 dev set을 찾아야 한다.
- Performs well in real world
  - dev set, test set 분포가 잘 설정되어 있지 않거나 비용함수가 올바르게 계산되지 않는 경우.

## Setting up your goal

### Single number evaluation metric

![Image](https://i.imgur.com/0QCOy8U.png)

- precision: `a / (a + c)`
- recall: `a / (a + b)`
- accuracy: `(a + d) / (a + b + c + d)`
- 이 지표로 어떤 Classifier를 선택하느냐는 어렵다.
- F1 Score(Harmony Mean 이용)
  - `2 / (1/P + 1/R)`
- 어떤 알고리즘이 가장 좋은 성과를 내는지 지표를 낼때 평균을 이용한다.

### Satisficing and Optimizing metric

- running time 까지 고려하는 경우

`cost = accuracy - 0.5 * running time`

- maximize accuracy, running time은 100ms 이내.
- 즉 running time이 일정 수치 이하이면 신경쓰지 않고 가장 높은 Accuracy를 가지는 Classifier로 고르기.
- 이 때의 running time을 satisficing metric이라고 한다.

> Wakewords / Trigger words
> - Maximizing Accuracy : 정상적으로 작동하는 정확도를 높인다. 
> - Satisficing Metric: 잘못된 부름이 24시간 내에 1개 이하로 일어나게 한다.

### Train/dev/test distributuons

- development set(hold out cross-validation set)
- 무작위로 섞인 데이터를 dev set, test set 에 반영한다.
- 같은 분포도를 가져야 한다.

### Size of the dev and test sests

- 구시대엔 데이터가 100개 1,000개 10,000개 등과 같이 작았다.
- Train : Test = 70 :30
- Train : Dev : Test = 60 : 20 : 20
- 데이터의 양이 늘어남에 따라 1,000,000개 이상이 되면 98 : 1 : 1 의 비율로 충분하다.
- 1%도 10,000개의 데이터이기 때문에 dev와 test set으로는 충분한 양이다.

### When to change dev/test sets and metrics

#### 포르노 이미지와 일반 이미지를 구별하기 위한 방법


![Image](https://i.imgur.com/PYMD4fx.png)
- I 는 사실인 것의 개수를 센다.
- w값을 추가한다. 일반 이미지인 경우 1, 포르노 이미지인 경우 10을 부여해서 오류값이 올라가도록 한다.

![Image](https://i.imgur.com/ndiFpP2.png)
- 비용함수 수정.</br>
- metric + dev/test set에서 잘 동작하나 Application에서 잘 작동하지 않는다면 metric, dev/test set을 바꾸는 것을 고려해봐야 한다.

## Comparing to human-level performance

### Why human-level performance?
- 더 큰 모델이나 더 많은 데이터를 통해 알고리즘을 트레이닝 시키면서 성능이 이론적인 한계에 다가가지만 절대로 도달하지는 못한다.
- 이것을 Bayes Optimal Error라고 한다.
  - 최상의 오류.
- Perfect Error가 100%가 아닐 수 있다.
  - 손상된 오디오, noise가 심한 오디오, 흐릿한 이미지.
- 부족한 부분은 인간이 판단한 labeled data로 보충할 수 있다.

### Avoidable bias

#### bias 줄이기
- 더 큰 신경망을 Train
- 더 오랜 시간동안 Train

#### variance 줄이기
- regularization
- dev error를 training error와 비슷한 수준으로 만든다.
</br></br>
![Image](https://i.imgur.com/HZYMDoA.png)
- Computer vision에서 Bayes Error와 Human-level Error는 크게 떨어지지 않는다.
- Human-level error와 Training Error의 차이가 클 때 bias를 줄이는 기술이 가능하다.
- 차이가 작은 경우라면 편차를 줄이는 방법을 고려한다.
- Bayes Error와 Training Error의 차이를 Avoidable bias라고 부른다.
- Training Error와 Dev Error의 차이를 Variance라고 한다.

### Understnading human-level performance
![Image](https://i.imgur.com/4dfUKSd.png)
![Image](https://i.imgur.com/I73aLyf.png)
### Surpassing human-level performance

- Bayes Error로 잡은 게 Training Error 보다 크다면 인간의 직관적인 부분에 의존하기 어려워진다.
- Online Ad, Product Recommendations, Logistics(predicting transit time), Loan approvals 분야에선 인간보다 ML Algorithm이 더 뛰어나다.
  - Structed Data
  - 많은 양의 Data 
- 최근엔 음성 인식에도 Human-level을 뛰어 넘었다.
- Some image recognition, Medical 분야에도 

### Improving your model performance
![Image](https://i.imgur.com/L2bJvzw.png)
![Image](https://i.imgur.com/scXChid.png)