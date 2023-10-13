/*
CTCI - Chapter 8 - Question 13

Stack of Boxes: You have a stack of n boxes, with widths w[i], heights h[i],
and depths d[i]. The boxes cannot be rotated and can only be stacked on top of
one another if each box in the stack is strictly larger than the box above it in
width, height and depth. Implement a method to compute the height of the tallest
possible stack. The height of a stack is the sum of the heights of each box.

Example:
b[1] = (3, 2, 5)
b[2] = (6, 1, 6)
b[3] = (5, 3, 9)
b[4] = (4, 4, 6)

stack = (b[4], b[1])

height = 4+2 = 6

Solution:
Sort boxes by height from smallest to tallest.
Then sort by area w*d

...

Build:

Linux & Mac:
    g++ <file.cpp> or
    g++ -std=c++11 <file.cpp>

Windows (vcvarsall.bat):
    cl /EHsc <file.cpp>
*/

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <cassert>
#include <ctime>

using namespace std;

structure Box {
    size_t w;
    size_t h;
    size_t d;

    Box(size_t aw, size_t ah, size_t ad): w(aw), h(ah), d(ad) {}
};

// compare boxes
bool box_comp(Box lhs, Box rhs)
{
    if (lhs.h == rhs.h) {
        if (lhs.w == rhs.w) {
            return (lhs.d < rhs.d);
        }

        if (lhs.d == rhs.d) {
            return (lhs.w < rhs.w);
        }

        return (lhs.w*lhs.d < rhs.w*rhs.d);
    }

    return (lhs.h < rhs.h);
}

void sort_boxes(vector<Box>)

size_t stack_of_boxes(set<Box> &boxes) {
    if (boxes.size() == 1) {
        return 0; // tbd
    }

    return 0; // tbd
}

void test_stack_of_boxes(vector<Box> &boxes, size_t expected_height)
{
    size_t actual_height = stack_of_boxes(boxes);
}


int main()
{

    return 0;
}
