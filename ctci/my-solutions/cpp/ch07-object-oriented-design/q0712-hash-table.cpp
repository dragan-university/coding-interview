/*
Design and implement a hash table which uses chaining (linked list) to handle 
collisions.

Analysis:
- Hash table internals
  - hash function - converts an element into a number
  - max size of hash table entrie
    - e.g. int value
  - hash table entry
    - hash
    - data
    - link to list
- Hash table interface
  - add(element)
  - find(element)
  - remove(element)
  - size()

*/

#include <list>
#include <vector>
using namespace std;

template <typename T>
class Hash {
    vector<list<T> > _table;
    size_t _size;

    Hash(size_t hash_size) {
        _size = 0;
        _table = vector<list<T> >(hash_size); 
    }

    size_t _calculate_hash(T data) {

    }

public:
    void add(const T &data) {
        size_t hash = _calculate_hash(data);
        list<T> l = _table[hash];

        if (l.find(data) == nullptr) {
            l.push_back(data);
        } else {
            raise("already in the ")
        }
    }    
};