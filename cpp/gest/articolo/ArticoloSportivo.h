//
// Created by Mattia Lunardi on 15/05/22.
//

#ifndef PROGPROCEDURALE_ARTICOLOSPORTIVO_H
#define PROGPROCEDURALE_ARTICOLOSPORTIVO_H
#include "Articolo.h"

class ArticoloSportivo : public Articolo{
    int virtual iva(void){return 20;}
public:
    ArticoloSportivo(int c, float p): Articolo(c, p){};
};

#endif //PROGPROCEDURALE_ARTICOLOSPORTIVO_H
