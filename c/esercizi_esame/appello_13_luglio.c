//
// Created by Mattia Lunardi on 10/08/22.
//
#include "stdio.h"
#include "stdlib.h"


struct nodo{
    int info;
    struct nodo *next;
    struct nodo *sx;
    struct nodo *dx;
};

/**
 * Scrivete una funzione che accetta in ingresso un intero non negativo
 * e restituisce un vettore contenente le singole cifre
 */

int *IntToArray(unsigned int);

/**
 * Supponete che una lista di interi sia identificata dal puntatore al
 * primo nodo. Completate la seguente procedura C in modo che l'istruzione
 * pt = DeleteList(pt) cancelli l'interi lista.
 */
struct nodo *DeleteList(struct nodo *);

/**
 * supponete che una lista sia identificata dal puntatore al primo nodo
 * Completate la seguente funzione C in modo che la chiamata ArrayToList(A)
 * restituisca una lista contenente tanti caratteri quanti quelli presenti
 * nella stringa contenuta nel vettore A
 */

int arr_length(int *);


/**
 * Completate la seguente funzione C in modo che la chiamata ListToArray(L) restitu
 */

int main(int argc, char **argv){
    int num = 351;
    int *arr = IntToArray(num);

    int length = arr_length(arr);
    printf("Array length: %d\n", length);

    for(int i = 0; i < length; i++){
        printf("[%d] -> [%d]\n", i, *arr);
        arr+=1;
    }
}

int *IntToArray(unsigned  int n){
    int *pt;
    int ncifre = 1;
    unsigned int p = n;
    while(p >= 10){ p = p/10; ncifre++;}
    pt = (int *) calloc(ncifre, sizeof(int));
    for(int i = ncifre - 1; i >= 0; i--){
        pt[i] = n % 10;
        n = n / 10;
    }
    return pt;
}

int arr_length(int *arr){
    int i = 0;
    for(i; arr[i] != NULL; i++)
        ;
    return i;
}


struct nodo *DeleteList(struct nodo *pt){
    struct nodo *tmp = pt;
    while(tmp != NULL){
        tmp = tmp->next;
        free(pt);
        pt = tmp;
    }
    free(tmp);
}

struct nodo *CancellaFoglie(struct nodo *T){
    if(T == NULL) return T;
    if(T->sx == NULL && T->dx == NULL){free(T); return NULL;}
    T->sx = CancellaFoglie(T->sx);
    T->dx = CancellaFoglie(T->dx);
    return T;
}
