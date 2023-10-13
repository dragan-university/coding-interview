/*
https://www.hackerrank.com/challenges/ctci-contacts

How to time execution:
Mac & Linux:
$ time ./a.out

20170816: fails only test case 01
20170815: most of the test pass, some time out
    Improvement to do: save number of words under each node to speed up
    couting nuber of words.
*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
const bool DEBUG = false; 

struct TrieNode
{
    map<char, TrieNode*> values;
    bool is_final;
    size_t size;

    TrieNode() { 
        is_final = false;
        size = 0; 
    }
};

void print_trie(TrieNode* node, string& node_value)
{
    cout << "final:" << node->is_final << " size:" << node->size << " value:" << node_value << endl;
    for (auto& item: node->values) {
        node_value += item.first;
        print_trie(item.second, node_value);
        node_value = node_value.substr(0, node_value.length()-1);
    }
}

void add_contact(const string& contact, TrieNode* root)
{
    TrieNode* node = root;
    if (DEBUG) cout << "add " << contact << endl;
    for (auto c: contact) {
        if (node->values.count(c) == 0) {
            node->values[c] = new TrieNode;
        }

        node->size++;
        node = node->values[c];
    }

    node->is_final = true;
    node->size++;
    if (DEBUG) {
        string value = "*";
        print_trie(root, value);
    }
}

size_t find_contact(const string& contact, TrieNode* node)
{
    if (DEBUG) cout << "find " << contact;
    for (auto c: contact) {
        if (node->values.count(c) == 0) {
            if (DEBUG) cout << " - 0" << endl;
            return 0;
        }

        node = node->values[c];
    }

    return node->size;
}

void test_from_file(size_t n, ifstream &infile, ifstream &outfile)
{
    TrieNode* root = new TrieNode;

    for (size_t i=0; i<n; i++) {
        string op;
        string contact;

        infile >> op;
        infile >> contact;

        if (op == "add") {
            add_contact(contact, root);
        } else {
            size_t count = find_contact(contact, root);

            size_t expected;
            outfile >> expected;

            if (count != expected) {
                cout << "Find " << contact << " fails! Expected:" << 
                    expected << ", actual:" << count << endl;
                return;
            }
        }
    }
}

void test_from_file(const string& input, const string& output)
{
    ifstream infile(input);
    ifstream outfile(output);
    
    size_t n;
    infile >> n;
    cout << "n=" << n << endl;
  
    test_from_file(n, infile, outfile);
}

void perform_operation(const string& op, const string& contact, TrieNode* node)
{
    if (op == "add") {
        add_contact(contact, node);
    } else {
        size_t count = find_contact(contact, node);
        cout << count << endl;
    }
}

void hackerrank()
{
    TrieNode* root = new TrieNode;
    int n;
    cin >> n;

    vector<int> x(n);
    for(size_t i=0; i<n; i++) {
        string op;
        string contact;
        cin >> op;
        cin >> contact;

        perform_operation(op, contact, root);
    }
}

int main() {

    //hackerrank();
    test_from_file(
        "contacts-testcases/input/input03.txt",
        "contacts-testcases/output/output03.txt");
    return 0;
}
