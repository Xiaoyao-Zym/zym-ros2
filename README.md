# ROS2 learning notees
## 1 ROS2 Node(�ڵ�)
### 1.1 Basic Concept���������
Each node in ROS2 is only responsible for a separate modular function. For example, a node is responsible for controlling the wheel rotation, a node is responsible for the data obtained from the lidar, a node is responsible for processing the lidar data, and a node is responsible for positioning.
ÿһ���ڵ�Ҳ��ֻ����һ��������ģ�黯�Ĺ��ܣ�����һ���ڵ㸺����Ƴ���ת����һ���ڵ㸺��Ӽ����״��ȡ���ݡ�һ���ڵ㸺�������״�����ݡ�һ���ڵ㸺��λ
### 1.2 Interaction Between Nodes���ڵ�佻����  
ROS2 has four modes of communication
ROS2������ͨѶ����ʽ
* topics(����)
* servinces(����)
* Action(����)
* Paraments(����)
### 1.3 Start Node�������ڵ㣩
ʹ�����������ڵ�
`ros2 run <package_name> <executable_name>    `

���壺�������µ��еĽڵ�
ʹ��������
`ros2 run turtlesim turtlesim_node`
### 1.4 �鿴�ڵ���Ϣ
ROS2��ص�CLIָ��ROS2��ص������в�����
1.���нڵ�(����)
`ros2 run <package_name> <executable_name>`
2.�鿴�ڵ��б�(����)
`ros2 node list`
3.�鿴�ڵ���Ϣ
`ros2 node info<node_name>  
4.��ӳ��ڵ�����  
`ros2 run turtlesim_node --ros-args --remap __node:=my_turtle`
# 2 �����ռ�͹��ܰ�
### 2.1 Woking Space�������ռ䣩
�����ռ��ǰ������ɸ����ܰ���Ŀ¼��һ��ʼ��Ұѹ����ռ�����һ���ļ��о����ˡ�����ļ��а�������**src**��
>**mkdir: ����һ��Ŀ¼��mkdir -p ���ݹ鴴��Ŀ¼,��ʹ�ϼ�Ŀ¼������,�ᰴĿ¼�㼶�Զ�����Ŀ¼**  

`mkdir -p turtle_ws/src `
`cd turtle_ws/src`

>**ע�⣺һ�������ռ��¿����ж�����ܰ���һ�����ܰ������ж���ڵ����**
### 2.2 Package(���ܰ�)
���ܰ�ָ��Žڵ�ĵط���ROS2�й��ܰ����ݱ��뷽ʽ��ͬ��Ϊ��������
* ament_python��������python����
* cmake, ������C++
* ament_ament��������C++������cmake����ǿ��
### 2.3 ���ܰ���ȡ�����ַ�ʽ
��װһ��ʹ��
`sudo apt install ros-<version>-package_name`
��װ��ȡ���Զ�������ϵͳĿ¼�������ٴζ���source
### 2.4 ���ܰ���ص�ָ��ros2 pkg  
```
create       Create a new ROS2 package
executables  Output a list of package specific executables
list         Output a list of available packages
prefix       Output the prefix path of a package
xml          Output the XML of the package manifest or a specific tag
```
1.�������ܰ�
>**ros2 pkg create <package-name> --build-type {cmake,ament_cmake,ament_python} --dependencies<��������>**  

2.�г���ִ���ļ�  
  �г�����
>**ros2 pkg executables**

�г�ĳ�����ܰ���

>**ros2 pkg executables turtlesim**

3.�г����еİ�
>**ros2 pkg list**

4.���ĳ��������·����ǰ׺ 
>**ros2 pkg prefix  <package-name>**

����С�ڹ�

>**ros2 pkg xml turtlesim**

### 2.5 ROS2��������-Colcon
colcon��һ�����ܰ��������ߣ����ڱ������
#### ��װcolcon
>**sudo apt-install python3-colcon-common-extensions**
#### ����
���������ռ�
>**mkdir colcon_test&&cd colcon_test**

����ROS3ʾ��Դ��
>**git clone https://github.com/ros2/examples src/examples -b foxy**

���빤��
>**colcon build**

�鿴�ļ�Ŀ¼�ṹ
>**ls**
#### �����Զ���ڵ�
1.��ia�ն�ʹ��**cd colcon_test�������Ǹոմ����Ĺ����ռ䣬��source��Դ
>**source install/setup.bath**

2.����һ��������־�ڵ㣬 
>**ros2 run examples_rclcpp_minimal_subscriber subscriber_member_function**

3.�����նˣ���source ������һ��������־�ڵ�
>**source install/setup.bash**
>**ros2 run examples_rclcpp_minimal_publisher publisher_member_function**
### 2.6 �½�һ���ڵ�(Python)
#### 1. �½�һ�������ռ�
>**mkdir -p twn_ws/src**
>**cd town_ws/src**
#### 2. ����һ�����ܰ�
>**ros2 pkg create village_li --build-type ament_python --dependencies rclpy**
* pkg create: ������
* --build-type�� ָ���ð��ı������ͣ���**ament_pyhton,ament_cmake,cmake**��**Ĭ��**ament_cmake**
* --dependencies: ָ�����ܰ����������������һ����ros2��python�ͻ��˽ӿ�: **rcply**
#### 3. �����ڵ��ļ�
>**cd town_ws/village_li/village_li**
>**touch li4.py**

* �鿴�ļ��ṹ��tree
#### 4.��д����
��дROS2�ڵ��һ�㲽��
1. ������ļ�
2. ��ʼ���ͻ��˿�
3. �½��ڵ�
4. spinѭ���ڵ�
5. �رտͻ��˿�

@li4.py
```Python
import rclpy
from rclpy.node import Node

