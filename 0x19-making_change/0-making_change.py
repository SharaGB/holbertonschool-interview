#!/usr/bin/python3
"""
makeChange module
"""


def makeChange(coins, total):
    """
    makeChange function
    """
    if total <= 0:
        return 0

    newVal = total + 1
    store = {0: 0}

    for i in range(1, total + 1):
        store[i] = newVal

        for coin in coins:
            current = i - coin
            if current < 0:
                continue

            store[i] = min(store[current] + 1, store[i])

    if store[total] == total + 1:
        return -1

    return store[total]
