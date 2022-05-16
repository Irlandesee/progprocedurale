//
// Created by Mattia Lunardi on 10/05/22.
//

#include <vector>
#include <iostream>
#include <string>
#include "gest/articolo/Articolo.h"
#include "gest/articolo/ArticoloLusso.h"
#include "gest/articolo/ArticoloSportivo.h"
#include "gest/impiegato/manager/Manager.h"
#include "gest/impiegato/Impiegato.h"

int main(){

    ArticoloSportivo artSport(10, 50);
    ArticoloLusso artLusso(11, 200);

    std::string nome = "giovanni";
    short dipartimento = 12;
    int codice_impiegato = 213141;
    Impiegato i(nome, codice_impiegato, dipartimento);
    i.print();
    std::string nomeManager = "paolo";
    short dipartimentoManager = 12;
    int codice_impiegato_manager = 123144;
    Manager mng(nomeManager, codice_impiegato_manager, dipartimentoManager);
    mng.add_group(i);
    std::cout << "-------------------" << std::endl;
    mng.print_gruppo();
    return 0;
}