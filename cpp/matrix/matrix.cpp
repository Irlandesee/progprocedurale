//
// Created by Mattia Lunardi on 13/05/22.
//

#include "matrix.h"
#include <sstream>
matrix::matrix(matrix& otherMatrix) : rows{otherMatrix.rows}, cols{otherMatrix.cols},
    item_count{otherMatrix.item_count}{
    for(int i = 0; i < rows; i++) {
        this->vectors.emplace_back(otherMatrix.vectors[i]);
    }
}

void matrix::init_matrix(){
    printf("init matrix\n");
    for(int i = 0; i < rows; i++){
        std::vector<int> vec = this->vectors[i];
        size_t sz = vec.size();
        for(int j = 0; j < sz; j++)
           vec[j] = -1;
        this->vectors[i] = vec;
    }
}

std::string matrix::to_string() const{
    std::ostringstream ris;
    for(int i = 0; i < rows; i++){
        std::vector<int> vec = this->vectors[i];
        size_t sz = vec.size();
        for(int j = 0; j < sz; j++){
            if(j < sz - 1)
                ris << vec[j] << ", ";
            else
                ris << vec[j] << "\n";
        }
    }
    return ris.str();
}

void matrix::build_random_matrix() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6);
    for(int i = 0; i < rows; i++){
        std::vector<int> vec = this->vectors[i];
        for(int j = 0; j < cols; j++){
            vec[j] = dist6(rng);
        }
        this->vectors[i] = vec;
    }
}