//
// Created by Mattia Lunardi on 16/05/22.
//

#ifndef PROGPROCEDURALE_SIMPLE_VEC_H
#define PROGPROCEDURALE_SIMPLE_VEC_H

class Simple_Vec{
    int sz;
    double *elem;
public:
    Simple_Vec(int s) : sz{s}, elem{new double[s]}{
        for(int i = 0; i < sz; i++)elem[i] = 0;
    }
    ~Simple_Vec(){delete[] elem;}

    int size(){return this->sz;}
    double get(int n){return elem[n];}
    void set(int n, double v){elem[n] = v;}

};

#endif //PROGPROCEDURALE_SIMPLE_VEC_H
