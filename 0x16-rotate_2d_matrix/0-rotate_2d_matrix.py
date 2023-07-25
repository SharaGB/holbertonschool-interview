#!/usr/bin/python3
"""
Module rotate_2d_matrix method
"""


def rotate_2d_matrix(matrix):
    """Method that rotate it 90 degrees clockwise of a n x n matrix"""
    list_vals = list(zip(*matrix[::-1]))
    for y in range(len(list_vals)):
        for i in range(len(list_vals)):
            matrix[y][i] = list_vals[y][i]
