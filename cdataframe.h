//
// Created by wengj on 14/05/2024.
//

#ifndef CDATAFRAME_WENG_TADRIST_PMP_CDATAFRAME_H
#define CDATAFRAME_WENG_TADRIST_PMP_CDATAFRAME_H



COLUMN ** cdataframe_vide(int size);
void remplissage_cdataframe(COLUMN ***cdf, int *size);
void afficher_tout_cdataframe(COLUMN **cdf, int size);
void afficher_p_ligne_cdataframe(COLUMN **cdf, int size, int tete, int queue);
void afficher_p_colonne_cdataframe(COLUMN **cdf, int size, int tete, int queue);


#endif //CDATAFRAME_WENG_TADRIST_PMP_CDATAFRAME_H
