#include "rclcpp/rclcpp.hpp"

class TopicPublisher01:public rclcpp::Node
{
private:
    //�����ڵ�
public:
    TopicPublisher01(std::string name):Node(name)
    {
        RCLCPP_INFO(this->get_logger(), "��Һţ�����%s.", mame.c_str());
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc,argv);
    /*����һ���Ľڵ�*/
    auto node=std::make_shared<TopicPublisher01>("topic_publisher_01");
    /*���нڵ㣬������˳��ź�*/
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
