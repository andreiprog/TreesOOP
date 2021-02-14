#include <iostream>
using namespace std;
#include "Nod.h"
#include "Nod_Red_Black.h"

//constructor with parameters
Nod_Red_Black::Nod_Red_Black(int info):Nod(info),color('R'),left(nullptr),right(nullptr),parent(nullptr){}
// copy constructor
Nod_Red_Black::Nod_Red_Black(const Nod_Red_Black&node):Nod(node){
    this->color=node.color; this->parent=node.parent;
}
// destructor
Nod_Red_Black::~Nod_Red_Black(){
    this->info=0; this->left=nullptr; this->right=nullptr; this->parent=nullptr;
    this->color='0';
}
// overloading operator =
Nod_Red_Black& Nod_Red_Black::operator=(const Nod_Red_Black&node){
    if(&node==this) return *this;
    this->info=node.info;
    this->left=node.left;this->right=node.right;
    this->color=node.color;
    this->parent=node.parent;
    return *this;
}
// overloading operator >>
istream& operator>>(istream&in,Nod_Red_Black&node){
    in>>node.info; node.left=nullptr; node.right=nullptr; node.parent=nullptr;
    return in;
}
// overloading operator <<
ostream& operator<<(ostream&out,const Nod_Red_Black&node){
    out<<node.info;
    return out;
}
// getters
char Nod_Red_Black::get_color(){  return this->color; }
Nod_Red_Black* Nod_Red_Black::getRight(){ return this->right; }
Nod_Red_Black* Nod_Red_Black::getLeft(){ return this->left; }
Nod_Red_Black* Nod_Red_Black::get_parent(){ return this->parent; }
// setters
void Nod_Red_Black::set_color(char ch) { this->color=ch; }
void Nod_Red_Black::setLeft(Nod_Red_Black*node) { this->left=node; }
void Nod_Red_Black::setRight(Nod_Red_Black*node) { this->right=node; }
void Nod_Red_Black::set_parent(Nod_Red_Black*node) { this->parent=node; }
