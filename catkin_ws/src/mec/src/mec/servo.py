# -*- coding: utf-8 -*-

"""MEC servo."""

from std_msgs.msg import Int16


class Servo(object):

    """Servo class."""

    MIN_ANGLE = 0
    MAX_ANGLE = 180

    def __init__(self):
        self.__angle = 0

    @property
    def angle(self):
        return self.__angle

    @angle.setter
    def angle(self, theta):
        if theta <= 0:
            self.__angle = max(Servo.MIN_ANGLE, theta)
        else:
            self.__angle = min(theta, Servo.MAX_ANGLE)

    def serialize(self):
        return Int16(self.__angle)
