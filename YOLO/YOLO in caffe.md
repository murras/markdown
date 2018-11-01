## Windows 환경에서 Caffe 설치

- *Visual Studio, Python, CUDA, cuDNN, git bash setting은 이미 끝났다는 가정하에서 진행합니다.*
- 관련 링크
    - [CUDA](https://developer.nvidia.com/cuda-downloads)
    - [cuDNN](https://developer.nvidia.com/cudnn)
    - [git](https://git-scm.com/downloads)
  

### Caffe 소스코드 다운로드

- git bash를 원하는 디렉토리에서 실행하고 아래 명령을 입력한다.
- `git clone https://github.com/Microsoft/caffe`
  
    ![Image](https://i.imgur.com/Tovu6nr.png)

- 다운로드된 `caffe` 내에서 아래 작업을 한다.
    - `windows` 폴더 내의 `CommonSettings.props.example`을 `CommonSettings.props` 이름을 갖게 복사한다.
    - 복사된 `CommonSettings.props`을 에디터로 실행한다.
    ![Image](https://i.imgur.com/v5BNOex.png)

    - 다음을 수정한다.
        - `<CudaVersion>본인의 CUDA version</CudaVersion>`
        - `<CudaArchitecture>compute_52,sm_52</CudaArchitecture>`

- `caffe\windows` 폴더 내에 `Caffe.sln`을 실행한다.
  
    ![Image](https://i.imgur.com/QVmsk0T.png)
    - C/C++ - 일반 - 경고를 오류로 처리를 아니오로 바꾼다.
  
    ![Image](https://i.imgur.com/Y6Z7cEG.png)

- `libcaffe`를 빌드한다.