//
// Created by Mattia Lunardi on 10/05/22.
//

#include "Node.h"
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

Node::~Node() = default;

Node *Node::get_next() {return this->next;}
int Node::get_valore() const {return this->valore;}
std::string Node::to_string() const {
    std::ostringstream ris;
    ris << "valore: " << this->valore << "\nIndirizzo Prossimo: " << std::addressof(this->next) << "\n";
    return ris.str();
}