def main(args=None):
    """
    ros2���иýڵ����ں���
    ��дROS2�ڵ��һ�㲽��
    1. ������ļ�
    2. ��ʼ���ͻ��˿�
    3. �½��ڵ����
    4. spinѭ���ڵ�
    5. �رտͻ��˿�
    """
    rclpy.init(args=args) # ��ʼ��rclpy
    node = Node("li4")  # �½�һ���ڵ�
    node.get_logger().info("��Һã���������li4.")
    rclpy.spin(node) # ���ֽڵ����У�����Ƿ��յ��˳�ָ�Ctrl+C��
    rclpy.shutdown() # �ر�rclpy
```
�޸�setup.cpp
```Python
entry_points={
        'console_scripts': [
            "li4_node = village_li.li4:main"
        ],
    },
)
```
#### 5.�������нڵ�
��Vscode�նˣ�����town_ws
����ڵ�
>**colcon build**

source����
>**source install/setup.bash**

���нڵ�
>**ros2 run village_li li4_node**

�鿴���нڵ�
>**ros2 node list**
### 2.7 OOP����
1. ������̱��˼�룺POP
2. ���������˼�룺OOP
3. ����ʽ˼�룺FP

������������װ�����
#### POP
1. �򿪱�����
2. �Ѵ�������ȥ
3. ���ϱ�����
#### OOP
����=����+��Ϊ
1. ���ã�����->����(��Ϊ)
2. ���ã�����->װ����(��Ϊ)
3. ���ã�����->�ر���(��Ϊ) 

#### FP
1. ����ؽ�(���䣬����)����
2. ʵ�ֺ���������(���루���ţ�����)������))
���Ƕ�׺�������
ʹ��OOP����
```Python
#!/usr/bin/env python3
import rclpy
from rclpy.node import Node


class WriterNode(Node):
    """
    ����һ�����ҽڵ㣬���ڳ�ʼ��ʱ���һ����
    """
    def __init__(self,name):
        super().__init__(name)
        self.get_logger().info("��Һã�����%s,����һ�����ң�" %name)


def main(args=None):
    """
    ros2���иýڵ����ں���
    1. ������ļ�
    2. ��ʼ���ͻ��˿�
    3. �½��ڵ�
    4. spinѭ���ڵ�
    5. �رտͻ��˿�
    """
    rclpy.init(args=args) # ��ʼ��rclpy
    node = WriterNode("li4")  # �½�һ���ڵ�
    rclpy.spin(node) # ���ֽڵ����У�����Ƿ��յ��˳�ָ�Ctrl+C��
    rclpy.shutdown() # �ر�rclpy
