# YOLO v3 PyTorch 구현

- Windows, git bash 환경에서 진행합니다.
- Pytorch 설치법 참고
> - [PyTorch 설치 및 Jupyter 등록](http://murra.tistory.com/55)


- [pytorch-yolo-v3](https://github.com/ayooshkathuria/pytorch-yolo-v3)를 참고해서 작성했습니다.
- 환경
    - Python 3.5
        - `pip install matplotlib`
        - `pip install pandas`
    - OpenCV
        - `conda install -c menpo opencv`
    - PyTorch 0.4
        - pytorch 버전 확인
        ```py
        import torch
        print(torch.__version__)
        ```

- Image Detector
    - weights 파일을 [다운로드](https://pjreddie.com/media/files/yolov3.weights) 받는다.(COCO에 대한 dataset weights 파일이다.)
    - weights 파일을 다운받은 github repository로 옮긴다.
    - `python detect.py --images imgs --det det`
    - `--images` 다음 인자값은 image 파일들의 경로 / 혹은 single image일 경우 파일의 이름이다.
    - `--det` 저장할 이미지들이다.