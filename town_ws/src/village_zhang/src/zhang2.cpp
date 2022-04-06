#include"rclcpp/rclcpp.hpp"
using namespace std;
//POP方法编写
// int main(int argc, char **argv)
// {
//     rclcpp::init(argc, argv);
//     //产生一个zhang2节点
//     auto node=make_shared<rclcpp::Node>("zhang2");
//     RCLCPP_INFO(node->get_logger(),"大家好，我是逍遥子");
//     //运行节点，并检测退出信号
//     rclcpp::spin(node);
//     rclcpp::shutdown();
//     return 0;
// }
//OOP方法编写节点
/*
    创建一个类节点，名字叫做SingleDogNode,继承自Node.
*/
class SingleDogNode:public rclcpp::Node
{
public:
    //构造函数，有一个参数为节点名称
    SingleDogNode(string name):Node(name)
    {
        RCLCPP_INFO(this->get_logger(), "大家好，逍遥子%s.", name.c_str());
    }
private:
};
int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    //产生一个zhang2节点
    auto node=make_shared<SingleDogNode>("zhang2");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}