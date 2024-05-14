#ifndef CDATAFRAME_WENG_TADRIST_PMP_CDATAFRAME_H
#define CDATAFRAME_WENG_TADRIST_PMP_CDATAFRAME_H
#include "column2.h"

/*
typedef struct lnode_ {
    void *data; // Pointer to a column
    struct lnode_ *prev;
    struct lnode_ *next;
} LNODE;


typedef struct list_ {
    LNODE *head;
    LNODE *tail;
} LIST;

typedef LIST CDATAFRAME;
*/

COLUMN** cdataframe_vide();
void remplissage_cdataframe(COLUMN ***cdf, int *size);
void afficher_tout_cdataframe(COLUMN **cdf, int size);



#endif //CDATAFRAME_WENG_TADRIST_PMP_CDATAFRAME_H
