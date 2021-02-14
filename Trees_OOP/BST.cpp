#include "BST.h"

// helper function for copy constructor
Nod* BST::copy_bst(Nod*tree_source,Nod*tree_destination){
    if (tree_source == nullptr) return nullptr;
    Nod* node=new Nod; node->set_info(tree_source->get_info());
    node->setLeft(copy_bst(tree_source->getLeft(),node));
    node->setRight(copy_bst(tree_source->getRight(),node));
    return node;
}
// copy constructor
BST::BST(BST&bst_tree){
    this->number_of_nodes=bst_tree.get_number_of_nodes();
    this->root=copy_bst(bst_tree.get_root(),this->root);
}
// helper function for destructor
Nod* BST::delete_tree(Nod*node){
    if(node!=nullptr){
        node->setLeft(delete_tree(node->getLeft()));
        node->setRight(delete_tree(node->getRight()));
        delete node;
        return node;
    }
}
// destructor
BST::~BST(){ this->root=delete_tree(root); this->number_of_nodes=0; }
// overloading operator =
BST& BST::operator=(BST&bst_tree){
    if(&bst_tree==this) return *this;
    this->number_of_nodes=bst_tree.get_number_of_nodes();
    this->root=copy_bst(bst_tree.get_root(),this->root);
    return *this;
}
// Getter
Nod* BST::get_root(){ return (this->root); }
// helper function for insert_node function
Nod* BST::insertNode(Nod*node,int info){
    if(node==nullptr) { node=new Nod(info); (this->root)=node; (this->number_of_nodes)++; return node; }
    if(info < node->get_info() )
        node->setLeft(insertNode(node->getLeft(),info));
    else if(info > node->get_info())
        node->setRight(insertNode(node->getRight(),info));
    (this->root)=node;
    return node;
}
// helper function for delete_node function
Nod* BST::deleteNode(Nod*node,int info){
    if(node==nullptr) { (this->root)=node; return node; }
    if(info < node->get_info())
        node->setLeft(deleteNode(node->getLeft(),info));
    else if(info > node->get_info())
        node->setRight(deleteNode(node->getRight(),info));
    else{
        // The node has one son or none
        if(node->getLeft()==nullptr){
            Nod *temp=node->getRight(); delete node; (this->number_of_nodes)--; (this->root)=temp; return temp;
        }
        if(node->getRight()==nullptr){
            Nod *temp=node->getLeft(); delete node; (this->number_of_nodes)--; return temp;
        }
        // The node has 2 sons  : search the inorder predecesor ( the biggest element in left subtree )
        Nod *p=node->getLeft(), *q=node;
        while(p->getRight()!=nullptr){
            q=p; p=p->getRight();
        }
        node->set_info(p->get_info());
        if(q==node) node->setLeft(p->getLeft());
         else  q->setRight(p->getLeft());
        delete p;               // delete the inorder predecesor
        (this->number_of_nodes)--;   // update the number of nodes
    }
    (this->root)=node;
    return node;
}
// virtual function for insert a node
void BST::insert_node(int info){
    BST::insertNode(this->root,info);
}
// virtual function for insert a node
void BST::delete_node(int info){
    BST::deleteNode(this->root,info);
}
// helper function for preorder function
void BST::preorder_helper(Nod*node){
    if(node!=nullptr){
        cout<<node->get_info()<<' ';
        preorder_helper(node->getLeft());
        preorder_helper(node->getRight());
    }
}
// virtual function for preorder  traversal
void BST::preorder(){  BST::preorder_helper(this->root); }
// helper function for inorder function
void BST::inorder_helper(Nod*node){
    if(node!=nullptr){
        inorder_helper(node->getLeft());
        cout<<node->get_info()<<' ';
        inorder_helper(node->getRight());
    }
}
// virtual function for inorder  traversal
void BST::inorder(){ BST::inorder_helper(this->root); }
// helper function for postorder function
void BST::postorder_helper(Nod*node){
    if(node!=nullptr){
        postorder_helper(node->getLeft());
        postorder_helper(node->getRight());
        cout<<node->get_info()<<' ';
    }
}
// virtual function for postorder  traversal
void BST::postorder(){  BST::postorder_helper(this->root); }
// overloading operator >>
istream& operator>>(istream&in,BST&tree){
    int n,x;
    cout<<"Number of elements to be inserted: "; in>>n;
    try
    {
        if(n<1) throw -1;
        cout<<"Give the elements to insert :\n";
        for(int i=0;i<n;i++) { in>>x; tree.insert_node(x); }
    }
    catch(int x){ return in; }
    return in;
}
// overloading operator <<
ostream& operator<<(ostream&out,BST&tree){
    try
    {
        if(tree.get_root()==nullptr) throw "\nThe BST is empty!\n";
        out<<"\nThe preorder traversal : ";
        tree.preorder();
    }
    catch(const char*exception_msg)
    {
         out<<exception_msg; return out;
    }
    return out;
}
