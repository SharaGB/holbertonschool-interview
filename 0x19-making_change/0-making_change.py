#!/usr/bin/python3
"""
makeChange module
"""


def makeChange(coins, total):
    """
    makeChange function
    """
    if total == 0:
        return 0
    if total < 0 or len(coins) == 0:
        return - 1
    if len(coins) == 1 and total in coins:
        return 1

    nums = [float('inf') for x in range(total+1)]
    nums[0] = 0
    for denom in coins:
        for amount in range(len(nums)):
            if denom <= amount:
                nums[amount] = min(nums[amount], 1 + nums[amount - denom])
    return nums[total] if nums[total] != float('inf') else - 1
