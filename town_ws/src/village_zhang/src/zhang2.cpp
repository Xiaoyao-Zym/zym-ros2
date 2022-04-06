#include"rclcpp/rclcpp.hpp"
using namespace std;
//POP������д
// int main(int argc, char **argv)
// {
//     rclcpp::init(argc, argv);
//     //����һ��zhang2�ڵ�
//     auto node=make_shared<rclcpp::Node>("zhang2");
//     RCLCPP_INFO(node->get_logger(),"��Һã�������ң��");
//     //���нڵ㣬������˳��ź�
//     rclcpp::spin(node);
//     rclcpp::shutdown();
//     return 0;
// }
//OOP������д�ڵ�
/*
    ����һ����ڵ㣬���ֽ���SingleDogNode,�̳���Node.
*/
class SingleDogNode:public rclcpp::Node
{
public:
    //���캯������һ������Ϊ�ڵ�����
    SingleDogNode(string name):Node(name)
    {
        RCLCPP_INFO(this->get_logger(), "��Һã���ң��%s.", name.c_str());
    }
private:
};
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    //����һ��zhang2�ڵ�
    auto node=make_shared<SingleDogNode>("zhang2");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}