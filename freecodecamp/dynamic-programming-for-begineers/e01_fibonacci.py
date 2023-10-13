"""
Time: O(2^n)
Space: O(n)
"""
def fib_slow(n, memo={}):
    if n <=2: 
        return 1

    return fib(n-1) + fib(n-2)

"""
Time: O(n)
Space: O(n)
"""
def fib(n, memo={}):
    if n <=2: 
        return 1

    if not n in memo:
        memo[n] = fib(n-1) + fib(n-2)
    
    return memo[n] 

print(fib(6))
print(fib(7))
print(fib(8))
print(fib(50))
