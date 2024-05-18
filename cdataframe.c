//
// Created by wengj on 14/05/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "column2.h"
#include "cdataframe.h"


//1. Alimentation

COLUMN ** cdataframe_vide(int size){
        COLUMN ** cdataframe = (COLUMN **) malloc(size*sizeof(COLUMN)); //On crée un tableau dynamique de pointeur sur des colonnes selon la taille donné en paramètre
    return cdataframe;
}

//2. Affichage

void afficher_tout_cdataframe(COLUMN **cdf, int nb_col){
    if (nb_col!=0) {    //Si le CDataFrame n'est pas vide
        for (int i = 0; i < nb_col; i++) {
            printf("%s\n", cdf[i]->title);  //On affiche son titre puis les valeurs de la colonne
            print_col(cdf[i]);
        }
    }else{  //Sinon on indique simplement qu'il est vide
        printf("CDataFrame Vide\n");
    }
}

void afficher_p_ligne_cdataframe(COLUMN **cdf, int nb_col, int tete, int queue){
    for (int i=0; i<nb_col; i++){   //On parcourt toute les colonnes

        int fin=queue;  //condition si la fin demandé est supérieur à la taille logique
        if (queue>cdf[i]->size){    //si la fin d'intervalle donner est supérieur à la taille, on le réduit
            fin=cdf[i]->size;
        }
        if (tete<0){    //si le debut d'intervalle donner est inferieur à 0, on le remet a 0
            tete=0;
        }

        printf("%s\n", cdf[i]->title);  //On affiche le titre de la colonne
        for (int j = tete; j <= fin; j++){  //On parcourt les lignes de la colonne

            char str[N];
            convert_value(cdf[i], j, str, N);   //On convertit la valeur de la cellule en chaine de caractere pour pouvoir l'afficher
            if(str[0]!='\0') {    //Si la caractère n'est pas null, on l'affiche
                printf("[%d] %s\n", j, str);
            }
            else{   //Si le premier caractere est le caractere null et que c donc on seul caractere, on affiche null
                printf("[%d] NULL\n", j);
            }
        }
    }
}

void afficher_p_colonne_cdataframe(COLUMN **cdf, int tete, int queue){
    for (int i=tete; i<=queue; i++){    //On parcourt seulement les colonnes de l'intervalle donné
        printf("%s\n", cdf[i]->title);  //On affiche le titre
        print_col(cdf[i]);  //On affiche le contenue de la colonne
    }
}


//3. Opérations usuelles
void add_lig_cdataframe(COLUMN ***cdf, int indice_col, void *value){
    insert_value((*cdf)[indice_col], value);    //On insère la valeur donné dans le colonne donné
}

void del_lig_cdataframe(COLUMN ***cdf, int indice_col){
    (*cdf)[indice_col]->data = realloc((*cdf)[indice_col]->data, (--(((*cdf)[indice_col]->size)))*sizeof((*cdf)[indice_col]->column_type));
    //On realloc dont supprime la dernière ligne de la colonne donné selon son type et on décrémente la taille logique de la colonne (son col->size)
}


void add_col_cdataframe(COLUMN ***cdf, int *nb_col, COLUMN *col){
    *(*cdf)= realloc(*(*cdf), ((*nb_col)+1)*sizeof(COLUMN));    //On augment la taille du tableau dynamique lui offrant ainsi une place pour une autre colonne
    (*cdf)[(*nb_col)++]=col;    //On insère la nouvelle colonne donné en paramètre
}

void del_col_cdataframe(COLUMN ***cdf, int *nb_col, int col_del){
    delete_column(&((*cdf)[col_del]));  //On supprime la colonne donné (grace a l'indice nb_col)
    for(int i=col_del; i<(*nb_col)-1; i++){     //On décale les colonnes pour eviter d'avoir une colonne NULL au milieu du CDataFrame
        (*cdf)[i]=(*cdf)[i+1];
    }
    **cdf= realloc(**cdf, ((*nb_col)--)*sizeof(COLUMN));  //On réalloc pour reduire la taille est supprimer la dernière colonne qui existe en 2 exemplaire apres le decalage tout en décrémentant nb_col
}

void rename_title_of_col_in_cdf(COLUMN ***cdf,int index_col, char* new_title){
    (*cdf)[index_col]->title=new_title; //Le titre de la colonne donné est remplacé par le nouveau titre donné en paramètre
}

int val_existence_cdataframe(COLUMN **cdf, int nb_col, char* value){
    for (int i=0; i<nb_col; i++){   //On parcourt toutes les colonnes
        for(int j=0; j<cdf[i]->size; j++){  //Et chaque ligne de la colonne
            char str[N];
            convert_value(cdf[i], j, str, N);   //On convertit la valeur en chaine de caractère
            if(strcmp(str, value)==0) {   //Et si la valeur (chaine de caractère) donné en paramètre et exactement la même que celle la valeur de la colonne convertit
                return 1;           //On retourne 1 pour signaler la présence de la valeur
            }
        }
    }
    return 0;   //Sinon 0
}

void acceder_remplacer_val_cellule(COLUMN ***cdf, int num_lig, int num_col, void* value){
    char str[N];
    convert_value((*cdf)[num_col], num_lig, str, N);
    printf("Valeur de la cellule: %s", str);
    (*cdf)[num_col]->data[num_lig]=value;
}

void afficher_nom_col(COLUMN **cdf, int nb_col){
    for(int i=0; i<nb_col; i++){    //On parcourt chaque colonne
        printf("Colonne [%d] : %s\n", i, cdf[i]->title);    //On affiche son titre et son indice
    }
}


//4. Analyse et statistiques
int nb_cellule_val(COLUMN **cdf, int nb_col, char* value){
    int cmpt=0; //cpmt correspond à l'occurrence de la valeur
    for (int i=0; i<nb_col; i++){   //On parcourt toutes les colonnes
        for(int j=0; j<cdf[i]->size; j++){  //On parcourt chaque ligne de la colonn (cellule)
            char str[N];
            convert_value(cdf[i], j, str, N);   //On convertit la valeur de la cellule en chaine de caractere
            if(strcmp(str, value)==0) { //Si la valeur donné par l'utilisateur et celle de la cellule sont les mêmes
                cmpt++; //On incrémente l'occurrence
            }
        }
    }
    return cmpt;    //On retourne l'occurrence
}


int nb_cellule_val_sup(COLUMN **cdf, int nb_col, ENUM_TYPE type, void* value){
    int cmpt=0;
    for (int i=0; i<nb_col; i++){
        if(cdf[i]->column_type==type) {
            cmpt += superieur_value(cdf[i], value);
        }
    }
    return cmpt;
}

int nb_cellule_val_inf(COLUMN **cdf, int nb_col, ENUM_TYPE type, void* value){
    int cmpt=0;
    for (int i=0; i<nb_col; i++){
        if(cdf[i]->column_type==type) {
            cmpt += inferieur_value(cdf[i], value);
        }
    }
    return cmpt;
}