# FeeTech 2D Gimbal

此项目是基于[飞特舵机ST3032](https://item.taobao.com/item.htm?id=625751317567)制作的二维云台的驱动程序。

该项目包含了Linux主机（如Jetson nano）以及Tiva、STM32的驱动程序。

**克隆本项目**

```
git clone https://github.com/Pansamic/FeeTech_2D_Gimbal
```

## :rocket: API

### Linux

`void Gimbal_Init(void)`

说明：初始化二维云台。

`void Gimbal_SetAngle(float YawAngle, float PitchAngle)`

### STM32

### Tiva