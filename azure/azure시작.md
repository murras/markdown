# Microsoft Azure 새로운 리소스 만들고 시작하기

- [Azure 구독 페이지](https://azure.microsoft.com/ko-kr/free/?WT.mc_id=A261C142F)를 들어가서 로그인을 하고 `체험 계정을 만들기`나 `지금 바로 구입`을 선택합니다. 
  - 체험 계정으로는 GPU 사용 가능한 인스턴스가 없는 것으로 알고 있습니다.
- 결제 정보를 등록하고 계약 과정까지 진행합니다.
![Image](https://i.imgur.com/L0uwkLR.png)

- 위 사항이 다 끝나면 [Azure portal](https://portal.azure.com/#home)을 들어가서 로그인합니다.
- 새 리소스를 만들기 전에 할당량 증가 신청을 먼저 해야합니다. `도움말 + 지원` 탭에 들어가서 할당량 증가 요청을 해야합니다.
  - 저는 NC6 v2(코어 6개)를 사용할 예정이라 6개를 신청했습니다.

![Image](https://i.imgur.com/QxO9i5u.png)

- [Azure portal](https://portal.azure.com/#home)에 들어가서 `리소스 만들기`를 누르고 원하는 리소스를 선택합니다.
  - 저는 Ubuntu Server 18.04 LTS를 골랐습니다.
- 기본 사항에서 `가상 머신 이름`, 원하는 VM을 선택하고, 인증 형식, 인바운드 포트를 설정합니다.
  
![Image](https://i.imgur.com/BX8hAPr.png)

- 그 이후 쭉 따라서 진행을 하고 배포완료까지 되면, CMD창이나 bash에서 `ssh 계정명@IP주소` 입력을 통해 접속이 가능합니다.
    - 이후에 저는 putty가 편한것 같아 putty를 사용하고 있습니다.
- 연결 후 `lshw` 명령어를 통해 하드웨어 정보를 확인할 수 있습니다.

![Image](https://i.imgur.com/vykunqu.png)