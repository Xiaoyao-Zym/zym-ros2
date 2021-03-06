#include "rclcpp/rclcpp.hpp"
//POP方法编写C++节点
// int main(int argc, char **argv)
// {
//     rclcpp::init(argc, argv);
//     /*产生一个Wang2的节点*/
//     auto node = std::make_shared<rclcpp::Node>("wang2");
//     // 打印一句自我介绍
//     RCLCPP_INFO(node->get_logger(), "大家好，我是单身狗wang2.");
//     /* 运行节点，并检测退出信号*/
//     rclcpp::spin(node);
//     rclcpp::shutdown();
//     return 0;
// }
//OOP方式编写一个节点
/*
  创建一个类节点，名字叫做SingleDogNode，继承Node
*/
class SingleDogNode:public rclcpp::Node
{
public:
    //构造函数，有一个参数为节点名称
    SingleDogNode(std::string name):Node (name)
    {
        //打印一句自我介绍
        RCLCPP_INFO(this->get_logger(), "大家好，我是单身贵族\s)",name.c_str());
    }
private:
};
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    //产生一个Wang2的节点
    auto node=std::make_shared<SingleDogNode>("wang2");
    //运行节点，并检测退出信号
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}