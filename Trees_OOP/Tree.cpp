#include <iostream>
#include <string>
#include "Tree.h"
#include "BST.h"
#include "Red_Black_Tree.h"
using namespace std;

//constructor with parameters
Tree::Tree(int n){ this->number_of_nodes=n; }
// getter
int Tree::get_number_of_nodes(){  return (this->number_of_nodes); }
// function for read n trees
void read_n_trees(Tree**&v,int n){
    if(n<1) return;
    cout<<"Abreviations : \nBST-binary search tree\nRBT-red-black tree\n";
    v=new Tree*[n];
    string op;
    for(int i=0;i<n;i++){
        cout<<"\nGive the type of the tree(BST/RBT): "; cin>>op;
        try
        {
            if(op!="BST" && op!="RBT") { v[i]=nullptr; throw -1; }
            if(op=="BST"){
                    v[i]=new BST;
                    cin>>*dynamic_cast<BST*>(v[i]);
            }
            if(op=="RBT"){
                 v[i]=new Red_Black_Tree;
                 cin>>*dynamic_cast<Red_Black_Tree*>(v[i]);
            }
        }
        catch(int x) { cout<<"Invalid tree type\n"; return; }
    }
}
// function for display n trees
void display_n_trees(Tree**v,int n){
    if(v==nullptr || v[0]==nullptr) return;
    cout<<"Display trees: \n";
    for(int i=0;i<n;i++){
        try
        {
            if((dynamic_cast<BST*>(v[i])==nullptr) && (dynamic_cast<Red_Black_Tree*>(v[i])==nullptr))
                throw -1;
            if(dynamic_cast<BST*>(v[i])){
                cout<<"\nTree "<<i+1<<": BST\n";
                cout<<*dynamic_cast<BST*>(v[i]);
            }
            else if(dynamic_cast<Red_Black_Tree*>(v[i])){
                cout<<"\nTree "<<i+1<<": RBT\n";
                cout<<*dynamic_cast<Red_Black_Tree*>(v[i]);
            }
        }
        catch(int x){ return; }
    }
}
