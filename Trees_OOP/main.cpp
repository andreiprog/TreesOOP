#include <iostream>
#include "Nod.h"
#include "Nod_Red_Black.h"
#include "Tree.h"
#include "BST.h"
#include "Red_Black_Tree.h"
using namespace std;

int main()
{

    Tree**v=nullptr;
    int n;
    cout<<"n="; cin>>n;
    read_n_trees(v,n);
    display_n_trees(v,n);
    return 0;
}
