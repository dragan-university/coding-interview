/*
CTCI - Chapter 8 - Question 1

Tripple Step: A child is runnning up a staircase with n steps and can hop 
either 1 step, 2 steps or 3 steps at a time. Implement a method to count how
many possible ways the child can run up the stairs.

Solution: 


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

using namespace std;

long long tripple_step(int n)
{
    if (n < 3) {
        return n;
    } else if (n == 3) {
        return 4;
    } else {
        return tripple_step(n-1) + tripple_step(n-2) + tripple_step(n-3); 
    }
}

long long tripple_step_mem_rec(int n, long long m[])
{
    if (n < 3) {
        return n;
    } else if (n == 3) {
        return 4;
    }
    
    if (m[n-2] == 0) {
        m[n-2] = tripple_step_mem_rec(n-1, m);
    }

    if (m[n-3] == 0) {
        m[n-3] = tripple_step_mem_rec(n-2, m);
    }
    
    if (m[n-4] == 0) {
        m[n-4] = tripple_step_mem_rec(n-3, m);
    }
    
    return m[n-2] + m[n-3] + m[n-4]; 
}

long long tripple_step_mem(int n)
{
    long long m[n];

    for (int ix=0; ix<n; ++ix) {
        m[ix] = 0;
    }

    return tripple_step_mem_rec(n, m);
}

long long tripple_step_fast(int n)
{
    if (n < 3) {
        return n;
    } else if (n == 3) {
        return 4;
    }
    
    long long a = 1;
    long long b = 2;
    long long c = 4;
    int k = 4;
    long long count;

    while (k <= n) {
        count = a+b+c;
        a = b;
        b = c;
        c = count;
        k++;
    }

    return count; 
}

void test_tripple_step(int n, long long expected_count)
{
    cout << "***** n=" << n << endl;
    clock_t tstart;
    long long actual_count;

    if (n < 39) {
        tstart = clock();
        actual_count = tripple_step(n);
        cout << "Time taken: " << (double)((clock() - tstart)/CLOCKS_PER_SEC) << endl;

        if (actual_count == expected_count) {
            cout << "PASS";
        } else {
            cout << "FAIL: expected=" << expected_count << " actual=" << actual_count; 
        }
        cout << endl;
    }

    tstart = clock();
    actual_count = tripple_step_mem(n);
    cout << "Time taken mem: " << (double)((clock() - tstart)/CLOCKS_PER_SEC) << endl;

    if (actual_count == expected_count) {
        cout << "PASS mem";
    } else {
        cout << "FAIL mem: expected=" << expected_count << " actual=" << actual_count; 
    }
    cout << endl;

    tstart = clock();
    actual_count = tripple_step_fast(n);
    cout << "Time taken fast: " << (double)((clock() - tstart)/CLOCKS_PER_SEC) << endl;

    if (actual_count == expected_count) {
        cout << "PASS fast";
    } else {
        cout << "FAIL fast: expected=" << expected_count << " actual=" << actual_count; 
    }
    cout << endl;
}

int main()
{
    //test_tripple_step(1, 1);
    test_tripple_step(2, 2);
    test_tripple_step(3, 4);
    test_tripple_step(4, 7);
    test_tripple_step(5, 13);
    test_tripple_step(10, 274);
    test_tripple_step(20, 121415);
    test_tripple_step(30, 53798080);
    test_tripple_step(38, 7046319384);
    test_tripple_step(40, 23837527729);
    test_tripple_step(50, 10562230626642);

    return 0;
}
