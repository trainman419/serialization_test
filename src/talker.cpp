#include <ros/ros.h>

#include <serialization_test/Terrible.h>
#include <serialization_test/Terrible2.h>
#include <serialization_test/Terrible3.h>

int main(int argc, char ** argv) {
   ros::init(argc, argv, "talker");
   ros::NodeHandle n;

   ros::Publisher pub1 = n.advertise<serialization_test::Terrible>(
         "terrible1", 10);
   ros::Publisher pub2 = n.advertise<serialization_test::Terrible2>(
         "terrible2", 10);
   ros::Publisher pub3 = n.advertise<serialization_test::Terrible3>(
         "terrible3", 10);
  
   ros::Rate loop_rate(1.0);

   serialization_test::Terrible t1;
   serialization_test::Terrible2 t2;
   serialization_test::Terrible3 t3;
   int i=0;
   while(ros::ok()) {
      pub1.publish(t1);

      t2.s1 = "";
      for( int j=0; j<i; j++ ) {
         t2.s1 += ".";
      }
      pub2.publish(t2);

      t3.s1 = t2.s1;
      pub3.publish(t3);

      i = ++i % 65;
      ros::spinOnce();
      ROS_INFO("%d", i);
      loop_rate.sleep();
   }

   return 0;
}
