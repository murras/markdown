# 계획(로드맵)

Traffic Light(hereinafter referred to as TL)의 종류가 엄청 다양하기 때문에, Bus-only TL을 Detection을 하는데는 한 단계 기술을 거치는 것으로는 충분하지 않다. TL을 검출해내고, Traffic Sign의 글자도 인식해야 한다.

1.  TL Detection
    
    -   class 0 : General TL
        -   2단계로 넘어간다.
    -   class 1 : Bus-shaped TL
        -   Detection 끝.
    -   Real-time processing에 적합한 YOLO를 사용할 것으로 예상된다.
2.  Traffic Sign Detection
    
    -   신호등과 가까운 표지판을 찾아내야한다. 대개 해당 신호등의 위쪽에 있다.
    -   그 표지판에 적힌 글자에 `버스 전용`, `중앙 차선`이 포함되어 있는지 확인해내야한다.
    -   저해상도 이미지의 깨진 글자를 인식해낼수 있어야 한다.
    -   깨진 글자를 해결할 수 있는 기술이 필요하다
        - up-scaling
    -   Tesseract OCR, SVM
    -   [참고 링크](https://www.design-reuse.com/articles/41154/traffic-sign-recognition-tsr-system.html)

예상되는 한계점 : Real-Time Image Processing이기 때문에 Input Image의 화질이 좋지 않다.  
horizontal TL에 대해서만 고려하고, 검출하는 모델을 만들었기 때문에 vertical TL에 대한 성능은 확신할 수 없다.