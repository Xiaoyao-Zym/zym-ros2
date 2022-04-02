# ROS2 learning notees
## 1 ROS2 Node(节点)
### 1.1 Basic Concept（基本概念）
Each node in ROS2 is only responsible for a separate modular function. For example, a node is responsible for controlling the wheel rotation, a node is responsible for the data obtained from the lidar, a node is responsible for processing the lidar data, and a node is responsible for positioning.
每一个节点也是只负责一个单独的模块化的功能（比如一个节点负责控制车轮转动，一个节点负责从激光雷达获取数据、一个节点负责处理激光雷达的数据、一个节点负责定位
### 1.2 Interaction Between Nodes（节点间交互）  
ROS2 has four modes of communication
ROS2的四种通讯法方式
* topics(话题)
* servinces(服务)
* Action(动作)
* Paraments(参数)
### 1.3 Start Node（启动节点）
使用命令启动节点
`ros2 run <package_name> <executable_name>    `

意义：启动包下的中的节点
使用样例：
`ros2 run turtlesim turtlesim_node`
### 1.4 查看节点信息
ROS2相关的CLI指和ROS2相关的命令行操作。
1.运行节点(常用)
`ros2 run <package_name> <executable_name>`
2.查看节点列表(常用)
`ros2 node list`
3.查看节点信息
`ros2 node info<node_name>  
4.重映射节点名称  
`ros2 run turtlesim_node --ros-args --remap __node:=my_turtle`
# 2 工作空间和功能包
### 2.1 Woking Space（工作空间）
工作空间是包含若干个功能包的目录，一开始大家把工作空间理解成一个文件夹就行了。这个文件夹包含下有**src**。
>**mkdir: 创建一个目录，mkdir -p ：递归创建目录,即使上级目录不存在,会按目录层级自动创建目录**  

`mkdir -p turtle_ws/src `
`cd turtle_ws/src`

>**注意：一个工作空间下可以有多个功能包，一个功能包可以有多个节点存在**
### 2.2 Package(功能包)
功能包指存放节点的地方，ROS2中功能包根据编译方式不同分为三种类型
* ament_python，适用于python程序
* cmake, 适用于C++
* ament_ament，适用于C++程序，是cmake的增强版
### 2.3 功能包获取的两种方式
安装一般使用
`sudo apt install ros-<version>-package_name`
安装获取会自动放置在系统目录，不用再次动手source
### 2.4 功能包相关的指令ros2 pkg  
```
create       Create a new ROS2 package
executables  Output a list of package specific executables
list         Output a list of available packages
prefix       Output the prefix path of a package
xml          Output the XML of the package manifest or a specific tag
```
1.创建功能包
>**ros2 pkg create <package-name> --build-type {cmake,ament_cmake,ament_python} --dependencies<依赖名字>**  

2.列出可执行文件  
  列出所有
>**ros2 pkg executables**

列出某个功能包的

>**ros2 pkg executables turtlesim**

3.列出所有的包
>**ros2 pkg list**

4.输出某个包所在路径的前缀 
>**ros2 pkg prefix  <package-name>**

比如小乌龟

>**ros2 pkg xml turtlesim**

### 2.5 ROS2构建工具-Colcon
colcon是一个功能包构建工具，用于编译代码
#### 安装colcon
>**sudo apt-install python3-colcon-common-extensions**
#### 测试
创建工作空间
>**mkdir colcon_test&&cd colcon_test**

下载ROS3示例源码
>**git clone https://github.com/ros2/examples src/examples -b foxy**

编译工程
>**colcon build**

查看文件目录结构
>**ls**
#### 运行自定义节点
1.打开ia终端使用**cd colcon_test进入我们刚刚创建的工作空间，先source资源
>**source install/setup.bath**

2.运行一个订阅杂志节点， 
>**ros2 run examples_rclcpp_minimal_subscriber subscriber_member_function**

3.打开新终端，先source 再运行一个发行杂志节点
>**source install/setup.bash**
>**ros2 run examples_rclcpp_minimal_publisher publisher_member_function**
### 2.6 新建一个节点(Python)
#### 1. 新建一个工作空间
>**mkdir -p twn_ws/src**
>**cd town_ws/src**
#### 2. 创建一个功能包
>**ros2 pkg create village_li --build-tyoe ament_python --dependencies rclpy**
* pkg create: 创建包
* --build-type： 指定该包的编译类型，有**ament_pyhton,ament_cmake,cmake**，**默认**ament_cmake**
* --dependencies: 指定功能包的依赖，这里给了一个人ros2的python客户端接口: **rcply**
#### 3. 创建节点文件
>**cd town_ws/village_li/village_li**
>**touch li4.py**

* 查看文件结构：tree
#### 4.编写程序
编写ROS2节点的一般步骤
1. 导入库文件
2. 初始化客户端库
3. 新建节点
4. spin循环节点
5. 关闭客户端库

@li4.py
```Python
import rclpy
from rclpy.node import Node

def main(args=None):
    """
    ros2运行该节点的入口函数
    编写ROS2节点的一般步骤
    1. 导入库文件
    2. 初始化客户端库
    3. 新建节点对象
    4. spin循环节点
    5. 关闭客户端库
    """
    rclpy.init(args=args) # 初始化rclpy
    node = Node("li4")  # 新建一个节点
    node.get_logger().info("大家好，我是作家li4.")
    rclpy.spin(node) # 保持节点运行，检测是否收到退出指令（Ctrl+C）
    rclpy.shutdown() # 关闭rclpy
```
修改setup.cpp
```Python
entry_points={
        'console_scripts': [
            "li4_node = village_li.li4:main"
        ],
    },
)
```
#### 5.编译运行节点
打开Vscode终端，进入town_ws
编译节点
>**colcon build**

source环境
>**source install/setup.bash**

运行节点
>**ros2 run village_li li4_node**

查看现有节点
>**ros2 node list**
### 2.7 OOP介绍
1. 面向过程编程思想：POP
2. 面向对象编程思想：OOP
3. 函数式思想：FP

案例：将大象装入冰箱
#### POP
1. 打开冰箱门
2. 把大象塞进去
3. 关上冰箱门
#### OOP
对象=属性+行为
1. 调用：冰箱->打开门(行为)
2. 调用：冰箱->装东西(行为)
3. 调用：冰箱->关闭门(行为) 

#### FP
1. 定义关进(冰箱，大象)函数
2. 实现函数：关门(放入（开门（冰箱)，大象))
多层嵌套函数调用
使用OOP方法
```Python
#!/usr/bin/env python3
import rclpy
from rclpy.node import Node


class WriterNode(Node):
    """
    创建一个作家节点，并在初始化时输出一个话
    """
    def __init__(self,name):
        super().__init__(name)
        self.get_logger().info("大家好，我是%s,我是一名作家！" %name)


def main(args=None):
    """
    ros2运行该节点的入口函数
    1. 导入库文件
    2. 初始化客户端库
    3. 新建节点
    4. spin循环节点
    5. 关闭客户端库
    """
    rclpy.init(args=args) # 初始化rclpy
    node = WriterNode("li4")  # 新建一个节点
    rclpy.spin(node) # 保持节点运行，检测是否收到退出指令（Ctrl+C）
    rclpy.shutdown() # 关闭rclpy
```
### 新建一个节点(C++)
1. 创建王家村功能包
>**cd town_ws/src**
>**ros2 pkg create village_wang --build-type ament_cmake --dependencies rclcpp**

2. 创建节点
>**cd village_wang/src
touch wang2.cpp**






