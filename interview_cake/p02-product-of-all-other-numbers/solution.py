"""
2 - product of all other numbers
https://www.interviewcake.com/question/python/product-of-other-numbers
"""
DEBUG_LEVEL = 10

def product(arr):
    out_arr = []

    up_arr = [1]
    down_arr = [1]

    up_product = 1
    down_product = 1

    for ix in range(len(arr)-1):
        if DEBUG_LEVEL>5: print('arr[{0}]={1}, arr[-{0}]={2}'.format(ix, arr[ix], arr[-ix-1]))
        up_product *= arr[ix]
        down_product *= arr[-ix-1]
        if DEBUG_LEVEL>5: print('up_product={}, down_product={}'.format(up_product, down_product))

        up_arr.append(up_product)
        down_arr.insert(0, down_product)
        if DEBUG_LEVEL>5: print('up_arr={}, down_arr={}'.format(up_arr, down_arr))

    for ix in range(len(arr)):
        out_arr.append(up_arr[ix] * down_arr[ix])

    return out_arr

def test_driver(arr, expected_result):
    print('arr: {}, expected: {}'.format(arr, expected_result))

    actual_result = product(arr)
    if (actual_result == expected_result):
        print('PASS')
    else:
        print('FAIL: actual={}'.format(actual_result))

def test_sample():
    test_driver([1, 7, 3, 4], [84, 12, 28, 21])

def test_01():
    test_driver([1, 2, 3], [6, 3, 2])

test_sample()
