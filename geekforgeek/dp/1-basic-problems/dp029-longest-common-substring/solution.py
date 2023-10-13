#!/usr/local/bin/python
#  -*- coding: utf-8 -*-
"""
https://www.geeksforgeeks.org/longest-common-substring-dp-29/
http://www.geeksforgeeks.org/dynamic-programming/

"""
DEBUG = False
RUN_ALL = True

def is_substring(x, s):
    for i in range(len(s) - len(x)):
        if x == s[i:i+len(x)]:
            return True

    return False

def lcs(a, b):
    """
    btute force
    """
    if len(b) < len(a):
        a, b = b, a

    for i in range(len(b), 0, -1):
        for j in range(len(b) - i):
            if is_substring(b[j:j+i], a):
                return i

    return 0

def lcs_dp(a, b):
    """
    dp
    """
    max_lcs = 0

    m = [0]*len(a)

    for i in range(len(b)):
        n = [0]*len(a)
        for j in range(len(a)):
            if a[j] == b[i]:
                if j > 0:
                    n[j] = m[j-1] + 1
                else:
                    n[j] = 1
            else:
                n[j] = 0

            max_lcs = max(max_lcs, n[j])

        m = n

    return max_lcs


def test_driver(a, b, expected_result):
    print('a = {}, b = {}, result={}'.format(a, b, expected_result))
    actual_result = lcs_dp(a, b)
    if actual_result == expected_result:
        print('PASS')
    else:
        print('FAIL: E={}, A={}'.format(expected_result, actual_result))
    
if RUN_ALL: test_driver('XXYZZYXXX', 'TTYZZYTT', 4)
if RUN_ALL: test_driver('XXY', 'TTZ', 0)
if RUN_ALL: test_driver('XXXXXYXXXXX', 'TTYYYYYYYYYY', 1)
