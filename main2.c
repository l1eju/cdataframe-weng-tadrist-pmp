//
// Created by wengj on 26/04/2024.
//

#include <stdio.h>
#include "cdataframe.h"


int main() {
    COLUMN *mycol = create_column(CHAR, "Column 1");
    char a = 'A', c = 'C';
    insert_value(mycol, &a);
    insert_value(mycol, NULL);
    insert_value(mycol, &c);
    //delete_column(&(*mycol));
    print_col(mycol);

    printf("Present %d fois", nb_occurences(mycol, &a));

    COLUMN** cdf;
    cdf=cdataframe_vide();

    int len=5;

    //remplissage_cdataframe(&cdf, &len);
    //afficher_tout_cdataframe(cdf, len);
}