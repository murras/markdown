## Convonlutional Neural Network

### Computer Vision

- Image Classification
    - Cat or not
- Object detection
    - 물체 발견 뿐 아니라 주변에 Box를 그려야한다.
    - 한장의 사진 안에 여러개의 물체가 있다.
- Neural Style Transfer
</br></br>
large image를 입력할때 너무 큰 parameter가 생성된다.

### Edge Detection Example

Convolution Operation 중 Edge Detection에 관한 예제
#### Edge Detection
![Image](https://i.imgur.com/mHNBufc.png)
- 이미지 안의 모서리를 감지하는 방법.
- 첫번째로 하는 것은 이미지 안의 수직, 수평 테두리를 탐지하는 것.
- Vertical edge detection
    - `*` 기호는 곱셈이 아닌 convolution의 의미.</br>
    > ![Image](https://i.imgur.com/Pmen3y5.png)
    - tensorflow에서는 `tf.nn.conv2d`를 사용해서 구한다.
![Image](https://i.imgur.com/qLdOdSa.png)

### More Edge Detection
filter에서 1이 밝은쪽, -1이 어두운쪽 영역이 된다.
![Image](https://i.imgur.com/uotfIcK.png)
![Image](https://i.imgur.com/wOEY87s.png)
- 필터의 종류
    - Sobel filter : 중간값에 가중치를 좀 더 둔다.
    - Scharr filter
> ![Image](https://i.imgur.com/KXxubfw.png)
> 수평, 수직 filter 뿐 아니라 다양한 각도의 filter를 적용한다.
> 신경망을 통해 데이터로부터 parameter 값을 학습시킬 수 있다.

### Padding
n x n의 이미지에 f x f의 필터를 합성시키면 output은 (n-f+1) x (n-f+1)의 차원을 가진다.
- shrink ouput : 이미지가 작아지기 때문에 연산의 수가 제한된다.
- throw away informatin from edge : 이미지의 테두리 부분은 연산에서 가운데 있는 부분보다 적게 사용된다. 이미지의 가장자리 정보를 일부 버리는 문제가 생긴다.
![Image](https://i.imgur.com/AN415kg.png)
#### padding으로 해결할 수 있다.
6 x 6의 이미지를 8 x 8의 이미지로 padding하여 사용하면 이미지 축소를 줄일 수 있다.
</br></br>
- Valid Convolution : padding이 없는 것
- Same Convolution : padding을 통해 input과 output의 크기를 같게 하는 방식.
    - padding size를 p라고 한다.
    - n x n = (n+2p-f+1) x (n+2p-f+1)
    >![Image](https://i.imgur.com/ewM4OzM.png)
    - padding의 크기와 중앙의 pixel이 명확해져서 filter의 크기를 주로 홀수로 사용한다.

### Strided Convolutions

(n x n)*(f x f)에서 padding size: p, stride: s</br>
<img src="https://latex.codecogs.com/png.latex?\dpi{120}&space;\bg_white&space;\fn_phv&space;\large&space;\left&space;\lfloor&space;\frac{n-2p-f}{s}&plus;1&space;\right&space;\rfloor&space;x&space;\left&space;\lfloor&space;\frac{n-2p-f}{s}&plus;1&space;\right&space;\rfloor" title="\large \left \lfloor \frac{n-2p-f}{s}+1 \right \rfloor x \left \lfloor \frac{n-2p-f}{s}+1 \right \rfloor" />
- stride로 인해 filter가 완전히 이미지 속에 들어가지 않고 걸친다면 계산하지 않는다.
</br>
![Image](https://i.imgur.com/YNOhCCt.png)

### Convolutions Over Volume
![Image](https://i.imgur.com/wQj2a6u.png)
RGB Image는 `n` x `n` x `3`과 같이 3가지 색의 이미지이다(height width #channel). 필터 역시 `f`x`f`x`3`이 되어야 한다. 이미지의 채널 수와 필터의 채널 수는 같다.</br>
![Image](https://i.imgur.com/CdR7k4t.png)
output은 `n-f+1` x `n-f+1` x `1`이 된다.
- Channel Red에서만 수직을 감지하는 필터.
- 모든 채널에서 수직을 감지하는 필터.</br>
![Image](https://i.imgur.com/2pQFZRp.png)
- 수직, 수평을 감지하는 필터를 각각 적용해서 output을 convolution한다. 그러면 output이 4x4x2가 된다.

### One Layer of a Convolutional Network

![Image](https://i.imgur.com/DM9bmR7.png)
- 3x3x3의 필터가 10개 있는 경우, parameter의 개수는 bias까지 고려한다면 `(27+1)*10=280`개이다.
- 이미지의 크기에 관계 없이 항상 280개로 유지할 수 있다.
![Image](https://i.imgur.com/WzRQbGl.png)
- m x n<sub>h</sub><sup>[l]</sup> x n<sub>w</sub><sup>[l]</sup> x n<sub>c</sub><sup>[l]</sup>의 형태로 표현한다.

### Simple Convolutional Network Example
![Image](https://i.imgur.com/sy1r5KP.png)
- 마지막 층에서 펼친 후 벡터로 전개한후 logistic / softmax.

### Polling Layers
![Image](https://i.imgur.com/fHi7QK8.png)
높이와 너비를 줄이는 효과를 가진다. 

채널의수는 유지된다.

보통의 경우에는 padding을 사용하지 않는다.

주의점은 배울 파라미터가 없다.
- Max pooling</br>
![Image](https://i.imgur.com/cEKWEK8.png)
구역을 나눈뒤 구역의 최댓값을 가지는 output.
![Image](https://i.imgur.com/kZv0JiY.png)
- Average pooling</br>
잘 사용되지 않지만 최댓값이 아닌 구역의 평균값을 output으로 가진다. 

### CNN Examples
![Image](https://i.imgur.com/MFIY93q.png)
- conv1, pool1을 거친 것을 Layer1이라고 정한다.
- layer를 거칠수록 n<sub>h</sub>와 n<sub>w</sub>는 줄어들지만 n<sub>c</sub>는 증가한다.</br>
![Image](https://i.imgur.com/LzpuTfz.png)
- Activation Size가 점점 줄어드는게 맞지만, 너무 급격히 줄어들면 성능이 좋지 않다.

### Why Convolutions?
![Image](https://i.imgur.com/DcCBs1t.png)
- 작은 이미지임에도 불구하고 14M개의 Parameter를 요구한다.
- CNN의 경우 필요한 Parameter의 개수가 크게 줄어든다.
![Image](https://i.imgur.com/RDbARy7.png)
![Image](https://i.imgur.com/iFtSBvW.png)