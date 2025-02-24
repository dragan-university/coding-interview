/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

import java.util.ArrayList;
import java.util.List;

public class Solution {
    public static int maxDepth(Node root) {
        if (root == null) {
            return 0;
        }
        
        List<Node> level = new ArrayList<Node>();
        level.add(root);
        int depth = 0;

        while (!level.isEmpty()) {
            List<Node> nextLevel = new ArrayList<Node>();

            for (Node node : level) {
                for (Node child: node.children) {
                    nextLevel.add(child);
                }
            }

            depth++;
            level = nextLevel;
        }

        return depth;
    }

    private static void testMaxDepth() {
        Node n6 = new Node(6, null);
        Node n5 = new Node(5, null);
        Node n4 = new Node(4, null);

        List<Node> n3children = new ArrayList<>();
        n3children.add(n5);
        n3children.add(n6);
        Node n3 = new Node(3, n3children);

        Node n2 = new Node(2, null);

        List<Node> n1children = new ArrayList<>();
        n1children.add(n2);
        n1children.add(n3);
        n1children.add(n4);
        Node n1 = new Node(1, n1children);

        int depth = maxDepth(n1);
        System.out.println(depth);
    }

    private static void testMaxDepthEmpty() {
        Node n = null;
        
        int depth = maxDepth(n);
        System.out.println(depth);
    }

    public static void main(String[] args) {
        testMaxDepth();
        testMaxDepthEmpty();
    }    
}

// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
