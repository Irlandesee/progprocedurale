//
// Created by Mattia Lunardi on 17/05/22.
//

#include "MatAdiacenza.h"
#include <sstream>

MatAdiacenza::MatAdiacenza(int r, int c) : rows{r}, cols{c}{
    vectors = new int*[rows];
    for(int i = 0; i < rows; i++)
        vectors[i] = new int[cols];
    printf("Creata matrice %d x %d\n", rows, cols);
}

MatAdiacenza::MatAdiacenza(const MatAdiacenza& other_matrix) : rows{other_matrix.rows}, cols{other_matrix.cols}{
    delete[] vectors;
    vectors = (int **) new int(rows);
    for(int i = 0; i < rows; i++){
        vectors[i] = new int(cols);
        for(int j = 0; j < cols; j++)
            vectors[i][j] = other_matrix.vectors[i][j];
    }
}

MatAdiacenza::~MatAdiacenza(){
    std::cout << "Destructor for " << this << " called" << std::endl;
    delete[] vectors;
}

MatAdiacenza& MatAdiacenza::operator=(const MatAdiacenza& other_matrix){
    std::cout << "copy assignment function called" << std::endl;
    this->rows = other_matrix.rows;
    this->cols = other_matrix.cols;
    delete[] vectors;
    vectors = (int **) new int(rows);
    for(int i = 0; i < rows; i++){
        vectors[i] = new int(cols);
        for(int j = 0; j < cols; j++)
            vectors[i][j] = other_matrix.vectors[i][j];
    }
    return *this;
}

void MatAdiacenza::push(int item, int r, int c){
   if(vectors){
       printf("Adding %d to pos:[%d,%d]\n", item, r, c);
       vectors[r][c] = item;
   }
   else throw index_out_of_bounds(r, c);
}


std::string MatAdiacenza::to_string() const{
    std::stringstream ris;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++)
            ris << vectors[i][j] << " ";
        ris << "\n";
    }
    return ris.str();
}

int MatAdiacenza::remove(int r, int c){
    printf("Removing item at: [%d,%d]\n", r, c);
    if(r > this->rows || r < 0)
        throw index_out_of_bounds(r, c);
    else if(c > this->cols || c < 0)
        throw index_out_of_bounds(r, c);
    int item = vectors[r][c];
    vectors[r][c] = -1;
    return item;
}

MatAdiacenza& MatAdiacenza::random(){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1,6);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++)
            vectors[i][j] = dist6(rng);
    }
    return *this;
}