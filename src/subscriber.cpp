#include <ros/ros.h>
#include "std_msgs/String.h"
#include <sstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cctype>

using namespace std;

ros::Publisher pub;

void recieve(const std_msgs::String & msg) {
  std_msgs::String str;
  str.data = msg.data;
  std::transform(str.data.begin(), str.data.end(), str.data.begin(), [](unsigned char c) {return std::tolower(c); });
  for (ulong i = 0; i < str.data.length(); i++) {
    if (str.data[i] == ' ') {
      i++;
    } else {
      if (!(i % 2)) {
        str.data[i] = toupper(str.data[i]);
      } else {
        str.data[i] = str.data[i];
      }
    }
  }
  ROS_INFO_STREAM("Result string:" << str.data);
  pub.publish(str);
  return;
}

int main(int argc, char ** argv) {
  ros::init(argc, argv, "subscriber");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("/string_in", 1, recieve);
  pub = n.advertise<std_msgs::String>("/string_out",1);
  ros::spin();
  return 0;
}
