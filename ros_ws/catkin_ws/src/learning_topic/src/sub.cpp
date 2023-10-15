#include <ros/ros.h>
#include "turtlesim/Pose.h"

// 接收到订阅的消息后，（是储存信息的长指针）会进入消息回调函数
void poseCallback(const turtlesim::Pose::ConstPtr& msg)
{
    // 将接收到的消息打印出来
    ROS_INFO("Turtle pose: x:%0.6f, y:%0.6f", msg->x, msg->y);
}

//主函数
int main(int argc, char **argv)
{
    // 初始化ROS节点，节点名称[pose_subscriber]
    ros::init(argc, argv, "pose_subscriber");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个订阅者[pose_sub]，订阅名为[/turtle1/pose]的topic
    //注册回调函数poseCallback
    //消息队列为10，不确定处理能力，可能会掉帧
    ros::Subscriber pose_sub = n.subscribe("/turtle1/pose", 10, poseCallback);

    // 循环等待回调函数，死循环，不断查看队列里有没有新的消息进来
    ros::spin();

    return 0;
}

