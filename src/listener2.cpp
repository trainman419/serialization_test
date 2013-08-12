#include <ros/ros.h>
#include <serialization_test/Terrible2.h>

int count = 0;

void cb( const serialization_test::Terrible2::ConstPtr & t) {
   count++;
   ROS_INFO("Got %d messages", count);
}

int main(int argc, char ** argv) {
   ros::init(argc, argv, "listener2");

   ros::NodeHandle n;

   ros::Subscriber s = n.subscribe("terrible2", 10, &cb);

   while(ros::ok() && count < 100 ) {
      ros::spinOnce();
   }
   ROS_INFO("Test Successful");
   return 0;
}
