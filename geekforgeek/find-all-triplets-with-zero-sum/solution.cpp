/*
http://www.geeksforgeeks.org/find-triplets-array-whose-sum-equal-zero/

Solution 1 (brute force) O(n^3):
The naive approach is that run three loops and check one by one that sum of 
three elements is zero or not if sum of three elements is zero then print 
elements other wise print not found.

Solution 2 (using hash table) O(n^2):
Run a loop from i=0 to n-2
  Create an empty hash table
  Run inner loop from j=i+1 to n-1
      If -(arr[i] + arr[j]) is present in hash table
         print arr[i], arr[j] and -(arr[i]+arr[j])
      Else
         Insert arr[j] in hash table.

Solution 3 (sort array first) O(n^2):
    Sort all element of array
    Run loop from i=0 to n-2.
        Initialize two index variables l=i+1 and r=n-1
    while (l < r) 
        Check sum of arr[i], arr[l], arr[r] is
        zero or not if sum is zero then print the
        triplet and do l++ and r--.
    If sum is less than zero then l++
    If sum is greater than zero then r--
    If not exist in array then print not found.

Build:

Linux & Mac:
    g++ <file.cpp> or 
    g++ --std=c++11 <file.cpp> 

Windows (vcvarsall.bat):
    cl /EHsc <file.cpp>
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void find_triplets(
        vector<int> &arr,  // in
        vector<vector<int> > &triplets)   // out
{
    sort(arr.begin(), arr.end());

    for (size_t i=0; i<arr.size(); ++i) {
        size_t l = i+1;
        size_t r = arr.size();

        while (l < r) {
            cout << "check " << i << "," << l << "," << r << endl;
            int sum = arr[i] + arr[l] + arr[r];
            if (sum == 0) {
                cout << "BINGO" << endl;
                vector<int> triplet = {arr[i], arr[l], arr[r]};
                triplets.push_back(triplet);
                break;
            }

            if (sum < 0) l++;
            if (sum > 0) r--;
        }
    }
}

bool check_result(vector<vector<int> > &actual, vector<vector<int> > &expected)
{
    if (actual.size() != expected.size()) {
        return false;
    }

    for (size_t i=0; i<actual.size(); ++i) {
        for (size_t j=0; j<actual[i].size(); ++j) {
            if (actual[i][j] != expected[i][j]) {
                cout << i << "," << j << ": A=" << actual[i][j] << ", E=" << expected[i][j] << endl;
                return false;
            }
        }
    }

    return true;
}

void test_find_triplets(
        vector<int> &arr,
        vector<vector<int> > &expected_result)
{
    vector<vector<int> > actual_result;
    find_triplets(arr, actual_result);

    if (check_result(actual_result, expected_result) {
        cout << "PASS";
    } else {
        cout << "FAIL (actual=" << actual_result << ", expected=" << expected_result;
    }
    cout << endl;
}

void test_00()
{
    vector<int> arr = {0, -1, 2, -3, 1};
    vector<vector<int> > expected_result = {
        {-3, 1, 2},
        {-1, 0, 1}
    };

    test_find_triplets(arr, expected_result);
}

int main()
{
    test_00();

    return 0;
}
