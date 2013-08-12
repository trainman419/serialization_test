#include <ros/ros.h>
#include <serialization_test/Terrible.h>

int count = 0;

void cb( const serialization_test::Terrible::ConstPtr & t) {
   count++;
   ROS_INFO("Got %d messages", count);
}

int main(int argc, char ** argv) {
   ros::init(argc, argv, "listener1");

   ros::NodeHandle n;

   ros::Subscriber s = n.subscribe("terrible1", 10, &cb);

   ros::Rate loop_rate(1.0);

   while( ros::ok() && count < 5 ) {
      ros::spinOnce();
   }
   ROS_INFO("Test Successful");
   return 0;
}
