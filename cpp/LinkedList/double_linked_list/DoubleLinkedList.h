//
// Created by Mattia Lunardi on 16/05/22.
//

#ifndef PROGPROCEDURALE_DOUBLELINKEDLIST_H
#define PROGPROCEDURALE_DOUBLELINKEDLIST_H
#include <string>

class DoubleLinkedList {
private:
    DoubleLinkedList *prev;
    DoubleLinkedList *next;
public:
    DoubleLinkedList(const std::string &v, DoubleLinkedList*p = nullptr, DoubleLinkedList*n = nullptr)
       : value{v}, prev{p}, next{n}{}
    DoubleLinkedList *insert(DoubleLinkedList*, DoubleLinkedList *);
    DoubleLinkedList *add(DoubleLinkedList *, DoubleLinkedList*);
    DoubleLinkedList *erase(DoubleLinkedList*);
    DoubleLinkedList *find(DoubleLinkedList*, const std::string&);
    DoubleLinkedList *advance(DoubleLinkedList *, int);
    DoubleLinkedList *succ() const{return next;}
    DoubleLinkedList *previous() const{return prev;}
    DoubleLinkedList &operator=(const DoubleLinkedList&);
    std::string value;

};


#endif //PROGPROCEDURALE_DOUBLELINKEDLIST_H
