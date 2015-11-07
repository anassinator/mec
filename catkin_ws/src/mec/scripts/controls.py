#! /usr/bin/env python
# -*- coding: utf-8 -*-

"""MEC controls node."""

import rospy
from mec.motor import Motor
from mec.servo import Servo
from mec.msg import Command
from std_msgs.msg import Int16
from geometry_msgs.msg import Twist


left_motor = Motor(1.0)
right_motor = Motor(1.3)
servo = Servo()
velocity = 255


def publish():
    cmd = Command()
    cmd.left_velocity = left_motor.to_msg()
    cmd.right_velocity = right_motor.to_msg()
    cmd.servo = servo.to_msg()
    pub.publish(cmd)


def servo_cb(msg):
    servo.angle = msg.data
    publish()


def keyboard_cb(msg):
    linear_rate = abs(msg.linear.x)
    angular_rate = abs(msg.angular.z)

    # No rotation.
    if not msg.angular.z:
        if msg.linear.x > 0:
            left_motor.forward(linear_rate * velocity)
            right_motor.forward(linear_rate * velocity)
        elif msg.linear.x < 0:
            left_motor.backward(linear_rate * velocity)
            right_motor.backward(linear_rate * velocity)
        else:
            left_motor.stop()
            right_motor.stop()
    # Left.
    elif msg.angular.z > 0:
        if msg.linear.x > 0:
            left_motor.forward(angular_rate * velocity / 2)
            right_motor.forward(angular_rate * velocity)
        elif msg.linear.x < 0:
            left_motor.backward(angular_rate * velocity / 2)
            right_motor.backward(angular_rate * velocity)
        else:
            left_motor.backward(angular_rate * velocity)
            right_motor.forward(angular_rate * velocity)
    # Right.
    elif msg.angular.z < 0:
        if msg.linear.x > 0:
            left_motor.forward(angular_rate * velocity)
            right_motor.forward(angular_rate * velocity / 2)
        elif msg.linear.x < 0:
            left_motor.backward(angular_rate * velocity)
            right_motor.backward(angular_rate * velocity / 2)
        else:
            left_motor.forward(angular_rate * velocity)
            right_motor.backward(angular_rate * velocity)

    publish()


if __name__ == "__main__":
    rospy.init_node("controls")
    rospy.Subscriber("/key_vel", Twist, keyboard_cb, queue_size=1)
    rospy.Subscriber("/servo", Int16, servo_cb, queue_size=1)
    pub = rospy.Publisher("/controls", Command, queue_size=1)
    rospy.spin()
