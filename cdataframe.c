//
// Created by wengj on 14/05/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "column2.h"
#include "cdataframe.h"

COLUMN ** cdataframe_vide(int size){
    COLUMN ** cdataframe = (COLUMN **) malloc(size*sizeof(COLUMN));
    return cdataframe;
}

void remplissage_cdataframe(COLUMN ***cdf, int *size){
    int choice, r, len;
    ENUM_TYPE type;
    char title[N];
    COLUMN *col;
    do {
        printf("0:UINT, 1:INT, 2:CHAR, 3:FLOAT, 4:DOUBLE, 5:STRING, 6:STRUCTURE\n"
               "Choisissez le type de donnee de la colonne :");
        r=scanf("%d", &choice);
    } while (r!=1 || choice>6 || choice<0);

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
    printf("Entrez le titre de la colonne: ");
    scanf(" %s", title);

    col=create_column(type, title);
    printf("Entrez le nombre de valeur a entrer dans la colonne :");
    scanf("%d", &len);

    for (int i=0; i<len; i++){

        printf("Insérer la valeur [%d] : ", i);
        void* val;
        switch (col->column_type) {
            case UINT: {
                unsigned int entree;
                scanf("%u", &entree);
                val=&entree;
                break;
            }
            case INT: {
                int entree;
                scanf("%d", &entree);
                break;
            }
            case CHAR:{
                char entree;
                scanf(" %c", &entree);
                break;
            }

        }
        insert_value(col, val);
        }


    printf("ok");
    **cdf= realloc(**cdf, (*size + 1) * sizeof(COLUMN));
    *cdf[*size] = col;
    (*size)++;
}

void afficher_tout_cdataframe(COLUMN **cdf, int size){
    for (int i=0; i<size; i++){
        printf("%s\n", cdf[i]->title);
        print_col(cdf[i]);

    }
}

void afficher_p_ligne_cdataframe(COLUMN **cdf, int size, int tete, int queue){
    for (int i=0; i<size; i++){
        printf("%s\n", cdf[i]->title);
        for (int j = tete; j <= queue; j++){
            char str[N];
            convert_value(cdf[i], j, str, N);
            if(str[0]!='\0') {
                printf("[%d] %s\n", j, str);
            }
            else{
                printf("[%d] NULL\n", j);
            }
        }
    }
}

void afficher_p_colonne_cdataframe(COLUMN **cdf, int size, int tete, int queue){
    for (int i=tete; i<=queue; i++){
        printf("%s\n", cdf[i]->title);
        print_col(cdf[i]);
    }
}