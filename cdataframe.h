//
// Created by wengj on 14/05/2024.
//

#ifndef CDATAFRAME_WENG_TADRIST_PMP_CDATAFRAME_H
#define CDATAFRAME_WENG_TADRIST_PMP_CDATAFRAME_H


//1. Alimentation
COLUMN ** cdataframe_vide(int size);

//2. Affichage
void afficher_tout_cdataframe(COLUMN **cdf, int size_col);
void afficher_p_ligne_cdataframe(COLUMN **cdf, int size_col, int tete, int queue);
void afficher_p_colonne_cdataframe(COLUMN **cdf, int tete, int queue);

//3. Opérations usuelles
void add_lig_cdataframe(COLUMN ***cdf, int size_col, void* value);
void del_lig_cdataframe(COLUMN ***cdf, int size_col);
void add_col_cdataframe(COLUMN ***cdf, int *size_col, COLUMN *col);
void del_col_cdataframe(COLUMN ***cdf, int *size_col, int col_del);
void rename_title_of_col_in_cdf(COLUMN ***cdf,int index_col, char* new_title);
int val_existence_cdataframe(COLUMN **cdf, int size, char* value);
void acceder_remplacer_val_cellule(COLUMN ***cdf, int num_lig, int num_col, void* value);
void afficher_nom_col(COLUMN **cdf, int nb_col);

//4. Analyse et statistiques
int nb_cellule_val(COLUMN **cdf, int nb_col, char* value);
int nb_cellule_val_sup(COLUMN **cdf, int nb_col, ENUM_TYPE type, void* value);
int nb_cellule_val_inf(COLUMN **cdf, int nb_col, ENUM_TYPE type, void* value);


#endif //CDATAFRAME_WENG_TADRIST_PMP_CDATAFRAME_H
