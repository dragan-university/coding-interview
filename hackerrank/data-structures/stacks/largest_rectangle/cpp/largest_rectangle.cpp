#include <cmath>
#include <cstdio>
#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int largest_rectangle_array(int, int[]);
int largest_rectangle_vector(const vector<int>&);

// this code was used at hackerrank.com
void get_stdin()
{
    int n;
    scanf("%d", &n);
    int* heights = new int[n];
    int* p = heights;
    for (int ix=0; ix<n; ix++) {
        scanf("%d", p++);
    }

}

int main() {
    int area;

    int n = 5;
    int heights[]{1,2,4,3,4};
    area = largest_rectangle_array(5, heights);
    assert(area == 9);
    cout << "area is " << area << endl;

    vector<int> hv{1,2,4};
    area = largest_rectangle_vector(hv);
    assert(area == 4);
    cout << "area is " << area << endl;

    return 0;
}

int largest_rectangle_array(int n, int heights[])
{
    int largest_area = 0;

    for (int ix=0; ix<n; ix++)
    {
        cout << "check ix " << ix << ": " << heights[ix] << endl;
        int left = ix;
        int right = ix;
        int iy;

        if (left > 0)
        {
            for (iy=left-1; iy>=0; iy--)
            {
                cout << "check left iy " << iy << endl;
                if (heights[iy] < heights[ix]) break;
            }

            if (iy<0) iy=0;
            if (heights[iy] < heights[ix]) left = iy+1;
            else left = iy;
            cout << "left " << left << endl;
        }

        if (right < n-1)
        {
            for (iy=right+1; iy<n; iy++)
            {
                cout << "check right iy " << iy << endl;
                if (heights[iy] < heights[ix]) break;
            }

            if (iy>n-1) iy=n-1;
            if (heights[iy] < heights[ix]) right = iy-1;
            else right = iy;
            cout << "right " << right << endl;
        }

        cout << "area " << (right-left+1)*heights[ix] << endl;
        largest_area = max(largest_area, (right-left+1)*heights[ix]);
    }

    return largest_area;
}

int largest_rectangle_vector(const vector<int>& heights)
{
    int largest_area = 0;
    int n = heights.size();

    for (int ix=0; ix<n; ix++)
    {
        cout << "check ix " << ix << ": " << heights[ix] << endl;
        int left = ix;
        int right = ix;
        int iy;

        if (left > 0)
        {
            for (iy=left-1; iy>=0; iy--)
            {
                cout << "check left iy " << iy << endl;
                if (heights[iy] < heights[ix]) break;
            }

            if (iy<0) iy=0;
            if (heights[iy] < heights[ix]) left = iy+1;
            else left = iy;
            cout << "left " << left << endl;
        }

        if (right < n-1)
        {
            for (iy=right+1; iy<n; iy++)
            {
                cout << "check right iy " << iy << endl;
                if (heights[iy] < heights[ix]) break;
            }

            if (iy>n-1) iy=n-1;
            if (heights[iy] < heights[ix]) right = iy-1;
            else right = iy;
            cout << "right " << right << endl;
        }

        cout << "area " << (right-left+1)*heights[ix] << endl;
        largest_area = max(largest_area, (right-left+1)*heights[ix]);
    }

    return largest_area;
}
