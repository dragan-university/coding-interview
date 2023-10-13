"""
13 - https://www.interviewcake.com/question/python/find-rotation-point?
"""
import traceback

DEBUG_LEVEL = 0

def solution(words):
    """
    :type: words - list of str
    :rtype: int - index
    """
    if DEBUG_LEVEL > 5: print('{}'.format(words))
    lidx = 0
    ridx = len(words) - 1

    if words[ridx] > words[lidx]:
        return 0

    while lidx < ridx - 1:
        if DEBUG_LEVEL > 5: print('{} - {}'.format(lidx, ridx))
        midx = int((ridx+lidx)/2)

        if words[midx] < words[ridx]:
            ridx = midx
        else:
            lidx = midx

    return ridx

def test_driver(data, expected):
    test_name = traceback.extract_stack(None, 2)[0][2]
    print('=== {} ==='.format(test_name))
    print('data: {}, expected: {}'.format(data, expected))

    actual = solution(data)
    if actual == expected:
        print('PASS')
    else:
        print('FAIL: actual={}'.format(actual))
    print()

def test_01():
    test_driver(['d', 'a', 'b', 'c'], 1)

def test_01_1():
    test_driver(['h', 'a', 'b', 'c', 'd'], 1)

def test_02():
    test_driver(['d', 'e', 'f', 'g', 'a', 'b', 'c'], 4)

def test_02_1():
    test_driver(['d', 'e', 'f', 'g', 'a', 'b', 'c', 'cc'], 4)

def test_03():
    test_driver(['d', 'e', 'f', 'g', 'h', 'a', 'b', 'c'], 5)

def test_04():
    test_driver(['a', 'b', 'c'], 0)

test_01()
test_01_1()
test_02()
test_02_1()
test_03()
test_04()
