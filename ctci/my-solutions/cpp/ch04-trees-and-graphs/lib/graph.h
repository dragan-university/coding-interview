#ifndef __GRAPH_H
#define __GRAPH_H

#include <iostream>
#include <vector>
#include <queue>

//#define MYDEBUG (1)

template <class T>
class Node
{
private:
    T data;

public:
    bool visited;
    std::vector<Node*> adjacency_list;

    Node(
        T a_data,
        std::vector<Node*> a_adjacency_list = std::vector<Node*>()): 
            data(a_data), adjacency_list(a_adjacency_list), visited(false) {}

    T get_data() {
        return data;
    }

    void add_adjacent(Node* node) {
        adjacency_list.push_back(node);
    }
};

template <class T>
class Graph
{
private:
    std::vector<Node<T> *> nodes;
    size_t size;

public:
    Graph(): nodes(std::vector<Node<T>*>()), size(0) {}
    ~Graph() {
        for (size_t ix=0; ix<nodes.size(); ix++) {
            delete nodes[ix];
        }
    }

    size_t get_size() {
        return size;
    }

    void add_node(Node<T>* node) {
        nodes.push_back(node);
        size++;
    }

    bool are_nodes_connected(Node<T> *n1, Node<T> *n2) {
        for (size_t ix=0; ix<nodes.size(); ix++) {
            nodes[ix]->visited = false;
        }

        std::queue<Node<T> *> qnodes;
        qnodes.push(n1);

        Node<T> *qnode;
        while (!qnodes.empty()) {
            qnode = qnodes.front();
            qnodes.pop();

            if (!qnode->visited) {
                if (qnode == n2) {
                    return true;
                }

                qnode->visited = true;
                for (size_t ix=0; ix<qnode->adjacency_list.size(); ix++) {
                    if (!qnode->adjacency_list[ix]->visited) {
                        qnodes.push(qnode->adjacency_list[ix]);
                    }
                }
            }
        }

        return false;
    }

    void print_dfs() {
        for (size_t ix=0; ix<nodes.size(); ix++) {
            nodes[ix]->visited = false;
        }

        for (size_t ix=0; ix<nodes.size(); ix++) {
            print_dfs(nodes[ix]);
        }
    }

    void print_bfs() {
        for (size_t ix=0; ix<nodes.size(); ix++) {
            nodes[ix]->visited = false;
        }

        for (size_t ix=0; ix<nodes.size(); ix++) {
            print_bfs(nodes[ix]);
        }
    }

    /*
    n1 --> n2,n3,n4
    n2 --> n1
    n3 --> n6,n7
    n4 --> (none)
    n5 --> n6,n7
    n6 --> n3
    n7 --> (none)
    */
    void create_directed_test_graph()
    {
        Node<T> *n1 = new Node<T>(1);
        Node<T> *n2 = new Node<T>(2);
        Node<T> *n3 = new Node<T>(3);
        Node<T> *n4 = new Node<T>(4);
        Node<T> *n5 = new Node<T>(5);
        Node<T> *n6 = new Node<T>(6);
        Node<T> *n7 = new Node<T>(7);

        n1->add_adjacent(n2);
        n1->add_adjacent(n3);
        n1->add_adjacent(n4);
            
        n2->add_adjacent(n1);

        n3->add_adjacent(n6);
        n3->add_adjacent(n7);

        n5->add_adjacent(n6);
        n5->add_adjacent(n7);

        n6->add_adjacent(n3);

        add_node(n1);
        add_node(n2);
        add_node(n3);
        add_node(n4);
        add_node(n5);
        add_node(n6);
        add_node(n7);
    }

    /*
    n1 -- n2,n3,n8
    n2 -- n1,n3
    n3 -- n1,n2,n4,n8
    n4 -- n3,n8
    n5 -- (none)
    n6 -- n7
    n7 -- n6
    n8 -- n1,n3,n4
    */
    void create_test_graph()
    {
        Node<T> *n1 = new Node<T>(1);
        Node<T> *n2 = new Node<T>(2);
        Node<T> *n3 = new Node<T>(3);
        Node<T> *n4 = new Node<T>(4);
        Node<T> *n5 = new Node<T>(5);
        Node<T> *n6 = new Node<T>(6);
        Node<T> *n7 = new Node<T>(7);
        Node<T> *n8 = new Node<T>(8);

        n1->add_adjacent(n2);
        n2->add_adjacent(n1);
        n1->add_adjacent(n3);
        n3->add_adjacent(n1);
        n1->add_adjacent(n8);
        n8->add_adjacent(n1);

        n2->add_adjacent(n3);
        n3->add_adjacent(n2);
            
        n3->add_adjacent(n4);
        n4->add_adjacent(n3);
        n3->add_adjacent(n8);
        n8->add_adjacent(n3);

        n4->add_adjacent(n8);
        n8->add_adjacent(n4);

        n6->add_adjacent(n7);
        n7->add_adjacent(n6);

        add_node(n1);
        add_node(n2);
        add_node(n3);
        add_node(n4);
        add_node(n5);
        add_node(n6);
        add_node(n7);
        add_node(n8);
    }

    Node<T> *get_test_node(T data) {
        for (size_t ix=0; ix<nodes.size(); ix++) {
            if (nodes[ix]->get_data() == data) {
                return nodes[ix];
            }
        }

        return nullptr;
    }

private:
    void print_dfs(Node<T> *node) {
        if (!node->visited) {
            std::cout << node->get_data() << std::endl;
            node->visited = true;

            // visit all adjacent nodes
            for (size_t ix=0; ix<node->adjacency_list.size(); ix++) {
                print_dfs(node->adjacency_list[ix]);
            }
        }
    }

    void print_bfs(Node<T> *node) {
        std::queue<Node<T> *> qnodes;
        qnodes.push(node);
        
        Node<T> *qnode;
        while (!qnodes.empty()) {
            qnode = qnodes.front();
            qnodes.pop();

            if (!qnode->visited) {
                std::cout << qnode->get_data() << std::endl;
                qnode->visited = true;

                for (size_t ix=0; ix<qnode->adjacency_list.size(); ix++) {
                    if (!qnode->adjacency_list[ix]->visited) {
                        qnodes.push(qnode->adjacency_list[ix]);
                    }
                }
            }
        }
    }
};

#endif // __GRAPH_H
