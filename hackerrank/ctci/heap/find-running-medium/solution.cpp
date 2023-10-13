/*
https://www.hackerrank.com/challenges/ctci-find-the-running-median
*/

#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

const bool DEBUG = false; 

template<typename T> void print_vector(const vector<T>& v, const char* message="vector=")
{
    cout << message;
    for (auto item: v) {
        cout << item << ":";
    }
    cout << endl;
}

void insert_in_sorted_vector(vector<int>& x, int n, int value)
{
    if (DEBUG) cout << n << " insert " << value << endl;
    x[n] = value;
    for (size_t i=0; i<n; ++i) {
        if (value < x[i]) {
            for (size_t j=n; j>i; --j) {
                x[j] = x[j-1];
            }

            x[i] = value;
            break;
        }
    }    
}

// function still has error
// it seems that max heap does not work as expected
void find_running_medium(vector<int>& x, vector<double>& m) 
{
    priority_queue<int> qmax;
    priority_queue<int, vector<int>, greater<int> > qmin;
    qmax.push(x[0]);
    m.push_back(x[0]);

    for (size_t i=1; i<x.size(); ++i) {
        if (DEBUG) cout << i << " - " << x[i] << endl; 
        if (x[i] > qmax.top()) {
            qmin.push(x[i]);
        } else {
            qmax.push(x[i]);
        }

        if (qmin.size() > qmax.size()) {
            qmax.push(qmin.top());
            qmin.pop();
        }

        if (qmax.size() > qmin.size() + 1) {
            qmin.push(qmax.top());
            qmax.pop();
        }

        if (qmin.size() == qmax.size()) {
            m.push_back((qmin.top()+qmax.top())/2.0f);
        } else {
            m.push_back(qmax.top());
        }

        if (DEBUG) cout << "qmax: " << qmax.top() << " qmin: " << qmin.top() << endl;
    }
}

// same result as for v1
void find_running_medium_v2(vector<int>& x, vector<double>& m) 
{
    m.push_back(x[0]);
    vector<int> y(x.size());
    y[0] = x[0];

    for (size_t i=1; i<x.size(); ++i) {
        if (DEBUG) cout << i << "-";
        insert_in_sorted_vector(y, i, x[i]);

        if (i%2 == 0) {
            if (DEBUG) cout << "odd";
            m.push_back(y[i/2]);
        } else {
            size_t midx = i/2;
            if (DEBUG) cout << "even " << midx;
            m.push_back((y[midx] + y[midx+1])/2.0);
        }
        if (DEBUG) cout << endl;

        if (DEBUG) print_vector(y, "y=");
        if (DEBUG) print_vector(m, "m=");
    }
}

// passed tc 1-3
// timed out tc 4-9
void find_running_medium_v1(vector<int>& x, vector<double>& m) {
    m.push_back(x[0]);

    for (size_t i=1; i<x.size(); ++i) {
        if (DEBUG) cout << i << "-";
        sort(x.begin(), x.begin()+i+1);

        if (i%2 == 0) {
            if (DEBUG) cout << "odd";
            m.push_back(x[i/2]);
        } else {
            size_t midx = i/2;
            if (DEBUG) cout << "even " << midx;
            m.push_back((x[midx] + x[midx+1])/2.0);
        }
        if (DEBUG) cout << endl;

        if (DEBUG) print_vector(x, "x=");
        if (DEBUG) print_vector(m, "m=");
    }
}

void print_result(const vector<double>& m)
{
    for (auto item: m) {
        //cout << setprecision(2) << item << endl;
        printf("%.1f\n", item);
    }
}

void test_find_running_medium(vector<int>& x, vector<double>& expected)
{
    vector<double> actual;
    find_running_medium(x, actual);

    if (actual.size() != expected.size()) {
        cout << "FAIL - actual szie=" << actual.size() << " expected_size=" << expected.size() << endl;
        return;
    }

    for (size_t i=0; i<actual.size(); ++i) {
        cout << "A=" << actual[i] << " E=" << expected[i] << endl;
        if (actual[i] != expected[i]) {
            cout << "FAIL" << endl;
            return;
        }
    }

    print_result(actual);
    cout << "PASS" << endl;
}

void tc_hr_sample()
{
    vector<int> x = {12, 4, 5, 3, 8, 7};
    vector<double> expected = {12.0, 8.0, 5.0, 4.5, 5.0, 6.0};
    test_find_running_medium(x, expected);
}

void tc_hr_01()
{
    vector<int> x = {1,2,3,4,5,6,7,8,9,10};
    vector<double> expected = {1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5, 5.0, 5.5};
    test_find_running_medium(x, expected);
}

void hackerrank()
{
    int n;
    cin >> n;

    vector<int> x(n);
    for(size_t i=0; i<n; i++) {
        cin >> x[i];
    }

    vector<double> m;
    find_running_medium(x, m);
    print_result(m);
}

int main() {

    //hackerrank();
    //tc_hr_sample();
    tc_hr_01();
    return 0;
}
