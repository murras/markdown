# 동영상에서 프레임 추출하기

### ffmpeg을 사용하여 프레임 추출하기.

- 운영체제에 맞게 [ffmpeg 다운로드](http://ffmpeg.org/download.html)

- (Windows를 기준으로) bin 폴더 안에서 cmd 실행.

    `ffmpeg -ss [시작시간] -t [길이] -i [동영상이름] -r [프레임레이트] -s [출력해상도] -qscale:v 2 -f image2 [이미지이름]`

    예시)
        `ffmpeg -ss 00:00:0 -i test.mp4 -r 10 -f image2 test-%d.jpg` 

    - 처음부터 10 프레임마다 test-%d.jpg 형식으로 이미지 저장.
