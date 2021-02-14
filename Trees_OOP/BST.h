#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include <iostream>
#include "Nod.h"
#include "Tree.h"
using namespace std;

class BST:public Tree{
protected:
    Nod *root;
public:
    BST():Tree(),root(nullptr){} // constructor
    Nod* copy_bst(Nod*,Nod*); // helper function for copy constructor
    BST(BST&);  // copy constructor
    Nod* delete_tree(Nod*); // helper function for destructor
    ~BST();     // destructor
    BST& operator=(BST&);   // overloading operator =
    Nod* get_root();    // getter
    Nod* insertNode(Nod*,int); // helper function for insert_node function
    Nod* deleteNode(Nod*,int);  // helper function for delete_node function
    void insert_node(int);      // virtual function for insert a node
    void delete_node(int);      // virtual function for delete a node
    void preorder_helper(Nod*); // helper function for preorder function
    void preorder();       // virtual function for preorder  traversal
    void inorder_helper(Nod*);  // helper function for inorder function
    void inorder();     // virtual function for inorder  traversal
    void postorder_helper(Nod*);  // helper function for postorder function
    void postorder();       // virtual function for postorder  traversal
    friend istream& operator>>(istream&,BST&);  // overloading operator >>
    friend ostream& operator<<(ostream&,BST&);  // overloading operator <<
};

#endif // BST_H_INCLUDED
