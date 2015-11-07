# -*- coding: utf-8 -*-

"""MEC motor."""

from std_msgs.msg import Int16


class Motor(object):

    """Motor class."""

    MIN_VELOCITY = -255
    MAX_VELOCITY = 255

    def __init__(self):
        self.__velocity = 0

    @property
    def velocity(self):
        return self.__velocity

    @velocity.setter
    def velocity(self, v):
        if v < 0:
            self.__velocity = max(Motor.MIN_VELOCITY, v)
        else:
            self.__velocity = min(v, Motor.MAX_VELOCITY)

    def serialize(self):
        return Int16(self.__velocity)
