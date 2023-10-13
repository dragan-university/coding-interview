"""
Alghoritm:
- find biggest decreasing sequence from the end
- replace the number before the sequence with the smallest number from the
  sequence that is bigger then the number
- rearange the sequence in increasing order

Example: Find next permutation of 326541
- deacreasin sequence is 6541
- the number before the sequence is 2
- replace 2 with smallest number from sequence that is bigger than 2, which is 4
- we have 346521
- rearange 6521 in increasing order, ie 1256
- next permutation is 341256
"""

"""
Input: sequence 's'
Return: next permutation of sequence 's'
"""
def next_permutation(s):
    # find decreasing sequence from the end
    l = -len(s)-1
    pivot = None
    for ix in range(-2, l, -1):
        if s[ix] <= s[ix+1]:
            pivot = s[ix]
            break

    before = s[:ix]
    after = s[ix+1:]
    after = sorted(after)

    if not pivot:
        return ''.join(sorted(s))

    for iy in range(len(after)):
        if after[iy] > pivot:
            pivot, after[iy] = str(after[iy]), pivot
            break

    return before + pivot + ''.join(after)

def run_next_permutation_test(s, expected):
    actual = next_permutation(s)
    assert actual == expected
    # if actual == expected:
    #     print("PASS")
    # else:
    #     print("FAIL: expected {} got {}".format(expected, actual))

def test_326541_341256():
    run_next_permutation_test("326541", "341256")

def test_123_132():
    run_next_permutation_test("123", "132")

def test_4321_1234():
    run_next_permutation_test("4321", "1234")

def test_3421_4123():
    run_next_permutation_test("3421", "4123")
