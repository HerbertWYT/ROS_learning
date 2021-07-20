#!/usr/bin/env python

import sys
import rospy
from learning_service.srv import Person, PersonRequest


def person_client():

    rospy.init_node("person_client")

    rospy.wait_for_service("/show_person")
    try:
        person_client = rospy.ServiceProxy("/show_person", Person)

        response = person_client("Tom", 20, PersonRequest.male)
        return response.result
    except rospy.ServiceException as e:
        print("service call failed: %s" % e)


if __name__ == "__main__":
    print("Show person reuslt : %s" % (person_client()))
