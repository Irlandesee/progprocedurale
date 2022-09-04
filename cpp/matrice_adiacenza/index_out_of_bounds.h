//
// Created by Mattia Lunardi on 17/05/22.
//

#ifndef PROGPROCEDURALE_INDEX_OUT_OF_BOUNDS_H
#define PROGPROCEDURALE_INDEX_OUT_OF_BOUNDS_H


#include <exception>
#include <iostream>
class index_out_of_bounds : std::exception{
public:
    index_out_of_bounds(int i, int j){
        printf("Index : [%d,%d]\n", i, j);
    }
    //needs one less parameter
    friend std::ostream& operator<<(std::ostream& , int, int);
};


#endif //PROGPROCEDURALE_INDEX_OUT_OF_BOUNDS_H
