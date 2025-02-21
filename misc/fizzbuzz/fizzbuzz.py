def fizzbuzz(n):
    count = 1

    while count <= n:
        print(fizzbuzz_helper(count))
        count += 1

def fizzbuzz2(n):
    for e in map(fizzbuzz_helper, range(1, n+1)):
        print(e)

def fizzbuzz_helper(n):
    if n%15 == 0:
        return("FizzBuzz")
    elif n%5 == 0:
        return("Buzz")
    elif n%3 == 0:
        return("Fizz")
    else:
        return(n)

fizzbuzz(30)
