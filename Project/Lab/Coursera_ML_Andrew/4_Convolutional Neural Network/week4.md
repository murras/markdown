## Face Recognition

### What is face recognition?
#### Verification
#### Recognition
- 99%의 정확도를 가져도 100명을 인식할때 한명이 빗나가면 비교적 정확한 수치가 아니다.

#### One Shot Learning
- 학습 자료 한 개로 정확하게 예측해야한다.
![Image](https://i.imgur.com/4VJ5r61.png)
- 사람이 늘어나면 다시 class의 개수를 늘려야 한다.
- 좋지 못한 방법이다.
![Image](https://i.imgur.com/RIECwkQ.png)
- similarity function
    - d를 같은 사람일 경우 작은 값을, 다른 사람일 경우 큰 값이 되게 한다.
    - 임계치(타우)보다 낮으면 같은 사람, 그렇지 않으면 다른 사람이라고 예측한다.
- DB에 있는 사람일 경우와 없는 사람일 경우.
- 새로운 사람을 추가할 때는 사진을 DB에 추가한다.

### Siamese network
- 위의 d를 구하기 위해 Siamese network를 이용한다.
![Image](https://i.imgur.com/haKhixx.png)
- softmax 사용하지 않는다.
- 비교하고자 하는 두개의 이미지를 같은 NN에서 읽힌다.
- 출력으로 나온 벡터(128개)를 비교하는 개념을 Siamese Network라고 한다.
![Image](https://i.imgur.com/UqMZ1Nl.png)

### Triplet Loss

- 같은 사람일 경우 Anchor와 Positive, 다른 사람일 경우 Negative.
- Anchor, Positive, Negative 세가지 이미지를 보기 때문에 Triplet.
![Image](https://i.imgur.com/6WqFPe9.png)


<a href="https://www.codecogs.com/eqnedit.php?latex=\bg_white&space;d(A,P)\leq&space;d(A,N)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\bg_white&space;d(A,P)\leq&space;d(A,N)" title="d(A,P)\leq d(A,N)" /></a></br>
<a href="https://www.codecogs.com/eqnedit.php?latex=\bg_white&space;\left&space;\|&space;f(A)-f(P)&space;\right&space;\|^{2}&space;&plus;\alpha&space;\leq&space;\left&space;\|&space;f(A)-f(N)&space;\right&space;\|^{2}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\bg_white&space;\left&space;\|&space;f(A)-f(P)&space;\right&space;\|^{2}&space;&plus;\alpha&space;\leq&space;\left&space;\|&space;f(A)-f(N)&space;\right&space;\|^{2}" title="\left \| f(A)-f(P) \right \|^{2} +\alpha \leq \left \| f(A)-f(N) \right \|^{2}" /></a>
- f가 항상 0을 출력한다면 만족시켜서 문제가 생긴다.
- d(A,P)=0.5, d(A,N)=0.51 일때 더 큰 차이를 원한다. hyperparameter인 α를 추가한다.

#### Loss function
![Image](https://i.imgur.com/FhYWQuB.png)</br>
<a href="https://www.codecogs.com/eqnedit.php?latex=\bg_white&space;L(A,P,N)&space;=&space;max(\left&space;\|&space;f(A)-f(P)&space;\right&space;\|^2-\left&space;\|&space;f(A)-f(N)&space;\right&space;\|^2&plus;\alpha,\&space;0)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\bg_white&space;L(A,P,N)&space;=&space;max(\left&space;\|&space;f(A)-f(P)&space;\right&space;\|^2-\left&space;\|&space;f(A)-f(N)&space;\right&space;\|^2&plus;\alpha,\&space;0)" title="L(A,P,N) = max(\left \| f(A)-f(P) \right \|^2-\left \| f(A)-f(N) \right \|^2+\alpha,\ 0)" /></a>
- 0보다 작으면 `L=0` 이다.</br>

<a href="https://www.codecogs.com/eqnedit.php?latex=\bg_white&space;J&space;=&space;\sum_{i}^{m}L(A^{(i)},P^{(i)},N^{(i)})" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\bg_white&space;J&space;=&space;\sum_{i}^{m}L(A^{(i)},P^{(i)},N^{(i)})" title="J = \sum_{i}^{m}L(A^{(i)},P^{(i)},N^{(i)})" /></a></br>
- 1000명의 사람을 찍어서 10000장의 Training set을 가지고 있다면 위의 식을 통해 기울기 강하로 학습시킨다.
- 같은 사람의 사진을 여러개 가지고 있어야 한다.
![uploading...](http://i.imgur.com/uploading.png)
![Image](https://i.imgur.com/khTvF6o.png)

### Face verification and binary classification
![Image](https://i.imgur.com/UW2FzUa.png)
- Triplet Loss 이외의 다른 방법.
- 같은 사람이라면 1, 다른 사람이면 0을 출력.
- 절댓값 말고 다른 계산 방법도 있다. chi square similarity라고 한다.
- 새로운 사람이 늘어나면(class) siamese network을 통해 학습 시키고, 결과를 미리 계산해놓는다.

---
## Neural Style Transfer
### What is neural style transfer?
![Image](https://i.imgur.com/1EIFwkv.png)

### What are deep ConvNets learning?
![Image](https://i.imgur.com/KhRvM8m.png)
- 어떤 이미지가 각각의 레이어에서 Activation을 최대로 활성화 하는지 살펴보자.

![Image](https://i.imgur.com/PZ0tssL.png)</br>
![Image](https://i.imgur.com/Viyc1AV.png)</br>
![Image](https://i.imgur.com/sVFaxHu.png)</br>
![Image](https://i.imgur.com/WRObqQv.png)</br>
![Image](https://i.imgur.com/HMxNQ2V.png)

### Cost Function
![Image](https://i.imgur.com/9v8mAGA.png)
- 어렵지 않은 논문이다.
- 초기 G는 무작위로 생성된 이미지.
- 기울기 강하를 통해 천천히 바뀌어간다.
![Image](https://i.imgur.com/78nfagO.png)

### Content Cost Fucntion
![Image](https://i.imgur.com/YhrNMm3.png)
- l의 깊이는 얕지도 깊지도 않은 곳을 골라야한다.
- l 상태에서 activation 값이 C와 G가 비슷하면 비슷한 내용을 갖고 있음을 의미한다.

### Style Cost Function
![Image](https://i.imgur.com/Kb9OEzK.png)
- 채널간 어떤 상관관계를 가지는지 알 수 있다. 
![Image](https://i.imgur.com/VzpY5P4.png)
- 수직 텍스쳐가 있는 채널과 주황빛을 띄는 채널의 상관 관계가 크다면 수직 텍스쳐를 가지면 주황빛을 띈다는 것이고 관계가 없다면 수직 텍스쳐를 가지더라도 주황빛이 아닐 수 있다는 것이다.
- 얼마나 자주 같이 발생하는지 측정하는 것.
![Image](https://i.imgur.com/PqDh9Hh.png)
- G<sub>kk\`</sub> : k와 k`이 얼마나 큰 상관 관계를 갖는지를 의미.
- 이미지 S에 대한 스타일 이미지를 표시하기 위해 윗첨자 (S)를 썼다.
- 만들어진 이미지는 윗첨자 (G)로 표현했다.
![Image](https://i.imgur.com/kNsGm4N.png)
- F:Frobenius, 정규화상수는 중요치 않다.

### 1D and 3D Generalizations
![Image](https://i.imgur.com/tu6hLLk.png)
</br>
![Image](https://i.imgur.com/bOKDAb9.png)