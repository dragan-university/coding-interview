/*
Explain the data structure and algorithms that you would use to design an
in-memory file system. Illustrate with an example in code where possible.

Analysis:
- File system has directories and files
- Need commands to create, modify and delete files
- Tree structure
  - Node can be file or dir
  - Node can have other nodes
  - What are limits 
    - how many subnodes per node?
    - maximum node name size

*/

#include <set>
#include <string>
#include <vector>
using namespace std;


class Node
{
    Node *_parent;
    string _name;
    set<Node *> _nodes;

public:
    Node(
            Node *parent=nullptr, 
            string name="root"): _parent(parent), _name(name) {
        
    }
};

class File: public Node
{
    vector<char> content;

public:
    File(Node *parent)
};

class FileSystem
{
    Node *root;

public:
    FileSystem() {
        root = new Node(Directory);
    }

    void create(NodeType type, Node *parent) {
        
    }
};