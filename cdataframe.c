//
// Created by wengj on 14/05/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "column2.h"
#include "cdataframe.h"

void* adpater_valeur(COLUMN **cdf, int indice){
    void* value;
    switch (cdf[indice]->column_type) {
        case UINT: {
            unsigned int tmp;
            scanf("%u", &tmp);
            value = &tmp;
            break;
        }
        case INT: {
            int tmp;
            scanf("%d", &tmp);
            value = &tmp;
            break;
        }
        case CHAR: {
            char tmp;
            scanf(" %c", &tmp);
            value = &tmp;
            break;
        }
        case FLOAT: {
            float tmp;
            scanf("%f", &tmp);
            value = &tmp;
            break;
        }
        case DOUBLE: {
            double tmp;
            scanf("%lf", &tmp);
            value = &tmp;
            break;
        }
        case STRING: {
            char tmp[N];
            scanf("%s", tmp);
            value = &tmp;
            break;
        }
        case STRUCTURE: {
            void *tmp;
            scanf("%p", &tmp);
            value = &tmp;
            break;
        }
    }
    return value;
}

//1. Alimentation

COLUMN ** cdataframe_vide(int size){
        COLUMN ** cdataframe = (COLUMN **) malloc(size*sizeof(COLUMN));
    return cdataframe;
}

void remplissage_cdataframe(COLUMN ***cdf, ENUM_TYPE type, int size, char *title, void *(value[]), int nb_value){
    COLUMN *col;
    col=create_column(type, title);

    for (int i=0; i<nb_value; i++) {
        insert_value(col, value[i]);
    }
    add_col_cdataframe(cdf, &size, col);
}


//2. Affichage

void afficher_tout_cdataframe(COLUMN **cdf, int nb_col){
    if (nb_col!=0) {
        for (int i = 0; i < nb_col; i++) {
            printf("%s\n", cdf[i]->title);
            print_col(cdf[i]);
        }
    }else{
        printf("CDataFrame Vide\n");
    }
}

void afficher_p_ligne_cdataframe(COLUMN **cdf, int nb_col, int tete, int queue){
    for (int i=0; i<nb_col; i++){

        int fin=queue;  //condition si la fin demandé est supérieur à la taille logique
        if (queue>cdf[i]->size){
            fin=cdf[i]->size;
        }
        if (tete<0){
            tete=0;
        }

        printf("%s\n", cdf[i]->title);
        for (int j = tete; j <= fin; j++){

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


//3. Opérations usuelles
void add_lig_cdataframe(COLUMN ***cdf, int indice_col, void* value){
    insert_value((*cdf)[indice_col], value);
}

void del_lig_cdataframe(COLUMN ***cdf, int indice_col){
    (*cdf)[indice_col]->data = realloc((*cdf)[indice_col]->data, (--(((*cdf)[indice_col]->size)))*sizeof((*cdf)[indice_col]->column_type));

}


void add_col_cdataframe(COLUMN ***cdf, int *nb_col, COLUMN *col){
    *(*cdf)= realloc(*(*cdf), ((*nb_col)+1)*sizeof(COLUMN));
    (*cdf)[(*nb_col)++]=col;
}

void del_col_cdataframe(COLUMN ***cdf, int *nb_col, int col_del){
    delete_column(cdf[col_del]);
    afficher_p_colonne_cdataframe(*cdf, 0, 0);
    for(int i=col_del; i<(*nb_col)-1; i++){
        (*cdf)[i]=(*cdf)[i+1];
    }
    **cdf= realloc(**cdf, (*nb_col-1)*sizeof(COLUMN));
    (*nb_col)--;
}

void rename_title_of_col_in_cdf(COLUMN ***cdf,int index_col, char* new_title){
    (*cdf)[index_col]->title=new_title;
}

int val_existence_cdataframe(COLUMN **cdf, int nb_col, char* value){
    for (int i=0; i<nb_col; i++){
        for(int j=0; j<cdf[i]->size; j++){
            char str[N];
            convert_value(cdf[i], j, str, N);
            if(strcmp(str, value)==0) {
                return 1;
            }
        }
    }
    return 0;
}

void acceder_remplacer_val_cellule(COLUMN ***cdf, int num_lig, int num_col, void* value){

    if (value!=NULL) {
        (*cdf)[num_col]->data[num_lig] = value;
    }

}

void afficher_nom_col(COLUMN **cdf, int nb_col){
    for(int i=0; i<nb_col; i++){
        printf("Colonne [%d] : %s\n", i, cdf[i]->title);
    }
}