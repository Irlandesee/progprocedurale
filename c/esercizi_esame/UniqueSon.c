//
// Created by Mattia Lunardi on 30/08/22.
//
#include "stdio.h"
#include "stdlib.h"
#include "stdarg.h"

struct nodo {
    int k;
    struct nodo *sx;
    struct nodo *dx;
};

struct node{
    int k;
    struct nodo *next;
};


int UniqueSon(struct nodo *root);

/**
 * Definite una funzione che non fa nulla
 * e che alla decima volta che viene chiamata si
 * limita a terminare dopo aver stampato il messaggio credito esaurito.
 */
void nulla();

void Scambio(float *, float *);

/**
 *
 * Scrivete una funzione deleteList che accetta in ingresso una lista
 * nota attraverso un puntatore al primo nodo, e la cancella.
 * Il puntatore passato come parametro dovrà al termine risultare
 * nullo.
 */

void deleteList(struct node **head);

/**
 *
 * Progettate una funzione che accetta in ingresso un albero, ne elimina le foglie
 * e restituisce un puntatore alla radice dell'albero cosi ottenuto.
 */

struct nodo *deleteLeaves(struct nodo *);

int sum(int, ...);

int main(int argc, char **argv){
    int s = sum(4, 20, 30, 40, 50);
    printf("%d\n", s);
}

int UniqueSon(struct nodo *root){
    //caso base
    if(root == NULL) return 0;
    //caso figlio sx NULL e figlio dx != NULL
    if(root->sx == NULL) return 1 + UniqueSon(root->dx);
    //caso figlio dx NULL e figlio sx != NULL
    else if(root->dx == NULL) return 1 + UniqueSon(root->sx);
    //Caso entrambi i figli != NULL
    else return UniqueSon(root->sx) + UniqueSon(root->dx);
}

/**
 *
 * @param x indicates the number of arguments
 * @param ...
 * @return
 */
int sum(int x, ...){
   va_list valist;
   int sum = 0;
   va_start(valist, x);
   for(int i = 0; i < x; i++)
      sum += va_arg(valist, int);
   va_end(valist);
   return sum;
}


void nulla(){
    static int count = 0;
    if(count < 10) count++;
    else {printf("Credito Esaurito"); count = 0;}
}


void Scambio(float *a, float *b){
    float tmp = *a;
    *a = *b;
    *b = tmp;
}

void deleteList(struct node **head){
   if(*head == NULL) return;
   struct node *head_copy = *head;
   while(head_copy != NULL){
      struct node *tmp = head_copy->next;
      free(head_copy);
      head_copy = tmp;
   }
   free(head_copy);
   *head = NULL;
}

struct nodo *deleteLeaves(struct nodo *root){
    if(root == NULL) return root;
    if(root->sx == NULL && root->dx == NULL){free(root); return NULL;}
    if(root->sx != NULL) root->sx = deleteLeaves(root->sx);
    if(root->dx != NULL) root->dx = deleteLeaves(root->dx);
    return root;
}