#!/usr/bin/python

from math import sin

pi = 3.1415

inc = (2*pi) / 1024
items = 1
theta = 0.0
while (theta < 2*pi):
    print 64 + int(64 * sin(theta))
    theta = theta + inc
    items = items + 1
