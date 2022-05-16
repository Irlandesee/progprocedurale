//
// Created by Mattia Lunardi on 10/05/22.
//
#include <string>

#ifndef PROGPROCEDURALE_NODE_H
#define PROGPROCEDURALE_NODE_H

class Node{
public:
    explicit Node(int);
    Node(int, Node *);
    ~Node();
    Node *get_next();
    [[nodiscard]] int get_valore() const;
    [[nodiscard]] std::string to_string() const;
private:
    Node *next;
    int valore;
};

#endif //PROGPROCEDURALE_NODE_H
