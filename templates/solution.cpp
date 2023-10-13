/*
Description
*/
#include <cstddef>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int DEBUG_LEVEL = 10;

int solution(string arg) {
    if (DEBUG_LEVEL > 5) {
        cout << arg << endl;
    }

    return 0;
}

void test_solution(string arg, int expected)
{
    cout << "arg: " << arg << ", expected: " << expected << endl;
    int actual = solution(arg);

    if (actual == expected) {
        cout << "PASS";
    } else {
        cout << "FAIL (actual=" << actual << ")";
    }
    cout << endl;
}

void test_01()
{
    test_solution("arg", 3);
}

int main()
{
    test_01();

    return 0;
}