```
### 2.8 ����һ��C++���ܰ�
1. �������Ҵ幦�ܰ�
>**cd town_ws/src**
>**ros2 pkg create village_wang --build-type ament_cmake --dependencies rclcpp**

2. �����ڵ�
>**cd village_wang/src
touch wang2.cpp**
### 2.9 POP������дC++�ڵ㲢����
####1.��д����
```C++
#include "rclcpp/rclcpp.hpp"
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    /*����һ��Wang2�Ľڵ�*/
    auto node = std::make_shared<rclcpp::Node>("wang2");
    // ��ӡһ�����ҽ���
    RCLCPP_INFO(node->get_logger(), "��Һã����ǵ���wang2.");
    /* ���нڵ㣬������˳��ź�*/
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
```
�����������ȳ�ʼ��rclcpp��Ȼ���½�һ��Node�ڵ�Ķ�������wang2��������ʹ��rclcpp������ڵ㱩¶�����棬������˳��źţ�Ctrl+��⣩����⵽�˳��źź󣬾ͻ�ִ��rcl.shutdown()�رսڵ�
####2. ���CmakeLists
��wang2.cpp��������������ݣ�����Ҫ�޸�һ��CmakeLists.txt
��CmakeLists.txt���һ�м������д���
>**add_executable(wnag2_node src/wang2.cpp)**
>**ament_target_dependencies(wang2_node rclcpp)**

��������д����Ŀ�����ñ���������wang2.cpp����ļ�����Ȼ�����������롣�������������д��������������Ĵ��롣
```C++
install(TARGETS
  wang2_node
  DESTINATION lib/${PROJECT_NAME}
)
```
�����C++��PythonҪ�鷳�ĵط�����Ҫ�ֶ�������õ��ļ���װ��install/village_wang/lib/village_wang��
#### 3. �������нڵ�
��Vscode�նˣ�����town_ws
����ڵ�
>**colcon build**

source����
>**source install/setup.bash**

���нڵ�
>**ros2 run village_wang wang2_node**

####4. ����
���ڵ����������󣬿����ٳ���ʹ��ros2 node list ָ�����鿴���еĽڵ㡣���ʱ����Ӧ���ܿ���
### 2.10 OOP��ʽ��дһ���ڵ�
####1. ��д����
�������д���
```C++
#include "rclcpp/rclcpp.hpp"
/*
    ����һ����ڵ㣬���ֽ���SingleDogNode,�̳���Node.
*/
class SingleDogNode : public rclcpp::Node
{
public:
    // ���캯��,��һ������Ϊ�ڵ�����
    SingleDogNode(std::string name) : Node(name)
    {
        // ��ӡһ�����ҽ���
        RCLCPP_INFO(this->get_logger(), "��Һã����ǵ���%s.",name.c_str());
    }
private:
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    /*����һ��Wang2�Ľڵ�*/
    auto node = std::make_shared<SingleDogNode>("wang2");
    /* ���нڵ㣬������˳��ź�*/
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
```
����Ĵ���������һ������**SingleDogNode**���࣬������ĳ�ʼ�������У������һ�仰�������������ȳ�ʼ��rclcpp��Ȼ���½���һ��**SingleDogNode**�ڵ�Ķ��󣬽���ʹ��**rclcpp**������ڵ㱩¶�����棬������˳��źţ�Ctrl+C������⵽�˳��źź󣬾ͻ�ִ��**rcl.shutdown()**�رսڵ㡣
### 2.11 ros2���ָ��
#### 2.11.1.ros2���ܰ����ָ��
�÷���ros2 pkg [-h]
Call ros2 pkg command  -h ���Ի�ø���ʹ��ϸ��
��������йص�������
��ѡ�Ĳ�����
-h, --help     ��ʾ�������˳�
Commands:
creat     ����һ���µ�ROS���ܰ�
executable   �г����µĿ�ִ���ļ�
list    �����Ч�İ����б�
prefix  ���һ������ǰ׺·��
xml     ���ĳ������xml
ʹ�á�ros2 pkg < command > -h'���Ի�ø���ϸ��
#### 2.11.2. ros2�ڵ����ָ��
�÷���ros2 node[-h]
Call 'ros2 node < command>-h'���Ի�ø���ϸ��
������node�йص���ָ��
��ѡ�Ĳ�����
-h ��-help   ��ʾ�������˳�
Command��
info ���һ���ڵ����Ϣ
list ����������ߵĽڵ�
ʹ�á�ros2 node < commmand> -h'���Ի�ø���ʹ��ϸ��
#### 2.11.3.colcon����ĵ�
�����ĵ���https://colcon.readthedocs.io/en/released/user/installation.html
### 2.12 ROS2�ͻ��˿�RCL����
* RCL��ROS Client Library��ROS�ͻ��˿⣬��ʵ����ROS��һ��API���ṩ�˶�ROS���⡢���񡢲�����Action�Ƚӿڡ�
* python�����ṩ��rclpy������ROS2�Ľڵ㻰�����ȣ���C++��ʹ��rclcpp�ṩAPI����ROS2�Ľڵ㻰��ͷ���ȡ�
## 3. ROS2ͨ�Ż���(���������)
* ROS2��Topicͨ�ŷ�ʽ��Topicͨ��ģ����һ�ַ�������ģ��
* �ڵ���ڵ�֮��ͨ���������໥ͨ�ţ��������ݣ�
* �ڵ�1����һ�������ߣ�Publisher)����һ�����⣨topic�����ڵ�2������һ�������ߣ�Subscriber�����������ķ����Ļ��⡣
* ROS2�л���ͨ�ſ�����1��1��1��n��n��1��n��n��ͨ�š�
### 3.1 ROS2�������
#### 3.1.1 ����ͨ�Ź���
��Ҫ�������¹���
* ���������ǹؼ����������Ľӿ�����Ҫ��ͬ�����������ַ���������ҲҪ���ַ���������
* ͬһ���ڵ���Զ��Ķ�����⣬ͬʱҲ���Է���������⣬����һ���������Ҳ����������һ����Ķ��ߣ�
* ͬһ��С˵�����ж�����ߣ�����С˵��һ����ͬһ����������ж�������ߡ�
### 3.2 ��صĹ���
#### 3.2.1 RQT����rqt_graph
ROS2��Ϊǿ��Ĺ��ߣ������й����У����ǿ���ͨ�������������ڵ�ͽڵ�֮������ݹ�ϵ�ġ�
�������룺
>**ros2 run demo_nodes_py listener**
>**ros2 run demo_nodes_cpp talker**
>**rqt_graph**
#### 3.2.2 ROS2������������н��棨CLI������
>**ros2 topic -h**
>**ros2 topic list  //����ϵͳ��ǰ�������������б�**
>**ros2 topic list -t ������Ϣ����**
>**ros2 topic echo //��ӡʵʱ��������**
>**ros2 topic info //�鿴������Ϣ**
>**ros2 interface show   //�鿴��Ϣ����**
>**ros2 topic pub arg //�ֶ���������**
### 3.3 ROS2������
#### 3.3.1 ����ͨ��ʵ�֣�python��
1. ��������
���Ǵ������������WriterNode��ʱ������̳�Node�ڵ㣬������������
>**class WriterNode(Node):**

�̳к�WriterNode��߱������ĸ�����
* ����һ�����ⷢ���ߵ�����
* ����һ����ʱ��������
* ����һ�����ⶩ���ߵ�����
* ��ȡ��־��ӡ��������
2. ��д����
��li4.py�ļ���������´���
```Pyhton
#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
# 1. ������Ϣ����
from std_msgs.msg import String


class WriterNode(Node):
    """
    ����һ�����Ľڵ㣬���ڳ�ʼ��ʱ���һ����
    """
    def __init__(self,name):
        super().__init__(name)
        self.get_logger().info("��Һã�����%s,����һ�����ң�" % name)
        # 2.��������ʼ�������߳�Ա����pubnovel
        self.pub_novel = self.create_publisher(String,"sexy_girl", 10) 

