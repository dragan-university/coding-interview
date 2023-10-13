#!/usr/local/bin/python
#  -*- coding: utf-8 -*-
"""
http://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/

DP solution:
    n = amount
    c[1] < c[2] < ... < c[m] = coins

    mc(n) = min{mc(n-c[i])}, i=1,m & n-c[i] >= 0

    mc(0) = 0

    mc(1):
        1, if c[1] = 1
        0, otherwise

    mc(2):
        2, if c[1]=1 and c[2]!=2
        1, if there is j such that c[j] = 2
        0, if c[1] > 2
"""
DEBUG = False
RUN_ALL = True

def make_change(amount, coins):
    """
    amount - amount to make change
    coins - available coins

    return: minumum number of coins to make amount 
    """
    if DEBUG: print('amount: {}'.format(amount))
    # array holding min count for all sub-amounts and amount itself
    mc = [0]*(amount+1)

    # starting from 0 count all sub-amounts
    sub_amount = 0
    while (sub_amount <= amount):
        coin_index = 0
        min_coins_count = 0
        if DEBUG: print('sub_amount: {}'.format(sub_amount))
        # for current sub-amount find solution that involves current coin
        while (coin_index < len(coins) and coins[coin_index] <= sub_amount):
            if DEBUG: print('coin_index: {}, coin: {}'.format(coin_index, coins[coin_index]))
            if not min_coins_count:
                if (mc[sub_amount-coins[coin_index]] > 0):
                    min_coins_count = mc[sub_amount-coins[coin_index]] + 1
                elif (sub_amount % coins[coin_index] == 0):
                    min_coins_count = sub_amount / coins[coin_index]
                if DEBUG: print('init mc: {}'.format(min_coins_count))
            else:   
                if DEBUG: print('subamount={}, coin_index={}'.format(sub_amount, coin_index))       
                if (mc[sub_amount-coins[coin_index]] > 0):
                    if ((mc[sub_amount-coins[coin_index]] + 1) < min_coins_count):
                        min_coins_count = mc[sub_amount-coins[coin_index]] + 1
                    if DEBUG: print('smaller mc: {}'.format(min_coins_count))
                elif (sub_amount % coins[coin_index] == 0):
                    if ((sub_amount / coins[coin_index]) < min_coins_count):
                        min_coins_count = sub_amount / coins[coin_index]
                if DEBUG: print('init mc: {}'.format(min_coins_count))

            coin_index += 1

        mc[sub_amount] = min_coins_count
        if DEBUG: print('mc[{}]={}'.format(sub_amount, mc[sub_amount]))
        sub_amount += 1

    if DEBUG: print('min count is: ', mc[amount])
    return mc[amount]

def test_driver(amount,coins, expected_result):
    print('amount = {}, coins = {}'.format(amount, coins))
    min_count = make_change(amount, coins)
    print('min_count = {}'.format(min_count))
    if min_count == expected_result:
        print('PASS')
    else:
        print('FAIL: E={}, A={}'.format(expected_result, min_count))
    
def test_05_1():
    test_driver(1, [1,2,5], 1)

def test_05_2():
    test_driver(2, [1,2,5], 1)

def test_05_5():
    test_driver(5, [1,2,5], 1)

def test_05_6():
    test_driver(6, [1,2,5], 2)

def test_05_8():
    test_driver(8, [1,2,5], 3)

def test_05_10():
    test_driver(10, [1,2,5], 2)

def test_10_1():
    test_driver(1, [2,5], 0)

def test_10_3():
    test_driver(3, [2,5], 0)

def test_10_4():
    test_driver(4, [2,5], 2)

def test_20_5():
    test_driver(5, [2,4,9], 0)

def test_20_8():
    test_driver(8, [2,4,9], 2)

def test_20_11():
    test_driver(11, [2,4,9], 2)

if RUN_ALL: test_05_1()
if RUN_ALL: test_05_2()
if RUN_ALL: test_05_5()
if RUN_ALL: test_05_6()
if RUN_ALL: test_05_8()
if RUN_ALL: test_05_10()
if RUN_ALL: test_10_1()
if RUN_ALL: test_10_3()
if RUN_ALL: test_10_4()
if RUN_ALL: test_20_5()
if RUN_ALL: test_20_8()
if RUN_ALL: test_20_11()
