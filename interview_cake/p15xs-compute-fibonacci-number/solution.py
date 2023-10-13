"""
15 - https://www.interviewcake.com/question/python/nth-fibonacci
"""
import traceback
import time

DEBUG_LEVEL = 0

def solution_recursion(N):
    """
    Recursion
    """
    if N < 2:
        return N

    return solution_recursion(N-1) + solution_recursion(N-2)

def solution_dp_r(N, table):
    if DEBUG_LEVEL>11: time.sleep(2)
    if N < 2: 
        return N

    if DEBUG_LEVEL>5: print('N={}, table={}'. format(N, table))
    if N-1 in table:
        if DEBUG_LEVEL>7: print('1:{} IN table'.format(N-1))
        n1_value = table[N-1]
    else:
        if DEBUG_LEVEL>7: print('1:{} NOT in table'.format(N-1))
        n1_value = solution_dp_r(N-2, table) + solution_dp_r(N-3, table)
        table[N-1] = n1_value

    if N-2 in table:
        if DEBUG_LEVEL>7: print('2:{} IN table'.format(N-2))
        n2_value = table[N-2]
    else:
        if DEBUG_LEVEL>7: print('2:{} NOT in table'.format(N-2))
        n2_value = solution_dp_r(N-3, table) + solution_dp_r(N-4, table)
        table[N-2] = n2_value

    return n1_value + n2_value

def solution_dp(N):
    """
    DP - time O(N) - space O(N)
    """
    table = {0:0, 1:1}
    return solution_dp_r(N, table)

def solution_iteration(N):
    """
    Iterative solution - time O(N) - space O(1)
    """
    if N < 2:
        return 1

    a = 0
    b = 1
    
    for i in range(N-1):
        a, b = b, a+b

    return b

def multiple_matrix(A, B):
    return [
        [A[0][0]*B[0][0]+A[0][1]*B[1][0], A[0][0]*B[0][1]+A[0][1]*B[1][1]],
        [A[1][0]*B[0][0]+A[1][1]*B[1][0], A[1][0]*B[0][1]+A[1][1]*B[1][1]],
    ]

def solution_matrix(N):
    """
    matrix solution - time O(lgN) - space O(N)
    """
    if N < 2:
        return 1

    F = [[1,1], [1,0]]

    M = [[1,0], [0,1]]
    while N > 0:
        if N%2:
            M = multiple_matrix(M, F)

        F = multiple_matrix(F, F)
        N = int(N/2)

    return M[0][1]

def test_driver(N):
    print('=== Fib:{} ==='.format(N))

    # # time solution 1
    btime = time.clock()
    # result = solution_recursion(N)
    # print('Fib={}'.format(result))
    print('solution recursion time: {}'.format(time.clock()-btime))
    # print()

    # # time solution 2
    # btime = time.clock()
    # result = solution_dp(N)
    # print('Fib={}'.format(result))
    # print('solution dp time: {}'.format(time.clock()-btime))
    # print()

    # time solution 3
    btime = time.clock()
    result = solution_iteration(N)
    print('Fib={}'.format(str(result)[:100]))
    print('solution iteration time: {}'.format(time.clock()-btime))
    print()

    # time solution 4
    btime = time.clock()
    result = solution_matrix(N)
    print('Fib={}'.format(str(result)[:100]))
    print('solution matrix time: {}'.format(time.clock()-btime))
    print()

def test_matrix_multiple(N):
    F = [[1,1], [1,0]]
    M = F
    for i in range(N):
        M = multiple_matrix(M, F)
        print('{}'.format(M[0][1]))

#test_matrix_multiple(5)
test_driver(2000000)
