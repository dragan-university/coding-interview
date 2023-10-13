#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include <algorithm>

const bool HEAP_DEBUG = false;

void print_heap(const std::vector<int>& v, const char* message="heap=")
{
    std::cout << message;
    for (auto item: v) {
        std::cout << item << ":";
    }
    std::cout << std::endl;
}

struct EmptyHeapException: public std::exception
{
  const char* what () const throw ()
  {
    return "Empty Heap Exception";
  }
};

struct RootHasNoParentException: public std::exception
{
  const char* what () const throw ()
  {
    return "Root item has no parent Exception";
  }
};

template <class T>
class Heap
{
public:
    Heap(bool min_heap=true): _min_heap(min_heap) {}

    T pop() {
        if (_data.empty()) throw EmptyHeapException();
        T value = _data[0];
        if (HEAP_DEBUG) std::cout << "pop " << value << std::endl;
        _data[0] = _data.back();
        _data.pop_back();
        if (HEAP_DEBUG) print_heap(_data, "befor hdown=");
        _heapify_down();
        if (HEAP_DEBUG) print_heap(_data, "after hdown=");

        return value;
    }

    void push(const T &item) {
        if (HEAP_DEBUG) std::cout << "push " << item << std::endl;
        _data.push_back(item);
        if (HEAP_DEBUG) print_heap(_data, "after adding=");
        _heapify_up();
        if (HEAP_DEBUG) print_heap(_data, "after heapify=");
    }

    bool empty() {
        return _data.empty();
    }

    size_t size() {
        return _data.size();
    }

private:
    std::vector<T> _data;
    bool _min_heap;

    void _heapify_up() {
        size_t node_idx = _data.size()-1;
        while (node_idx > 0 && _comp(node_idx, _parent(node_idx))) {
            _swap(node_idx, _parent(node_idx));
            node_idx = _parent(node_idx);
        }  
    }

    void _heapify_down() {
        size_t node_idx = 0;

        while (node_idx < _data.size()) {
            if (HEAP_DEBUG) {
                std::cout << "node_idx=" << node_idx << " l_idx=" << 
                    _lchild(node_idx) << " ridx=" << _rchild(node_idx) << std::endl;
            }

            size_t lchild_idx = _lchild(node_idx);
            size_t rchild_idx = _rchild(node_idx);
            
            if (_check_index(lchild_idx) && !_comp(node_idx, lchild_idx)) {
                if (HEAP_DEBUG) std::cout << "swap with left" << std::endl;
                _swap(node_idx, lchild_idx);
                node_idx = lchild_idx;
            }
            
            if (_check_index(rchild_idx) && !_comp(node_idx, rchild_idx)) {
                if (HEAP_DEBUG) std::cout << "swap with right" << std::endl;
                _swap(node_idx, rchild_idx);
                node_idx = rchild_idx;
            } else {
                if (HEAP_DEBUG) std::cout << "done swapping" << std::endl;
                break;
            }
        }
    }

    size_t _lchild(size_t index) {
        return 2*index+1;
    }

    size_t _rchild(size_t index) {
        return 2*(index+1);
    }

    bool _check_index(size_t index) {
        return (index < _data.size());
    }

    size_t _parent(size_t index) {
        if (index == 0) throw RootHasNoParentException();
        return (index-1)/2; 
    }

    void _swap(size_t idx1, size_t idx2) {
        T t = _data[idx1];
        _data[idx1] = _data[idx2];
        _data[idx2] = t;
    } 

    bool _comp(size_t idx1, size_t idx2) {
        if (HEAP_DEBUG) {
            std::cout << "comp: idx1=" << idx1 << ":" << _data[idx1] << 
                " idx2=" << idx2 << ":" << _data[idx2] << std::endl;
        }

        if (_data[idx1] < _data[idx2]) {
            return _min_heap;
        } else {
            return !_min_heap;
        }
    }
};

#endif // HEAP_H
