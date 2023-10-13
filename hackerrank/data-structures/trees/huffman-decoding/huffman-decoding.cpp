#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
The structure of the node
*/
typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
} node;



void decode_huff(node * root, string s)
{
    node * current_node = root;
    string decode = "";

    for (char c: s)
    {
        if (c == '1')
        {
            current_node = current_node->right;
        }
        else
        {
            current_node = current_node->left;
        }

        if (current_node->data != '\0')
        {
            decode += current_node->data;
            current_node = root;
        }
    }

    cout << decode << endl;
}

int main() {
    node b = {1, 'b', nullptr, nullptr};
    node c = {1, 'c', nullptr, nullptr};
    node g1 = {2, 0, &b, &c};
    node a = {3, 'a', nullptr, nullptr};
    node root = {5, 0, &g1, &a};

    decode_huff(&root, "1001011");

    return 0;
}

