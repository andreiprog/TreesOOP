#ifndef NOD_H_INCLUDED
#define NOD_H_INCLUDED

#include <iostream>
using namespace std;

class Nod{
protected:
    int info;
    Nod *left,*right;
public:
    Nod():info(0),left(nullptr),right(nullptr){} //constructor by default
    Nod(int);       //constructor with parameters
    Nod(const Nod&);    // copy constructor
    ~Nod();     //destructor
    Nod& operator=(const Nod&);  // overloading operator =
    friend istream& operator>>(istream&,Nod&);  // overloading operator >>
    friend ostream& operator<<(ostream&,const Nod&);    // overloading operator <<
    void setLeft(Nod*); // setter
    void setRight(Nod*); // setter
    void set_info(int);  // setter
    Nod* getLeft();     // getter
    Nod* getRight();    // getter
    int get_info();     // getter
};

#endif // NOD_H_INCLUDED
