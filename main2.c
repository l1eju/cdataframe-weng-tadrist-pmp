//
// Created by wengj on 26/04/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include "column2.h"
#include "cdataframe.h"


int main() {
    COLUMN  *dur1=create_column(INT, "Julie");
    int tab_1[5]={19, 13, 11, 16, 20};
    for (int i=0; i<5; i++){
        insert_value(dur1, &(tab_1[i]));
    }//Initalisation en dur d'une colonne d'int

    COLUMN  *dur2=create_column(INT, "Fahed");
    int tab_f[5]={20, 17, 12, 13, 10};
    for (int i=0; i<5; i++){
        insert_value(dur2, &(tab_f[i]));
    }//Initalisation en dur d'une colonne d'int

    COLUMN  *dur=create_column(CHAR, "Lettre");
    int tab[5]={'A', 'H', 'P', 'F', 'N'};
    for (int i=0; i<5; i++){
        insert_value(dur, &(tab[i]));
    }//Initalisation en dur d'une colonne de char

    COLUMN **cdf_dur=cdataframe_vide(3);
    cdf_dur[0]=dur1;
    cdf_dur[1]=dur2;
    cdf_dur[2]=dur;

    afficher_tout_cdataframe(cdf_dur, 3);
    afficher_p_ligne_cdataframe(cdf_dur, 3, 2, 4);
    afficher_p_colonne_cdataframe(cdf_dur, 3, 0, 1);


    /*COLUMN  *mycol = create_column(CHAR, "Column 1");
    char a = 'A', c = 'C';
    insert_value(mycol, &a);
    insert_value(mycol, NULL);
    insert_value(mycol, &c);
    //delete_column(&(*mycol));
    print_col(mycol);

    printf("Present %d fois", nb_occurences(mycol, &a));

    //COLUMN** cdf;
    //cdf=cdataframe_vide();
    COLUMN ** cdf = (COLUMN **) malloc(sizeof(COLUMN));


    int len=5;

    remplissage_cdataframe(&cdf, &len);
    afficher_tout_cdataframe(cdf, len);*/
}