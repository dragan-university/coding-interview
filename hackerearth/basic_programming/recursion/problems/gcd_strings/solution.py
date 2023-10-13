"""
GCD Strings
https://www.hackerearth.com/practice/basic-programming/recursion/recursion-and-backtracking/practice-problems/algorithm/gcd-strings/description/

P[0...5] = '101100'
S8(P) = '101100101100101100...'

g(6,3) = '100000'

g(8,5) = '10110101'
g(5,3) = '10110', S8 = '101101011010110...'
g(3,2) = '101', S8 = '101101101...' 
g(2,1) = '10', S8 = '101010...'

g(10,4) = '1000100010'
g(4,2) = '1000', S8 = '100010001000...
"""

DEBUG = False

def S8(P, n):
    k = int(n/len(P))
    S = P*(k+1)
    return S[0:n]

def g(a, b):
    if a % b == 0:
        return '1'+'0'*(a-1)

    return S8(g(b, a%b), a)

def solution(a,b):
    s = g(a, b)
    return int(s, 2) % (10**9 + 7)

def test_driver(a, b, expected_result):
    print('a: {}, b: {}, expected: {}'.format(a, b, expected_result))

    actual_result = solution(a, b)

    if (actual_result == expected_result):
        print('PASS')
    else:
        print('FAIL: actual={}'.format(actual_result))

def test_01():
    test_driver(5, 2, 21)

def test_05():
    test_driver(10, 4, 546)

def hacker_earth():
    T = int(input())

    for t in range(T):
        xy = input().split(' ')
        print(solution(int(xy[0]), int(xy[1])))

test_01()
test_05()
