# 5G RAN Testbed using srsRAN [1]

**This document is written to help small and medium-sized enterprises and research labs in Korea easily build a 5G RAN testbed.** We utilize `srsRAN` and `Open5GS` [2] open source to summarize how to build a
`srsRAN` and `Open5GS` [2] open source to build a 5G NR Band n3 testbed. `srsRAN` is a software that supports commercial Software Define Radio (SDR) hardware to fully implement LTE, 5G RAN, and User Equipment (UE) solutions [2].
solutions [2]. `Open5GS` is used to easily implement your own LTE/NR Core Network. The architecture of our testbed is shown in the figure below.

<br />
<br />


![ran_testbed](https://user-images.githubusercontent.com/28584258/226221865-c89d7dbd-9976-49bb-9d8a-76d159411b7e.png)


## Structure

This repository is organized as follows:
<br />

```
/root/K-O-RAN 
|
└──setup-scripts
|   |
|   └──setup-ran.sh
|   |
|   └──setup-code.py
|   
└──setup
|  |
|  └──Open5GS
|  |
|  └──srsRAN
|  |
|  └──srsRAN_config.conf
```

## Quick Start

From the `setup-scripts` directory: <br />
- Install srsRAN and Open5GS: `./configure_os.sh`
- In `setup-config.conf`, modify `IP` to match your network environment.
- Configure and install 5G RAN: `./setup-ran.sh`


<br />

## References

[1] srsRAN, https://www.srslte.com/ <br />
[2] Open5GS, https://open5gs.org/ <br />
[3] Upadhyaya, P. S., Abdalla, A. S., Marojevic, V., Shah, V. K., and Reed, J. H., “Prototyping next-generation O-RAN research testbeds with SDRs,” arXiv preprint arXiv:2205.13178, 2022.
