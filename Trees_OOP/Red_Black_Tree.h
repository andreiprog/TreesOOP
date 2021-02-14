#ifndef RED_BLACK_TREE_H_INCLUDED
#define RED_BLACK_TREE_H_INCLUDED

#include <iostream>
#include "Tree.h"
#include "Nod.h"
#include "Nod_Red_Black.h"
using namespace std;

class Red_Black_Tree:public Tree{
protected:
    Nod_Red_Black *root;
public:
    Red_Black_Tree():Tree(),root(nullptr){} // constructor
    Nod_Red_Black* copy_red_black_tree(Nod_Red_Black*,Nod_Red_Black*);  // helper function for copy constructor
    Red_Black_Tree(Red_Black_Tree&);  // copy constructor
    Nod_Red_Black* delete_tree(Nod_Red_Black*); // helper function for destructor
    ~Red_Black_Tree();          // destructor
    Red_Black_Tree& operator=(Red_Black_Tree&); // overloading operator =
    Nod_Red_Black* get_root();      // getter
    Nod_Red_Black* insertBST(Nod_Red_Black*,Nod_Red_Black*);  // helper function for insertNode function
    Nod_Red_Black* rotateRight(Nod_Red_Black*); // helper function for balanceRedBlackTree function
    Nod_Red_Black* rotateLeft(Nod_Red_Black*);  // helper function for balanceRedBlackTree function
    Nod_Red_Black* balanceRedBlackTree(Nod_Red_Black*,Nod_Red_Black*);  // helper function for insertNode function
    Nod_Red_Black* insertNode(Nod_Red_Black*,int);  // helper function for insert_node function
    Nod_Red_Black* search_Nod(Nod_Red_Black*,int);  // helper function for deleteNode function
    Nod_Red_Black* successor(Nod_Red_Black*);       // helper function for replace_BST function
    Nod_Red_Black* replace_BST(Nod_Red_Black*);      // helper function for delete_Red_Black_Tree_Node function
    Nod_Red_Black* node_sibling(Nod_Red_Black*);    // helper function for fixDoubleBlack function
    bool hasRedChild(Nod_Red_Black*);               // helper function for fixDoubleBlack function
    void fixDoubleBlack(Nod_Red_Black*&,Nod_Red_Black*);    // helper function for delete_Red_Black_Tree_Node function
    void delete_Red_Black_Tree_Node(Nod_Red_Black*&,Nod_Red_Black*);    // helper function for deleteNode function
    Nod_Red_Black* deleteNode(Nod_Red_Black*&,int);     // helper function for delete_node function
    void insert_node(int);      // virtual function for insert a node
    void delete_node(int);      // virtual function for delete a node
    void preorder_helper(Nod_Red_Black*);   // helper function for preorder function
    void preorder();            // virtual function for preorder  traversal
    void inorder_helper(Nod_Red_Black*);    // helper function for inorder function
    void inorder();             // virtual function for inorder  traversal
    void postorder_helper(Nod_Red_Black*);  // helper function for postorder function
    void postorder();           // virtual function for postorder  traversal
    virtual int black_depth(); // virtual function for find black_depth of the red-black tree
    friend istream& operator>>(istream&,Red_Black_Tree&);   // overloading operator >>
    friend ostream& operator<<(ostream&,Red_Black_Tree&);   // overloading operator <<
};

#endif // RED_BLACK_TREE_H_INCLUDED
