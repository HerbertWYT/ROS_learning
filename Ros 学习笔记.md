#ROS——learning 按步骤编写一个ROS软件包

写在最前：ROS开发在Ubuntu中执行，ROS版本请根据Ubuntu版本进行调整。

此文档只为快速开发ROS软件包进行参考，扩展/延伸阅读请跳转ROS Wiki，内置简体中文和English。

简体中文链接：[ROS教程_简体中文](http://wiki.ros.org/cn/)

English链接：[ROS_Tutorial_English](http://wiki.ros.org/)

##1. 基建——从零到Package

###1.0 “零”的基础

Ubuntu基本终端指令：cd/cd ..进入/退出某一文件夹,ls当前目录下所有内容, mkdir创建一个新的文件夹。

###1.1 工作空间

建立工作空间文件夹

```
#标准代码格式
mkdir ${workspacen_ws} # ${workspace_ws} 可替换为任意名字
cd ${workapace_ws}
mkdir src
catkin init
```

创建package包

```
#标准代码格式
cd ${workspacen_ws}/src/
catkin_create_pkg ${package_name} [dependence 1] [dependence 2] [dependence 3] ... [dependence N] 
# ${package_name} 可替换为任意名字 [dependence i]替换所需的依赖包 数量按需缩写
```

###1.2 package——空软件包搭建

进入`${package_name}`文件夹，里面已自动生成好src和include文件夹，CMakeLists.txt和package.xml文件。

因ROS的package可以用C++和python两种语言编写，故此处建议将C++语言源代码文件放入src文件，python脚本代码放入${package_name}文件下scripts文件夹。

注：此文件夹不会自动生成，需要自己新建。

另外，一个package可能还需要多种功能例如：launch启动文件，msg信息文件，srv服务文件等。建议每种文件分别建文件夹。

###1.3 小结

所以一个完整的初始的ROS工作空间应该如下

```
${workspace_ws}---|/.
                  |-build # 执行catkin_make后自动生成
                  |-devel # 执行catkin_make后自动生成
                  |-src--|/.
                         |-${package_1}
                         |-${package_2}
                         |-${package_3}-|/.
                                        |-launch  # 存放launch文件
                                        |-include # 存放C++头文件
                                        |-msg     # 存放message文件
                                        |-scripts # 存放python脚本
                                        |-src     # 存放C++源代码
                                        |-srv     # 存放service文件
                                        |-CMakelists.txt∫
                                        |-package.xml
                         |-CMakeLists.txt # 执行catkin init后自动生成 后续无需修改
```

有了工作空间就可进行编译使用了。

###1.番外 工作空间的编译（Build）

进入工作空间进行编译（build）

```
cd ${workspace_ws}
catkin_make
catkin_make install #可选
```

##2. Package中的Node实现——如何写源代码

ROS主要用到的功能：（还包括一些其他功能，请跳转顶端Wiki界面查阅）

  - Node 节点：可执行文件，通过ROS与其他Node进行通信
  - Topic 话题：节点Publish（发布）信息到话题或者通过Subcribe（订阅）信息从话题接收信息
  - Service 服务：节点发送一个Request（请求）并获得一个Response（响应）
  - Paramter 参数
  - Messages消息：Publish（发布）或者Subscribe（订阅）Topic（话题）时使用的数据类型
  - Launch 启动脚本

以下分别以C++和python两种代码实现说明。

###2.1 C++源代码基本结构

C++源代码文件cpp应该包括几个部分：引用，自动定义函数（按需设置），主函数。

引用范式：

```c++
//参考
#include <ros/ros.h>
#include "xxx/XXX.h"
//示例
#include <ros/ros.h>
#include "package_name/createhead.h" //此处引用了package后续编译生成的头文件
```

自定义函数范式：

```c++
void functionname(datetype1 datename1,datetype2 datename2)
{
    //function_A;
    //function_B;
    //...
}
```
主函数范式：

```c++
init main(int argc, char **argv)
{
    ros::init(argc, argv, "node_name"); // node_name可自定义
    ros::NodeHanle n; //n可换为其他变量，推荐n，nh 这种比较简单的方式，按需更改
    //输入函数的其他功能
    return 0;
}
```
###2.2 python脚本基本内容

Python源代码文件cpp应该包括几个部分：库的调用，自动定义函数（按需设置），主函数。

```python
#!/usr/bin/env python
import rospy
from package.msg import msg

def selfidentifictedfunction():
    #函数功能

def function():

    rospy.init_node("node_name", anonymous = True)
    #函数功能


if __name__ == "__main__":
    function()
```

###2.3 Topic相关————C++版本

Topic话题包含两个功能：Publish发布和Subscribe订阅。

**1.** Publish发布

















