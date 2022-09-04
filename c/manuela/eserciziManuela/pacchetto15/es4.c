#include "stdio.h"
#include "stdlib.h"
struct nodo{
    char c;
    struct nodo *next;
};
typedef struct nodo *lista;

struct nodo *alloc_nodo();
int lunghezza_stringa(char *str);
char carattere(char *str, int i);
struct nodo *string_to_list(char str[]); //versione del prof
struct nodo *stringa_a_lista(char *s);

int main(int argc, char *argv[]) {
    char *v = argv[1];
    lista *head = (struct nodo **) malloc(sizeof(struct nodo));
    *head = (struct nodo *) malloc(sizeof(struct nodo));
    struct nodo *head_copy = *head;
    int v_length = lunghezza_stringa(v);
    printf("lunghezza stringa %d\n", v_length);

    for (int i = 0; i < v_length; i++) {
        char car = carattere(v, i);
        printf("%c-%d\n", car, i);
        struct nodo *new_node = alloc_nodo();
        new_node->c = car;
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

struct nodo *alloc_nodo(){
    return (struct nodo*)malloc(sizeof(struct nodo));
}

int lunghezza_stringa(char *str){
    int i = 0;
    while(str[i] != '\0') i++;
    return i;
}

char carattere(char *str, int i){
    if(str[i] != '\0'){
        return str[i];
    }
    return '\0';
}

struct nodo *string_to_list(char s[]){
    struct nodo *l, *pt;
    int i = 1;
    if(s[0] != '0'){
        l = (struct nodo *) malloc(sizeof(struct nodo));
        l->c = s[0];
        l->next = NULL;
    }
    else return NULL;

    pt = l;
    while(s[i] != '\0'){
        pt->next = (struct nodo *) malloc(sizeof(struct nodo));
        pt = pt->next;
        pt->c = s[i];
        i++;
    }
    pt->next = NULL;
    return l;
}