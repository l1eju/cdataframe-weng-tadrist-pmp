#ifndef CDATAFRAME_WENG_TADRIST_PMP_CDATAFRAME_H
#define CDATAFRAME_WENG_TADRIST_PMP_CDATAFRAME_H
#include "column2.h"

/**
* Élément lnode
*/
typedef struct lnode_ {
    void *data; // Pointer to a column
    struct lnode_ *prev;
    struct lnode_ *next;
} LNODE;

/**
* Une liste
*/
typedef struct list_ {
    LNODE *head;
    LNODE *tail;
} LIST;

typedef LIST CDATAFRAME;

CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size);
void delete_cdataframe(CDATAFRAME **cdf);


#endif //CDATAFRAME_WENG_TADRIST_PMP_CDATAFRAME_H
