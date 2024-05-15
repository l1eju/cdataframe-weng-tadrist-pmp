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

void remplissage_cdataframe(COLUMN ***cdf, ENUM_TYPE type, int size, char *title, void *value[], int nb_value){
    COLUMN *col;
    col=create_column(type, title);

    for (int i=0; i<nb_value; i++) {
        insert_value(col, value[i]);
    }
    add_col_cdataframe(cdf, &size, col);
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

void afficher_p_colonne_cdataframe(COLUMN **cdf, int tete, int queue){
    for (int i=tete; i<=queue; i++){
        printf("%s\n", cdf[i]->title);
        print_col(cdf[i]);
    }
}

void add_col_cdataframe(COLUMN ***cdf, int *size, COLUMN *col){
    **cdf= realloc(**cdf, (*size+1)*sizeof(COLUMN));
    *cdf[(*size)++]=col;
}

void del_col_cdataframe(COLUMN ***cdf, int *size, int col_del){
    delete_column(cdf[col_del]);
    **cdf= realloc(**cdf, (*size-1)*sizeof(COLUMN));
    (*size)--;
}

void rename_title_of_col_in_cdf(COLUMN ***cdf,int index_col, char* new_title){
    (*cdf)[index_col]->title=new_title;
}

int val_existence_cdataframe(COLUMN **cdf, int size, char* value){
}