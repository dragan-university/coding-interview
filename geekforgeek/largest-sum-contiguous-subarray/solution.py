#!/usr/local/bin/python
#  -*- coding: utf-8 -*-
"""
http://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
http://www.geeksforgeeks.org/dynamic-programming/

Largest Sum Contiguous Subarray

Write an efficient C program to find the sum of contiguous subarray within a 
one-dimensional array of numbers which has the largest sum.
"""
DEBUG = True
RUN_ALL = True

def largest_sum(array):
    """
    array
    """
    largest_sum = array[0]
    running_sum = array[0]

    for i in range(1, len(array)):
        running_sum = max(running_sum+array[i], array[i])
        largest_sum = max(largest_sum, running_sum)
        if DEBUG: print('{}: ls={}, rs={}'.format(i, largest_sum, running_sum))

    return largest_sum

def test_driver(array, expected_result):
    print('array = {}, result={}'.format(array, expected_result))
    _largest_sum = largest_sum(array)
    if _largest_sum == expected_result:
        print('PASS')
    else:
        print('FAIL: E={}, A={}'.format(expected_result, _largest_sum))
    
if RUN_ALL: test_driver([-2,-3,4,-1,-2,1,5,-3], 7)
if RUN_ALL: test_driver([-2,-3,-1,-2,-3], -1)
