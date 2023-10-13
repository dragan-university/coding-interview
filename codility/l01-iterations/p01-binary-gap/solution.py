"""
binary-gap
"""
DEBUG_LEVEL = 0

def solution(N):
    maxgap = 0
    curgap = 0
    border = False

    while N:
        if not border:
            if N%2:
                border = True
        else:
            if N%2:
                maxgap = max(maxgap, curgap)
                curgap = 0
            else:
                curgap += 1

        N = int(N/2)

    return maxgap

def test_driver(N, expected_result):
    print('N: {}, expected: {}'.format(N, expected_result))

    actual_result = solution(N)
    if (actual_result == expected_result):
        print('PASS')
    else:
        print('FAIL: actual={}'.format(actual_result))

def test_sample():
    test_driver(9, 2)

def test_01():
    test_driver(529, 4)

def test_02():
    test_driver(20, 1)

test_sample()
test_01()
test_02()