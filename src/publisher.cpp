#include <ros/ros.h>
#include "std_msgs/String.h"
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

int main(int argc, char ** argv) 
{
  ros::init(argc, argv, "publisher");
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise < std_msgs::String > ("/string_in", 1);
  ros::Rate loop_rate(1);

  while (ros::ok()) 
  {
    std_msgs::String str;
    str.data = (char)"Some fucking message";
    pub.publish(str);
    loop_rate.sleep();;
  }
  return 0;
}