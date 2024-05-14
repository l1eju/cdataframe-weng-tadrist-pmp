#include <stdio.h>
#include <stdlib.h>
#include "cdataframe.h"

// Partie 4.2.1. Fonctionnalités
int* cdataframe_vide(){
    int* cdataframe = (int*) malloc(sizeof(int *));
    return cdataframe;
}

void remplissage_cdataframe(int **cdf, int *size){
    int choice;
    ENUM_TYPE type;
    char title[N];
    COLUMN *col;
    printf("0:UINT, 1:INT, 2:CHAR, 3:FLOAT, 4:DOUBLE, 5:STRING, 6:STRUCTURE\n"
           "Choisissez le type de donnée de la colonne : ");
    scanf("%d", &choice);

    switch (choice) {
        case 0:
            type=UINT;
            break;
        case 1:
            type=INT;
            break;
        case 2:
            type=CHAR;
            break;
        case 3:
            type=FLOAT;
            break;
        case 4:
            type=DOUBLE;
            break;
        case 5:
            type=STRING;
            break;
        case 6:
            type=STRUCTURE;
            break;
    }
    printf("\nEntrez le titre de la colonne: ");
    scanf(" %s", title);

    col=create_column(type, title);

    *cdf= realloc(*cdf, *size+1);
    *(cdf[*size]) = col;
    (*size)++;
}



/*
CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size){
    LIST* liste = (LIST*) malloc(sizeof(LNODE));
    CDATAFRAME* cdf = (CDATAFRAME*) malloc(size*sizeof(LIST));

    return cdf;
}

void delete_cdataframe(CDATAFRAME **cdf) {
    //free(*cdf.list);
}
*/