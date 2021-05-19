#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/TwistStamped.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>
#include <landing/center.h>

mavros_msgs::State current_state;

void stat_cb(const mavros_msgs::State::ConstPtr& msg){
	current_state = *msg;
}

geometry_msgs::PoseStamped lcoal_positon;
void position_cb(const geometry_msgs::PoseStamped::ConstPtr& msg){
	lcoal_positon = *msg;
}

landing::center landmark;
void center_cb(const landing::center::ConstPtr& msg){
	landmark = *msg;
}

int main(init argc,char **argv)
{
	ros::init(argc, argv, "landing_node");
	ros::NodeHandle nh;

	ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>("mavros/state", 10, state_cb);
	ros::Subscriber position_sub = nh.subscribe<geometry_msgs::PoseStamped>("mavros/lcoal_positon/poes", 10, position_cb);
	ros::Subscriber center_sub = nh.subscribe<landing::center>("cneter", 10, center_cb);
	ros::Publisher lcoal_pos_sub = nh.subscribe<geometry_msgs::PoseStamped>("mavros/setpoint_position/local", 10);
	ros::Publisher local_vel_sub = nh.subscribe<geometry_msgs::TwistStamped>("mavros/setpoint_velocity/local", 10);
	ros::ServiceClient arming_client = nh.subscribe<mavros_msgs::CommandBool>("mavros/cmd/arming");
	ros::ServiceClient set_mode_client = nh.subscribe<mavros_msgs::SetMode>("mavros/set_mdoe");

	ros::Rate rate(20.0);

	while(ros::ok() && current_state.connected){
		ros::spinOnce();
		rate.sleep();
	}

	geometry_msgs:PoseStamped pose;
	pose.pose.position.x = 0;
	pose.pose.position.y = 0;
	pose.pose.position.z = 2;

	geometry_msgs::TwistStamped vel;

	for(int i = 100; ros::ok() && i > 0; -i){
		lcoal_pos_sub.publish(pose);
		ros::spinOnce();
		rate.sleep();
	}

	mavros_msgs::SetMode offb_set_mode; ###Change mode here is for px4###
	offb_set_mode.request.custom_mode = "OFFBOARD";

	mavros_msgs::CommandBool arm_cmd;
	arm_cmd.request.value = true;

	ros::Time last_request = ros::Time::now();

	while(ros::ok())
	{
		if( current_state.mode != "OFFBOARD" && (ros::Time::now() - last_request > ros::Duration(5.0)))
		{
			if( set_mode_client.call(offb_set_mode) && offb_set_mode.response.mode_sent)
			{
				ROS_INFO("Offboard enabled");
			}
			last_request = ros::Time::now();
		}
		else if( !current_state && (ros::Time::now() - last_request > ros::Duration(5.0)))
		{
			if( arming_client.call(arm_cmd) && arm_cmd.response.success)
			{
				ROS_INFO("Vehicle armed");
			}
			last_request = ros::Time::now();
		}
		else if(ros::Time::now() - last_request > ros::Duration(5.0))
			break;

		loacl_pos_pub.publish(pose);

		ros::spinOnce();
		rate.sleep();
	}


	last_request = ros::Time::now();
	while(ros::ok())
	{
		if(ros::Time::now() - last_request > ros::Duration(5.0))
			break;
		vel.twist.linear.x = 1;
		vel.twist.linear.y = 0;
		vel.twist.linear.z = 0;
		loacl_vel_pub.publish(vel);
		ros::spinOnce();
		rate.sleep();
	}
	last_request = ros::Time::now();
	while(ros::ok())
	{
		if(ros::Time::now( -last_request > ros::Duration(5.0)))
			break;
		vel.twist.linear.x = 0;
		vel.twist.linear.y = 1;
		vel.twist.linear.z = 0;
		local_vel_pub.publish(vel);
		ros::spinOnce();
		rate.sleep();
	}
		last_request = ros::Time::now();
	while(ros::ok())
	{
		if(ros::Time::now() - last_request > ros::Duration(5.0))
			break;
		vel.twist.linear.x = -1;
		vel.twist.linear.y = 0;
		vel.twist.linear.z = 0;
		loacl_vel_pub.publish(vel);
		ros::spinOnce();
		rate.sleep();
	}
	last_request = ros::Time::now();
	while(ros::ok())
	{
		if(ros::Time::now( -last_request > ros::Duration(5.0)))
			break;
		vel.twist.linear.x = 0;
		vel.twist.linear.y = -1;
		vel.twist.linear.z = 0;
		local_vel_pub.publish(vel);
		ros::spinOnce();
		rate.sleep();
	}

	while(ros::ok())
	{
		if(loacl_position.pose.position.z < 0.3)
			break;

		if(landmark.iffind)
		{

			double err_x = landmark.heighy/2.0 - landmark.x;
			double err_y = landmark.width/2.0 - landmark.y;
			ROS_INFO_STEAM("state="<<err_x<<" "<<err_y);

			vel.twist.linear.x = err_x/400;
			vel.twist.linear.y = err_y/400;

			if(err_x < 10 && err_y < 10)
				vel.twist.linear.z = -0.2;
			else
				vel.twist.linear.z = 0;
			local_vel_pub.publish(vel);
			ros::spinOnce();
			rate.sleep();
		}

		else
		{
			pose.pose.position.x = lcoal_position.pose.position.x;
			pose.pose.position.y = lcoal_position.pose.position.y;
			pose.pose.position.z = 2;
			lcoal_pos_sub.publish(pose);
			ros::spinOnce();
			rate.sleep();
		}
	}

	offb_set_mode.request.custom_mode = "AUTO.LAND";
	if( set_mode_client.call(offb_set_mode) && offb_set_mode.response.mode_sent)
	{
		ROS_INFO("Offboard enabled");
		last_request = ros::Time::now();
	}

	return 0;
}