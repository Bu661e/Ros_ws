#include <ros/ros.h>
#include <std_msgs/String.h>

void chaoshengbocallback(std_msgs::String msgs)
{
    ROS_INFO(msgs.data.c_str());
    printf("\n");
}
void copytestcallback(std_msgs::String msgs)
{
    ROS_WARN(msgs.data.c_str());
    printf("\n");
}

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL, "");
    //把这个节点链接到ROS中
    ros::init(argc, argv, "mada_node");


    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("Topic1", 20, chaoshengbocallback);
    ros::Subscriber sub2 = nh.subscribe("Topic2", 20, copytestcallback);






    //ros::ok() 是专门用于无限循环的条件，支持^C退出终端
    while (ros::ok())
    {
        ros::spinOnce();
    }
    
    return 0;
}

