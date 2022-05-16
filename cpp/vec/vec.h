//
// Created by Mattia Lunardi on 13/05/22.
//
#include <string>
#ifndef PROGPROCEDURALE_VEC_H
#define PROGPROCEDURALE_VEC_H
#define DEFAULT_SIZE 10
#define FREE -1

class vec {
public:
    inline vec() : v{new int[DEFAULT_SIZE]}, size{DEFAULT_SIZE}, item_count{0}{
        init_vector();
    }
    inline explicit vec(int size) : v{new int[size]}, size{size}, item_count{0}{
        init_vector();
    };
    vec(vec&);
    vec(const vec&);
    [[nodiscard]] int get_item_count() const;
    bool push(int);
    int rm(int);
    [[nodiscard]] int get_size() const;
    [[nodiscard]] std::string to_string() const;
    vec& operator=(const vec&);
    void *operator new(size_t);
    void operator delete(void*);
    int& operator[](int);
private:
    int item_count;
    int size;
    int *v;
    void init_vector();
};


#endif //PROGPROCEDURALE_VEC_H
