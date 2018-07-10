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
<a href="https://www.codecogs.com/eqnedit.php?latex=\bg_white&space;L(A,P,N)&space;=&space;max(\left&space;\|&space;f(A)-f(P)&space;\right&space;\|^2-\left&space;\|&space;f(A)-f(N)&space;\right&space;\|^2&plus;\alpha,\&space;0)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\bg_white&space;L(A,P,N)&space;=&space;max(\left&space;\|&space;f(A)-f(P)&space;\right&space;\|^2-\left&space;\|&space;f(A)-f(N)&space;\right&space;\|^2&plus;\alpha,\&space;0)" title="L(A,P,N) = max(\left \| f(A)-f(P) \right \|^2-\left \| f(A)-f(N) \right \|^2+\alpha,\ 0)" /></a>
- 0보다 작으면 `L=0` 이다.</br>
<a href="https://www.codecogs.com/eqnedit.php?latex=\bg_white&space;J&space;=&space;\sum_{i}^{m}L(A^{(i)},P^{(i)},N^{(i)})" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\bg_white&space;J&space;=&space;\sum_{i}^{m}L(A^{(i)},P^{(i)},N^{(i)})" title="J = \sum_{i}^{m}L(A^{(i)},P^{(i)},N^{(i)})" /></a>