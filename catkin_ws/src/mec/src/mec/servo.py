# -*- coding: utf-8 -*-

"""MEC servo."""


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
            self.__angle = int(max(Servo.MIN_ANGLE, theta))
        else:
            self.__angle = int(min(theta, Servo.MAX_ANGLE))

    def to_msg(self):
        return int(self.__angle)
