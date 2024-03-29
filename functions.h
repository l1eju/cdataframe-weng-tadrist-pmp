//
// Created by wengj on 29/03/2024.
//

#ifndef CDATAFRAME_WENG_TADRIST_PMP_FUNCTIONS_H
#define CDATAFRAME_WENG_TADRIST_PMP_FUNCTIONS_H

typedef struct{
    char* Titre;
    int Taille_physique;
    int Taille_logique;
    int* Donnees;
}COLUMN;

COLUMN *create_column(char* title);

int insert_value(COLUMN *col, int value);

void delete_column(COLUMN **col);

void print_col(COLUMN* col);

int greater_value(COLUMN* col, int x);




#endif //CDATAFRAME_WENG_TADRIST_PMP_FUNCTIONS_H