        #3. ��д�����߼�
        # ������ʱ����Ա����timer
        self.i = 0 # i �Ǹ����������������½ڱ�ŵ�
        timer_period = 5  #ÿ5sдһ�½ڻ�
        self.timer = self.create_timer(timer_period, self.timer_callback)  #����һ����ʱװ�ã�ÿ 1 s,����һ��time_callback����


    def timer_callback(self):
        """
        ��ʱ���ص�����
        """
        msg = String()
        msg.data = '��%d�أ����ٺ� %d ��ż��������' % (self.i,self.i)
        self.pub_novel.publish(msg)  #��С˵���ݷ�����ȥ
        self.get_logger().info('����:�ҷ��������ﴫ�棺"%s"' % msg.data)    #��ӡһ�·��������ݣ������ǿ�
        self.i += 1 #�½ڱ��+1
```
3. �������
* ����������
create_publisher(type,name,size)
--------type����������
--------name����������
--------size����Ϣ���г���
from std_msgs.msg import String
--------��std_msgs.msg�е���String��
--------std_msgs��ROS2�Դ��Ľӿ����ͣ��涨�����ǳ��õ���Ϣ���ͣ�����ʹ��������������鿴std.msgs�����е���Ϣ����
**ros2 interface package std_msgs**
������ʹ��������������鿴ros2�Դ�����Ϣ����
**ros2 interface list**
* ��д�����߼���������
����һ����ʱ��
**self.create_timer(timer_period, self.timer_calback)**
�����ʱ���������Ǹ��ݴ����**timer_period**ʱ�����ڣ�ÿ��һ��timer_period�룬����һ��**self.timer_calback**��������**self.timer_calback**���������ʹ��public���������ݷ��ͳ�ȥ��Ҳ����ÿ1s�з���һ������
**self.write.publish(msg)   #��С˵���ݷ�����ȥ** 








