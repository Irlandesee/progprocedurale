//
// Created by Mattia Lunardi on 15/05/22.
//
#include "Impiegato.h"
std::vector<Impiegato> Impiegato::lista;

Impiegato::Impiegato(std::string& nome, short dipartimento)
    : nome{nome}, dipartimento{dipartimento}, next{nullptr}, codice_impiegato{-1}{
    std::cout << "Creato impiegato\nNome: " << this->nome << "\nDipartimento: " << this->dipartimento << "\n";
    Impiegato::lista.emplace_back(*this);
}

Impiegato::Impiegato(std::string& nome, int codice_impiegato, short dipartimento)
    : nome{nome}, codice_impiegato{codice_impiegato}, dipartimento{dipartimento}, next{nullptr}{
    std::cout << "Creato impiegato\nNome: " << this->nome << "\nDipartimento: " << this->dipartimento
        << "\nCodice Impiegato: " << this->codice_impiegato << "\n";
    Impiegato::lista.emplace_back(*this);
}

void Impiegato::print_lista(){
    for(const auto&  imp : Impiegato::lista){
        imp.print();
    }
}


Impiegato Impiegato::remove(std::string& nome, short dipartimento){
    Impiegato imp(nome, dipartimento);
    for(int i = 0; i < Impiegato::lista.size(); i++){
        if(imp == Impiegato::lista[i])
            Impiegato::lista.erase(Impiegato::lista.begin()+i);
    }
    return imp;
}

bool Impiegato::operator==(const Impiegato& otherImpiegato) const{
    if(this->nome == otherImpiegato.nome &&
    this->dipartimento == otherImpiegato.dipartimento)
        return true;
    return false;
}

std::string Impiegato::get_nome(){return this->nome;}

int Impiegato::get_codice_impiegato(){return this->codice_impiegato;}