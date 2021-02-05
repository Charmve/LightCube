## Dev Enviroment

<img align="left" alt="GIF" src="https://www.keil.com/images/icons/mdk_dld_v2.png?raw=true" width="40" height="40"/>
<p>
  MDK-ARM
  <br>Complete the following form to download the Keil software development tools.
  <br> [Download](https://www.keil.com/download/product/)
</p>

## CHANGELOG

### v1.3
- 引入文件系统FatFs
- 通过SPI总线读取内存卡的内容发送到串口

### v1.2
- 实现蓝牙串口传输数据
- UART管脚定义

### v1.1
- 实现SM12126写入16位数据

### v1.0
- 实现模板配置


## SPI管脚定义

```
TX--PB6
RX--PB7

SCK				PB13
MOSI				PB15
MISO				PB14
CS				PB11
```

> !!!!!!!!!!!!读内存卡一定要5V!!!!!!!!!!!!


