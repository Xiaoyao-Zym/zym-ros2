 #-*-coding:GBK -*-   
import rclpy
from rclpy.node import Node
class WritherNode(Node):
    """
    ����һ�����ҽڵ㣬���ڳ�ʼ��ʱ���һ����
    """
    def _init__(self,name):
        super().__init__(name)
        self.get_logger().info("��Һã�����%s������һ�����ң�" %name)
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