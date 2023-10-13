#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

#define MYDEBUG (1)

template <class T>
class BTreeNode
{
public:
    T data;

    BTreeNode* parent;
    BTreeNode* left;
    BTreeNode* right;

    BTreeNode(
        T a_data,
        BTreeNode* a_parent = nullptr,
        BTreeNode* a_left = nullptr,
        BTreeNode* a_right = nullptr
        ): data(a_data), parent(a_parent), left(a_left), right(a_right) {}

    T get_data() {
        return data;
    }
};

template <class T>
class BTree
{
public:
    BTreeNode<T> *root;
    size_t size;

    BTree(): root(nullptr), size(0) {}

    BTree(BTreeNode<T> *a_root): root(a_root), size(0) {
        set_size(a_root);
    }

    ~BTree() {
        free_memory(root);
    }

    // bst only: insert data in order
    void insert_in_order(const T& data) {
        if (root == nullptr) {
            root = new BTreeNode<T>(data);
            size++;
            return;
        }

        insert_in_order(root, data);
    }

    // same functionality as 'insert_in_order' just implemented without using
    // recursion
    void insert_in_order2(const T&);

    // any btree:
    bool is_balanced() const {
        std::cout << "=== isBalanced ===" << std::endl;
        reset_visits();
        bool result = is_balanced(root);
        std::cout << "*** isBalanced visits: " << get_visits() << std::endl;
        return result;
    }

    bool is_balanced2() const;

    size_t get_height() {
        return get_height(root);
    }

    void print_in_order(bool single_line=false) const {
        print_in_order(root, single_line);
    }

    void print_bfs() const;

    // create minimal BST given an array of sorted integers
    void minimal_bst(int arr[], size_t size) {
        minimal_bst(arr, 0, size-1);
    }

    BTreeNode<T> *first_common_ancestor(BTreeNode<T> *n1, BTreeNode<T> *n2) {
        vector<BTreeNode<T>*> path_to_n1;
        vector<BTreeNode<T>*> path_to_n2;

        find_path_to_node(n1, path_to_n1);
        find_path_to_node(n2, path_to_n2);

        size_t min_size = min(path_to_n1.size(), path_to_n2.size());
        unsigned i;
        for (i=1; i<min_size; ++i) {
            if (path_to_n1[i] != path_to_n2[i]) {
                break;
            }
        }

        return path_to_n1[i-1];
    }

    void find_path_to_node(
            BTreeNode<T> *n,
            std::vector<BTreeNode<T>*> &path_to_n) {
        find_path_to_node(n, path_to_n, root);
        #ifdef MYDEBUG
        cout << "path to " << n->data << " is ";
        for (auto node: path_to_n) {
            cout << node->data << ":";
        }
        cout << endl;
        #endif
    }

    // bst only: successor is right child if exists, otherwise it's' first
    // bigger parent
    BTreeNode<T> *find_successor(BTreeNode<T> *node) {

    }

    static int get_visits() { return visits; }
    static void reset_visits() { visits = 0; }

private:
    static int visits;  // counts number of node visits since last counter reset

    void set_size(BTreeNode<int> *node) {
        if (node == nullptr) return;

        size++;
        set_size(node->left);
        set_size(node->right);
    }

    bool find_path_to_node(
            BTreeNode<T> *n,
            std::vector<BTreeNode<T>*> &path_to_n,
            BTreeNode<T> *current) {

        if (current == n) {
            path_to_n.push_back(current);
            return true;
        }

        if (current == nullptr) {
            return false;
        }

        path_to_n.push_back(current);

        bool lresult = find_path_to_node(n, path_to_n, current->left);
        bool rresult = find_path_to_node(n, path_to_n, current->right);

        if (lresult || rresult) {
            return true;
        }

        path_to_n.pop_back();
        return false;
    }

    void free_memory(BTreeNode<T>*);
    void insert_in_order(BTreeNode<T>*, const T&);
    size_t get_height(BTreeNode<T>*) const;
    bool is_balanced(BTreeNode<T>*) const;
    int is_balanced2(BTreeNode<T>*) const;

    // print elements following depth first in order search
    void print_in_order(BTreeNode<T>* node, bool single_line=false) const
    {
        if (node == nullptr)
        {
            return;
        }

        print_in_order(node->left, single_line);
        std::cout << node->get_data();
        if (single_line) {
            std::cout << ":";
        } else {
            std::cout << std::endl;
        }
        print_in_order(node->right, single_line);
    }

