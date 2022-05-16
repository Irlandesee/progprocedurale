//
// Created by Mattia Lunardi on 13/05/22.
//

#include "vec.h"
#include <sstream>
vec::vec(vec& other_vector) : v{new int[other_vector.size]}, size{other_vector.get_size()}, item_count{other_vector.get_item_count()}{
    for(int i = 0; i < size; i++)
        v[i] = other_vector.v[i];
}

vec::vec(const vec& other_vector) : v{new int[other_vector.size]}, size{other_vector.get_size()}, item_count{other_vector.item_count}{
   for(int i = 0; i < size; i++){
       v[i] = other_vector.v[i];
   }
}

int vec::get_item_count() const {return this->item_count;}

bool vec::push(int item){
    for(int i = 0; i < this->size; i++)
        if(v[i] == FREE){
            v[i] = item;
            this->item_count++;
            return true;
        }
    return false;
}

int vec::rm(int index){
    int item = v[index];
    if(item != FREE){
        v[index] = FREE;
        return item;
    }

    return -1;
}

void vec::init_vector() {
    for(int i = 0; i < this->get_size(); i++){v[i] = FREE;}
}

int vec::get_size() const {return this->size;}

std::string vec::to_string() const{
    std::ostringstream ris;
    int sz = this->get_size();
    for(int i = 0; i < sz; i++){
        if(i < sz-1) ris << v[i] << ", ";
        else ris << v[i];
    }
    return ris.str();
}

vec& vec::operator=(const vec& otherVector){
    if(&otherVector != this){//check for self assignment
        delete[] v;
        this->size = otherVector.size;
        v = new int[size];
        std::copy_n(otherVector.v, size, v);
    }
    return *this;
}

void *vec::operator new(size_t size){
    void *p = ::operator new(size);
    return p;
}

void vec::operator delete(void* p){
    free(p);
}

int& vec::operator[](int i){
    //TODO: check validity of index
    return v[i];
}