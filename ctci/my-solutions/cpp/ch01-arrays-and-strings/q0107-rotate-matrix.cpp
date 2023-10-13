/*
Q 1.7

Given an image represented by an NxN matrix, where each pixel in the image is 4  bytes, 
write a method to rotate the image by 90 degrees. Can you do this in place?

---
Examples:

00 01 02 03
10 11 12 13
20 21 22 23
30 31 32 33

30 20 10 00
31 21 11 01
32 22 12 02
33 23 13 03

00 -> 03
01 -> 13
02 -> 23
03 -> 33

10 -> 02
11 -> 12
12 -> 22
13 -> 32

...

cell (i,j) of the original image becomes cell (j,n-i-1) of the rotated image:
    (i,j) = rot(j,n-i-1)

if we substitue n-i-1=k => i=n-k-1, we can find how we map cell (i,j) of the
rotated image to the cell of the original image. Solution is:
    rot(k,j) = (n-k-1,j)  

for exmaple:
rot(0,0) = (n-1,0)
rot(0,1) = (n-2,0)
etc.

Questions to ask:
- can I use int to represent 4 bytes?

Design:
solution 1: use another matrix for rotated image ... in that case it's easy
but the space requirement is n^2

solution 2: do it in layers:
for layer =  1 to n-1/2:
   see solution below

Notes:

Used single pointer and pointer arithmetic to access elements in the 2-dimensional
image:
    a[i][j] = *(a+i*n+j)
*/
#include <iostream>
#include <cstdint>
#include <cstring>

using namespace std;

void set_element(uint32_t* matrix, int n, int i, int j, uint32_t v) {
    cout << "set " << i << ":" << j << " = " << v << endl;
    *(matrix + i*n + j) = v;
}

uint32_t get_element(uint32_t* matrix, int n, int i, int j) {
    return *(matrix + i*n + j);
}

/*
solution 1:
- create new rotated matrix

time complexity is O(n^2), where n is the matrix dimension
space complexity is also O(n^2)
*/
void rotate90(uint32_t* image, int n) {
    uint32_t rimage[n][n];


    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            rimage[i][j] = get_element(image, n, n-j-1, i);
            //cout << i << ":" << j << "=" << rimage[i][j] << endl;
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            set_element(image, n, i, j, rimage[i][j]);
        }
    }
}

/*
solution 2 - do it in place
*/
void rotate90_in_place(uint32_t* image, int n) {
    int number_of_layers = n/2;
    for (int layer=0; layer<number_of_layers; layer++) {
        for (int i=layer; i<n-layer-1; i++) {
            uint32_t t = get_element(image, n, layer, i);
            set_element(
                image, n, layer, i, 
                get_element(image, n, n-i-1, layer));
            set_element(
                image, n, n-i-1, layer, 
                get_element(image, n, n-layer-1, n-i-1));
            set_element(
                image, n, n-layer-1, n-i-1, 
                get_element(image, n, i, n-layer-1));
            set_element(image, n, i, n-layer-1, t);
        }
    }
}

template<typename T> bool compare_images(T* a, T* b, int n) {
    bool result = true;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            T av = *(a+i*n+j);
            T bv = *(b+i*n+j);
            cout << i << ":" << j << "= (" << av << ":" << bv << ")" << endl;
            if (av != bv) {
                cout << "different at: " << i << ":" << j << " (" << av << ":" << bv << ")" << endl;
                return false;
            }
        }
    }

    return true;
}

void test_rotate90(uint32_t* image, uint32_t* expected, int n) {
    //rotate90(image, n);
    rotate90_in_place(image, n);

    // if (memcmp(image, expected, n*n*sizeof(uint32_t)) == 0) {
    //     cout << "PASS" << endl;
    // } else {
    //     cout << "FAIL" << endl;
    // }

    if (compare_images<uint32_t>(image, expected, n)) {
        cout << "PASS" << endl;
    } else {
        cout << "FAIL" << endl;
    }
}

void test_3x3() {
    uint32_t m[3][3] = {{11,12,13},{21,22,23},{31,32,33}};
    uint32_t e[3][3] = {{31,21,11},{32,22,12},{33,23,13}};

    test_rotate90((uint32_t*)m, (uint32_t*)e, 3);
}

void test_4x4() {
    uint32_t m[4][4] = {
        {00,01,02,03},
        {10,11,12,13},
        {20,21,22,23},
        {30,31,32,33}};
    uint32_t e[4][4] = {
        {30,20,10,00},
        {31,21,11,01},
        {32,22,12,02},
        {33,23,13,03}};

    test_rotate90((uint32_t*)m, (uint32_t*)e, 4);
}

int main()
{
    test_3x3();
    test_4x4();
    return 0;
}
