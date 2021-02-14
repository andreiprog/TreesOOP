#include <iostream>
#include "Nod.h"
using namespace std;

//  constructor with parameters
Nod::Nod(int info){
    this->info=info;
    this->left=nullptr; this->right=nullptr;
}
// copy constructor
Nod::Nod(const Nod&cp){
    this->info=cp.info;
    this->left=cp.left; this->right=cp.right;
}
// destructor
Nod::~Nod(){
    this->info=0; this->left=nullptr; this->right=nullptr;
}
// overloading operator =
Nod& Nod::operator=(const Nod&node){
    if(&node==this) return *this;
    this->info=node.info;
    this->left=node.left;
    this->right=node.right;
    return *this;
}
// overloading operator >>
istream& operator>>(istream&in,Nod&node){
    in>>node.info; node.left=nullptr; node.right=nullptr;
    return in;
}
// overloading operator <<
ostream& operator<<(ostream&out,const Nod&node){
    out<<node.info;
    return out;
}
//Setters
void Nod::setLeft(Nod*node) { this->left=node; }
void Nod::setRight(Nod*node) { this->right=node; }
void Nod::set_info(int info) { this->info=info;  }
// Getters
Nod* Nod::getLeft(){  return (this->left); }
Nod* Nod::getRight(){  return (this->right); }
int  Nod::get_info(){ return (this->info); }
