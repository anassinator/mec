#! /usr/bin/env python
# -*- coding: utf-8 -*-

"""MEC controls node."""

import rospy
from mec.motor import Motor

if __name__ == "__main__":
    rospy.init_node("controls")
    m = Motor()
    rospy.spin()
