//
// Created by Mattia Lunardi on 15/05/22.
//

#include "Manager.h"
void Manager::add_group(Impiegato& imp) {
    this->lista_impiegati.push_back(imp);
}

Impiegato Manager::remove_from_group(std::string& nome, int codice_impiegato){
    size_t sz = this->lista_impiegati.size();
    for(int i = 0; i < sz; i++){
        Impiegato imp = this->lista_impiegati[i];
        if(imp.get_nome() == nome && imp.get_codice_impiegato() == codice_impiegato){
            this->lista_impiegati.erase(lista_impiegati.begin() + i);
            return imp;
        }
    }
    throw InvalidImpiegato();
}

void Manager::print() const{
    std::cout << "Manager: " << this->nome << "\nCodice Impiegato: " << this->codice_impiegato
        <<"\nDipartimento: " << this->dipartimento;
}

void Manager::print_gruppo() const{
    int sz = this->lista_impiegati.size();
    this->print();
    for(int i = 0; i < sz; i++)
        lista_impiegati[i].print();
}