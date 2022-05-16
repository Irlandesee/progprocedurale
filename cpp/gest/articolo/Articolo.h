//
// Created by Mattia Lunardi on 15/05/22.
//
#include <string>
#include <sstream>
#ifndef PROGPROCEDURALE_ARTICOLO_H
#define PROGPROCEDURALE_ARTICOLO_H


class Articolo {
public:
    Articolo(int c, float p){codice = c; prezzo = p;}

    float calcola_iva(void){
        return(prezzo + (prezzo * iva() / 100));
    }

    [[nodiscard]] std::string to_string() const{
        std::ostringstream ris;
        ris << this->codice << " " << this->prezzo << "\n";
        return ris.str();
    }

private:
    int codice;
    float prezzo;
    virtual int iva(void) = 0;
};


#endif //PROGPROCEDURALE_ARTICOLO_H
