#ifndef NOD_RED_BLACK_H_INCLUDED
#define NOD_RED_BLACK_H_INCLUDED

#include <iostream>
#include "Nod.h"
using namespace std;

class Nod_Red_Black:public Nod{
protected:
    char color;
    Nod_Red_Black *left,*right,*parent;
public:
    Nod_Red_Black():Nod(),color('R'),left(nullptr),right(nullptr),parent(nullptr){} // constructor by default
    Nod_Red_Black(int);        //constructor with parameters
    Nod_Red_Black(const Nod_Red_Black&); // copy constructor
    ~Nod_Red_Black();                    //destructor
    Nod_Red_Black& operator=(const Nod_Red_Black&); // overloading operator =
    friend istream& operator>>(istream&,Nod_Red_Black&);      // overloading operator >>
    friend ostream& operator<<(ostream&,const Nod_Red_Black&); // overloading operator <<
    char get_color();   // getter
    Nod_Red_Black* getLeft();  // getter
    Nod_Red_Black* getRight(); // getter
    Nod_Red_Black* get_parent(); // getter
    void set_color(char);   // setter
    void setLeft(Nod_Red_Black*); // setter
    void setRight(Nod_Red_Black*);  // setter
    void set_parent(Nod_Red_Black*);  // setter

};

#endif // NOD_RED_BLACK_H_INCLUDED
