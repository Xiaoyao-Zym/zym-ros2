 #-*-coding:GBK -*-   
from time import time
import rclpy
from rclpy.node import Node
# 1. ������Ϣ����
from std_msgs.msg import String

class WritherNode(Node):
    """
    ����һ�����ҽڵ㣬���ڳ�ʼ��ʱ���һ����
    """
    def _init__(self,name):
        super().__init__(name)
        self.get_logger().info("��Һã�����%s������һ�����ң�" % name)
        # 2.������������ʼ�������߳�Ա����pubnovel
        self.pub_novel=self.create_publisher(String,"sexy_girl", 10)
        
        # 3.��д�����߼�
        # ������ʱ����Ա����timer
        self.i = 0 #i��һ�����������������½ڱ�ŵ�
        timer_period=5 #ÿ5sдһ�½ڻ�
        # ����һ����ʱװ�ã�ÿ1s������һ��timer_callback����
        self.timer=self.create_timer(timer_period, self.timer_callback)
        #�˻�Ǯ������
        self.account=80
        # ��������ʼ�������߳�Ա����submoney
        self.submoney = self.create_subscription(UInt32,"sexy_girl_money",self.recv_money_callback,10)
    def timer_callback(self):
        """
        ��ʱ���ص�����
        """
        msg=String()
        msg.data='��%d�أ�����%d��ż��������' % (self.i, self.i)
        # ��С˵���ݷ�����ȥ
        self.pub_novel.publish(msg)
        # ��ӡһ�·������ݣ������ǿ�
        self.get_logger().info('���ģ��ҷ�����Ϣ��"%s"'% msg.data)
        # �½ڱ��+1
        self.i+=1
    def recv_money_callback(self,money):
        """
        4. ��д���Ļص������߼�
        """
        self.account += money.data
        self.get_logger().info('���ģ����Ѿ��յ���%d�ĸ��' % self.account)
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
    node = WritherNode("li4")  # �½�һ���ڵ�
    rclpy.spin(node) # ���ֽڵ����У�����Ƿ��յ��˳�ָ�Ctrl+C��
    rclpy.shutdown() # �ر�rclpy