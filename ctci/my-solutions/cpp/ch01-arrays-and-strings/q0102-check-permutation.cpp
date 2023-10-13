/*
Q 1.2

Given two strings, write a method to decide if one is a permutation of the other.

---
Examples:

"dragan" - "gandra" -- yes
"dragan" - "ganxdra" -- no

---
Questions to ask:
- can I use STL?
- how many different chars are there?

---
Design:

solution 1
- sort both strings and check if they are the same
- complexity O(n*lgn)

solution 2
- keep number of occurences of each char in an array, where index is char code
- then just check if arrays are the same

*/
#include <stdio.h>
#include <string.h>

/*
complexity is O(?) ...
*/
const int MAX_CHARS = 255;

bool is_permutation(char* a, char* b) {
    int a_chars[MAX_CHARS];
    int b_chars[MAX_CHARS];

    memset(a_chars, 0, MAX_CHARS*sizeof(int));
    memset(b_chars, 0, MAX_CHARS*sizeof(int));

    while (*a) {
        a_chars[*a]++;

        if (*b) {
            b_chars[*b]++;
        } else {
            return false;
        }

        a++;
        b++;
    }

    if (*b) {
        return false;
    }

    if (memcmp(a_chars, b_chars, sizeof(a_chars)) != 0) {
        return false;
    }

    return true;
}

void test_is_permutation(const char* a, const char* b, bool expected) {
    const int MAX_STRING_LENGTH = 1000;
    char _a[MAX_STRING_LENGTH];
    char _b[MAX_STRING_LENGTH];
    strncpy(_a, a, MAX_STRING_LENGTH);
    strncpy(_b, b, MAX_STRING_LENGTH);
    _a[MAX_STRING_LENGTH-1] = 0;
    _b[MAX_STRING_LENGTH-1] = 0;

    if (is_permutation(_a, _b) == expected) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }
}

int main()
{
    test_is_permutation("dragan", "gandra", true);
    test_is_permutation("dragan", "ganxdra", false);
}
