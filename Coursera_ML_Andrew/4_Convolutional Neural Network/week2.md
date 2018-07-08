## Case studies
### Why look at case studies?
다른 사람들의 코드를 보고 배우는 과정.
- Classic networks
    - LeNet-5
    - AlexNet
    - VGG
#### Resnet
152 Layer로 구성되어 있다.
#### Inception Neural Network

### Classic Networks

#### LeNet-5
![Image](https://i.imgur.com/L7TYoCS.png)
LeNet-5의 목표는 손으로 쓴 숫자를 인식하는 것이다. 따라서 Output이 0~10으로 나온다.</br>
Gray Scale의 이미지에 대해 학습되어서 32x32x1의 형태를 가진 Input이다.</br>
Layer를 거칠수록 높이와 폭이 줄어들고, 채널의 수는 늘어난다.</br>
60,000개 정도의 Parameter를 가진다.
> 당시에는 sigmoid와 tanh를 사용했고 비선형성을 가진 것을 사용하지 않았다(ReLu).
> - 또 필터가 Input에 해당하는 채널 이외에도 다른 채널도 봤다.
> - Section II와 III을 살펴보는데, II를 중점적으로 살펴보자.

#### AlexNet
![Image](https://i.imgur.com/cp9imgC.png)
- 논문을 보면 224x224x3으로 나와있지만 227x227x3으로 수정해야 한다.</br>
LeNet과 비슷하지만 규모가 훨씬 커졌다. 약 6천만개의 Parameter가 있다.</br>
논문이 쓰여질 때에 느린 GPU를 가지고 있었다. 그래서 레이어를 교차 분리시키고 두 개의 GPU를 통해 학습시켰다.</br>
Local Response Normalization이라는 레이어 세트가 추가됐다.
    - 특정 위치(높이, 너비)에서 모든 채널을 살펴본다.
    - 채널의 모든 숫자를 보고 그것들을 Normalization한다.
    - too high Activation을 가진 너무 많은 뉴런을 갖지 않게 하기 위함이다.
    - 큰 도움이 되지 않는다. 빨간 부분은 이해하는 것 중요하지 않다.

#### VGG - 16
![Image](https://i.imgur.com/5IRvDAc.png)
많은 parameter를 사용하지만 단순한 네트워크를 사용한다.</br>
CONV 과정에 stride 1, same padding, 3x3 filter를 사용한다.</br>
MAX-POOL 과정은 2x2 filter에 stride 2를 사용한다.</br>
신경망이 단순하지만 깊은 아키텍쳐를 가진다.</br>
가중치가 있는 Layer가 16개가 있다.</br>
1억3천8백만개의 parameter를 가진다.

### Residual Networks(ResNets)
깊은 신경망일수록 Vanishing Gradient / Exploding Gradient 문제가 나타난다.
![Image](https://i.imgur.com/K7N9Msl.png)
- main path와 short cut(skip connection).
![Image](https://i.imgur.com/DupthUm.png)
- Plain Network의 경우에는 신경망이 깊어질수록 이론적 수치와는 다르게 오류가 증가하는 반면 ResNet은 감소한다.
- Vanishing / Exploding Gradient 문제점을 처리하도록 도와준다.
- 신경망이 아주 깊어지면 효과가 크지 않다.

### Why ResNets Work
![Image](https://i.imgur.com/KrlTvVB.png)
- `z[l+2]`와 `a[l]`이 같은 차원을 가져야한다.
- 다른 차원을 가지면 w<sub>s</sub>a<sup>[l]</sup>을 더해준다.
![Image](https://i.imgur.com/qWLbjB4.png)

### Networks in Networks and 1x1 Convolutions
![Image](https://i.imgur.com/Kemv6n0.png)
![Image](https://i.imgur.com/IEHunUZ.png)
- 높이와 너비를 줄이기 위해선 pooling을 쓴다.
- 채널이 너무 커서 채널을 줄여야할때 1x1 filter, channel이 작은 conv 연산을 하면 줄일 수 있다.
- 네트워크에 비선형성을 추가할 수 있다.

### Inception Network Motivation
![Image](https://i.imgur.com/qitbP2K.png)
- padding은 same으로 여러 종류의 filter를 이용해서 나온 Output을 이어 붙인다.
- Pooling도 가능하다.
![Image](https://i.imgur.com/ehNs391.png)
- 1억2천만번의 계산이 필요하다.
![Image](https://i.imgur.com/wucoKVF.png)
- Input과 Output의 차수가 같지만, 계산횟수는 1/10로 줄어든다.
- bottleneck layer.

### Inception Network
![Image](https://i.imgur.com/45lys3J.png)
![Image](https://i.imgur.com/NMm92Xr.png)
- gooLeNet

## Practical advices for using ConvNets
### Using Open-Source Implementation
- github를 이용해 open source를 활용한다.

### Transfer Learning
다른 사람이 Training한 Network를 가져와서 나만의 Architecture로 바꾸면 더 빠르게 진행이 가능하다.</br>
![Image](https://i.imgur.com/bksbDlZ.png)
- 모든 Layer를 train시키지 않는다. 마지막 layer만 내가 하려는 작업에 맞게 수정한다.
- dataset의 크기가 클수록 여러개의 Layer를 학습시키는 것을 고려해본다.

### Data Augmentation
![Image](https://i.imgur.com/kyP2pIv.png)
![Image](https://i.imgur.com/5Aus451.png)
- Color Shifting
    - Principles Component Analysis(PCA) 알고리즘</br>
    AlexNet에 언급되어있다.</br>

 ![Image](https://i.imgur.com/Z1bEi0l.png)

 ### State of Computer Vision
 ![Image](https://i.imgur.com/JiJEBxr.png)
 - Object detection은 bounding box 처리를 해야해서 이미지 인식보다 훨씬 어렵다.
 - data가 부족할 때는 hand engineering.
 - Transfer Learning.</br>
![Image](https://i.imgur.com/vFM3HqH.png)
 Ensembling은 running time이 길어져 benchmark를 높이는데는 도움이 될 수 있어도 실제 서비스로는 활용하기 어렵다. 여러 네트워크가 동시에 이루어져야해서 메모리를 많이 먹는다.</br>
 Multi-crop at test time 방식은 Ensembling과 같이 실제로는 쓰이기 어렵다. 메모리를 적게 차지한다.
 
 ![Image](https://i.imgur.com/SooXk63.png)