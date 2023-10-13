/*
https://www.hackerrank.com/challenges/tree-top-view

Examples:

Discussion:

How to build:
Linux: g++ --std=c++11 <file>.cpp
Windows (vcvarsall.bat): cl /EHsc <file>.cpp
*/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;

// Class for a tree node
class TreeNode
{
    int key;
    TreeNode left, right;
 
    // Constructor
    public TreeNode(int key)
    {
        this.key = key;
        left = right = null;
    }
}
 
// A class to represent a queue item. The queue is used to do Level
// order traversal. Every Queue item contains node and horizontal
// distance of node from root
class QItem
{
   TreeNode node;
   int hd;
   public QItem(TreeNode n, int h)
   {
        node = n;
        hd = h;
   }
}
 
// Class for a Binary Tree
class Tree
{
    TreeNode root;
 
    // Constructors
    public Tree()  { root = null; }
    public Tree(TreeNode n) { root = n; }
 
    // This method prints nodes in top view of binary tree
    public void printTopView()
    {
        // base case
        if (root == null) {  return;  }
 
        // Creates an empty hashset
        TreeMap<Integer, TreeNode> topNodes = new TreeMap<Integer, TreeNode>();
 
        // Create a queue and add root to it
        Queue<QItem> Q = new LinkedList<QItem>();
        Q.add(new QItem(root, 0)); // Horizontal distance of root is 0
 
        // Standard BFS or level order traversal loop
        while (!Q.isEmpty())
        {
            // Remove the front item and get its details
            QItem qi = Q.remove();
            int hd = qi.hd;
            TreeNode n = qi.node;
 
            // If this is the first node at its horizontal distance,
            // then this node is in top view
            if (!topNodes.containsKey(hd))
            {
                topNodes.put(hd, n);
                //System.out.print(n.key + " ");
            }
 
            // Enqueue left and right children of current node
            if (n.left != null)
                Q.add(new QItem(n.left, hd-1));
            if (n.right != null)
                Q.add(new QItem(n.right, hd+1));
        }

        Set set = topNodes.entrySet();
        Iterator i = set.iterator();
        while(i.hasNext()) {
            Map.Entry me = (Map.Entry)i.next();
            TreeNode n = (TreeNode)me.getValue();
            System.out.print(n.key + " ");
        }
        System.out.println();
    }
}
 
// Driver class to test above methods
public class Solution2
{
    public static void main(String[] args)
    {
        /* Create following Binary Tree
             1
           /  \
          2    3
           \
            4
             \
              5
               \
                6*/
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.right = new TreeNode(4);
        root.left.right.right = new TreeNode(5);
        root.left.right.right.right = new TreeNode(6);
        Tree t = new Tree(root);
        System.out.println("Following are nodes in top view of Binary Tree");
        t.printTopView();
    }
}
