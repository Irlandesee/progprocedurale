//
// Created by Mattia Lunardi on 15/05/22.
//

#ifndef PROGPROCEDURALE_MANAGER_H
#define PROGPROCEDURALE_MANAGER_H
#include "../Impiegato.h"

class Manager : public Impiegato{
    std::vector<Impiegato> lista_impiegati;
public:
    Manager(std::string& nome, short dipartimento) : Impiegato(nome, dipartimento){}
    Manager(std::string& nome, int codice_impiegato, short dipartimento)
        : Impiegato(nome, codice_impiegato, dipartimento){}
    void print() const override;
    void print_gruppo() const;
    void add_group(Impiegato&);
    Impiegato remove_from_group(std::string&, int);
};


#endif //PROGPROCEDURALE_MANAGER_H
