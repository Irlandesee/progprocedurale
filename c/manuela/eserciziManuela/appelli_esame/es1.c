//
// Created by Mattia Lunardi on 23/05/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//Se c si trova in s ritorna 1 altrimenti 0
int find_carattere(char c, char *s);
//ritorna l'indice di c in s, si presume che c sia presente in s
int index_carattere(char c, char *s);
void wordle(char[], char[], int[]);

int main(int argc, char *argv[]){

   char s[6] = "casto";
   char tentativo[6] = "porta";
   int risultato[6];
   wordle(s, tentativo, risultato);

   printf("=================\n");
   int array_giusto[6] = {0, 1, 0, 2, 1};
   for(int i = 0; i < 6; i++){
      //assert(risultato[i] == array_giusto[i]);
      printf("%d-%d\n", risultato[i], array_giusto[i]);
   }

}

int find_carattere(char c, char *s){
    char tmp = s[0];
    while(tmp != '\0'){
        if(c == tmp)
            return 1;
        tmp = *++s;
    }
    return 0;
}

void wordle(char s[], char t[], int ris[]){
    for(int i = 0; t[i] != '\0'; i++){
       char c = t[i];
       if(find_carattere(c, s) == 1){
           int pos_t = index_carattere(c, s);
           if(i == pos_t) ris[i] = 2;
           else ris[i] = 1;
       }
       else
           ris[i] = 0;
   }
}

int index_carattere(char c, char *s){
    for(int i = 0; s[i] != '\0'; i++)
        if(c == s[i]) return i;
    return -1;
}