//
// Created by fahed on 29/03/2024.
//
#include <stdio.h>
#include "column.h"
#include "cdataframe.h"

int main() {
    // Test des fonctions :
    COLUMN *mycol = create_column("Age");
    printf("%s\n", mycol->Titre);

    insert_value(mycol, 19);
    insert_value(mycol, 18);
    insert_value(mycol, 18);
    insert_value(mycol, 4);

    print_col(mycol);

    printf("%d",nb_occurences(mycol, 18));

    printf("\nRecherche de la valeur a la position 3 : \n");
    printf("%d",val_in_pos(mycol,3));

    printf("\nRecherche de/des valeur(s) qui sont superieures a 10 : \n");
    printf("%d",greater_value(mycol,10));

    printf("\nRecherche de/des valeur(s) qui sont inferieurs a 10 : \n");
    printf("%d", lower_value(mycol,10));

    printf("\nSuppression de la colonne :");
    delete_column(&mycol);
    print_col(mycol);

    return 0;
}
