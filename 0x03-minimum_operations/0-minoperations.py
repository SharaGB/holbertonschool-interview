#!/usr/bin/python3
""" Calculates the fewest number of operations needed to
result in exactly n H characters in the file """


def minOperations(n):
    """ Calculates the fewest number of operations needed to """
    count = 0
    i = 2

    while i <= n:
        while n % i == 0:
            count += i
            n = n / i
        i += 1
    return count
