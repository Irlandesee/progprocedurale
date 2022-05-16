//
// Created by Mattia Lunardi on 11/05/22.
//

#ifndef PROGPROCEDURALE_LINKEDLIST_H
#define PROGPROCEDURALE_LINKEDLIST_H
#include <utility>

template <class T>
class LinkedList {
private:
    struct Node{
        Node *next;
        T value;

        explicit inline Node(const T &value) : value(value),next(nullptr){}
        explicit inline Node(T &&value) : value(std::move(value)), next(nullptr){}
    };
    Node *root;
    Node *curr;
    int count;
public:
    LinkedList() : count(0), root(NULL){}

    void add(const T &val);

    void add(T &&val);
    [[nodiscard]] int get_size() const {return this->count;}
    T next() const;

    T& get_curr() const;

};

template<class T>
T LinkedList<T>::next() const {
    if(this->next != nullptr){
        curr = this->next;
        return curr;
    }else{
        return nullptr;
    }
}

template<class T>
void LinkedList<T>::add(T &&val) {
    if(this->root == nullptr){
        this->root = new Node(std::move(val));
        this->curr = root;
    }else{
        this->curr->next = new Node(val);
        this->curr = this->curr->next;
    }
    this->count++;
}

template<class T>
void LinkedList<T>::add(const T &val) {
    if(this->root == nullptr){
        this->root = new Node(val);
        this->curr = root;
    }else{
        this->curr->next = new Node(val);
        this->curr = this->curr->next;
    }
    this->count++;
}

template<class T>
T& LinkedList<T>::get_curr() const {return this->curr;}


#endif //PROGPROCEDURALE_LINKEDLIST_H
