#!/bin/python3
"""
DP solution as explained by Tushar Roy
https://www.youtube.com/watch?v=_fgjrs570YE&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=10
--------------------------------------
coins: c[0],..., c[m-1]

S[i,j] - number of ways to make change on the amount 'j' with coins c[0],...,c[i-1]
S[0,j] = 0, j=0,1,2,...,n
S[i,0] = 1, i=0,1,2,...,m
S[i,j] = S[i-1,j], if c[i-1]>j
S[i,j] = S[i,j-c[i-1]] + S[i-1,j], if c[i-1]<=j

"""

DEBUG = False

def print_dp_matrix(dp_matrix):
    for ix in range(len(dp_matrix)):
        for iy in range(len(dp_matrix[0])):
             print(dp_matrix[ix][iy])
        
        print()
    print()

# Tushan Roy's DP solution
def dp_coin_change(amount, coins):
    dp_matrix = []

    for ix in range(len(coins)):
        if DEBUG: print('coin ', coins[ix])
        dp_matrix.append([1])

    value = 1
    while value<=amount:
        if value % coins[0]:
            dp_matrix[0].append(0)
        else:
            dp_matrix[0].append(1)

        value += 1

    for ix in range(1, len(coins)):
        if DEBUG: print('coin = ', coins[ix])
        for iy in range(1, amount+1):
            if DEBUG: print(" amount:", iy)
            count = dp_matrix[ix-1][iy]

            if iy >= coins[ix]:
                count += dp_matrix[ix][iy-coins[ix]]

            if DEBUG: print(count, "-")
            dp_matrix[ix].append(count)
        
        if DEBUG: print()

    # if DEBUG: print_dp_matrix(dp_matrix)
    return dp_matrix[len(coins)-1][amount]


def test_coin_change(amount, coins, expected_result):
    actual_result = dp_coin_change(amount, coins)
    if actual_result == expected_result:
        print(" PASS")
    else:
        print(" FAIL: E:", expected_result, " A:", actual_result)

    print('')


def test_hr_sample():
    amount = 4
    coins = [1,2,3]

    test_coin_change(amount, coins, 4)


def test_hr_02():
    amount = 166
    coins = [5, 37, 8, 39, 33, 17, 22, 32, 13, 7, 10, 35, 40, 2, 43, 49, 46, 19, 41, 1, 12, 11, 28]

    test_coin_change(amount, coins, 96190959)


def test_hr_09():
    amount = 250
    coins = [41, 34, 46, 9, 37, 32, 42, 21, 7, 13, 1, 24, 3, 43, 2, 23, 8, 45, 19, 30, 29, 18, 35, 11]

    test_coin_change(amount, coins, 15685693751)


def hackerrank():
    n,m = input().strip().split(' ')
    n,m = [int(n),int(m)]
    coins = [int(coins_temp) for coins_temp in input().strip().split(' ')]
    print(dp_coin_change(n, coins))


#hackerrank()
#test_hr_sample()
#test_hr_02()
test_hr_09()

