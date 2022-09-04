//
// Created by Mattia Lunardi on 05/08/22.
//
#include "stdio.h"
#include "stdlib.h"

int main(int argc, char **argv){

    //relativi
    char *rel_filename = "../file.md";
    //assoluti
    char *abs_filename = "/Users/mattiamac/Documents/GitHub/progprocedurale/c/eserciziManuela/file.md";
    FILE *fp = fopen(abs_filename, "rb");

    char buffer[100];
    fread(buffer, sizeof(buffer), 1, fp);

    for(int i = 0; i < 100; i++)
        printf("%c", buffer[i]);

    fclose(fp);
}