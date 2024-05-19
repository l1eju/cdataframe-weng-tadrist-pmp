//
// Created by wengj on 26/04/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    if(value==NULL){    //Si value est NULL on le transforme en caractère null
        value="\0";
    }
    if (col == NULL) {  //Erreur
        printf("Erreur : colonne invalide.\n");
        return 0;
    }
    if (col->data == NULL) {    //Si la colonne ne contient aucune donnée, on l'initialise selon son type
        col->data = (COL_TYPE **) malloc(REALOC_SIZE * sizeof(col->column_type));
        col->max_size = REALOC_SIZE;    //On change la valeur de la taille physique puisqu'on l'a augmenté
        if (col->data == NULL) {    //Erreur
            printf("Erreur : Pas d'espace disponible.\n");
            return 0;
        }
    } else if (col->max_size == col->size) {    //Si l'espace de col->data est complet, on l'agrandit
        col->data = realloc(col->data, ((col->max_size + REALOC_SIZE))*sizeof(col->column_type));
        col->max_size += REALOC_SIZE;   //On change la valeur de la taille physique puisqu'on l'a augmenté
        if (col->data == NULL) {    //Erreur
            printf("Erreur : Pas d'espace disponible.\n");
            return 0;
        }
    }
    if (col->data != NULL && col->max_size > col->size) {    //Si les conditions d'insertion de la valeur sont correctes
        switch (col->column_type) {     //On crée un pointeur selon le type dans le tableau de pointeur col->data de la taille du type puis on insère la valeur
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
            col->size++;    //On augmente la taille logique puisqu'on vient d'ajouter une valeur
        return 1;
    } else {
        return 0;
    }
}

void delete_column(COLUMN **col){
    free((*col)->data); //On libère le tableau de pointeur
    (*col)->data = NULL;

    free(*col); //On libère la colonne
    *col=NULL;
}

