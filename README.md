# 5G RAN Testbed using srsRAN [1]

**이 문서는 국내 중소 기업 및 연구실에서 쉽게 5G RAN 테스트베드를 구축할 수 있도록 돕기 위해 작성되었습니다.** 우리는 `srsRAN`과 `Open5GS` [2] 오픈소스를 활용하여
5G NR Band n3 테스트베드를 구축하는 방법을 정리합니다. `srsRAN`은 상용 Software Defind Radio (SDR) 하드웨어를 지원하는 소프트웨어로 LTE, 5G RAN 그리고 User Equipment (UE)
솔루션을 완벽하게 구현합니다 [2]. `Open5GS`는 자신만의 LTE/NR Core Network를 쉽게 구현하는데 사용됩니다. 우리 테스트베드의 아키텍처는 아래 그림과 같습니다.
<br />
<br />


![ran_testbed](https://user-images.githubusercontent.com/28584258/226221865-c89d7dbd-9976-49bb-9d8a-76d159411b7e.png)


## Structure

해당 저장소의 폴더의 구성은 아래와 같습니다.
<br />

```
/root/K-O-RAN 
|
└──setup-scripts
|   |
|   └──setup-ran.sh
|   |
|   └──setup-code.py
|   |
|   └──setup-config.conf
|   |
|   └──configure_os.sh
|   
└──setup
|  |
|  └──Open5GS
|  |
|  └──srsRAN
```

## Quick Start

`setup-scripts` 폴더에서: <br />
- srsRAN과 Open5GS 설치: `./configure_os.sh`
- `setup-config.conf`에서 자신의 네트워크 환경에 맞춰 `IP`를 수정합니다. <br />
- 5G RAN 환경을 구성하고 설치: `./setup-ran.sh`


<br />

## Reference

[1] srsRAN, https://www.srslte.com/ <br />
[2] Open5GS, https://open5gs.org/ <br />
[3] Upadhyaya, P. S., Abdalla, A. S., Marojevic, V., Shah, V. K., and Reed, J. H., “Prototyping next-generation O-RAN research testbeds with SDRs,” arXiv preprint arXiv:2205.13178, 2022.
