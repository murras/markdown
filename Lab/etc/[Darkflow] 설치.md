# Darkflow 설치 및 사용법 on Windows

- [이 github 페이지](https://github.com/thtrieu/darkflow/)를 참조했습니다.
- *Anaconda, tensorflow, opencv3, numpy가 설치되어 있는 환경에서 진행했습니다.*

- Python 3.5가 권장된다고 합니다. 저는 3.6.5에서 진행했습니다.
- 선택사항으로 가상 환경(virtualenv, conda, pipenv)에서 진행해도 된다고 하는데, 저는 아직 가상 환경에 대한 체감이 없어서 그냥 base env에서 진행했습니다.

#### 사전 준비
- `pip3 install --upgrade tensorflow`
- `pip3 install cython`
- `pip3 install opencv-python`

#### repo Download
- [Darkflow github Page](https://github.com/thtrieu/darkflow/)에서 repo를 다운로드 받고 그 디렉토리에서 다음을 실행합니다.
    - `python setup.py build_ext --inplace`
    - `python flow --h`
    - Microsoft Visual C++ 14.0 is required error가 생기는 경우 [이 곳](https://github.com/thtrieu/darkflow/issues/849)을 참조해서 해보세요. 저는 해당되지 않아서 자세히는 잘 모르겠습니다.

#### 시작 방법
- 3가지 방법이 있다.
    - `python setup.py build_ext --inplace`
        -  이 방법을 쓰면 `./flow`로 명령을 실행해야한다고 한다.
    - `pip install -e .`
    - `pip install .`
- 나는 세번째가 제일 짧아서 세번째걸로 했다. 별 문제 없이 됐다.

#### 학습 방법(Training on your own dataset)
- cfg 디렉토리에서 cfg 파일을 복사해서 원하는 대로 이름을 변경한다.(Original cfg를 건드리지 않는것이 좋다.)
- 복사한 cfg 파일의 [region] 부분 밑에 class 수를 원하는대로 변경한다. 나는 일단 신호등 하나만 할거라서 1로 했다.
```c
[region]
anchors =  0.57273, 0.677385, 1.87446, 2.06253, 3.33843, 5.47434, 7.88282, 3.52778, 9.77052, 9.16828
bias_match=1
classes=1
coords=4
num=5
softmax=1
jitter=.3
rescore=1
```
- 바로 위의 [convolutional] 부분을 수정해야한다. filters 값을 num * (class + 5)로 한다. 나는 num이 5고 class는 1이어서 5 * (1 + 5) = 30으로 바꿨다.
```c
[convolutional]
size=1
stride=1
pad=1
filters=30
activation=linear
```
- `labels.txt`에 class명을 적는다.
```
traffic light
```

- annotation 경로와 dataset 경로를 적어주고 아래 형식으로 입력한다.
    - bash
        - `python flow --model cfg/my.cfg --train --load yolo.weights --dataset data/train_traffic_light --annotation data/annotations --gpu 1.0`
    - cmd
        - `python flow --model cfg\my.cfg --train --load yolo.weights --dataset data\train_traffic_light --annotation data\annotations --gpu 1.0`
