/* Synchronous_shopping.cpp

Incomplete ... this seems to be more difficult problem then the difficulty
assigned in the problem description

Design:

References:
- https://www.quora.com/How-do-I-solve-synchronous-shopping-graph-problem-from-HackerRank

The end goal is to minimize the time taken by cats to reach from 1st Shopping 
center to Nth Shopping center with collective K fishes. Obviously if one of the 
cat reaches early then it will wait for the other and the answer will be the 
greater of the two.

But I can assume you know this part. So let's get down to understand why the 
heck bits, states and masks comes into the picture.

I think we should first solve an easier version of this problem. One cat, one 
fish and every shopping center is selling it. Yeah.. its then a simple shortest 
path problem.

What if every shopping center may or may not selling that one fish. You have to 
make sure when you reach Nth shopping center you have that goddamn fish.

So at every shopping center I should know whether I have taken that fish at all to reach it. This 
will help me in taking decision whether i have it at the Nth shopping center. So now with every 
vertex in the graph I maintain a boolean to tell me if I have got that fish till here. So 
effectively in our graph there are N∗2 vertices.

Now run Dijkstra’s Algorithm on this graph. So in your priority queue/heap you will add time taken, 
vertex along with that boolean. You will update priority of this tuple in any of the “relax” step.

Now it makes sense if we have K fishes and 1 cat, we can maintain the status of having K fishes by 
K bits. This K bit number is called a mask/bitmask.

Now the actual problem has two cats. But that doesn’t make much difference as we know shortest 
distance to reach Nth shopping center with any of the K fishes. So why not try all combinations i.e. 
mask M1 and M2 such that M1 or M2==K and we take the minimum for all such combos.

P.S. I have tried to be extra verbose to explain the idea behind it. For more details on 
implementation you can refer to the Editorial.


How to build:
Linux: g++ --std-c++11 <file>.cpp
Windows: cl /EHsc <file>.cpp
Windows environment setup: run vcvarsall.bat
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <cassert>

using namespace std;

const bool MY_DEBUG = false;

struct adjustent_center
{
  int center;
  int travel_time;
};

struct center
{
  vector<adjustent_center> adjustent_centers;
  vector<int> fish_types;
};

struct road
{
  int center[2];  // 2 shopping centers connected with this road
  int travel_time;
};

void init_centers(
  vector<center> &centers,
  vector<vector<int>> &fish_types,
  vector<road> &roads)
{
  // set fish_types
  for (int i=0; i<centers.size(); ++i) {
    centers[i].fish_types = fish_types[i];
  }

  // set adjustent centers
  for (int i=0; i<roads.size(); ++i) {
    adjustent_center adj_center;
    adj_center.center = roads[i].center[1];
    adj_center.travel_time = roads[i].travel_time;
    centers[roads[i].center[0]].adjustent_centers.push_back(adj_center);

    adj_center.center = roads[i].center[0];
    adj_center.travel_time = roads[i].travel_time;
    centers[roads[i].center[1]].adjustent_centers.push_back(adj_center);
  }
}

int find_minimum_time(
    vector<center> &centers,
    int K)
{

}

int find_minimum_time(
    int N,
    int K,
    const vector<vector<int>> &fish_types,
    const vector<road> &roads)
{
  vector<center> centers(N);
  init_centers(nodes, fish_types, roads);
  return find_minimum_time(centers, K);
}

void test_hr_sample(void)
{
  int N = 5;
  int K = 5;

  vector<vector<int>> fish_types = {
    {1},
    {2},
    {3},
    {4},
    {5}};

  vector<road> roads = {
    {1, 2, 10},
    {1, 3, 10},
    {2, 4, 10},
    {3, 5, 10},
    {4, 5, 10},
    };

  int minimum_time = find_minimum_time(N, K, roads, fish_types);

  cout << minimum_time << endl;
  assert (minimum_time == 30);
}

void read_fish_types(vector<int> &fish_types)
{
    int fish_types_count;
    cin >> fish_types_count;

    for (int j=0; j<fish_types_count; ++j) {
      int fish_type;
      cin >> fish_type;
      fish_types.push_back(fish_type);
    }
}

void hr_testcase()
{
  int N;
  int M;
  int K;
  cin >> N >> M >> K;

  vector<vector<int> > fish_types(N);
  for (int i=0; i<N; ++i)
  {
    read_fish_types(fish_types[i]);
  }

  vector<road> roads(M);
  for (int i=0; i<M; ++i) {
    cin >> roads[i].center[0];
    cin >> roads[i].center[1];
    cin >> roads[i].travel_time;
  }

  int minimum_time = find_minimum_time(N, K, roads, fish_types);

  cout << minimum_time << endl;
}

void hackerrank()
{
  int T;
  cin >> T;

  for(int i = 0; i < T; i++) {
    hr_testcase();
  }
}

int main()
{
  //hackerrank();
  test_hr_sample();
  return 0;
}