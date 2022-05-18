//
// Created by Mattia Lunardi on 10/05/22.
//

#include "Node.h"
#include <iostream>
#include <sstream>
#include <ostream>
#include <memory>

Node::Node(int valore){
    this->valore = valore;
    this->next = nullptr;
}

Node::Node(int valore, Node *next){
    this->valore = valore;
    this->next = next;
}

//copy constructor
Node::Node(const Node& other_node) : valore{other_node.valore}, next{other_node.next}{
    std::cout << "Copy constructor called\n" << std::endl;
}
//copy assignment
Node& Node::operator=(const Node& other_node){
    this->valore = other_node.valore;
    delete next;
    this->next = other_node.next;
    return *this;
}

Node::~Node(){
    //delete next;
}

Node *Node::get_next() {return this->next;}
int Node::get_valore() const {return this->valore;}
std::string Node::to_string() const {
    std::ostringstream ris;
    ris << "valore: " << this->valore << "\nIndirizzo Prossimo: " << std::addressof(this->next) << "\n";
    return ris.str();
}
