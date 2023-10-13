"""
min-abs-sum
"""
DEBUG_LEVEL = 10

"""
initial solution for which I got 54%

does not wotk for test case 02
"""
def solution(A):
    # we can assume thay all values are positive and sorted
    # since there is constant number of values this does not affect asymptotic
    # behaviour
    A = [abs(x) for x in A]

    mA = {}

    for x in A:
        if x in mA:
            mA[x] += 1
        else:
            mA[x] = 1

    keys = list(mA.keys())
    keys.sort(reverse=True)
    if DEBUG_LEVEL>5: print('mA keys: {}'.format(keys))

    # initial value is 0 or biggest value (depending if count of biggest value
    # is even or odd)
    abssum = 0
    if mA[keys[0]]%2:
         abssum = keys[0]

    for x in range(1, len(keys)):
        divide_abssum = int(abssum / keys[x])

        if divide_abssum >= mA[keys[x]]:
            abssum = abssum - mA[keys[x]]*keys[x]
        else:
            abssum = abssum % keys[x]
            if (mA[keys[x]]-divide_abssum) % 2:
                abssum = abs(abssum - keys[x])

    return abssum

"""
This solution should work for test case 2 too

Similar setup as first, using dictionary to store count of each value

But instead going from biggest to smallest value do the following.
Start with biggest value, same as in solution 1
Then go to smallest value and deduct until go into negative
Then add next biggest value and go again deducting smaller values
until all items are exausted.

So for  5, 4, 3, 3, 3 case it would go this way:

Start with 5
Deduct 3, total is 2 > 0
Deduct 3, total is -1 < 0
Add 4, total is 3 > 0
Deduct 3, total is 0
No more items

It would work for 5, 2, 2, 1 and 5, 2, 1, 1 too
"""
def solution2(A)
    pass

def test_driver(A, expected_result):
    print('A: {}, expected: {}'.format(A, expected_result))

    actual_result = solution(A)
    if (actual_result == expected_result):
        print('PASS')
    else:
        print('FAIL: actual={}'.format(actual_result))

def test_sample():
    test_driver([1,5,2,-2], 0)

def test_01():
    test_driver([1,5,2,-1], 1)

def test_02():
    test_driver([3,3,3,4,5], 0)

test_sample()
test_01()
test_02()
