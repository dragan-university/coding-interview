"""
demo dict or list as function arguments with default value

expected that default value would be used every time we don't 
explicitely pass the value.
Actual behavior is that default value is used only for first
call. after that value from previous call is used for every subsequent call.
"""

def dict_test(memo={}):
    memo[len(memo)] = len(memo)
    print(memo)

def list_test(memo=[]):
    memo.append(len(memo))
    print(memo)

#tests
dict_test()
dict_test()
dict_test({})

list_test()
list_test()
