//
// Created by wengj on 29/03/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

#define REALOC_SIZE 256

COLUMN *create_column(char* title) {
    COLUMN* p_col = NULL;
    COLUMN* col = (COLUMN*)malloc(sizeof(COLUMN));

    col->Titre = title;
    col->Taille_logique = 0;
    col->Taille_physique = 0;
    col->Donnees = NULL;

    p_col = &col;

    return p_col;
}

int insert_value(COLUMN *col, int value) {
    if(col->Taille_logique==NULL){
        col->Donnees= (int*) malloc(REALOC_SIZE*sizeof(int));
        if (col->Donnees == NULL) {
            printf("Pas d'espace disponible");
            return 0;
        }
        else {
            col->Taille_physique = REALOC_SIZE;

            col->Donnees[0] = value;
            col->Taille_logique = 1;
            return 1;
        }
    }
    else if(col->Taille_physique==col->Taille_logique){
        col->Donnees= realloc(col->Donnees,(col->Taille_physique+REALOC_SIZE));

        if (col->Donnees == NULL) {
            printf("Pas d'espace disponible");
            return 0;
        }
        else {
            col->Taille_physique += REALOC_SIZE;

            col->Donnees[col->Taille_logique] = value;
            col->Taille_logique += 1;
            return 1;
        }
    }
    else if(col->Taille_physique>col->Taille_logique){
        col->Donnees[col->Taille_logique]=value;
        col->Taille_logique++;
        return 1;
    }
    return 0;
}

void delete_column(COLUMN **col){
    free((*col)->Donnees);
    (*col)->Donnees = NULL;

    free((*col)->Titre);
    (*col)->Titre = NULL;

    free(*col);
    *col=NULL;
}

void print_col(COLUMN* col){
    for(int i=0; i<(col->Taille_logique); i++){
        printf("[%d] %d\n", i, col->Donnees[i]);
    }
}

int nb_occurences(COLUMN *col, int x) {
    int cmpt = 0;
    for (int i = 0; i < col->Taille_logique; i++) {
        if (col->Donnees[i] == x) {
            cmpt += 1;
        }
    }
    return cmpt;
}

int val_in_pos(COLUMN *col, int x) {
    return col->Donnees[x];
}

int greater_value(COLUMN* col, int x){
    int greater=0;
    for(int i=0; i<col->Taille_logique; i++){
        if(col->Donnees[i]>x){
            greater++;
        }
    }
    return greater;
}

int lower_value(COLUMN* col, int x){
    int lower=0;
    for(int i=0; i<col->Taille_logique; i++){
        if(col->Donnees[i]<x){
            lower++;
        }
    }
    return lower;
}

int lower_value(COLUMN* col, int x){
    int lower=0;
    for(int i=0; i<col->Taille_logique; i++){
        if(col->Donnees[i]<x){
            lower++;
        }
    }
    return lower;
}