    void minimal_bst(
            int arr[],
            size_t first,
            size_t last)
    {
        #ifdef MYDEBUG
        std::cout << "first=" << first << ", last=" << last << std::endl;
        #endif
        if (first > last) {
            return;
        }

        if (first == last) {
            insert_in_order(arr[first]);
            return;
        }

        // important: mid element must be ceil((last - first)/2)
        // id does not work if we take floor((last - first)/2)
        size_t m = (last - first - 1) / 2 + 1; // = ceil((last - first)/2)
        insert_in_order(arr[first+m]);

        minimal_bst(arr, first, first+m-1);
        minimal_bst(arr, first+m+1, last);
    }
};

template <class T>
int BTree<T>::visits = 0;

template <class T>
void BTree<T>::free_memory(BTreeNode<T>* node)
{
    if (node == nullptr)
    {
        return;
    }

    free_memory(node->left);
    free_memory(node->right);

    delete node;
}

template <class T>
void BTree<T>::insert_in_order(BTreeNode<T>* node, const T& data)
{
    if (data < node->get_data())
    {
        if (node->left == nullptr) {
            node->left = new BTreeNode<T>(data, node);
            size++;
        } else {
            insert_in_order(node->left, data);
        }
    }
    else
    {
        if (node->right == nullptr) {
            node->right = new BTreeNode<T>(data, node);
            size++;
        } else {
            insert_in_order(node->right, data);
        }
    }
}

template <class T>
void BTree<T>::insert_in_order2(const T& data)
{
    if (root == nullptr)
    {
        root = new BTreeNode<T>(data);
        size++;
        return;
    }

    BTreeNode<T>* node = root;
    while (node != nullptr)
    {
        if (data < node->get_data())
        {
            if (node->left == nullptr) {
                node->left = new BTreeNode<T>(data, node);
                break;
            } else {
                node = node->left;
            }
        } else {
            if (node->right == nullptr) {
                node->right = new BTreeNode<T>(data, node);
                break;
            } else {
                node = node->right;
            }
        }
    }

    size++;
}

// print elements following breath first search
template <class T>
void BTree<T>::print_bfs() const
{
    if (root == nullptr) return;

    std::queue<BTreeNode<T>*> nodes;
    nodes.push(root);

    BTreeNode<T>* node;
    while (!nodes.empty()) {
        node = nodes.front();
        nodes.pop();
        std::cout << node->get_data() << std::endl;
        if (node->left) nodes.push(node->left);
        if (node->right) nodes.push(node->right);
    }
}

template <class T>
size_t BTree<T>::get_height(BTreeNode<T>* node) const
{
    if (node == nullptr)
    {
        return 0;
    }

    BTree<T>::visits++;

    size_t lh = get_height(node->left);
    size_t rh = get_height(node->right);

    #ifdef MYDEBUG
    std::cout << "getHeight " << node->get_data() << " LH:" << lh << " RH:" << rh << endl;
    #endif

    return std::max(lh, rh) + 1;
}

// this implementation is not very efficient, every node is visited multiple times
// complexity is O(n^2)
//
// Example:
//               5
//              / \
//             3   7
//            /     \
//           1       9
//          /
//         0
//
// h(5->left) = 3
// h(5->right) = 2
// 5 is ok
//
// h(3->left) = 2
// h(3->right) = 0
// 3 is not ok, therefore tree is not balanced
template <class T>
bool BTree<T>::is_balanced(BTreeNode<T>* node) const
{
    if (node == nullptr)
    {
        return true;
    }

    BTree<T>::visits++;

    int lh = get_height(node->left);
    int rh = get_height(node->right);

    #ifdef MYDEBUG
    std::cout << "isBalanced " << node->get_data() << " LH:" << lh << " RH:" << rh << endl;
    #endif

    if (abs(lh-rh) > 1)
    {
        return false;
    }

    bool lb = is_balanced(node->left);
    bool rb = is_balanced(node->right);

    #ifdef MYDEBUG
    std::cout << "isBalanced " << node->get_data() << " LB:" << lb << " RB:" << rb << endl;
    #endif

    return lb && rb;
}

// this is more efficient implementation of balance check
// relies on different implementation of finding height which returns -1 if node is not balanced
// this reduces number of visits to each node
// complexity is O(n)
template <class T>
bool BTree<T>::is_balanced2() const
{
    std::cout << "=== isBalanced2 ===" << std::endl;
    reset_visits();
    int result = is_balanced2(root);
    std::cout << "*** isBalanced2 visits: " << get_visits() << std::endl;
    return (result != -1);
}

template <class T>
int BTree<T>::is_balanced2(BTreeNode<T>* node) const
{
    if (node == nullptr)
    {
        return 0;
    }

    BTree<T>::visits++;

    int lh = is_balanced2(node->left);
    if (lh == -1)
    {
        return -1;
    }

    int rh = is_balanced2(node->right);
    if (rh == -1)
    {
        return -1;
    }

    if (abs(lh-rh) > 1)
    {
        return -1;
    }

    return std::max(lh, rh) + 1;
}

#endif // BTREE_H
