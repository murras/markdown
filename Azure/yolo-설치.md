- 기본 설치  
   - `sudo apt update`
   - `sudo apt upgrade`
   - `sudo apt install build-essential`
   - `sudo apt install unzip`

- CMake 설치
```sh
wget https://github.com/Kitware/CMake/releases/download/v3.14.5/cmake-3.14.5.tar.gz
tar -xvzf cmake-3.14.5.tar.gz
cd cmake-3.14.5
./bootstrap
make
sudo make install
```

- OpenCV
```sh
sudo apt-get update
sudo apt-get upgrade
sudo apt-get install build-essential cmake unzip pkg-config
sudo apt-get install libxvidcore-dev libx264-dev
sudo apt-get install libgtk-3-dev
sudo apt-get install libatlas-base-dev gfortran
sudo apt-get install python3-dev
cd ~
wget -O opencv.zip https://github.com/opencv/opencv/archive/3.3.0.zip
wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/3.3.0.zip
unzip opencv.zip
unzip opencv_contrib.zip
mv opencv-3.3.0 opencv
mv opencv_contrib-3.3.0/ opencv_contrib
wget https://bootstrap.pypa.io/get-pip.py
sudo python3 get-pip.py
sudo pip install virtualenv virtualenvwrapper
sudo rm -rf ~/get-pip.py ~/.cache/pip

echo -e "\n# virtualenv and virtualenvwrapper" >> ~/.bashrc
echo "export WORKON_HOME=$HOME/.virtualenvs" >> ~/.bashrc
echo "export VIRTUALENVWRAPPER_PYTHON=/usr/bin/python3" >> ~/.bashrc
echo "source /usr/local/bin/virtualenvwrapper.sh" >> ~/.bashrc

source ~/.bashrc

mkvirtualenv cv -p python3

workon cv
pip install numpy

cd ~/opencv
mkdir build
cd build
cmake -D CMAKE_BUILD_TYPE=RELEASE \
	-D CMAKE_INSTALL_PREFIX=/usr/local \
	-D INSTALL_PYTHON_EXAMPLES=ON \
	-D INSTALL_C_EXAMPLES=OFF \
	-D OPENCV_ENABLE_NONFREE=ON \
	-D OPENCV_EXTRA_MODULES_PATH=~/opencv_contrib/modules \
	-D PYTHON_EXECUTABLE=~/.virtualenvs/cv/bin/python \
	-D BUILD_EXAMPLES=ON ..
# 나중에 추가    -DBUILD_opencv_xfeatures2d=OFF
make -j4
```
- 오류 나는 파일에 들어가서 아래를 추가해준다.
![Image](https://i.imgur.com/WbrudQI.png)

![Image](https://i.imgur.com/wDWccZu.png)

![Image](https://i.imgur.com/5rBJtzX.png)
```sh
sudo make install
sudo ldconfig

pkg-config --modversion opencv
```

- Cuda 10.0
  - [링크](https://developer.nvidia.com/cuda-10.0-download-archive?target_os=Linux&target_arch=x86_64&target_distro=Ubuntu&target_version=1804&target_type=runfilelocal)를 들어가서 다운을 받는다.
  - Cuda 10.0 - Linux - x86_64 - Ubuntu - 18.04 - runfile(local)
  - `wget https://developer.nvidia.com/compute/cuda/10.0/Prod/local_installers/cuda_10.0.130_410.48_linux`

```sh
sudo sh cuda_~linux.run
# 설치 과정 입력
accept
no
yes
[Enter] : default
yes
no
```

```
echo "export PATH=/usr/local/cuda-9.0/bin${PATH:+:${PATH}} " >> ~/.bashrc
echo "export LD_LIBRARY_PATH=/usr/local/cuda-9.0/lib64${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}" >> ~/.bashrc

source ~/.bashrc


export PATH=/usr/local/cuda-9.0/bin${PATH:+:${PATH}} 
export LD_LIBRARY_PATH=/usr/local/cuda-9.0/lib64${LD_LIBRARY_PATH:+:${LD_LIBRARY_PATH}}


sudo apt-get install nvidia-cuda-toolkit

nvcc -V
```

- cudnn
```sh
sudo cp cuda/include/cudnn.h /usr/local/cuda/include/
sudo cp cuda/lib64/libcudnn* /usr/local/cuda/lib64/
sudo chmod a+r /usr/local/cuda/include/cudnn.h /usr/local/cuda/lib64/libcudnn*
sudo cp cuda/lib64/libcudnn* /usr/lib/x86_64-linux-gnu
```

sudo apt-get install mesa-utils libgl1-mesa-dri libqt4-opengl-dev 

OpenCV 최적화를 위해 사용되는 라이브러리들입니다.

 

sudo apt-get install libatlas-base-dev gfortran libeigen3-dev




 

python2.7-dev와 python3-dev 패키지는 OpenCV-Python 바인딩을 위해 필요한 패키지들입니다. 

Numpy는 매트릭스 연산등을 빠르게 처리할 수 있어서 OpenCV에서 사용됩니다. 

sudo apt-get install python2.7-dev python3-dev python-numpy python3-numpy
cmake -D CMAKE_BUILD_TYPE=RELEASE \
-D CMAKE_INSTALL_PREFIX=/usr/local \
-D WITH_TBB=OFF \
-D WITH_IPP=OFF \
-D WITH_1394=OFF \
-D BUILD_WITH_DEBUG_INFO=OFF \
-D BUILD_DOCS=OFF \
-D INSTALL_C_EXAMPLES=ON \
-D INSTALL_PYTHON_EXAMPLES=ON \
-D BUILD_EXAMPLES=OFF \e
-D BUILD_TESTS=OFF \
-D BUILD_PERF_TESTS=OFF \
-D WITH_QT=ON \
-D WITH_OPENGL=ON \
-D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib-3.4.0/modules \
-D WITH_V4L=ON  \
-D WITH_FFMPEG=ON \
-D WITH_XINE=ON \
-D BUILD_NEW_PYTHON_SUPPORT=ON \
../
[출처] Ubuntu 16.04에 opencv_contrib 포함하여 OpenCV 3.4 설치|작성자 쿠핑