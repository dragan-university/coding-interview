#!/usr/local/bin/python
#  -*- coding: utf-8 -*-
"""
http://www.geeksforgeeks.org/check-whether-a-given-string-is-an-interleaving-of-two-other-given-strings-set-2/
http://www.geeksforgeeks.org/dynamic-programming/

"""
DEBUG = False
RUN_ALL = True

def is_interleaved_r(a, b, c, memo):
    """
    recursive routine
    """
    if (a, b) in memo:
        return memo[(a, b)]

    if (b, a) in memo:
        return memo[(b,a)]

    if len(a) == 0:
        return b == c

    if len(b) == 0:
        return a == c

    result = False
    if a[0] == c[0]:
        result = is_interleaved_r(a[1:], b, c[1:], memo)

    if not result and b[0] == c[0]:
        result = is_interleaved_r(a, b[1:], c[1:], memo)

    memo[(a,b)] = result
    return result

def is_interleaved(a, b, c):
    """
    main routine

    only check if string lengths are ok, setup memo table (for memoization)
    and then call recursive function
    """
    if len(c) != len(a) + len(b):
        return False

    memo = {}

    return is_interleaved_r(a, b, c, memo)


def test_driver(a, b, c, expected_result):
    print('a = {}, b = {}, c={}, result={}'.format(a, b, c, expected_result))
    actual_result = is_interleaved(a, b, c)
    if actual_result == expected_result:
        print('PASS')
    else:
        print('FAIL: E={}, A={}'.format(expected_result, actual_result))
    
if RUN_ALL: test_driver('XXY', 'XXZ', 'XXZXXY', True)
if RUN_ALL: test_driver('XXY', 'XXZ', 'XXZYXX', False)
if RUN_ALL: test_driver(
    'YXXXXXXXXXX', 
    'XXXXXXXXXXX', 
    'XXXXXXXXXXXYXXXXXXXXXX', 
    True)
