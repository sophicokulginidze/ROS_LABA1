#include <ros/ros.h>
#include "std_msgs/String.h"
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

void recieve(const std_msgs::String & msg) {
  std_msgs::String str;
  str.data = msg.data;
  transform(str.begin(), str.end(), str.begin(), tolower);
  for (int i = 0; i < strlen(str); i++) 
  {
    if (str[i] == " ")
    {
      i++;
    } else
    {
      if (!(i % 2)) 
      {
        str[i] = toupper(str[i]);
      } else 
      {
        str[i] = str[i];
      }
    }
  }
  ROS_INFO("Result string: %s", str.data);
  return;
}

int main(int argc, char ** argv) {
  ros::init(argc, argv, "subscriber");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("/string_out", 1, recieve);
  ros::spin();
  return 0;
}