void convert_value(COLUMN* col, unsigned long long int i, char* str, int size){

    switch(col->column_type){   //Selon son type, on convertit la valeur en chaine de caractère
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

    for (int i = 0; i < col->size; i++){    //On parcourt toute la colonne
        char str[N];
        convert_value(col, i, str, N);
        if(str[0]!='\0') {  //Si la valeur n'est pas le caractère null, on l'affiche normalement
            printf("[%d] %s\n", i, str);
        }
        else{   //Sinon on affiche "NULL"
            printf("[%d] NULL\n", i);
        }
    }
}

int nb_occurences(COLUMN *col, void* x) {
    if (col == NULL || col->data == NULL) {
        printf("Erreur : Colonne invalide ou vide.\n");
        return 0;
    }

    int cmpt = 0;
    switch(col->column_type){
        case UINT:
            for (int i = 0; i < col->size; i++) {
                if (*(unsigned int*)col->data[i] == *(unsigned int*)x) {
                    cmpt += 1;
                }
            }
            break;
        case INT:
            for (int i = 0; i < col->size; i++) {
                if (*(int *) col->data[i] == *(int *) x) {
                    cmpt += 1;
                }
            }
            break;
        case CHAR:
            for (int i = 0; i < col->size; i++) {
                if (*(char*)col->data[i] == *(char*)x) {
                    cmpt += 1;
                }
            }
            break;
        case FLOAT:
            for (int i = 0; i < col->size; i++) {
                if (*(float*)col->data[i] == *(float*)x) {
                    cmpt += 1;
                }
            }
            break;
        case DOUBLE:
            for (int i = 0; i < col->size; i++) {
                if (*(double*)col->data[i] == *(double*)x) {
                    cmpt += 1;
                }
            }
            break;
        case STRING:
            // Comparaison de chaînes de caractères
            for (int i = 0; i < col->size; i++) {
                if (strcmp((char*)col->data[i], (char*)x) == 0) {
                    cmpt += 1;
                }
            }
            break;
        case STRUCTURE:
            // Non réalisable
            break;
        default:
            printf("Type de colonne non pris en charge.\n");
            return 0;
    }
    return cmpt;
}

void* val_in_pos(COLUMN *col, int indice) {
    void* val;
    switch(col->column_type) {   //Verifie l'infériorité selon le type
        case UINT:
            val=(unsigned int *) col->data[indice];
            break;

        case INT:
            val=(int *) col->data[indice];
            break;

        case CHAR:
            val=(char *) col->data[indice];
            break;

        case FLOAT:
            val=(float *) col->data[indice];
            break;

        case DOUBLE:
            val=(double *) col->data[indice];
            break;

        case STRING:
            val=(char **) col->data[indice];
            break;

        case STRUCTURE:
            val=(void **) col->data[indice];
            break;

        default:
            printf("Type de colonne non pris en charge.\n");
            return 0;
    }
    return val;
}

int superieur_value(COLUMN* col, char* value) {
    int superieur = 0;
    switch(col->column_type){   //Verifie la superiorité selon le type
        case UINT:
            for (int i = 0; i < col->size; i++) {
                if (*(unsigned int*)col->data[i] > *(unsigned int*)value) {
                    superieur ++;
                }
            }
            break;
        case INT:
            for (int i = 0; i < col->size; i++) {
                if (*(int *) col->data[i] > *(int *) value) {
                    superieur ++;
                }
            }
            break;
        case CHAR:
            for (int i = 0; i < col->size; i++) {
                if (*(char*)col->data[i] > *(char*)value) {
                    superieur ++;
                }
            }
            break;
        case FLOAT:
            for (int i = 0; i < col->size; i++) {
                if (*(float*)col->data[i] > *(float*)value) {
                    superieur ++;                }
            }
            break;
        case DOUBLE:
            for (int i = 0; i < col->size; i++) {
                if (*(double*)col->data[i] > *(double*)value) {
                    superieur ++;                }
            }
            break;
        case STRING:
            // Comparaison de chaînes de caractères
            for (int i = 0; i < col->size; i++) {
                if (strcmp((char*)col->data[i], (char*)value) > 0) {
                    superieur ++;                }
            }
            break;
        case STRUCTURE:
            for (int i = 0; i < col->size; i++) {
                if (strcmp((void *) col->data[i], (void *) value) > 0) {
                    superieur++;
                }
                break;

            }
        default:
            printf("Type de colonne non pris en charge.\n");
            return 0;

    }
    return superieur;
}

int inferieur_value(COLUMN* col, char* value) {
    int inferieur = 0;
    switch(col->column_type){   //Verifie l'infériorité selon le type
        case UINT:
            for (int i = 0; i < col->size; i++) {
                if (*(unsigned int*)col->data[i] < *(unsigned int*)value) {
                    inferieur ++;
                }
            }
            break;
        case INT:
            for (int i = 0; i < col->size; i++) {
                if (*(int *) col->data[i] < *(int *) value) {
                    inferieur ++;
                }
            }
            break;
        case CHAR:
            for (int i = 0; i < col->size; i++) {
                if (*(char*)col->data[i] < *(char*)value) {
                    inferieur ++;
                }
            }
            break;
        case FLOAT:
            for (int i = 0; i < col->size; i++) {
                if (*(float*)col->data[i] < *(float*)value) {
                    inferieur ++;
                }
            }
            break;
        case DOUBLE:
            for (int i = 0; i < col->size; i++) {
                if (*(double*)col->data[i] < *(double*)value) {
                    inferieur ++;
                }
            }
            break;
        case STRING:
            // Comparaison de chaînes de caractères
            for (int i = 0; i < col->size; i++) {
                if (strcmp((char*)col->data[i], (char*)value) < 0) {
                    inferieur ++;
                }
            }
            break;
        case STRUCTURE:
            for (int i = 0; i < col->size; i++) {
                if (strcmp((void *) col->data[i], (void *) value) < 0) {
                    inferieur++;
                }
                break;

            }
        default:
            printf("Type de colonne non pris en charge.\n");
            return 0;

    }
    return inferieur;
}
