Ubuntu 18.04
Azure P100

```cmd
#nouveau 비활성화
sudo apt-get remove nvidia* && sudo apt autoremove
sudo apt-get install dkms build-essential linux-headers-generic



# /etc/modprobe.d/blacklist.conf 파일에서
sudo vi /etc/modprobe.d/blacklist.conf

# 맨밑에 추가.
blacklist nouveau
blacklist lbm-nouveau
options nouveau modeset=0
alias nouveau off
alias lbm-nouveau off

# 확인 및 재빌드
echo options nouveau modeset=0 | sudo tee -a /etc/modprobe.d/nouveau-kms.conf
sudo update-initramfs -u
sudo reboot
```
CUDA 10.0 다운로드 받는 링크 복사
![Image](https://i.imgur.com/MyDqe0r.png)
```cmd
# CUDA 10.0 다운
wget https://developer.nvidia.com/compute/cuda/10.0/Prod/local_installers/cuda_10.0.130_410.48_linux
# 이름 변경
mv cuda_10.0.130_410.48_linux cuda_10.0.130_410.48_linux.run
sudo sh *.run
```
# 설치 과정

# cudnn 설치
- https://developer.nvidia.com/rdp/cudnn-archive
  - 여기서 맞는 버전 다운로드 후 `scp 파일 계정@AzureIP`를 통해 전송한다.
```cmd
# 압축 해제
tar -zxvf cudnn*

# 파일을 CUDA에 복사
sudo cp -P cuda/lib64/libcudnn* /usr/local/cuda-10.0/lib64/
sudo cp  cuda/include/cudnn.h /usr/local/cuda-10.0/include/

# 이동시킨 파일 권한 부여
sudo chmod a+r /usr/local/cuda-10.0/include/cudnn.h /usr/local/cuda-10.0/lib64/libcudnn*

# libcupti 설치
sudo apt-get install libcupti-dev

# Path variable 설정
export PATH=/usr/local/cuda-10.0/bin${PATH:+:${PATH}}
export LD_LIBRARY_PATH=/usr/local/cuda-10.0/lib64\${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}
source ~/.bashrc

# 설치 확인
nvcc --version
```

# OpenCV 3.2.0 설치
```
sudo apt-get update
sudo apt-get upgrade

cd ~
git clone https://github.com/opencv/opencv.git
git clone https://github.com/opencv/opencv_contrib.git
cd opencv
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release \
-DCMAKE_INSTALL_PREFIX=/usr/local \
-DOPENCV_EXTRA_MODULES_PATH=~/opencv_contrib/modules \
-DPYTHON2_EXECUTABLE=/usr/bin/python2.7 \
-DPYTHON_INCLUDE_DIR=/usr/include/python2.7 \
-DPYTHON_INCLUDE_DIR2=/usr/include/x86_64-linux-gnu/python2.7 \
-DPYTHON2_NUMPY_INCLUDE_DIRS=/usr/lib/python2.7/dist-packages/numpy/core/include/ ..

make -j $(($(nproc) + 1))
sudo make install
sudo ldconfig



sudo add-apt-repository "deb http://security.ubuntu.com/ubuntu xenial-security main"
sudo apt update
sudo apt install libjasper1 libjasper-dev