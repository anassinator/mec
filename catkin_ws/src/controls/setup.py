#!/usr/bin/env python

"""Controls ROS package setup."""

from distutils.core import setup
from catkin_pkg.python_setup import generate_distutils_setup

d = generate_distutils_setup(
    packages=["controls"],
    package_dir={"": "src"}
)

setup(**d)