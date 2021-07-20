# 目录

- 1.ardupilot_ws
- 2.catkin_ws
- 3.mkl_ws
- 4.project_learn
- 5.ros_ml
- 6.ros_ws
- 7.videolearn_ws

## 1. ardupilot_ws

目前只包含一个launch文件，此文件用于启动mavros和mavlink。此文件是根据APM固件，ubuntu_18.04,ROS_melodic, gazebo本地仿真进行针对性修改的文件。可直接运行，运行指令：

- 1.在终端中进入此文件见路径至 ./src/launch/
- 2.roslaunch apm.launch

## 2. catkin_ws

此文件夹中包含下载的3个ros的node，此nodes中iq_gnc,iq_sim是来自于youtube教程,offboard来自于px4官方教程。

## 3. mkl_ws

研究测试用的node，正在加紧修改中...

## 4.project_learn

来自APM官方的blog，其中包括两个部分：1 ArduCopter ROS AprilTag Detection; 2 ArduCopter ROS aruco Boards Detection
### 1 ArduCopter ROS AprilTag Detection
[原文链接](https://ardupilot.org/dev/docs/ros-apriltag-detection.html)
### 2 ArduCopter ROS aruco Boards Detection
[原文链接](https://ardupilot.org/dev/docs/ros-aruco-detection.html)

## 5.ros_ml

来自CSDN的博客代码，node是基于PX4固件的自主着陆。

## 6.ros_ws

下载的darknet_ros的node，目前可用，后续考虑在此基础上进行扩展学习。

## 7.videolearn_ws

根据古月居ROS的教程的学习代码。