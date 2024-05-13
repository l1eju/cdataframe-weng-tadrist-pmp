#include <stdio.h>
#include <stdlib.h>
#include "cdataframe.h"
/*
// Partie 4.2.1. Fonctionnalités
int* cdataframe_vide(int len){
    int* cdataframe = (int*) malloc(len*sizeof(int));
    return cdataframe;
}*/
CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size){
    CDATAFRAME* cdf = (CDATAFRAME*) malloc(size*sizeof(LNODE));
    return cdf;
}

void delete_cdataframe(CDATAFRAME **cdf) {
    free(*((*cdf)->head));
}
