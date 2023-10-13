"""
Description
"""
import traceback

DEBUG_LEVEL = 10

def solution(arg):
    """
    :type arg: str
    :rtype: int
    """
    if DEBUG_LEVEL > 5: print('{}'.format(arg))
    return 0

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
    test_driver('arg', 3)

test_01()
