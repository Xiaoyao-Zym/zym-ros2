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