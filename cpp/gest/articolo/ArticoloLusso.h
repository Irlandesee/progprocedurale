//
// Created by Mattia Lunardi on 15/05/22.
//

#ifndef PROGPROCEDURALE_ARTICOLOLUSSO_H
#define PROGPROCEDURALE_ARTICOLOLUSSO_H
#include "Articolo.h"

class ArticoloLusso : public Articolo {
    int virtual iva(void){return 36;}
public:
    ArticoloLusso(int c, float p): Articolo(c, p){};
};


#endif //PROGPROCEDURALE_ARTICOLOLUSSO_H
