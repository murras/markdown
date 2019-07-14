- [Abstract](#Abstract)
- [Introduction](#Introduction)
- [Related work](#Related-work)
- [Method](#Method)
- [Result](#Result)
- [Conclusion](#Conclusion)
- [References](#References)

# Abstract

# Introduction

   
최근 자율 주행에 관한 연구가 활발히 일어나고 있다. 신호등 탐지 및 인식 기술은 자율 주행에 있어서 핵심 기술 중 하나이다. 신호등 탐지 및 인식 기술은 신호등의 신호를 인식하고 해당 차량의 주행 가능 여부를 판단하는 기술이다. 차량에 부착된 카메라를 통해 얻어낸 영상에서 신호등을 탐지하고 인식한다. 

기존의 신호등 인식에 관련해서 신호등의 종류와 관계 없이 신호등 인식 혹은 신호등의 색상을 통해 어떤 신호인지 인식하는 연구들만이 있었다. 한국에는 중앙버스전용차로가 있어 기존 차량들과의 신호 혼동을 줄이기 위해 일반적인 신호등이 아닌 버스모양 신호등이 있다. 기존의 연구들을 통해 신호등을 인식한다면 일반 차량이 버스 모양 신호등을 인식하고 주행하는 경우 혹은 중앙버스전용차로를 이용하는 버스의 경우에는 일반 신호등을 인식하고 주행하는 경우가 발생한다.

본 논문은 상위와 같은 문제를 해결하기 위해 딥 러닝 기술 적용하여 일반 신호등과 버스 모양 신호등을 구별하여 인식하는 모델을 제안한다. 

신호등 탐지 및 인식에는 이미지 처리에 쓰이는 
실시간으로 검출할 수 있을 정도로 빠르고 정확한 모델인 YOLO(You Only Look Once) 프레임워크를 기반으로 만들어진 모델들을 적용하여 성능을 비교 분석한다.

YOLO는 객체 인식 과정에서 입력 이미지를 그리드로 나누어서 Bounding Box의 좌표와 어떤 Class가 어느 정도의 Confidence를 가지는지 한번에 확률적으로 추정하는 Regression 문제로 단순화시켜 수행 속도를 크게 높인 기술이다.
// YOLO 에 관한 설명 추가
// 각 모델별 간단한 설명 추가
YOLOv3 
// 성능표 추가

(하드웨어 사양)

# Related work
Object Dection에 관한 연구들 나열
AlexNet GoogLeNet VGGNet R-CNN Fast R-CNN Faster R-CNN SSD YOLO
객체 인식 분야에서 CNN(Convolutional Neural Network)을 기반으로 하는 인공신경망 네트워크 모델들이 발전되어 왔다. AlexNet 

# Method
실험 방법 및 결과

YOLOv3-spp.cfg : 3 different max pool to the same image by using [route]. 그 이후에 "fixed-length representation"이라고 불리는 feature map을 모은다.

yolov3-tiny에서는 Max-Pooling layer(stride = 2)를 통해 downsampling을 하고 yolov3는 Convolution layer를 통해 downsampling을 한다. yolov3-spp 모델은 Convolution layer와 Max-Polling layer를 통해 best feature를 얻어내 downsampling을 한다.

실험 환경
실험 방법

성공한 사례

# Result

# Conclusion

# References
[1] Joseph Redmon, Santosh Divvala, Ross Girshick, Ali Farhadi. You Only Look Once: Unified, Real-Time Object Detection. Jun 2015.
[2] Joseph Redmon and Ali Farhadi. YOLO9000: Better, Faster, Stronger. Dec 2016.
[3] Zhanchao Huang and Jianlin Wang. DC-SPP-YOLO: Dense Connection and Spatial Pyramid Pooling Based YOLO for Object Detection. Mar 2019.
https://arxiv.org/abs/1903.08589
[3] 
https://arxiv.org/abs/1612.08242 yolo9000
[4] https://arxiv.org/abs/1506.02640 yolo