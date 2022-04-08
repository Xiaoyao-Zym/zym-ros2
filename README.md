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
>**ros2 pkg create village_li --build-type ament_python --dependencies rclpy**
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
### 2.8 创建一个C++功能包
1. 创建王家村功能包
>**cd town_ws/src**
>**ros2 pkg create village_wang --build-type ament_cmake --dependencies rclcpp**

2. 创建节点
>**cd village_wang/src
touch wang2.cpp**
### 2.9 POP方法编写C++节点并测试
####1.编写代码
```C++
#include "rclcpp/rclcpp.hpp"
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    /*产生一个Wang2的节点*/
    auto node = std::make_shared<rclcpp::Node>("wang2");
    // 打印一句自我介绍
    RCLCPP_INFO(node->get_logger(), "大家好，我是单身狗wang2.");
    /* 运行节点，并检测退出信号*/
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
```
主函数中首先初始化rclcpp，然后新建一个Node节点的对象，命名wang2，接着是使用rclcpp让这个节点暴露在外面，并检测退出信号（Ctrl+检测），检测到退出信号后，就会执行rcl.shutdown()关闭节点
####2. 添加CmakeLists
在wang2.cpp中输入上面的内容，还需要修改一下CmakeLists.txt
在CmakeLists.txt最后一行加入两行代码
>**add_executable(wnag2_node src/wang2.cpp)**
>**ament_target_dependencies(wang2_node rclcpp)**

添加这两行代码的目的是让编译器编译wang2.cpp这个文件，不然不会主动编译。接着在上面两行代码下面添加下面的代码。
```C++
install(TARGETS
  wang2_node
  DESTINATION lib/${PROJECT_NAME}
)
```
这个是C++比Python要麻烦的地方，需要手动将编译好的文件安装到install/village_wang/lib/village_wang下
#### 3. 编译运行节点
打开Vscode终端，进入town_ws
编译节点
>**colcon build**

source环境
>**source install/setup.bash**

运行节点
>**ros2 run village_wang wang2_node**

####4. 测试
当节点运行起来后，可以再尝试使用ros2 node list 指令来查看现有的节点。这个时候你应该能看到
### 2.10 OOP方式编写一个节点
####1. 编写代码
输入下列代码
```C++
#include "rclcpp/rclcpp.hpp"
/*
    创建一个类节点，名字叫做SingleDogNode,继承自Node.
*/
class SingleDogNode : public rclcpp::Node
{
public:
    // 构造函数,有一个参数为节点名称
    SingleDogNode(std::string name) : Node(name)
    {
        // 打印一句自我介绍
        RCLCPP_INFO(this->get_logger(), "大家好，我是单身狗%s.",name.c_str());
    }
private:
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    /*产生一个Wang2的节点*/
    auto node = std::make_shared<SingleDogNode>("wang2");
    /* 运行节点，并检测退出信号*/
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
```
上面的代码声明了一个叫做**SingleDogNode**的类，并在类的初始化函数中，输出了一句话。主函数中首先初始化rclcpp，然后新建了一个**SingleDogNode**节点的对象，接着使用**rclcpp**让这个节点暴露在外面，并检测退出信号（Ctrl+C），检测到退出信号后，就会执行**rcl.shutdown()**关闭节点。
### 2.11 ros2相关指令
#### 2.11.1.ros2功能包相关指令
用法：ros2 pkg [-h]
Call ros2 pkg command  -h 可以获得更多使用细节
各种与包有关的子命令
可选的参数：
-h, --help     显示帮助并退出
Commands:
creat     创建一个新的ROS功能包
executable   列出包下的可执行文件
list    输出有效的包的列表
prefix  输出一个包的前缀路径
xml     输出某个包的xml
使用‘ros2 pkg < command > -h'可以获得更多细节
#### 2.11.2. ros2节点相关指令
用法：ros2 node[-h]
Call 'ros2 node < command>-h'可以获得更多细节
各种与node有关的子指令
可选的参数：
-h ，-help   显示帮助并退出
Command：
info 输出一个节点的信息
list 输出所有在线的节点
使用‘ros2 node < commmand> -h'可以获得更多使用细节
#### 2.11.3.colcon相关文档
在线文档：https://colcon.readthedocs.io/en/released/user/installation.html
### 2.12 ROS2客户端库RCL介绍
* RCL（ROS Client Library）ROS客户端库，其实就是ROS的一种API，提供了对ROS话题、服务、参数、Action等接口。
* python语言提供了rclpy来操作ROS2的节点话题服务等，而C++则使用rclcpp提供API操作ROS2的节点话题和服务等。
## 3. ROS2通信机制(话题与服务)
* ROS2中Topic通信方式，Topic通信模型是一种发布订阅模型
* 节点与节点之间通过话题来相互通信（传输数据）
* 节点1创建一个发布者（Publisher)发布一个话题（topic），节点2创建了一个订阅者（Subscriber）来订阅李四发布的话题。
* ROS2中话题通信可以是1对1、1对n、n对1、n对n的通信。
### 3.1 ROS2话题介绍
#### 3.1.1 话题通信规则
需要满足以下规则：
* 话题名字是关键，发布订阅接口类型要相同，发布的是字符串，接受也要用字符串来接受
* 同一个节点可以订阅多个话题，同时也可以发布多个话题，就像一本书的作者也可以是另外一本书的读者；
* 同一个小说不能有多个作者，但是小说不一样，同一个话题可以有多个发布者。
### 3.2 相关的工具
#### 3.2.1 RQT工具rqt_graph
ROS2作为强大的工具，在运行过程中，我们可以通过命令来看到节点和节点之间的数据关系的。
依次输入：
>**ros2 run demo_nodes_py listener**
>**ros2 run demo_nodes_cpp talker**
>**rqt_graph**
#### 3.2.2 ROS2话题相关命令行界面（CLI）工具
>**ros2 topic -h**
>**ros2 topic list  //返回系统当前活动的所有主题的列表**
>**ros2 topic list -t 增加消息类型**
>**ros2 topic echo //打印实时话题内容**
>**ros2 topic info //查看主题信息**
>**ros2 interface show   //查看消息类型**
>**ros2 topic pub arg //手动发布命令**
### 3.3 ROS2话题编程
#### 3.3.1 话题通信实现（python）
1. 发布话题
我们创建作家这个类WriterNode的时候让其继承Node节点，即下面这样：
>**class WriterNode(Node):**

