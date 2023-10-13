#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Pump
{
public:
    size_t gas_amount;
    size_t distance_to_next_pump;
    //Pump(size_t g, size_t d): gas_amount(g), distance_to_next_pump(d) {}
};

// this is my solution
void truck_tour(const vector<Pump>& pumps)
{
    const size_t N = pumps.size();
    size_t start_pump = 0;
    size_t next_pump = 1;
    size_t gas_in_truck = pumps[start_pump].gas_amount;
    size_t gas_total = pumps[start_pump].gas_amount;
    size_t distance_total = pumps[start_pump].distance_to_next_pump;
    size_t number_of_checked_pumps = 1;

    while (start_pump != next_pump)
    {
        if (gas_in_truck > pumps[next_pump-1].distance_to_next_pump)
        {
            gas_in_truck += (pumps[next_pump].gas_amount - pumps[next_pump-1].distance_to_next_pump);
        }
        else
        {
            start_pump = next_pump;
            gas_in_truck = pumps[start_pump].gas_amount;
        }

        gas_total += pumps[next_pump].gas_amount;
        distance_total += pumps[next_pump].distance_to_next_pump;

        next_pump++;
        number_of_checked_pumps++;
        if (number_of_checked_pumps == N)
        {
            if (gas_total >= distance_total)
            {
                // solution found
                cout << start_pump << endl;
            }
            else
            {
                cout << "no solution " << endl;
            }
            break;
        }
    }

    if (start_pump == next_pump)
    {
        // solution found
        cout << start_pump << endl;
    }
}

// this is one of hackerrank solutions
void ctzsm_solution(int n, int* p, int *d) {
    int ret = 0, amount = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        p[i] -= d[i];
        sum += p[i];
        if (amount + p[i] < 0) {
            amount = 0;
            ret = i + 1;
        } else amount += p[i];
    }
    printf("%d\n", sum >= 0 ? ret : -1);
}

int main() {
    int N;
    cin >> N;
    
    vector<Pump> pumps(N);
    
    for (int i=0; i<N; ++i)
    {
        cin >> pumps[i].gas_amount >> pumps[i].distance_to_next_pump;
    }
    
    truck_tour(pumps);

    return 0;
}

