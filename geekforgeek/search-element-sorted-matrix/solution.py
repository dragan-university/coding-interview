"""
http://www.geeksforgeeks.org/search-element-sorted-matrix/
"""
import traceback
import time

DEBUG_LEVEL = 0

def solution(M, x):
    """
    Find if 'x' is in sorted matrix 'M'

    :type M: matrix of int - sorted matrix
    :type x: int - number to find
    :rtype: tuple - element if exist otherwise None
    """
    rows = len(M)
    cols = len(M[0])
    if DEBUG_LEVEL>11: print('rows:{} -- cols:{}'.format(rows, cols))

    lidx = 0
    ridx = rows*cols-1
    while lidx < ridx-1:
        midx = int((lidx+ridx)/2)
        if DEBUG_LEVEL>5: 
            print('l:{} -- r:{} -- m:{}'.format(lidx, ridx, midx))
            #time.sleep(2)
        rx = int(midx/cols)
        cx = midx%cols

        if M[rx][cx] == x:
            return (rx, cx)

        if M[rx][cx] < x:
            lidx = midx
        else:
            ridx = midx

    rx = int(lidx/cols)
    cx = lidx%cols
    if M[rx][cx] == x:
        return (rx, cx)

    rx = int(ridx/cols)
    cx = ridx%cols
    if M[rx][cx] == x:
        return (rx, cx)

    return None

def test_driver(data, x, expected):
    test_name = traceback.extract_stack(None, 2)[0][2]
    print('=== {} ==='.format(test_name))
    print('data: {}, x: {}, expected: {}'.format(data, x, expected))

    actual = solution(data, x)
    if actual == expected:
        print('PASS')
    else:
        print('FAIL: actual={}'.format(actual))
    print()

def test_01():
    M = [
        [1,5,9],
        [14,20,21],
        [30,34,43]
    ]
    x = 14
    test_driver(M, x, (1,0))

def test_02():
    M = [
        [1,5,9],
        [14,20,21],
        [30,34,43],
        [55,58,69],
    ]
    x = 14
    test_driver(M, x, (1,0))

def test_03():
    M = [
        [1,5,9],
        [14,20,21],
        [30,34,43],
        [55,58,69],
    ]
    x = 15
    test_driver(M, x, None)

def test_04():
    M = [
        [1,5,9],
        [14,20,21],
        [30,34,43],
        [55,58,69],
    ]
    x = 1
    test_driver(M, x, (0,0))

def test_05():
    M = [
        [1,5,9],
        [14,20,21],
        [30,34,43],
        [55,58,69],
    ]
    x = 69
    test_driver(M, x, (3,2))

def test_06():
    M = [
        [1,5,9],
        [14,20,21],
        [30,34,43],
        [55,58,69],
    ]
    x = 100
    test_driver(M, x, None)

test_01()
test_02()
test_03()
test_04()
test_05()
test_06()