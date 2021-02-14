#include "Red_Black_Tree.h"

// helper function for copy constructor
Nod_Red_Black* Red_Black_Tree::copy_red_black_tree(Nod_Red_Black*tree_source,Nod_Red_Black*tree_destination){
    if (tree_source == nullptr) return nullptr;
    Nod_Red_Black* node=new Nod_Red_Black();
    node->set_info(tree_source->get_info()); node->set_color(tree_source->get_color());
    node->setLeft(copy_red_black_tree(tree_source->getLeft(),node));
    node->setRight(copy_red_black_tree(tree_source->getRight(),node));
    return node;
}
// copy constructor
Red_Black_Tree::Red_Black_Tree(Red_Black_Tree&tree){
    this->number_of_nodes=tree.get_number_of_nodes();
    this->root=copy_red_black_tree(tree.get_root(),this->root);
}
// helper function for destructor
Nod_Red_Black* Red_Black_Tree::delete_tree(Nod_Red_Black*node){
    if(node!=nullptr){
        node->setLeft(delete_tree(node->getLeft()));
        node->setRight(delete_tree(node->getRight()));
        delete node;
        return node;
    }
}
// destructor
Red_Black_Tree::~Red_Black_Tree(){ this->root=delete_tree(root); this->number_of_nodes=0; }
// overloading operator =
Red_Black_Tree& Red_Black_Tree::operator=(Red_Black_Tree&tree){
    if(&tree==this) return *this;
    this->number_of_nodes=tree.get_number_of_nodes();
    this->root=copy_red_black_tree(tree.get_root(),this->root);
    return *this;
}
// Getter
Nod_Red_Black* Red_Black_Tree::get_root(){ return (this->root); }
// helper function for insertNode function
Nod_Red_Black* Red_Black_Tree::insertBST(Nod_Red_Black*tree_root,Nod_Red_Black*node){
    if(tree_root==nullptr) return node;
    if(node->get_info()< tree_root->get_info()){
            tree_root->setLeft(insertBST(tree_root->getLeft(),node)); tree_root->getLeft()->set_parent(tree_root);
    }
    else if(node->get_info()> tree_root->get_info()){
            tree_root->setRight(insertBST(tree_root->getRight(),node)); tree_root->getRight()->set_parent(tree_root);
    }
    return tree_root;
}
// helper function for balanceRedBlackTree function
Nod_Red_Black* Red_Black_Tree::rotateRight(Nod_Red_Black*b){
    if(b->getLeft()!=nullptr){
        Nod_Red_Black*p=b->getLeft();
        if(p->getRight()!=nullptr) p->getRight()->set_parent(b);
        b->setLeft(p->getRight());
        p->setRight(b);
        if(b->get_parent()!=nullptr && b==b->get_parent()->getLeft())  b->get_parent()->setLeft(p);
        else if(b->get_parent()!=nullptr && b==b->get_parent()->getRight()) b->get_parent()->setRight(p);
        p->set_parent(b->get_parent());
        b->set_parent(p);
        return p;
    }
    return b;
}
// helper function for balanceRedBlackTree function
Nod_Red_Black* Red_Black_Tree::rotateLeft(Nod_Red_Black*b){
    if(b->getRight()!=nullptr){
        Nod_Red_Black*p=b->getRight();
        if(p->getLeft()!=nullptr) p->getLeft()->set_parent(b);
        b->setRight(p->getLeft());
        p->setLeft(b);
        if(b->get_parent()!=nullptr && b==b->get_parent()->getLeft())  b->get_parent()->setLeft(p);
        else if(b->get_parent()!=nullptr && b==b->get_parent()->getRight()) b->get_parent()->setRight(p);
        p->set_parent(b->get_parent());
        b->set_parent(p);
        return p;
    }
    return b;
}
// helper function for insertNode function
Nod_Red_Black* Red_Black_Tree::balanceRedBlackTree(Nod_Red_Black*tree_root,Nod_Red_Black*node){
    if(node==tree_root || node->get_parent()==tree_root) return tree_root;
    Nod_Red_Black*parent=node->get_parent(), *grandparent=node->get_parent()->get_parent(),*uncle;
    while(node!=nullptr && node->get_color()=='R' && parent!=nullptr && parent->get_color()=='R'){
     parent=node->get_parent(); grandparent=node->get_parent()->get_parent();
     if(parent==grandparent->getLeft()) uncle=grandparent->getRight(); else uncle=grandparent->getLeft();
     if(uncle!=nullptr && uncle->get_color()=='R'){ //if uncle is red (recoloring)
        parent->set_color('B'); uncle->set_color('B'); grandparent->set_color('R');
        node=grandparent;
        if(node->get_parent()==nullptr) tree_root=node;
     }
     else{  // uncle is nullptr or black
       if(parent==grandparent->getLeft()){ //left case
         if(node==parent->getRight()) parent=rotateLeft(parent);
         grandparent->set_color('R'); parent->set_color('B');
         grandparent=rotateRight(grandparent);
         node=grandparent;
         if(node->get_parent()==nullptr) tree_root=node;
      }
      else if(parent==grandparent->getRight()){ //right case
        if(node==parent->getLeft()) parent=rotateRight(parent);
        grandparent->set_color('R'); parent->set_color('B');
        grandparent=rotateLeft(grandparent);
        node=grandparent;
        if(node->get_parent()==nullptr) tree_root=node;
      }
     }
     parent=node->get_parent();
    }
    tree_root->set_color('B');
    return tree_root;
}
// helper function for insert_node function
Nod_Red_Black* Red_Black_Tree::insertNode(Nod_Red_Black*tree_root,int info){
    Nod_Red_Black*node=new Nod_Red_Black(info); (this->number_of_nodes)++;
    tree_root=insertBST(tree_root,node);
    tree_root=Red_Black_Tree::balanceRedBlackTree(tree_root,node);
    tree_root->set_color('B');
    return tree_root;
}
// helper function for deleteNode function
Nod_Red_Black* Red_Black_Tree::search_Nod(Nod_Red_Black*tree_root,int val){
    Nod_Red_Black*node=tree_root,*v=nullptr;
    while(node!=nullptr && v==nullptr){
        if(val==node->get_info()) { v=node; }
        if(val < node->get_info()) node=node->getLeft();
        else node=node->getRight();
    }
    return v;
}
// helper function for replace_BST function
Nod_Red_Black* Red_Black_Tree::successor(Nod_Red_Black*x){
    Nod_Red_Black*temp = x;
    while(temp->getLeft()!= nullptr) temp=temp->getLeft();
    return temp;
}
// helper function for delete_Red_Black_Tree_Node function
Nod_Red_Black* Red_Black_Tree::replace_BST(Nod_Red_Black*x){
    if(x->getLeft()!= nullptr && x->getRight()!= nullptr) // when node have 2 children
        return successor(x->getRight());
    if (x->getLeft()==nullptr && x->getRight()==nullptr) return nullptr;    // when leaf
    if (x->getLeft() != nullptr) return x->getLeft(); // when single child
    else return x->getRight();
}
// helper function for fixDoubleBlack function
Nod_Red_Black*  Red_Black_Tree::node_sibling(Nod_Red_Black*v){
    if(v->get_parent()==nullptr) return nullptr;
    if (v==v->get_parent()->getLeft()) return v->get_parent()->getRight();
    else return v->get_parent()->getLeft();
}
// helper function for fixDoubleBlack function
bool Red_Black_Tree::hasRedChild(Nod_Red_Black*x){
    if((x->getLeft()!=nullptr && x->getLeft()->get_color()=='R')|| (x->getRight()!=nullptr && x->getRight()->get_color()=='R'))
        return true;
    else return false;
}
// helper function for delete_Red_Black_Tree_Node function
void Red_Black_Tree::fixDoubleBlack(Nod_Red_Black*&tree_root,Nod_Red_Black*x){
    if (x == tree_root) return;
    Nod_Red_Black*sibling_nod=node_sibling(x),*parent=x->get_parent();
    if(sibling_nod==nullptr) { fixDoubleBlack(tree_root,parent); }
 else{
      if(sibling_nod->get_color()=='R'){ // Sibling red
        parent->set_color('R'); sibling_nod->set_color('B');
        if(sibling_nod==sibling_nod->get_parent()->getLeft()){ parent=rotateRight(parent); } //  //left case
        else { parent=rotateLeft(parent);  }  // right case
        fixDoubleBlack(tree_root,x);
      }else{ // Sibling black
        if(hasRedChild(sibling_nod)){
          // at least 1 red children
          if (sibling_nod->getLeft()!= nullptr && sibling_nod->getLeft()->get_color() == 'R'){
            if(sibling_nod==sibling_nod->get_parent()->getLeft()){ // left left
              sibling_nod->getLeft()->set_color(sibling_nod->get_color());  sibling_nod->set_color(parent->get_color());
              parent=rotateRight(parent);
            }else{ // right left
              sibling_nod->getLeft()->set_color(parent->get_color());
              sibling_nod=rotateRight(sibling_nod);
              parent=rotateLeft(parent);
            }
          }
          else{
            if(sibling_nod==sibling_nod->get_parent()->getLeft()){ // left right
              sibling_nod->getRight()->set_color(parent->get_color());
              sibling_nod=rotateLeft(sibling_nod);
              parent=rotateRight(parent);
            }else{ // right right
              sibling_nod->getRight()->set_color(sibling_nod->get_color());
              sibling_nod->set_color(parent->get_color());
              parent=rotateLeft(parent);
            }
          }
          parent->set_color('B');
        }
    else{ // 2 black children
        sibling_nod->set_color('R');
        if(parent->get_color()=='B') fixDoubleBlack(tree_root,parent);
        else parent->set_color('B');
        }
      }
    }
}
// helper function for deleteNode function
void Red_Black_Tree::delete_Red_Black_Tree_Node(Nod_Red_Black*&tree_root,Nod_Red_Black*v){
    Nod_Red_Black*u = replace_BST(v);
    bool uvBlack=false; // True when u and v are both black
    if((u==nullptr || u->get_color()=='B')&&(v->get_color()=='B')) uvBlack=true;
    Nod_Red_Black*parent=v->get_parent();
    if(u==nullptr){
      if (v == tree_root) { tree_root=nullptr; }
      else
      {
        if(uvBlack){ fixDoubleBlack(tree_root,v); }  // u and v both black , v is leaf, fix double black at v
        else   // u or v is red
            if (node_sibling(v)!= nullptr) node_sibling(v)->set_color('R'); // sibling is not null, make it red
        if(v==parent->getLeft()) parent->setLeft(nullptr);
        else parent->setRight(nullptr);
      }
      delete v;
      return;
    }
    if(v->getLeft()==nullptr || v->getRight()==nullptr){  // v has 1 child
      if (v == tree_root){
        v->set_info(u->get_info()); v->setLeft(nullptr); v->setRight(nullptr); // v is tree_root, assign the value of u to v, and delete u
        delete u;
      }
      else{
        // Detach v from tree and move u up
        if (v==parent->getLeft()) parent->setLeft(u);
        else parent->setRight(u);
        delete v;
        u->set_parent(parent);
        if(uvBlack) { fixDoubleBlack(tree_root,u); } // u and v both black, fix double black at u
        else
            { u->set_color('B'); } // u or v red, color u black
      }
      return;
    }
    int t=v->get_info(); v->set_info(u->get_info()); u->set_info(t);
    delete_Red_Black_Tree_Node(tree_root,u);
}
// helper function for delete_node function
Nod_Red_Black* Red_Black_Tree::deleteNode(Nod_Red_Black*&tree_root,int val){
    if(tree_root==nullptr) return tree_root;
    Nod_Red_Black *v=search_Nod(tree_root,val);
    if(v==nullptr) { cout<<"The value don't exist in the tree\n"; return tree_root; }
    delete_Red_Black_Tree_Node(tree_root,v);
    return tree_root;
}
// virtual function for insert a node
void Red_Black_Tree::insert_node(int info){ this->root=Red_Black_Tree::insertNode(this->root,info); }
// virtual function for delete a node
void Red_Black_Tree::delete_node(int info) { this->root=deleteNode(this->root,info); }
// helper function for preorder function
void Red_Black_Tree::preorder_helper(Nod_Red_Black*node){
    if(node!=nullptr){
        cout<<node->get_info()<<' ';
        preorder_helper(node->getLeft());
        preorder_helper(node->getRight());
    }
}
// virtual function for preorder  traversal
void Red_Black_Tree::preorder(){  Red_Black_Tree::preorder_helper(this->root); }
// helper function for inorder function
void Red_Black_Tree::inorder_helper(Nod_Red_Black*node){
    if(node!=nullptr){
        inorder_helper(node->getLeft());
        cout<<node->get_info()<<' ';
        inorder_helper(node->getRight());
    }
}
// virtual function for inorder  traversal
void Red_Black_Tree::inorder(){ Red_Black_Tree::inorder_helper(this->root); }
// helper function for postorder function
void Red_Black_Tree::postorder_helper(Nod_Red_Black*node){
    if(node!=nullptr){
        postorder_helper(node->getLeft());
        postorder_helper(node->getRight());
        cout<<node->get_info()<<' ';
    }
}
// virtual function for postorder  traversal
void Red_Black_Tree::postorder(){  Red_Black_Tree::postorder_helper(this->root); }
// virtual function for find black_depth of the red-black tree
int Red_Black_Tree::black_depth(){
    int height=0;
    Nod_Red_Black*node=root;
    if(root!=nullptr) node=root->getLeft();
    while(node!=nullptr){
        if(node->get_color()=='B') height++;
        node=node->getLeft();
    }
    return height;
}
// overloading operator >>
istream& operator>>(istream&in,Red_Black_Tree&tree){
    int n,x;
    cout<<"Number of elements to be inserted: "; in>>n;
    try
    {
        if(n<1) throw -1;
        cout<<"Give the elements to insert :\n";
        for(int i=0;i<n;i++) { in>>x; tree.insert_node(x); }
    }
    catch(int exception_val){ return in; }
    return in;
}
// overloading operator <<
ostream& operator<<(ostream&out,Red_Black_Tree&tree){
    try
    {
        if(tree.get_root()==nullptr) throw -1;
        out<<"\nThe preorder traversal : ";
        tree.preorder();
    }
    catch(int error_val)
    {
        cout<<"\nThe Tree is empty !\n"; return out;
    }
    return out;
}
