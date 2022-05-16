//
// Created by Mattia Lunardi on 15/05/22.
//
#include <string>
#include <iostream>
#include <vector>
#include "InvalidImpiegato.h"
#ifndef PROGPROCEDURALE_IMPIEGATO_H
#define PROGPROCEDURALE_IMPIEGATO_H

class Impiegato{
private:
    //float stipendio;
    Impiegato *next;
    static std::vector<Impiegato> lista;
protected:
    std::string nome;
    int codice_impiegato;
    short dipartimento;
public:
    Impiegato(std::string&, short);
    Impiegato(std::string&, int, short);
    Impiegato remove(std::string&, short);
    static void print_lista();
    virtual void print() const{std::cout << nome << "\t" << dipartimento << "\n";}
    virtual bool operator==(const Impiegato&) const;
    //virtual void calcolo_stipendio() const;
    std::string get_nome();
    int get_codice_impiegato();
};


#endif //PROGPROCEDURALE_IMPIEGATO_H
