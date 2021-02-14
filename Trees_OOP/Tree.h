#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include <iostream>
using namespace std;

// abstract class
class Tree{
protected:
    int number_of_nodes;
public:
    Tree():number_of_nodes(0){} // constructor by default
    Tree(int);  //constructor with parameters
    int get_number_of_nodes();  // getter
    virtual void insert_node(int)=0;  // pure virtual function for insert a node
    virtual void delete_node(int)=0;   // pure virtual function for delete a node
    virtual void preorder()=0;  // pure virtual function for preorder  traversal
    virtual void inorder()=0;   // pure virtual function for inorder  traversal
    virtual void postorder()=0; // pure virtual function for postorder  traversal
    friend void read_n_trees(Tree**&,int);  // friend function for read n trees
    friend void display_n_trees(Tree**,int);    // friend function for display n trees
};

#endif // TREE_H_INCLUDED
