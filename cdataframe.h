//
// Created by wengj on 14/05/2024.
//

#ifndef CDATAFRAME_WENG_TADRIST_PMP_CDATAFRAME_H
#define CDATAFRAME_WENG_TADRIST_PMP_CDATAFRAME_H


//1. Alimentation
COLUMN ** cdataframe_vide(int size);
void remplissage_cdataframe(COLUMN ***cdf, ENUM_TYPE type, int size, char *title, void *value[], int nb_value);

//2. Affichage
void afficher_tout_cdataframe(COLUMN **cdf, int size);
void afficher_p_ligne_cdataframe(COLUMN **cdf, int size, int tete, int queue);
void afficher_p_colonne_cdataframe(COLUMN **cdf, int tete, int queue);

//3. Opérations usuelles
void add_col_cdataframe(COLUMN ***cdf, int *size, COLUMN *col);
void del_col_cdataframe(COLUMN ***cdf, int *size, int col_del);
void rename_title_of_col_in_cdf(COLUMN ***cdf,int index_col, char* new_title);
int val_existence_cdataframe(COLUMN **cdf, int size, char* value);

#endif //CDATAFRAME_WENG_TADRIST_PMP_CDATAFRAME_H
