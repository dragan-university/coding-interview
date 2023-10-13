/*
CTCI - Chapter 8 - Question 3

Magic Index: A magic index in anarray A[1...n-1] is defined to be an index such
that A[i]=i. Given a sorted array of distinct integers write a method to find a
magic index, if one exists, in array A.

Follow up: What if the values are not distinct?

Examples:

A = [-8, -2, 0, 3, 16] - magic index is 3
A = [-8, -2, 0, 5, 16] - no magic index

Solution:

Similar to doing binary search.
Check the middle element first.
If value is bigger then index then possible magic index is in the first half,
otherwise is in the second half.
If subarray has only one element and that element is not magic index then there
is no magic index.

Build:

Linux & Mac:
    g++ <file.cpp> or
    g++ -std=c++11 <file.cpp>

Windows (vcvarsall.bat):
    cl /EHsc <file.cpp>
*/

#include <iostream>
#include <cassert>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

int find_magic_index(vector<int> &arr)
{
    int magic_index = -1;

    unsigned left_index = 0;
    unsigned right_index = arr.size()-1;

    while (right_index >= left_index) {
        int mid_index = (right_index + left_index) / 2;

        if (arr[mid_index] == mid_index) {
            magic_index = mid_index;
            break;
        } else if (arr[mid_index] < mid_index) {
            if (left_index == mid_index) {
                break;
            } else {
                left_index = mid_index;
            }
        } else {
            if (right_index == mid_index) {
                break;
            } else {
                right_index = mid_index;
            }
        }
    }

    return magic_index;
}

void print_arr(const vector<int> &arr)
{
    for (auto i: arr) {
        cout << i << ":";
    }
    cout << endl;
}

void test_find_magic_index(vector<int> &arr, int expected_result)
{
    print_arr(arr);
    cout << "E:" << expected_result;
    int actual_result = find_magic_index(arr);
    cout << " A:" << actual_result << endl;
    assert(actual_result == expected_result);
}

void test_01_01()
{
    vector<int> arr = {-8, -2, 0, 3, 16};
    test_find_magic_index(arr, 3);
}

void test_01_02()
{
    vector<int> arr = {-8, -2, 0, 5, 16};
    test_find_magic_index(arr, -1);
}

void test_02_01()
{
    vector<int> arr = {0};
    test_find_magic_index(arr, 0);
}

void test_02_02()
{
    vector<int> arr = {1};
    test_find_magic_index(arr, -1);
}

int main()
{
    test_01_01();
    test_01_02();
    test_02_01();
    test_02_02();

    return 0;
}
