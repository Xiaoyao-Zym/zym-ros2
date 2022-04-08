 #-*-coding:GBK -*-   
from time import time
import rclpy
from rclpy.node import Node
# 1. 导入消息类型
from std_msgs.msg import String

class WritherNode(Node):
    """
    创建一个作家节点，并在初始化时输出一个话
    """
    def _init__(self,name):
        super().__init__(name)
        self.get_logger().info("大家好，我是%s，我是一名作家！" % name)
        # 2.创建并发布初始化发布者成员属性pubnovel
        self.pub_novel=self.create_publisher(String,"sexy_girl", 10)
        
        # 3.编写发布逻辑
        # 创建定时器成员属性timer
        self.i = 0 #i是一个计数器，用来算章节编号的
        timer_period=5 #每5s写一章节话
        # 启动一个定时装置，每1s，调用一次timer_callback函数
        self.timer=self.create_timer(timer_period, self.timer_callback)
        #账户钱的数量
        self.account=80
        # 创建并初始化订阅者成员属性submoney
        self.submoney = self.create_subscription(UInt32,"sexy_girl_money",self.recv_money_callback,10)
    def timer_callback(self):
        """
        定时器回调函数
        """
        msg=String()
        msg.data='第%d回：西湖%d次偶遇梦中人' % (self.i, self.i)
        # 将小说内容发布出去
        self.pub_novel.publish(msg)
        # 打印一下发布数据，供我们看
        self.get_logger().info('李四：我发布消息："%s"'% msg.data)
        # 章节编号+1
        self.i+=1
    def recv_money_callback(self,money):
        """
        4. 编写订阅回调处理逻辑
        """
        self.account += money.data
        self.get_logger().info('李四：我已经收到了%d的稿费' % self.account)
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
    node = WritherNode("li4")  # 新建一个节点
    rclpy.spin(node) # 保持节点运行，检测是否收到退出指令（Ctrl+C）
    rclpy.shutdown() # 关闭rclpy