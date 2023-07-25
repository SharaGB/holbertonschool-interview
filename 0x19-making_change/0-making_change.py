#!/usr/bin/python3
"""
Make change module
"""


def makeChange(coins, total):
    """Given a pile of coins of different values,
    determine the fewest number of coins
    needed to meet a given amount 'total'

    Args:
        coins ([list]): a list of the values of the coins in your possession
        total ([number]): amount
    Return: fewest number of coins needed to meet total
    """
    if total <= 0:
        return 0

    coins.sort(reverse=True)

    i, ncoins = (0, 0)
    cpy_total = total
    len_coins = len(coins)

    while(i < len_coins and cpy_total > 0):
        if (cpy_total - coins[i]) >= 0:
            cpy_total -= coins[i]
            ncoins += 1
        else:
            i += 1

    check = cpy_total > 0 and ncoins > 0
    return -1 if check or ncoins == 0 else ncoins
