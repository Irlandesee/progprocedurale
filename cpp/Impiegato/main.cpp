//
// Created by Mattia Lunardi on 14/08/22.
//
#include <iostream>

class Impiegato{
    const char *nome;
    const char *cognome;
    const char *dipartimento;
    float stipendio;
public:
    Impiegato *next;

    Impiegato(const char *nome,const char *cognome,const char *dipartimento, float stipendio) : nome(nome),
        cognome(cognome), dipartimento(dipartimento), stipendio(stipendio), next(nullptr){}

    char *get_nome() const;
    char *get_cognome() const;
    char *get_dipartimento() const;
    float get_stipendio();
    void print() const;
};

char *Impiegato::get_nome() const {return const_cast<char *>(this->nome);}
char *Impiegato::get_cognome() const {return  const_cast<char *> (this->cognome);}
char *Impiegato::get_dipartimento()const {return const_cast<char *> (this->dipartimento);}
float Impiegato::get_stipendio(){return this->stipendio;}
void Impiegato::print() const{
    std::cout << this->nome << " " << this->cognome << " " << this->dipartimento << std::endl;
}

class Manager : public virtual Impiegato{
    short livello;
    Impiegato *gruppo;
public:
    Manager(char *nome, char *cognome, char *dipartimento, float stipendio, short livello)
        : Impiegato(nome, cognome, dipartimento, stipendio), livello(livello){}
    short get_livello() const;
    void print_gruppo();
    void print();
};

short Manager::get_livello() const {return this->livello;}
void Manager::print_gruppo(){
    for(Impiegato *p = gruppo; p; p = p->next)p->print();
}

void Manager::print(){
    std::cout << this->get_nome() << " " << this->get_cognome()
        << " " << this->get_livello() << std::endl;
}

/**
class Venditore : public virtual Impiegato{

};

class ManagerVenditore : public Manager, public Venditore{

};

 **/

int main(int argc, char **argv){
    const char *nome_imp = "luca";
    const char *cognome_imp = "nervi";
    const char *dipartimento_imp = "acquisti";
    Impiegato i(nome_imp, cognome_imp, dipartimento_imp, 3200);

    const char *nome_man = "andrea";
    const char *cognome_man = "de marinis";
    short livello_man = 1;
}