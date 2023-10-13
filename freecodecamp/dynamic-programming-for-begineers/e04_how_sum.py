"""
Write a function 'how_sum(target_sum, numbers)' that takes in a target_sum and 
an array of numbers as arguments.

The function should return an array containing any combination of elements that
add up to exctly the target_sum. If there is no combination that adds up to the 
target_sum, then return null.

If there are multiple combinations possible, you may return any single one.

You may use an element of the array as many times as needed.

Yoiu may assume that all input numbers are nonnegative.
"""

def how_sum(target_sum, numbers, solution):
    if target_sum < 0:
        return False

    if target_sum == 0:
        return True

    result = False

    for number in numbers:
        solution.append(number)
        result = result or how_sum(target_sum-number, numbers, solution)
        if result:
            break
        else:
            solution.remove(number)

    return result

def test_how_sum(target_sum, numbers):
    solution = []
    how_sum(target_sum, numbers, solution)
    print(solution)

#tests
test_how_sum(7, [5,4,3,7,2])
test_how_sum(7, [2,4])
test_how_sum(7, [1])
test_how_sum(7, [5,4,3])
# print(how_sum(300, [7, 14]))
