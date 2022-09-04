//
// Created by Mattia Lunardi on 29/06/22.
//
#include <stdio.h>
#include <stdlib.h>

struct nodo{
    char info;
    struct nodo *next;
    //per esercizi con alberi
    struct nodo *sx;
    struct nodo *dx;
};

struct Rational{
    int num;
    int denum;
};

/**
* Definite una funzione che riceve in ingresso 2 strighe
 * vettori di caratteri e restituisce la stringa
 * corrispondente alla loro concatenazione
*/

char *StringsConcat(char *s1, char *s2);
unsigned MinMat(unsigned **mat, int, int);
int sommaVett(int [], int);
int main(int argc, char *argv[]){
    char *s1 = argv[1]; char *s2 = argv[2];


    int vec[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int vec_2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sum = sommaVett(vec, 10);
    printf("sum: %d\n", sum);
    sum = sommaVett(vec_2, 10);
    printf("sum: %d\n", sum);

    //char *conc = StringsConcat(s1, s2);
    //printf("%s\n", conc);
}

char *StringsConcat(char *s1, char *s2){
    if(s1 == NULL && s2 == NULL) return NULL;
    if(s1 == NULL && s2 != NULL) return s2;
    if(s1 != NULL && s2 == NULL) return s1;

    char *ris;
    char *s1_copy = s1;
    char *s2_copy = s2;
    int length_s1 = 0, length_s2 = 0;
    while(*s1_copy != '\0'){
        length_s1++;
        s1_copy+=1;
    }
    while(*s2_copy != '\0'){
        length_s2++;
        s2_copy+=1;
    }

    ris = (char *) malloc(sizeof(char) * (length_s1 + length_s2) + 1);
    for(int i = 0; i < length_s1; i++){
        ris[i] = s1[i];
    }
    for(int i = length_s1+1; i < length_s1+length_s2; i++){
        ris[i] = s2[i];
    }
    ris[length_s1 + length_s2 + 1] = '\0';
    return ris;
}

/**
* Definite una funzione che riceve in ingresso una matrice di interi
 * non negativi e restituisce il valore minore
*/

unsigned MinMat(unsigned **mat, int nrighe, int ncol){
    unsigned min = 0;
    for(int i = 0; i < nrighe; i++){
        for(int j = 0; j < ncol; j++)
            if(min < mat[i][j]) min = mat[i][j];
    }
    return min;
}

/**
* Considerate la struttura struct nodo {char info; struct nodo *next;}
 * supponete che una lista sia identificata dal puntatore al primo nodo
 * Completate la seguente funzione C in modo che la chiamata ArrayToList(A)
 * restituisca una lista contente tanti caratteri quanti quelli presenti
 * nella stringa contenuta nel vettore A
*/

struct nodo *ArrayToList(char a[]){
    struct nodo *head = (struct nodo *) malloc(sizeof(struct nodo));
    struct nodo *tmp = head;
    int i = 0;
    while(a[i] != '\0'){
        tmp->info = a[i];
        tmp->next = (struct nodo *) malloc(sizeof(struct nodo));
        tmp = tmp->next;
        i++;
    }
    if(a[i] == '\0'){head->info = '\0'; head->next = NULL;}
    return head;
}

/**
* Considerate la struttura struct nodo{char info; struct nodo *next;}
 * e supponete ceh una lista sia identificata dal puntatore al primo
 * nodo. Completate la seguente funzione C in modo che la chiamata
 * ListToArray(L) restituisca un vettore da interpretare come stringa
 * formata dai caratteri presenti nella lista L
*/

char *ListToArray(struct nodo *pt){
    char *v;
    int n_elementi = 0;
    struct nodo *pt_copy = pt;
    if(pt_copy->info == '\0'){
        v = (char *) malloc(sizeof(char));
        *v = '\0';
        return v;
    }
    while(pt_copy->info != '\0'){
        n_elementi++;
        pt_copy = pt_copy->next;
    }

    v = (char *) calloc(n_elementi+1, sizeof(char));
    for(int i = 0; i < n_elementi; i++){
        v[i] = pt->info;
        pt = pt->next;
    }
    if(pt->info == '\0')
        v[n_elementi] = '\0';
    return v;
}

/**
*   Definite una funzione Max che restituisce il massimo valore in una matrice
 *   di double
*/

double max(double **mat, int righe, int colonne){
    double max = 0;
    for(int i = 0; i < righe; i++)
        for(int j = 0; j < colonne; j++)
            if(mat[i][j] > max) max = mat[i][j];
    return max;
}


/**
* Definite una funzione che riceve in ingresso un vettore di interi e
 * ad ogni chiamata restituisce la somma di tutti gli interi incontrati
 * nei vettori che sono stati parametri attuali nella chiamata corrente
 * e in tutte le precedenti
*/

int sommaVett(int vec[], int length){
    static int count = 0;
    for(size_t i = 0; i < length; i++)
        count+= vec[i];
    return count;
}

/*+
 * Considerate la struttura
 * struct nodo{int info; struct nodo *next;}
 * supponete che una lista di interi sia identificata
 * dal puntatore al primo nodo
 * Completate la seguente procedura C in modo che
 * l'istruzione pt = DeleteList(pt) cancelli l'intera
 * lista
 */

struct nodo *DeleteList(struct nodo *head){
    struct nodo *tmp = head;
    while(tmp != NULL){
        tmp = head->next;
        free(tmp);
        head = tmp;
    }
    return tmp;
}

/**
* Considerate la struttura
 * struct nodo{int info; struct nodo *sx; struct nodo *dx}
 * e supponete che un albero binario sia identificato
 * dal puntatore alla radice. Completate la seguente
 * procedura C in modo che l'istruzione
 * pt = CancellaFoglie(pt) cancelli tutte le foglie dell'
 * albero associato a pt
*/

struct nodo *CancellaFoglie(struct nodo *T){
    if(T == NULL) return T;
    if(T->sx == NULL && T->dx == NULL){
        free(T); return NULL;
    }
    T->sx = CancellaFoglie(T->sx);
    T->dx = CancellaFoglie(T->dx);
    return T;
}

/**
 * Considerate la struttura così definita
 * struct nodo{int k; struct nodo *next;}
 * e progettate una funzione che accetta in ingresso un
 * intero n e restituisce una lista di n nodi, dove
 * il nodo i-esimo contiene il valore i (1 <= i <= n)
*/

struct nodo *IntList(int n){
    struct nodo *head = (struct nodo *) malloc(sizeof(struct nodo));
    struct nodo *tmp = head;
    for(int i = 1; i <= n; i++){
        tmp->info = i;
        tmp->next = (struct nodo *) malloc(sizeof(struct nodo));
        tmp = tmp->next;
    }
    return head;
}

/**
* Supponete di utilizzare la segunte struttura per implementare
 * liste concatenate
 * struct nodo{char c; struct nodo *next;}
 * Definite una procedura che riceve in ingresso una stringa v
 * (vettore di caratteri) e restituisce una lista di pari lunghezza
 * contenete gli stessi caratteri nello stesso ordine
*/

struct nodo *StringToList(char str[]){
    struct nodo *head = (struct nodo *) malloc(sizeof(struct nodo));
    if(str[0] == '\0'){
        head->info = '\0';
        head->next = NULL;
        return head;
    }
    struct nodo *tmp = head;
    int i = 0;
    while(str[i] != '\0'){
        head->info = str[i];
        head->next = (struct nodo *) malloc(sizeof(struct nodo));
        head = head->next;
        i++;
    }
    head->info = '\0';
    head->next = NULL;
    return tmp;
}

/**
* Definite una funzione che riceve in ingresso una stringa
 * (vettore di caratteri) e restituisce la somma delle lunghezze
 * di tutte le stringhe su cui è chiamata
*/

int sommaLun(char *s){
    static int length = 0;
    while(*s != '\0'){
        length++;
        s+=1;
    }
    return length;
}

/**
* Supponete di utilizzare la seguente struttura per implementare i
 * nodi di alberi binari
 * struct nodo{int c; struct nodo *sx; struct nodo *dx;}
 * Definite una procedura che riceve in ingresso un albero p
 * e un intero k e restituisce il numero di nodi dell'albero
 * che si trovano sul livello k
 * (il livello della radice è 0)
*/

int NnodiLiv(struct nodo *l ,int k){
    static int level = 0; int left = 0; int right = 0;
    if(k == level) return 1;
    if(l->sx != NULL){level++; left = NnodiLiv(l->sx, k);}
    level--;
    if(l->dx != NULL){level++; right = NnodiLiv(l->dx, level--);}
    return left+right;
}


/**
* Definite una procedura per lo scambio di 2 valori float
*/

void scambio(float *a, float *b){
    float tmp = *b;
    *a = *b;
    *b = tmp;
}

/**
* Considerate la struttura nodo{int i; struct nodo *next;} e
 * scrivete una funzione deleteList che accetta in ingresso una lista
 * nota attraverso un puntatore al primo nodo e la cancella
 * Il puntatore passato come parametro dovrà al termine risultare
 * nullo
*/

void deleteList(struct nodo **l){
    struct nodo *head = *l;
    struct nodo *tmp = head;
    if(l == NULL || *l == NULL) return;
    while(head != NULL){
        free(tmp);
        tmp = head;
        head = head->next;
    }
    free(tmp);
    *l = NULL;
    free(l);
}

/**
* Data la struttura struct Rational{int num; int denum;} scrivete una
 * procedura swap per effettura lo scambio di 2 variabili a e b di tipo
 * struct Rational
*/

void swap(struct Rational *a, struct Rational *b){
    struct Rational *tmp = (struct Rational *) malloc(sizeof(struct Rational));
    tmp->num = b->num;
    tmp->denum = b->denum;
    b->num = a->num;
    b->denum = a->denum;
    a->num = tmp->num;
    a->denum = tmp->denum;
}

/**
* La traccia di una matrice è definite come la somma degli elementi
 * sulla diagonale principale
 * Scrivete una funzione che accetta in ingresso una matrice A(quadrata)
 * di short, il suo ordine n e ne restituisce la traccia
 * Quali condizioni deve soddisfare il parametro attuale associato
 * alla matrice
*/
short Traccia(short **matrice, int n){
    short traccia = 0;
    for(int i = 0; i < n; i++){traccia += matrice[i][i];}
    return traccia;
}

/**
* Scrivete una funzione miamal che assegna un blocco di un KB di memoria
 * dinamica al puntatore costituente l'unico parametro e che restituisce
 * un intero che rappresenta il numero di KB allocati fino al quel momento.
 * La funzione deve permettere al massimo l'allocazione di 100 blocchi
 * Alla richeista del 101-esimo blocco il puntatore risulterà nullo
*/

int miamal(void **pt){
    static int count = 0;
    if(pt == NULL) return -1;
    if(count > 100){
        *pt = NULL;
        return -1;
    }
    *pt = (void *) malloc(sizeof(void) * 1024);
    count++;
    return count;
}