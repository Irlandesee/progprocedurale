//
// Created by Mattia Lunardi on 17/05/22.
//

#ifndef PROGPROCEDURALE_MATADIACENZA_H
#define PROGPROCEDURALE_MATADIACENZA_H
#include <iostream>
#include <string>
#include <random>
#include "index_out_of_bounds.h"
class MatAdiacenza {
public:
    MatAdiacenza() : rows{3}, cols{3}{
       vectors = new int*[rows];
       for(int i = 0; i < rows; i++){
           vectors[i] = new int[cols];
       }
       std::cout << "Creata matrice 3x3" << std::endl;
    }

    MatAdiacenza(int, int);
    MatAdiacenza(const MatAdiacenza&);
    ~MatAdiacenza();
    MatAdiacenza& operator=(const MatAdiacenza&);
    void push(int, int, int);
    int remove(int, int);
    std::string to_string() const;
    MatAdiacenza& random();
private:
    int rows, cols;
    int **vectors;
};


#endif //PROGPROCEDURALE_MATADIACENZA_H
