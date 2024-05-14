//
// Created by wengj on 26/04/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "column2.h"
#define REALOC_SIZE 256


COLUMN *create_column(ENUM_TYPE type, char *title) {
    COLUMN *p_col = (COLUMN*)malloc(sizeof(COLUMN));

    p_col->title = title;
    p_col->size = 0;    // Taille logique
    p_col->max_size = 0;    // Taille physique
    p_col->column_type = type;
    p_col->data = NULL;
    p_col->index = NULL;

    return p_col;
}

int insert_value(COLUMN *col, void *value) {
    if(value==NULL){
        value="\0";
    }
    if (col == NULL) {
        printf("Erreur : colonne invalide.\n");
        return 0;
    }
    if (col->data == NULL) {    //Si col->data n'a aucun pointeur, on l'initialise
        col->data = (COL_TYPE **) malloc(REALOC_SIZE * sizeof(int));
        col->max_size = REALOC_SIZE;    //On change la valeur de la taille physique puisqu'on l'a augmenté
        if (col->data == NULL) {
            printf("Erreur : Pas d'espace disponible.\n");
            return 0;
        }
    } else if (col->max_size == col->size) {    //Si l'espace de col->data est complet, on l'agrandit
        col->data = realloc(col->data, (col->max_size + REALOC_SIZE));
        col->max_size += REALOC_SIZE;   //On change la valeur de la taille physique puisqu'on l'a augmenté
        if (col->data == NULL) {
            printf("Erreur : Pas d'espace disponible.\n");
            return 0;
        }
    }
    if (col->data!= NULL && col->max_size > col->size) {    //Si les conditions d'insertion de la valeur sont correcte
        switch (col->column_type) {
            case UINT:
                col->data[col->size] = (unsigned int *) malloc(sizeof(unsigned int));
                *((unsigned int *) col->data[col->size]) = *((unsigned int *) value);
                break;
            case INT:
                col->data[col->size] = (int *) malloc(sizeof(int));
                *((int *) col->data[col->size]) = *((int *) value);
                break;
            case CHAR:
                col->data[col->size] = (char *) malloc(sizeof(char));
                *((char *) col->data[col->size]) = *((char *) value);
                break;
            case FLOAT:
                col->data[col->size] = (float *) malloc(sizeof(float));
                *((float *) col->data[col->size]) = *((float *) value);
                break;
            case DOUBLE:
                col->data[col->size] = (double *) malloc(sizeof(double));
                *((double *) col->data[col->size]) = *((double *) value);
                break;
            case STRING:
                col->data[col->size] = (char **) malloc(sizeof(char *));
                *((char **) col->data[col->size]) = *((char **) value);
                break;
            case STRUCTURE:
                col->data[col->size] = (void **) malloc(sizeof(void *));
                *((void **) col->data[col->size]) = *((void **) value);
                break;
        }
            col->size++;
        return 1;
    } else {
        return 0;
    }
}

void delete_column(COLUMN **col){
    free(*((*col)->data));
    *((*col)->data) = NULL;

    free((*col)->data);
    (*col)->data = NULL;

    free((*col)->title);
    (*col)->title = NULL;

    free(*col);
    *col=NULL;

    free(col);
    col=NULL;
}

void convert_value(COLUMN* col, unsigned long long int i, char* str, int size){

    switch(col->column_type){
        case UINT:
            snprintf(str, size, "%u", *((unsigned int*)col->data[i]));
            break;
        case INT:
            snprintf(str, size, "%d", *((int*)col->data[i]));
            break;
        case CHAR:
            snprintf(str, size, "%c", *((char *)col->data[i]));
            break;
        case FLOAT:
            snprintf(str, size, "%f", *((float *)col->data[i]));
            break;
        case DOUBLE:
            snprintf(str, size, "%lf", *((double *)col->data[i]));
            break;
        case STRING:
            snprintf(str, size, "%s", *((char **)col->data[i]));
            break;
        case STRUCTURE:
            snprintf(str, size, "%p", *((void **)col->data[i]));
            break;
    }

}

void print_col(COLUMN* col){

    for (int i = 0; i < col->size; i++){
        char str[N];
        convert_value(col, i, str, N);
        if(str[0]!='\0') {
            printf("[%d] %s\n", i, str);
        }
        else{
            printf("[%d] NULL\n", i);
        }
    }
}

int nb_occurences(COLUMN *col, int x) {
    if (col == NULL || col->data == NULL) {
        printf("Erreur : Colonne invalide ou vide.\n");
        return 0;
    }

    int cmpt = 0;
    for (int i = 0; i < col->size; i++) {
        if (*(int*)col->data[i] == x) {  // A méditer !
            cmpt += 1;
        }
    }
    return cmpt;
}

int val_in_pos(COLUMN *col, int x) {
    return *(int*)col->data[x];
}

int greater_value(COLUMN* col, int x) {
    int greater = 0;
    for (int i = 0; i < col->size; i++) {
        if (*(int*)col->data[i] > x){
            greater++;
        }
    }
    return greater;
}

int lower_value(COLUMN* col, int x) {
    int lower = 0;
    for (int i = 0; i < col->size; i++) {
        if (*(int*)col->data[i] < x) {
            lower++;
        }
    }
    return lower;
}