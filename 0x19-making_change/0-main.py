#!/usr/bin/python3
"""
Main file for testing
"""


import sys


makeChange = __import__('0-making_change').makeChange

print(makeChange([507, 500, 300, 200, 6, 5, 4, 3], 1413))
