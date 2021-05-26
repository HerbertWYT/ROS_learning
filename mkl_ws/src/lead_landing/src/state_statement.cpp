#include <ros/ros.h>
#include <mavros_msgs/State.h>
#include <sensor_msgs/NavSatFix.h>
#include <sensor_msgs/BatteryState.h>

void vehicleState(const mavros_msgs::State::ConstPtr& msg)
{
	ROS_INFO("CopterState: arm:%d guided:%d mode:%s", msg->armed, msg->guided, msg->mode.c_str());
}
void vehicleBatteryState(const sensor_msgs::BatteryState::ConstPtr& msg)
{
	ROS_INFO("CopterBattery: Voltage:%.3f Charge:%.3f", msg->voltage,msg->charge);
}
void vehiclePosition(const sensor_msgs::NavSatFix::ConstPtr& msg)
{
	ROS_INFO("CopterPosition: long:%.3f lat:%.3f alt:%.3f", msg->longitude,msg->latitude,msg->altitude);
}
int main(int argc, char**argv)
{
	ros::init(argc,	argv, "state_statement");
	ros::NodeHandle n;

	ros::Subscriber state_sub = n.subscribe<mavros_msgs::State>("mavros/state", 10, vehicleState);
	ros::Subscriber battery_sub = n.subscribe<sensor_msgs::BatteryState>("mavros/battery", 10, vehicleBatteryState);
	ros::Subscriber global_position_sub = n.subscribe<sensor_msgs::NavSatFix>("mavros/global_position/global", 10, vehiclePosition);


	ros::spin();

	return 0;

}