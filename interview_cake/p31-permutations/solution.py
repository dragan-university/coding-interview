"""
Permutations
"""

DEBUG = False

def permutations(s):
    if DEBUG: print(s)
    if len(s) == 1:
        return [s[0]]

    _permutations = []
    for ix in range(len(s)):
        for p in permutations(s[0:ix]+s[ix+1:len(s)]):
            _permutations.append(s[ix]+p)

    return _permutations

def permutations_print(s, p):
    if len(s) == 1:
        print(p+s[0])

    for ix in range(len(s)):
        permutations_print(s[0:ix]+s[ix+1:len(s)], p+s[ix])

def permutations_yield(s, p):
    if DEBUG: print('s={}, p={}'.format(s, p))
    if len(s) == 1:
        yield(p+s[0])

    for ix in range(len(s)):
        if DEBUG: print(ix)
        yield from permutations_yield(s[0:ix]+s[ix+1:len(s)], p+s[ix])

def test_a_00():
    for p in permutations('abc'):
        print(p)

def test_p_00():
    permutations_print('abc', '')

def test_y_00():
    for p in permutations_yield('abc', ''):
        print(p)

test_y_00()
