/*//
// Created by wengj on 29/03/2024.
//

#ifndef CDATAFRAME_WENG_TADRIST_PMP_COLUMN_H
#define CDATAFRAME_WENG_TADRIST_PMP_COLUMN_H


typedef struct {
    char *Titre;
    int Taille_physique;
    int Taille_logique;
    int *Donnees;
} COLUMN;

COLUMN *create_column(char* title);

int insert_value(COLUMN *col, int value);

void delete_column(COLUMN **col);

void print_col(COLUMN* col);

int nb_occurences(COLUMN *col, int x);

int val_in_pos(COLUMN *col, int x);

int greater_value(COLUMN* col, int x);

int lower_value(COLUMN* col, int x);

//Partie 2
/*

enum enum_type
{
    NULLVAL = 1 , UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
};
typedef enum enum_type ENUM_TYPE;

union column_type{
    unsigned int uint_value;
    signed int int_value;
    char char_value;
    float float_value;
    double double_value;
    char* string_value;
    void* struct_value;
};
typedef union column_type COL_TYPE ;

struct column {
    char *title;
    unsigned int size; //logical size
    unsigned int max_size; //physical size
    ENUM_TYPE column_type;
    COL_TYPE **data; // array of pointers to stored data
    unsigned long long int *index; // array of integers
};
typedef struct column COLUMN;


#endif //CDATAFRAME_WENG_TADRIST_PMP_COLUMN_H
*/