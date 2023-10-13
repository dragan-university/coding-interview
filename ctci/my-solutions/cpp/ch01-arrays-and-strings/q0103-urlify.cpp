/*
Q 1.3

Write method to replace all spaces in a string with '%20'. You may assume that
the string has sufficient space at the end to hold the additional characters,
and that you are given the 'true' length of the string. (Note: if implementing
in Java please use a character array so theta you can perfomr operaiton in place)

---
Examples:

Input:  "Mr John Smith    ", 13
Output: "Mr%20John%20Smith", 13

---
Questions to ask:

---
Design:
- check each char
- if char is space
  - move rest of the string to the right for 2 places
  - replace space with % and add 2 and 0 after it

*/
#include <stdio.h>
#include <string.h>

/*
complexity is O(?) ...
*/

void urlify(char* s, int len) {
    int i = 0;
    int j = 0;
    while (i<len) {
        printf("i=%d, j=%d\n", i, j);
        if (s[j] == ' ') {
            memmove(&s[j+2], &s[j], len-i);
            s[j] = '%';
            j++;
            s[j] = '2';
            j++;
            s[j] = '0';
        }

        i++;
        j++;
    }
}

void test_urlify(const char* input, const char* output) {
    const int MAX_STRING_LENGTH = 1000;
    char in[MAX_STRING_LENGTH];
    strncpy(in, input, strlen(input));

    urlify(in, strlen(input));

    if (strncmp(in, output, strlen(output)) == 0) {
        printf("PASS\n");
    } else {
        printf("FAIL\n");
    }
}

int main()
{
    test_urlify("dragan nikolic", "dragan%20nikolic");
    test_urlify("mr dragan nikolic", "mr%20dragan%20nikolic");
}
