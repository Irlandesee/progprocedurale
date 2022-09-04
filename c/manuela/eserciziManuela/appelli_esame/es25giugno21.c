//
// Created by Mattia Lunardi on 04/06/22.
//
#include "stdio.h"
#include "stdlib.h"

#define MAX_ROWS 4
#define MAX_COLS 4

#define START_X 0
#define START_Y 0
#define GOAL_X 3
#define GOAL_Y 3

#define NORD -1
#define SUD 1
#define EST 1
#define OVEST -1

struct nodo{
    int el;
    struct nodo *next;
};

typedef struct nodo *lista;

int matrice[4][4] = {
        0, 1, 2, 5,
        3, 5, 3, 5,
        5, 5, 2, 1,
        5, 5, 2, 0
};

int find_path(int [MAX_ROWS][MAX_COLS], int, int);
void centro(lista l, int el);
size_t lunghezza_lista(lista l);

int main(){
    int ris = find_path(matrice, START_X, START_Y);
    printf("%d\n", ris);
}

int find_path(int matrix[MAX_ROWS][MAX_COLS], int start_x, int start_y){
    int i = 0, j = 0;
    while((i >= 0 && i < 4) && (j >= 0 && j < 4)){
        if(i == GOAL_X && j == GOAL_Y) return 1;
        int x_prec = i;
        int y_prec = j;
        int val_att = matrix[i][j];
        //su
        if(matrix[i - 1][j] == (val_att + 1) || matrix[i - 1][j] == (val_att - 1)){
            if(i += 1 != x_prec) val_att = matrix[i][j];
            else i += 1;
        }
        //giu
        if(matrix[i + 1][j] == (val_att + 1) || matrix[i + 1][j] == (val_att - 1)){
            if(i += 1 != x_prec) val_att = matrix[i][j];
            else i += -1;
        }
        //dx
        if(matrix[i][j + 1] == (val_att + 1) || matrix[i][j + 1] == (val_att - 1)){
            if(j += 1 != y_prec) val_att = matrix[i][j];
            else j += -1;
        }
        //sx
        if(matrix[i][j - 1] == (val_att + 1) || matrix[i][j + 1] == (val_att + 1)){
            if(j += -1 != y_prec) val_att = matrix[i][j];
            else j += 1;
        }
    }
    return 0;
}

/**
 * La funzione modifica la lista l, inserendo el in pos centrale
 * (in modo che il nuovo nodo sia preceduto e seguito dallo stesso numero
 * di nodi. Si ipotizzi che la lista l contenga sempre un numero pari e non
 * inferiore a 2.
 */
void centro(lista l, int el){
    lista copia_testa = l;
    lista new_node = (struct nodo *) malloc(sizeof(struct nodo));
    new_node->el = el;
    size_t lung = lunghezza_lista(l);
    size_t meta = lung / 2;
    for(int i = 0; i < meta + 1; i++)
        copia_testa = copia_testa->next;

    lista next_node = copia_testa->next;
    copia_testa->next = new_node;
    new_node->next = next_node;

}

size_t lunghezza_lista(lista l){
    lista l_copy = l;
    size_t length = 0;
    while(l_copy != NULL){
        length++;
        l_copy = l_copy->next;
    }
    return length;
}