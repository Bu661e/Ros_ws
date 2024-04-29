#include <ros/ros.h>
#include <std_msgs/String.h>

int main(int argc, char  *argv[])
{
    //把这个节点链接到ROS中
    ros::init(argc, argv, "chaoshengbo_node");
    int i = 0;


    ros::NodeHandle nh;
    // advertise<消息类型>(Topic名称，缓存长度)
    ros::Publisher pub = nh.advertise<std_msgs::String> ("Topic1", 20);
    ros::Rate loop_rate(10);



    //ros::ok() 是专门用于无限循环的条件，支持^C退出终端
    while (ros::ok())
    {
        printf("msgs_%d from chaoshengbo_node!\n", i++);
        std_msgs::String msg;
        msg.data = "msgs1";
        pub.publish(msg);
        loop_rate.sleep();;
    }
    
    return 0;
}

