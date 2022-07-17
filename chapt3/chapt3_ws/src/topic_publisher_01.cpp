#include "rclcpp/rclcpp.hpp"

class TopicPublisher01:public rclcpp::Node
{
private:
    //声明节点
public:
    TopicPublisher01(std::string name):Node(name)
    {
        RCLCPP_INFO(this->get_logger(), "大家号，我是%s.", mame.c_str());
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc,argv);
    /*产生一个的节点*/
    auto node=std::make_shared<TopicPublisher01>("topic_publisher_01");
    /*运行节点，并检测退出信号*/
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
