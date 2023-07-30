# FeeTech 2D Gimbal

此项目是基于[飞特舵机ST3032](https://item.taobao.com/item.htm?id=625751317567)制作的二维云台的驱动程序。

该项目包含了Linux主机（如Jetson nano）以及Tiva、STM32的驱动程序。

**克隆本项目**

```
git clone https://github.com/Pansamic/FeeTech_2D_Gimbal
```

## :book: 使用说明

### 更改电机ID

需要注意，**初次使用**该电机时，所有的电机的ID都是1，因此对总线发串口信息的时候，两个电机均会对ID为1的指令进行响应，而**不会响应其他ID的指令**。这并不是我们期望的情况。因此，需要将驱动板连接上位机来**更改电机ID**。




## :hand: 示例程序

### Linux

```shell
git clone https://github.com/Pansamic/FeeTech_2D_Gimbal
cd FeeTech_2D_Gimbal/demo/linux
cmake .
make
#'/dev/ttyUSB0'替换成实际连接电机驱动板的串口设备
sudo ./gimbal_demo /dev/ttyUSB0 
```

在示例程序中，二维云台的两个电机会




### STM32

### Tiva

## :rocket: API

### Linux

`void Gimbal_Init(void)`

说明：初始化二维云台。

`void Gimbal_SetAngle(float YawAngle, float PitchAngle)`

### STM32

### Tiva