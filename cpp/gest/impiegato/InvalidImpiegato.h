//
// Created by Mattia Lunardi on 15/05/22.
//

#ifndef PROGPROCEDURALE_INVALIDIMPIEGATO_H
#define PROGPROCEDURALE_INVALIDIMPIEGATO_H
#include <iostream>
#include <exception>

class InvalidImpiegato : std::exception {
    virtual const char *what() const throw(){
       return "Invalid Impiegato";
    }
};


#endif //PROGPROCEDURALE_INVALIDIMPIEGATO_H
