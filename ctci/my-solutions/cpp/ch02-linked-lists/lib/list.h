/*
list.h -- singley linked list implementation
*/
#ifndef __DDN_LIST_H__
#define __DDN_LIST_H__

#include <string>

namespace ddn {
struct EmptyListException: public std::exception
{
  const char* what () const throw () {
    return "Empty List Exception!";
  }
};

struct UknownListItemException: public std::exception
{
  const char* what () const throw () {
    return "List item does not exist!";
  }
};

template <typename T>
struct node {
    T data;
    node* next;

    node(const T& a_data, node* a_next): data(a_data), next(a_next) {};
};

template <typename T>
class list
{
protected:
    node<T>* head;
    node<T>* tail;

public:
    list() {
        head = NULL;
        tail = NULL;
        _size = 0;
    }

    list(const list& original) {
        head = NULL;
        tail = NULL;

        node<T>* o_node = original.get_head();
        while (o_node) {
            push_back(o_node->data);
            o_node = o_node->next;
        }
    }

    ~list() {
        while (head != NULL) {
            node<T>* current = head;
            head = head->next;
            delete current;
        }
    }

    size_t size() const {
        return _size;
    }

    void push_front(const T& data) {
        node<T>* new_node = new node<T>(data, head);
        head = new_node;

        if (tail == NULL) {
            tail = head;
        }

        _size++;
    }

    void push_back(const T& data) {
        node<T>* new_node = new node<T>(data, NULL);
        if (tail) {
            tail->next = new_node;
            tail = new_node;
        } else {
            head = new_node;
            tail = new_node;
        }

        _size++;
    }

    void remove(const T& data) {
        if (head == NULL) {
            throw EmptyListException();
        }

        node<T>* a_node = head;

        if (a_node->data == data) {
            head = a_node->next;
            delete a_node;
            _size--;
            return;
        }

        while (a_node->next) {
            if (a_node->next->data == data) {
                node<T>* to_delete = a_node->next;
                a_node->next = a_node->next->next;
                delete to_delete;
                _size--;
                return;
            }
        }

        throw UknownListItemException();
    }

    void remove(node<T>* a_node) {
        a_node->data = a_node->next->data;
        node<T>* to_delete = a_node->next;
        a_node->next = a_node->next->next;
        delete to_delete;
        _size--;
    }

    node<T>* get_head() {
        return head;
    }

    // this is needed to support passing const list as an argument
    node<T>* get_head() const {
        return head;
    }

    bool is_same(const list& other) {
        node<T>* this_node = head;
        node<T>* other_node = other.get_head();

        while(this_node && other_node) {
            if (this_node->data != other_node->data) {
                return false;
            }

            this_node = this_node->next;
            other_node = other_node->next;
        }

        if (this_node || other_node) {
            return false;
        }

        return true;
    }

    void print(std::string note = "list") const {
        node<T>* a_node = head;
        cout << note << " = ";
        while (a_node) {
            cout << a_node->data << ":";
            a_node = a_node->next;
        }
        cout << endl;
    }

private:
    size_t _size;
};  // class list
}  // namspace ddn

#endif  // __DDN_LIST_H__