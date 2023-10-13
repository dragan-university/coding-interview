// How to build:
// Linux: g++ -std=c++11 <file>.cpp
// Windows: cl /EHsc <file>.cpp
// To init Windows run 'vcvarsall'

/*
int setBits(unsigned long long int n) {
    int count = 0 ;
    while(n) {
        n &= (n-1) ;
        count ++ ;
    }
    return count ;
}

int main() {
    int t ;
    scanf("%d\n",&t) ;
    while(t--) {
        unsigned long long int n ;
        scanf("%llu\n",&n) ;
        if (setBits(n-1) & 1) printf("Louise\n") ;
        else printf("Richard\n") ;
    }
    return 0;
}
*/

/*
TC #1

5
6703734870638684097
7597026128958891522
13174607262084689114
6959712971461184279
12572864054437627553

Richard
Richard
Louise
Louise
Louise
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long find_max_power(unsigned long long n) {
    unsigned long long m;
    if (n%2) m = (n-1)/2;
    else m = n/2;

    unsigned long long p = 2;

    while (p <= m) {
        p *= 2;
    }

    cout << "max_power for " << n << " is " << p << endl;
    return p;
}

int counter_game(unsigned long long n, int result) {
    cout << n << ":" << result << endl;
    if (n == 1) return result;

    unsigned long long max_power = find_max_power(n);

    if (max_power == n) {
        return counter_game(n/2, 1-result);
    } else {
        return counter_game(n-max_power, 1-result);
    }
}

void run_test(unsigned long long test_value, int expected_result)
{
    cout << "=== " << test_value << "-" << expected_result << " ===" << endl;
    int actual_result = counter_game(test_value, 0);

    if (actual_result == expected_result) {
        cout << "OK";
    } else {
        cout << "NOK";
    }

    cout << endl;
}

void test_001_hr(void)
{
    run_test(6703734870638684097, 0);
    run_test(7597026128958891522, 0);
    run_test(13174607262084689114, 1);
    run_test(6959712971461184279, 1);
    run_test(12572864054437627553, 1);
}

void test_010(void)
{
    run_test(6, 0);
}

void test_020(void)
{
    run_test(1, 0);
}

void test_030(void)
{
    run_test(2, 1);
}

void test_040(void)
{
    run_test(6703734870638684097, 0);
}

void test_050(void)
{
    run_test(6959712971461184279, 1);
}

void test_060(void)
{
    run_test(12538990046817067955, 1);
}

void hr_testcase()
{
    unsigned long long N;
    cin >> N;

    int result = counter_game(N, 0);

    if (result) {
        cout << "Louise";
    } else {
        cout << "Richard";
    }

    cout << endl;
}

void hackerrank()
{
    int T;
    cin >> T;

    for(int i = 0; i < T; i++) {
        hr_testcase();
    }
}

//#define RUNTESTS (1)
int main()
{
    #ifdef RUNTESTS
    test_010();
    test_020();
    test_030();
    #else
    //hackerrank();
    test_001_hr();
    #endif

    return 0;
}

