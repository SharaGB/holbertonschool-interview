#!/usr/bin/python3
""" Determines if all the boxes can be opened. """


def canUnlockAll(boxes):
    """ Function that determine if all the boxes can be opened. """
    new_list = [0]
    for key in new_list:
        for box in boxes[key]:
            if box not in new_list and box < len(boxes):
                new_list.append(box)

    if len(new_list) == len(boxes):
        return True
    return False
