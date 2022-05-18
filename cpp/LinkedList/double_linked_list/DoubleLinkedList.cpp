//
// Created by Mattia Lunardi on 16/05/22.
//

#include "DoubleLinkedList.h"

/**
 * Insert n before p, return n
 * @param p
 * @param n
 * @return
 */
DoubleLinkedList *DoubleLinkedList::insert(DoubleLinkedList *p, DoubleLinkedList *n){
    if(n == nullptr) return p;
    if(p == nullptr) return n;
    n->next = p;
    if(p->prev) p->prev->next = n;
    n->prev = p->prev;
    p->prev = n;
    return n;
}

/**
 * insert n after p; return n
 * @param p
 * @param n
 * @return
 */
DoubleLinkedList *DoubleLinkedList::add(DoubleLinkedList *p, DoubleLinkedList *n){
    if(n == nullptr) return p;
    if(p == nullptr) return n;
    if(p->next) n->next = p->next;
    p->next = n->next;
    n->prev = p;
    n->next->prev = n;
    return n;
}

/**
 * Remove *p from list, return p's successor
 * @param p
 * @return
 */
DoubleLinkedList *DoubleLinkedList::erase(DoubleLinkedList *p){
    if(p == nullptr) return nullptr;
    if(p->next) p->next->prev = p->prev;
    if(p->prev) p->prev->next = p->next;
    return p->next;
}

/**
 * find s in list
 * return nullptr if not found
 * @param p
 * @param s
 * @return
 */
DoubleLinkedList *DoubleLinkedList::find(DoubleLinkedList *p, const std::string& s){
    while(p){
        if(p->value == s) return p;
        p = p->next;
    }
    return nullptr;
}

/**
 * move n positions in list
 * return nullptr if not found
 * @param p
 * @param n
 * @return
 */
DoubleLinkedList *DoubleLinkedList::advance(DoubleLinkedList *p, int n){
    //positive n moves forwars, negative backward
    if(p == nullptr) return nullptr;
    if(0 < n){
        while(n--){
            if(p->next == nullptr) return nullptr;
            p = p->next ;
        }
    }
    else if(n < 0){
        while(n++){
            if(p->prev == nullptr) return nullptr;
            p = p->next;
        }
    }
   return p;
}

/**
 * makes this list a copy of a
 * @param a
 * @return
 */
DoubleLinkedList& DoubleLinkedList::operator=(const DoubleLinkedList& a){
    this->next = a.next;
    this->prev = a.prev;
    this->value = a.value;
    return *this;
}