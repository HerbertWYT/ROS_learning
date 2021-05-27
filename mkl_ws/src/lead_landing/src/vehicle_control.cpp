#include <ros/ros.h>
#include <mavros_msgs/State.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/CommandTOL.h>


mavros_msgs::State vehicle_current_state;
void vehicleState(const mavros_msgs::State::ConstPtr& msg){
    vehicle_current_state = *msg;
}




int main(int argc, char **argv)
{
	ros::init(argc, argv, "vehicle_control");
	ros::NodeHandle n;

	ros::Subscriber state_sub = n.subscribe<mavros_msgs::State>("mavros/state", 10, vehicleState);
	//ros::Publisher vehicle_control_pub = n.advertise<mavros_msgs:State>("mavros/state",10);
	ros::ServiceClient arming_client = n.serviceClient<mavros_msgs::CommandBool>("mavros/cmd/arming");
    ros::ServiceClient set_mode_client = n.serviceClient<mavros_msgs::SetMode>("mavros/set_mode");
    ros::ServiceClient takeoff_client = n.serviceClient<mavros_msgs::CommandTOL>("mavros/cmd/takeoff");

	ros::Rate rate(10.0);

	//Determine the connection
	// while(ros::ok() && !vehicle_current_state.connected)
	// {
	// 	ros::spinOnce();
 //        rate.sleep();
	// }

	//while(ros::ok())
	//{
		mavros_msgs::SetMode guided_set_mode;
		guided_set_mode.request.custom_mode = "GUIDED";

		mavros_msgs::CommandBool arm_cmd;
		arm_cmd.request.value = true;

		mavros_msgs::CommandTOL takeoff_cmd;
		takeoff_cmd.request.altitude = 2.0;

		if(vehicle_current_state.mode != "GUIDED")
		{
			set_mode_client.call(guided_set_mode);
			if(vehicle_current_state.mode == "GUIDED")
			{
				ROS_INFO("GUIDED mode enable");
			}
		}
		else
		{
			ROS_INFO("The current flight mode is %s", vehicle_current_state.mode.c_str());
		}
		if(!vehicle_current_state.armed)
		{
			arming_client.call(arm_cmd);
			if(vehicle_current_state.armed)
			{
				ROS_INFO("The Copter is armed");
			}
		}
		else
		{
			ROS_INFO("The Copter is already armed");
		}

		ros::spinOnce();


		
		takeoff_client.call(takeoff_cmd);

	//}

	



	//mavros_msgs::SetMode guided_set_mode;
    //guided_set_mode.request.custom_mode = "GUIDED";

    //mavros_msgs::CommandBool arm_cmd;
    //arm_cmd.request.value = true;

    //ros::Time last_request = ros::Time::now();

    //while(ros::ok())
    //{
    	// if (current_state.mode != "GUIDED" && (ros::Time::now() - last_request > ros::Duration(5.0)))
    	// {
    	// 	if(set_mode_client.call(guided_set_mode) && guided_set_mode.response.mode_sent)
    	// 	{
    	// 		ROS_INFO("Guided Mode Enabled!");
    	// 	}
    	// }
    	// else
    	// {
    	// 	if (!current_state.armed && (ros::Time::now() - last_request > ros::Duration(5.0)))
    	// 	{
    	// 		if (arming_client.call(arm_cmd) && arm_cmd.response.success)
    	// 		{
    	// 			ROS_INFO("Vehicle armed");
    	// 		}
    	// 	}
    	// }

    // 	ros::spinOnce();
    //     rate.sleep();
    // }

    return 0;
}