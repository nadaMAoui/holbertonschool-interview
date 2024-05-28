#!/usr/bin/python3
"""
Module for finding the minimum number of operations to get n amount of Hs
"""


def minOperations(n):
    """
    Function that finds le minimum number of operations to get n amount of Hs
    """
    if type(n) is not int:
        return 0
    if n <= 1:
        return 0

    ops = 0
    chars = 1
    copy = 1

    while chars < n:
        if n % chars == 0:
            copy = chars
            ops += 1
        if chars != n:
            chars += copy
            ops += 1
        else:
            break

    return ops
