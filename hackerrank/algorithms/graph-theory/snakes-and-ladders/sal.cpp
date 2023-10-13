#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <cassert>

using namespace std;

const bool MY_DEBUG = false;

struct node 
{
  vector<int> connections;  // nodes to which this node is connected
  int number_of_moves;  // number of moves to reach this node (-1 indicates node has not been visited)
};

void init_nodes(vector<node>& nodes, int max_move, const vector<pair<int, int>>& ladders, const vector<pair<int, int>>& snakes)
{
  // set connections
  for (int i=0; i<nodes.size(); ++i) {
    for (int j=1; j<=max_move; ++j) {
      nodes[i].connections.push_back(i+j);
    }
    
    nodes[i].number_of_moves = -1;
  }
  
  // set ladders
  for (int i=0; i<ladders.size(); ++i) {
    int ladder_base = ladders[i].first-1;
    int ladder_top = ladders[i].second-1;
    
    for (int i=1; i<=max_move && (ladder_base-i)>=0; ++i) {
      nodes[ladder_base-i].connections[i-1] = ladder_top;
    }
  }
    
  // set snakes
  for (int i=0; i<snakes.size(); ++i) {
    int snake_base = snakes[i].first-1;
    int snake_bottom = snakes[i].second-1;
    
    for (int i=1; i<=max_move && (snake_base-i)>=0; ++i) {
      nodes[snake_base-i].connections[i-1] = snake_bottom;
    }
  }
}

int find_shortest_path(vector<node>& nodes) {
  queue<int> nodes_to_process;  // indexes of nodes to process
  nodes_to_process.push(0);
  nodes[0].number_of_moves = 0;
    
  while(!nodes_to_process.empty()) {
    int node_idx = nodes_to_process.front();
    if (MY_DEBUG) {
      cout << "node_idx: " << node_idx << endl;
    }
    nodes_to_process.pop();
       
    for (vector<int>::iterator it = nodes[node_idx].connections.begin(); it != nodes[node_idx].connections.end(); ++it) {
      if (MY_DEBUG) {
        cout << "move: " << *it << endl;
      }
      if (nodes[*it].number_of_moves == -1) {
        nodes[*it].number_of_moves = nodes[node_idx].number_of_moves + 1;
        nodes_to_process.push(*it);
      }
        
      if (*it == nodes.size()-1) {
        return nodes[*it].number_of_moves;
      }
    }
  }

  return -1;
}

int find_shortest_path(
    int board_size, 
    int max_move, 
    const vector<pair<int, int>>& ladders,
    const vector<pair<int, int>>& snakes)
{     
  vector<node> nodes(board_size);
  
  init_nodes(nodes, max_move, ladders, snakes);
  
  return find_shortest_path(nodes);
}

void test_my_01(void)
{
  int BOARD_SIZE = 27;
  const int MAX_MOVE = 5;
  vector<pair<int, int>> ladders = {{6, 17}, {8, 20}, {10, 15}, {19, 26}};
  vector<pair<int, int>> snakes = {{16, 11}};
  
  int shortest_path = find_shortest_path(BOARD_SIZE, MAX_MOVE, ladders, snakes);
  
  cout << shortest_path << endl;
  assert (shortest_path == 3);
}

void test_hr_0101(void)
{
  int BOARD_SIZE = 100;
  const int MAX_MOVE = 6;
  vector<pair<int, int>> ladders = {
    {32, 62}, 
    {42, 68}, 
    {12, 98}};
  vector<pair<int, int>> snakes = {
    {95, 13},
    {97, 25},
    {93, 37},
    {79, 27},
    {75, 19},
    {49, 47},
    {67, 17}};
  
  int shortest_path = find_shortest_path(BOARD_SIZE, MAX_MOVE, ladders, snakes);
  
  cout << shortest_path << endl;
  assert (shortest_path == 3);
}

void test_hr_0201(void)
{
  int BOARD_SIZE = 100;
  const int MAX_MOVE = 6;
  vector<pair<int, int>> ladders = {
    {3, 54}, 
    {37, 100}};
  vector<pair<int, int>> snakes = {
    {56, 33}};
  
  int shortest_path = find_shortest_path(BOARD_SIZE, MAX_MOVE, ladders, snakes);
  
  cout << shortest_path << endl;
  assert (shortest_path == 3);
}

void test_hr_0202(void)
{
  int BOARD_SIZE = 100;
  const int MAX_MOVE = 6;
  vector<pair<int, int>> ladders = {
    {3, 57},
    {8, 100}};
  vector<pair<int, int>> snakes = {
    {88, 44}};
  
  int shortest_path = find_shortest_path(BOARD_SIZE, MAX_MOVE, ladders, snakes);
  
  cout << shortest_path << endl;
  assert (shortest_path == 2);
}

void test_hr_0203(void)
{
  int BOARD_SIZE = 100;
  const int MAX_MOVE = 6;
  vector<pair<int, int>> ladders = {
    {7, 98}};
  vector<pair<int, int>> snakes = {
    {99, 1}};
  
  int shortest_path = find_shortest_path(BOARD_SIZE, MAX_MOVE, ladders, snakes);
  
  cout << shortest_path << endl;
  assert (shortest_path == 2);
}

void hr_testcase()
{
  int N;
  cin >> N;
  
  vector<pair<int, int>> ladders(N);
  for (int i=0; i<N; ++i)
  {
    cin >> ladders[i].first >> ladders[i].second;
  }

  int M;
  cin >> M;
  
  vector<pair<int, int>> snakes(M);
  for (int i=0; i<M; ++i)
  {
    cin >> snakes[i].first >> snakes[i].second;
  }

  int shortest_path = find_shortest_path(100, 6, ladders, snakes);
  
  cout << shortest_path << endl;
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
  //test_my_01();
  //test_hr_0101();
  test_hr_0201();
  test_hr_0202();
  test_hr_0203();
  return 0;
}