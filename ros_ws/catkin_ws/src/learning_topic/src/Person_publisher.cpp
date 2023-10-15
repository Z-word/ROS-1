#include "ros/ros.h"
#include "learning_topic/Person.h"
 
 
int main(int argc, char *argv[])
{
    //加入本行，输出的中文字符不会乱码
    setlocale(LC_ALL,"");
 
    //初始化ros节点（节点名必须唯一）
    ros::init(argc,argv,"pub_person");
 
    //创建ros句柄
    ros::NodeHandle nh;
 
    //创建发布者对象 advertise<这里为自定义的消息类型> 话题名msg_person需要与订阅方保持一致
    ros::Publisher pub = nh.advertise<learning_topic::Person>("msg_person",1000);
 
    //定义封装消息
    learning_topic::Person person;
    person.name  = "sun";
    person.age = 24;
    person.height = 1.75;
 
    //设置发布频率
    ros::Rate r(1);
 
    while (ros::ok())
    {
        //发布数据
        pub.publish(person);
 
        //打印数据
        ROS_INFO("发布的信息,姓名:%s,年龄:%d,身高:%.2f", person.name.c_str(), person.age, person.height);
 
        r.sleep();
 
        ros::spinOnce();
    }
    
    return 0;
}