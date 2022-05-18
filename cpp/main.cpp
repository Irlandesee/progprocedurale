//
// Created by Mattia Lunardi on 10/05/22.
//

#include <vector>
#include <iostream>
#include <string>
#include "Node/Node.h"
#include "matrice_adiacenza/MatAdiacenza.h"
/**
struct X{
    int val;
    void out(const std::string& s, int nv){
        std::cerr << this << "->" << s << ":" << val << "(" << nv << ")\n";
    }

    X(){out("X()", 0); val = 0;}
    X(int v){val = v; out("X(int)", v);}
    X(const X& x){val = x.val; out("X(X&)", x.val);}
    X& operator=(const X& a){
        out("X::operator=()", a.val);
        val = a.val;
        return *this;
    }
    ~X(){ out("~X()", 0);}

};

X glob(2); //global var

X copy(X a){return a;}

X copy2(X a){X aa = a; return aa;}

X& ref_to(X& a){return a;}

X* make(int i){X a(i); return new X(a);}

struct XX{X a; X b;};
**/

int main(){
    /**
    Simple_Vec vec(10);
    for(int i = 0; i < vec.size(); i++)
        vec.set(i, 1.1*i);

    Simple_Vec *vc = new Simple_Vec(5); //allocates a vector on the free store
    delete vc; //deallocates it

    std::string nome = "mattia";
    DoubleLinkedList n(nome);
    DoubleLinkedList other_n = n;
    printf("address of n: %d\n", &n);
    printf("address of other_n: %d\n", &other_n);
    void *addr = &n.value;
    void *other_addr = &other_n.value;
    std::cout << addr << std::endl;
    std::cout << other_addr << std::endl;

    X loc{4}; //local var
    X loc2{loc}; //copy construction
    loc = X{5}; //copy assignment
    loc2 = copy(loc); //call by value and return
    X loc3{6};
    X& r = ref_to(loc); //call by ref and return
    delete make(7);
    delete make(8);
    std::vector<X> v(4); //def val
    XX loc4;
    X *p = new X{9}; //an X on the free store
    delete p;
    X *pp = new X[5]; //an array of Xs on the free store
    delete[] pp;
    **/

    MatAdiacenza m(3, 3);
    m.push(10, 0, 0);
    m.push(11, 0, 1);
    m.push(12, 0, 2);
    m.push(13, 1, 0);
    m.push(14, 1, 1);
    m.push(15, 1, 2);
    m.push(16, 2, 0);
    m.push(17, 2, 1);
    m.push(18, 2, 2);

    std::string mat = m.to_string();
    std::cout << mat << std::endl;


    int item = m.remove(0,0);
    mat = m.to_string();
    std::cout << mat << std::endl;

    m.random();
    mat = m.to_string();
    std::cout << mat << std::endl;

    return 0;
}