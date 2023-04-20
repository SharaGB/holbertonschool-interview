#!/usr/bin/python3
""" Rain excercise """


def rain(walls):
    """ Calculate contained raindrops """
    raindrops = 0
    if len(walls) < 1:
        return 0
    for i in range(len(walls)):
        # Find the maximum element on its left
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])

        # Find the maximum element on its right
        right = walls[i]
        for j in range(i + 1, len(walls)):
            right = max(right, walls[j])

        # Update the maximum water
        raindrops += min(left, right) - walls[i]
    return raindrops
