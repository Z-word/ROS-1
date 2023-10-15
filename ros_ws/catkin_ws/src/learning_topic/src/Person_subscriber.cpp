#include "ros/ros.h"
#include "learning_topic/Person.h"
 
void doPerson(const learning_topic::Person::ConstPtr& person_p){
    ROS_INFO("订阅的信息,姓名:%s, 年龄:%d, 身高:%.2f", person_p->name.c_str(), person_p->age, person_p->height);
}
 
 
 
int main(int argc, char *argv[])
{
    //加入本行避免中文输出乱码
    setlocale(LC_ALL,"");
 
    //初始化ros节点
    ros::init(argc,argv,"sub_person");
    //创建节点句柄
    ros::NodeHandle nh;
    //创建订阅对象 advertise<这里为自定义的消息类型> 话题名msg_person需要与发布方保持一致
    ros::Subscriber sub = nh.subscribe<learning_topic::Person>("msg_person",10,doPerson);
 
 
    //回头处理回调函数
    ros::spin(); 
    return 0;
}