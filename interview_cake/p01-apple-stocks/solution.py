"""
1 - Apple Stocks
https://www.interviewcake.com/question/python/stock-price
"""

DEBUG = False

def max_profit(stock_prices):
    if (len(stock_prices) < 2):
        raise Exception('We must have at least 2 prices to calculate profit')

    max_profit = stock_prices[1] - stock_prices[0]
    min_price = min(stock_prices[0], stock_prices[1])

    index = 2
    while (index < len(stock_prices)):
        max_profit = max(max_profit, stock_prices[index] - min_price)
        min_price = min(min_price, stock_prices[index])
        if DEBUG: 
            print('index: {}, profit: {}, min_price: {}'.format(index, max_profit, min_price))
        index += 1

    return max_profit

def test_driver(stock_prices, expected_result):
    print('prices: {}, expected: {}'.format(stock_prices, expected_result))
    try:
        actual_result = max_profit(stock_prices)
    except Exception as e:
        if expected_result == 'exception':
            print('PASS')
            return
        else:
            print('FAIL: {}'.format(e.message))
            return

    if (actual_result == expected_result):
        print('PASS')
    else:
        print('FAIL: actual={}'.format(actual_result))

def test_01():
    test_driver([10], 'exception')

def test_05():
    test_driver([10,7,5,8,11,3,12], 9)

def test_descending():
    test_driver([10, 7, 2, 1], -1)

test_01()
test_05()
test_descending()