"""
Write a function 'can_sum(target_sum, numbers)' that takes in a target_sum and 
an array of numbers as arguments.

The function should return a boolean indicating whether or not it is possible to
generate the target_sum using numbers from the array.

You may use an element of the array as many times as needed.

Yoiu may assume that all input numbers are nonnegative.
"""

def can_sum_slow(target_sum, numbers):
    if target_sum < 0:
        return False

    if target_sum == 0:
        return True

    for number in numbers:
        result = can_sum(target_sum-number, numbers)

        if result:
            return True

    return False

def can_sum(target_sum, numbers, memo={}):
    print("{}:{}:{}".format(target_sum, numbers, memo))
    if target_sum in memo:
        return memo[target_sum]

    if target_sum < 0:
        return False

    if target_sum == 0:
        return True

    for number in numbers:
        result = can_sum(target_sum-number, numbers, memo)

        if result:
            memo[target_sum] = result
            return True

    memo[target_sum] = False
    return False

#tests
print(can_sum(7, [5,4,3,7], {}))
print(can_sum(7, [2,4], {}))
# print(can_sum(7, [1]))
# print(can_sum(7, [5,4,3]))
# print(can_sum(300, [7, 14]))
