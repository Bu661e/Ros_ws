#include <ros/ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>


ros::Publisher pub;
ros::Subscriber sub;
void scancallback(sensor_msgs::LaserScan msgs);

int main(int argc, char  *argv[])
{
    //把这个节点链接到ROS中
    ros::init(argc, argv, "vel_node");
    int i = 0;
    ros::NodeHandle nh;
    pub = nh.advertise<geometry_msgs::Twist> ("/cmd_vel", 20);
    sub = nh.subscribe("/scan", 20, scancallback);


    //ros::ok() 是专门用于无限循环的条件，支持^C退出终端
    while (ros::ok())
    {

        ros::spinOnce();
    }
    
    return 0;
}



void scancallback(sensor_msgs::LaserScan msgs)
{
    int mid = msgs.angle_max + msgs.angle_min/2;
    printf("%f\n",msgs.ranges[mid] );
    if(msgs.ranges[(msgs.angle_max + msgs.angle_min)/2] < 2)
    {
        geometry_msgs::Twist to_msgs;
        to_msgs.linear.x = 0.05;
        to_msgs.linear.y = 0;
        to_msgs.linear.z = 0;
        to_msgs.angular.x = 0;
        to_msgs.angular.y = 0;
        to_msgs.angular.z = -0.2;
        pub.publish(to_msgs);
    
    }
    else
    {
        geometry_msgs::Twist to_msgs;
        to_msgs.linear.x = 0.2;
        to_msgs.linear.y = 0;
        to_msgs.linear.z = 0;
        to_msgs.angular.x = 0;
        to_msgs.angular.y = 0;
        to_msgs.angular.z = 0;
        pub.publish(to_msgs);
    }
}
