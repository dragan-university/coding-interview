"""
14 - https://www.interviewcake.com/question/python/inflight-entertainment?
"""
import traceback

DEBUG_LEVEL = 0

def solution(flight_length, movie_lengths):
    """
    :type flight_length: int
    :type movie_lengths: list of int
    :rtype: bool
    """
    if DEBUG_LEVEL > 5: print('{}'.format(flight_length))
    movie_lengths_d = {}
    for ml in movie_lengths:
        if (flight_length - ml) in movie_lengths_d:
            return True

        movie_lengths_d[ml] = True

    return False

def test_driver(fl, ml, expected):
    test_name = traceback.extract_stack(None, 2)[0][2]
    print('=== {} ==='.format(test_name))
    print('fl: {}, ml: {}, expected: {}'.format(fl, ml, expected))

    actual = solution(fl, ml)
    if actual == expected:
        print('PASS')
    else:
        print('FAIL: actual={}'.format(actual))
    print()

def test_01p():
    test_driver(42, [20, 30, 18, 12, 14], True)

def test_01n():
    test_driver(42, [20, 30, 18, 16, 14], False)

test_01p()
test_01n()
