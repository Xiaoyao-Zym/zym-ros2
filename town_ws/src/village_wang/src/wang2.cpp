#include "rclcpp/rclcpp.hpp"
//POP������дC++�ڵ�
// int main(int argc, char **argv)
// {
//     rclcpp::init(argc, argv);
//     /*����һ��Wang2�Ľڵ�*/
//     auto node = std::make_shared<rclcpp::Node>("wang2");
//     // ��ӡһ�����ҽ���
//     RCLCPP_INFO(node->get_logger(), "��Һã����ǵ���wang2.");
//     /* ���нڵ㣬������˳��ź�*/
//     rclcpp::spin(node);
//     rclcpp::shutdown();
//     return 0;
// }
//OOP��ʽ��дһ���ڵ�
/*
  ����һ����ڵ㣬���ֽ���SingleDogNode���̳�Node
*/
class SingleDogNode:public rclcpp::Node
{
public:
    //���캯������һ������Ϊ�ڵ�����
    SingleDogNode(std::string name):Node (name)
    {
        //��ӡһ�����ҽ���
        RCLCPP_INFO(this->get_logger(), "��Һã����ǵ������\s)",name.c_str());
    }
private:
};
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    //����һ��Wang2�Ľڵ�
    auto node=std::make_shared<SingleDogNode>("wang2");
    //���нڵ㣬������˳��ź�
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}