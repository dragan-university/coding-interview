"""
5 - making change

Analisys:
    DP problem

    assume that coins are in ascending order, if not just sort them

    c[n, k] = number of ways to make amount n using first k coins

    c[n, 1] = 1 if n can be divided by coin[0], otherwise 0
    c[0, k] = 1 
    c[n, k] = c[n, k-1] + c[n-coins[k-1], k], second part only if n-coins[k-1]>=0
"""
DEBUG_LEVEL = 7

def make_change(amount, coins):
    """
    count different ways to make amount using coins
    """
    coins.sort()

    c = [1]
    for i in range(1, amount+1):
        c.append(0 if i%coins[0] else 1)
    if DEBUG_LEVEL>5: print('1: {}'.format(c))

    for i in range(1, len(coins)):
        if DEBUG_LEVEL>7: print('coins={}'.format(i))
        d = [1]

        for j in range(1, amount+1):
            if DEBUG_LEVEL>7: print('amount={}'.format(j))
            count = c[j]
            if j-coins[i] >= 0:
                count += d[j-coins[i]]
            d.append(count)

        c = d
        if DEBUG_LEVEL>5: print('{}: {}'.format(i+1, c))

    return c[amount]

def test_driver(amount, coins, expected_result):
    print('amount: {}, coins: {}, expected: {}'.format(amount, coins, expected_result))

    actual_result = make_change(amount, coins)
    if (actual_result == expected_result):
        print('PASS')
    else:
        print('FAIL: actual={}'.format(actual_result))

def test_sample():
    test_driver(4, [1, 2, 3], 4)

test_sample()
