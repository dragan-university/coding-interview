"""
12 - find in ordered set
https://www.interviewcake.com/question/python/find-in-ordered-set

This is basically binary search, which is lgN
"""
import traceback

DEBUG_LEVEL = 10

def solution(sorted_list, number_to_find):
    """
    :type sorted_list: list
    :type number_to_find: number
    :rtype: bool
    """
    lidx = 0
    ridx = len(sorted_list)-1

    while lidx < ridx-1:
        midx = int((lidx+ridx)/2)
        if DEBUG_LEVEL>5: print('lidx={}, ridx={}, midx={}'.format(lidx, ridx, midx))

        if sorted_list[midx] == number_to_find:
            return True

        if sorted_list[midx] < number_to_find:
            lidx = midx
        else:
            ridx = midx

    if number_to_find == sorted_list[ridx]:
        return True

    if number_to_find == sorted_list[lidx]:
        return True

    return False

def test_driver(data, number_to_find, expected):
    test_name = traceback.extract_stack(None, 2)[0][2]
    print('=== {} ==='.format(test_name))
    print('data: {}, number: {}, expected: {}'.format(data, number_to_find, expected))

    actual = solution(data, number_to_find)
    if actual == expected:
        print('PASS')
    else:
        print('FAIL: actual={}'.format(actual))
    print()

def test_01():
    test_driver([1,2,3], 2, True)

def test_02():
    test_driver([1,3], 2, False)

def test_03():
    test_driver([1,2], 2, True)

def test_04():
    test_driver([1,2], 1, True)

def test_05_1():
    test_driver([1,2,3,4,5,6,7], 7, True)

def test_05_2():
    test_driver([1,2,3,4,5,6,7], 1, True)

test_01()
test_02()
test_03()
test_04()
test_05_1()
test_05_2()
