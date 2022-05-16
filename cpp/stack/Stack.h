//
// Created by Mattia Lunardi on 10/05/22.
//
#include <string>
#include <iostream>
#ifndef PROGPROCEDURALE_STACK_H
#define PROGPROCEDURALE_STACK_H
#define SIZE 5

template <class T>
class Stack{
private:
    int top;
    T st[SIZE];
public:
    Stack();
    void push(T k);
    T pop();
    T topElement();
    bool isFull();
    bool isEmpty();
};

template <class T> Stack<T>::Stack() : st(SIZE){top = -1;}

template <class T> void Stack<T>::push(T k){
    if(isFull()) std::cout << "Stack Full\n";
    std::cout << "Inserting element at " << top << "\n";
    ++top;
    st[top] = k;
}

template <class T> bool Stack<T>::isEmpty(){
    if(top == -1) return 1;
    return 0;
}

template <class T> bool Stack<T>::isFull(){
    if(top == (SIZE - 1)) return 1;
    return 0;
}

template <class T> T Stack<T>::pop(){
    T popped_element = st[top];
    --top;
    return popped_element;
}

template <class T> T Stack<T>::topElement() {
    return st[top];
}





#endif //PROGPROCEDURALE_STACK_H