继承后，WriterNode类具备以下四个能力
* 创建一个话题发布者的能力
* 创建一个定时器的能力
* 创建一个话题订阅者的能力
* 获取日志打印器的能力
2. 编写程序
在li4.py文件中添加如下代码
```Pyhton
#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
# 1. 导入消息类型
from std_msgs.msg import String


class WriterNode(Node):
    """
    创建一个李四节点，并在初始化时输出一个话
    """
    def __init__(self,name):
        super().__init__(name)
        self.get_logger().info("大家好，我是%s,我是一名作家！" % name)
        # 2.创建并初始化发布者成员属性pubnovel
        self.pub_novel = self.create_publisher(String,"sexy_girl", 10) 

        #3. 编写发布逻辑
        # 创建定时器成员属性timer
        self.i = 0 # i 是个计数器，用来算章节编号的
        timer_period = 5  #每5s写一章节话
        self.timer = self.create_timer(timer_period, self.timer_callback)  #启动一个定时装置，每 1 s,调用一次time_callback函数


    def timer_callback(self):
        """
        定时器回调函数
        """
        msg = String()
        msg.data = '第%d回：潋滟湖 %d 次偶遇胡艳娘' % (self.i,self.i)
        self.pub_novel.publish(msg)  #将小说内容发布出去
        self.get_logger().info('李四:我发布了艳娘传奇："%s"' % msg.data)    #打印一下发布的数据，供我们看
        self.i += 1 #章节编号+1
```
3. 代码解析
* 创建发布者
create_publisher(type,name,size)
--------type：方法类型
--------name：话题名称
--------size：消息队列长度
from std_msgs.msg import String
--------从std_msgs.msg中导入String类
--------std_msgs是ROS2自带的接口类型，规定了我们常用的消息类型，可以使用下面的命令来查看std.msgs中所有的消息类型
**ros2 interface package std_msgs**
还可以使用下面的命令来查看ros2自带的消息类型
**ros2 interface list**
* 编写发布逻辑发布数据
创建一个定时器
**self.create_timer(timer_period, self.timer_calback)**
这个定时器的作用是根据传入的**timer_period**时间周期，每隔一个timer_period秒，调用一次**self.timer_calback**函数，在**self.timer_calback**函数里，我们使用public方法将数据发送出去。也就是每1s中发送一次内容
**self.write.publish(msg)   #将小说内容发布出去** 








