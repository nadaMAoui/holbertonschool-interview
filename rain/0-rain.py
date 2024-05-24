#!/usr/bin/python3
'''Rain trapping module'''


def rain(walls):
    '''Function that calculates the water collected in a list of walls'''
    total_water = 0
    for i in range(len(walls)):
        lft_wall = 0
        rgt_wall = 0
        cur_water = 0
        for l in range(i, -1, -1):
            if walls[l] > lft_wall:
                lft_wall = walls[l]
        for r in range(i, len(walls)):
            if walls[r] > rgt_wall:
                rgt_wall = walls[r]
        if rgt_wall < lft_wall:
            cur_water = rgt_wall - walls[i]
        else:
            cur_water = lft_wall - walls[i]
        if cur_water > 0:
            total_water += cur_water

    return total_water
