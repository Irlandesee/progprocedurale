//
// Created by Mattia Lunardi on 19/05/22.
//
#include <stdio.h>
#include <stdlib.h>

//definite una funzione Max che restituisce il massimo valore in una matrice di double

double max(int **mat, int rows, int cols);
int **alloc_matrix(int, int);

int main(int argc, char **argv){
    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);
    int **mat = alloc_matrix(rows, cols);

}

double max(int **mat, int rows, int cols){
    if(mat == NULL || *mat == NULL) return -1;
    double max = mat[0][0];
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++)
            if(max < mat[i][j]) max = mat[i][j];
    }
    return max;
}

int **alloc_matrix(int rows, int cols){
   int **mat = (int **) malloc(sizeof(int) * rows);
   for(int i = 0; i < rows; i++)
       mat[i] = (int *) malloc(sizeof(int) * cols);
   return mat;
}
