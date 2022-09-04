//
// Created by Mattia Lunardi on 16/05/22.
//

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct nodo{
    char c;
    struct nodo *next;
};

typedef struct nodo *Nodo;

char carattere(char *, int);
int lunghezza_stringa(char *);
int main(int argc, char *argv[]){
    Nodo *head = (struct nodo **) malloc(sizeof(struct nodo));
    *head = (struct nodo *) malloc(sizeof(struct nodo));

    struct nodo *head_copy = *head;

    char *s = argv[1];
    size_t s_length = lunghezza_stringa(s);
    printf("lunghezza stringa: %zu\n", s_length);
    for(int i = 0; i < s_length; i++){
        char c = carattere(s, i);
        printf("%c ", c);
        Nodo new_node = (struct nodo *) malloc(sizeof(struct nodo));
        new_node->c = c;
        new_node->next = NULL;
        (*head)->next = new_node;
        (*head) = (*head)->next;
    }

    while(head_copy != NULL){
        printf("%c\n", head_copy->c);
        head_copy = head_copy->next;
    }

    return 0;
}

char carattere(char *s, int i){
    if(s[i] != NULL)
        return s[i];
    return NULL;
}

int lunghezza_stringa(char *s){
    char *p = s;
    while(*p != '\0') p++;
    return p - s;
}