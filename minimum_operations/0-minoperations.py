#!usr/bin/python3
"""
Module for finding the minimum number of operations to get n amount of Hs
"""


def minOperations(n):
    op = 0
    number = 2
    if type(n) is not int:
        return 0
    if n <= 1:
        return op
    while n > 1:
        if n % number == 0:
            op+= number
            n = n / number
        else:
            number += 1
    return(op)
