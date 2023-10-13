/*
Q 1.2

Implement a function void reverse(char* str) in C or C++ which reverses a null-terminated
string.

---
Build on Linux:
g++ <file.cpp>

Build on Windows:
cl <file.cpp>

---
Examples:
- "dragan" -> "nagard"

---
Questions to ask:

---
Design:
- find the length of the string
- swap the chars at the opposite end of the string which has the same distance from the
  center of the string

dragan f=0, b=5
nragad f=1, b=4
naagrd f=2, b=3
nagard f=3, b=2

draxgan f=0, b=6
nraxgad f=1, b=5
naaxgrd f=2, b=4
nagxard f=3, b=3
*/
#include <stdio.h>
#include <string.h>

/*
complexity is O(n) ...
*/
void reverse(char* str) {
    size_t len = strlen(str);

    char* f = str;
    char* b = str+len-1;

    while (f < b) {
        char t = *f;
        *f = *b;
        *b = t;

        f++;
        b--;
    }
}

void test_reverse(const char* input, const char* expected) {
    printf("original: %s -- expected: %s\n", input, expected);
    const int MAX_STRING_LENGTH = 1000;
    char in[MAX_STRING_LENGTH];
    strncpy(in, input, MAX_STRING_LENGTH);
    reverse(in);
    if (strcmp(in, expected) == 0) {
        printf("PASS\n");
    } else {
        printf("FAIL (%s)\n", in);
    }

}

int main()
{
    test_reverse("dragan", "nagard");
    test_reverse("draxgan", "nagxard");
    test_reverse("characters", "sretcarahc");
}
