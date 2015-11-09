# -*- coding: utf-8 -*-

"""MEC motor."""


class Motor(object):

    """Motor class."""

    MIN_VELOCITY = 0
    MAX_VELOCITY = 255

    def __init__(self, tune):
        self.tune = tune
        self.__velocity = 0
        self.__direction = 1

    def forward(self, v):
        self.velocity = v
        self.__direction = 1

    def backward(self, v):
        self.velocity = v
        self.__direction = -1

    @property
    def velocity(self):
        return self.__velocity

    @velocity.setter
    def velocity(self, v):
        if v <= 0:
            self.__velocity = int(max(Motor.MIN_VELOCITY, v))
        else:
            self.__velocity = int(min(v, Motor.MAX_VELOCITY))

    def stop(self):
        self.__velocity = 0

    def to_msg(self):
        return int(self.tune * self.__direction * self.__velocity)
