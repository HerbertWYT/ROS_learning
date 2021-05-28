#include <ros/ros.h>
#include <mavros_msgs/State.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/CommandTOL.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/TwistStamped.h>

mavros_msgs::State vehicle_current_state;
void vehicleState(const mavros_msgs::State::ConstPtr& msg){
    vehicle_current_state = *msg;
    //ROS_INFO("CopterState: arm:%d guided:%d mode:%s", msg->armed, msg->guided, msg->mode.c_str());
}

//geometry_msgs::PoseStamped vehicle_local_position;
//void positionPublish(const geometry_msgs::PoseStamped::ConstPtr& msg){
//	vehicle_local_position = *msg;
//}


int main(int argc, char **argv)
{
	ros::init(argc, argv, "vehicle_control");
	ros::NodeHandle n;

	ros::Subscriber state_sub = n.subscribe<mavros_msgs::State>("mavros/state", 10, vehicleState);
//	ros::Subscriber position_sub = n.subscribe<geometry_msgs::PoseStamped>("mavros/local_positon/pose",10,positionPublish);
	ros::Publisher local_pos_pub = n.advertise<geometry_msgs::PoseStamped>("mavros/setpoint_position/local",10);
	ros::Publisher local_vel_pub = n.advertise<geometry_msgs::TwistStamped>("mavros/setpoint_velocity/local",10);
	ros::ServiceClient arming_client = n.serviceClient<mavros_msgs::CommandBool>("mavros/cmd/arming");
    ros::ServiceClient set_mode_client = n.serviceClient<mavros_msgs::SetMode>("mavros/set_mode");
    ros::ServiceClient takeoff_client = n.serviceClient<mavros_msgs::CommandTOL>("mavros/cmd/takeoff");

	ros::Rate rate(30.0);

	//Determine the connection
	while(ros::ok() && !vehicle_current_state.connected)
	{
	 	ros::spinOnce();
        rate.sleep();
	}

    //Determin the vehicle state
	if(ros::ok())
	{
	    mavros_msgs::SetMode guided_set_mode;
	    guided_set_mode.request.custom_mode = "GUIDED";
        if (vehicle_current_state.mode == "GUIDED" && vehicle_current_state.armed)
        {
  	     	ROS_INFO(" Vehicle is ready");
  			//break;
  		}
  		if(vehicle_current_state.mode != "GUIDED")
  		{
  			set_mode_client.call(guided_set_mode);
			ROS_INFO("The current mode is set to GUIDED");
  		}
  		mavros_msgs::CommandBool arm_cmd;
  		arm_cmd.request.value = true;
  		if(!vehicle_current_state.armed)
  		{
  			arming_client.call(arm_cmd);
   			ROS_INFO("The vehicle is Armed");
	  	} 
	    ros::spinOnce();
        rate.sleep();
	}

 //    mavros_msgs::CommandTOL takeoff_cmd;
	// takeoff_cmd.request.altitude = 2.0;
	// while(ros::ok())
	// {
	// 	int takeoff_state;
	// 	if (takeoff_state == 1)
	// 	{
	// 		ROS_INFO("It already takeoff.");
	// 		break;
	// 	}
	//     if (takeoff_client.call(takeoff_cmd) && takeoff_cmd.response.success)
	//     {
	//     	takeoff_state = 1;
	//     }
	//     ros::spinOnce();
 //        rate.sleep();
	// } 
	


	geometry_msgs::PoseStamped pose;
	pose.pose.position.x = 0;
	pose.pose.position.y = 0;
	pose.pose.position.z = 10;

	geometry_msgs::TwistStamped vel;

	for(int i = 100; ros::ok() && i > 0; -i){
		local_pos_pub.publish(pose);
		ros::spinOnce();
		rate.sleep();
	}



	//
	//geometry_msgs::TwistStamped vel;
	//vel.twist.linear.x = 5;
	//vel.twist.linear.y = 0;
	//vel.twist.linear.z = 5;
	//ros::Time last_request = ros::Time::now();
	//while(ros::ok())
	//{
		//if(ros::Time::now() - last_request > ros::Duration(5.0))
		//	break;
		//vel.twist.linear.x = 5;
		//vel.twist.linear.y = 0;
		//vel.twist.linear.z = 5;
	//	local_vel_pub.publish(vel);
	//	ros::spinOnce();
	//	rate.sleep();
		//break;
	//}
	//last_request = ros::Time::now();
	//while(ros::ok())
	//{
		//if(ros::Time::now() -last_request > ros::Duration(5.0))
		//	break;
	//	vel.twist.linear.x = 0;
	// 	vel.twist.linear.y = 1;
	// 	vel.twist.linear.z = 0;
	// 	local_vel_pub.publish(vel);
	// 	ros::spinOnce();
	// 	rate.sleep();
	// 	//break;
	// }
	// //last_request = ros::Time::now();
	// while(ros::ok())
	// {
	// 	//if(ros::Time::now() - last_request > ros::Duration(5.0))
	// 	//	break;
	// 	vel.twist.linear.x = -1;
	// 	vel.twist.linear.y = 0;
	// 	vel.twist.linear.z = 0;
	// 	local_vel_pub.publish(vel);
	// 	ros::spinOnce();
	// 	rate.sleep();
	// 	//break;
	// }
	// //last_request = ros::Time::now();
	// while(ros::ok())
	// {
	// 	//if(ros::Time::now() -last_request > ros::Duration(5.0))
	// 	//	break;
	// 	vel.twist.linear.x = 0;
	// 	vel.twist.linear.y = -1;
	// 	vel.twist.linear.z = 0;
	// 	local_vel_pub.publish(vel);
	// 	ros::spinOnce();
	// 	rate.sleep();
	// 	//break;
	// }
	//ros::spin();
    return 0;
}