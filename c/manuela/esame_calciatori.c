//
// Created by Mattia Lunardi on 14/07/22.
//

#include "stdio.h"
#include "stdlib.h"
#define MAX_STAGIONI 5
struct calciatore{
    char *nome;
    char *cognome;
    int eta;
    char *nome_squadra;
    int numero_goal[MAX_STAGIONI]; //ultime 5 stagioni
};


int selezione(struct calciatore lista[], struct calciatore sel[], int n);

int selezione(struct calciatore lista[], struct calciatore sel[], int n){
    int j = 0; //indice di copia per sel
    int numero_giocatori_trovati = 0;
    for(int i = 0; i < n; i++){
        struct calciatore tmp = lista[i];

        int numero_goal_giocatore = 0;
        for(int k = 0; k < MAX_STAGIONI; k++){
            numero_goal_giocatore += tmp.numero_goal[k];
        }
        if(numero_goal_giocatore > 20){
            printf("%s, %s, totale goal: %d\n", tmp.nome, tmp.cognome, numero_goal_giocatore);
            sel[j] = tmp;
            numero_giocatori_trovati++;
            j++;
        }
    }

    return numero_giocatori_trovati;
}

