"""
Say that you are a traveler on a 2D grid. You begin in the top-left corner and
your goal is to travel to the botom-right corner. You may only move down and 
right.

In how many ways can you travel to the goal on a grid with dimensions m*n?
"""

"""
Time: O(m*n)
Space: O(m+n)
"""
def grid_traveler(m, n, memo={}):
    if m > n:
        m, n = n, m

    if m == 0:
        return 0

    if n == 1:
        return 1

    key = (m, n)

    if not key in memo:
        memo[key] = grid_traveler(m-1, n, memo) + grid_traveler(m, n-1, memo)

    return memo[key]

# tests
print(grid_traveler(1, 1))    # 1
print(grid_traveler(2, 3))    # 3
print(grid_traveler(3, 2))    # 3
print(grid_traveler(3, 3))    # 6
print(grid_traveler(18, 18))  # 2333606220
