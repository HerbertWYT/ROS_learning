#!/usr/bin/env python

import sys
import rospy
from learning_service.srv import Person, PersonResponse


def personCallback(req):

    rospy.loginfo("Person: name:%s age:%d sex:%s", req.name, req.age, req.sex)

    return PersonResponse("OK")


def person_server():
    rospy.init_node("person_server")

    s = rospy.Service("/show_person", Person, personCallback)

    print("Ready to show person information")
    rospy.spin()


if __name__ == "__main__":
    person_server()
