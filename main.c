//
// Created by fahed on 29/03/2024.
//
#include <stdio.h>
#include "functions.h"

int main() {
    // Test des fonctions :
    COLUMN *mycol = create_column("Age");
    printf("%s\n", mycol->Titre);

    insert_value(mycol, 19);
    insert_value(mycol, 18);
    insert_value(mycol, 18);

    print_col(mycol);

    printf("%d",nb_occurences(mycol, 18));

    return 0;
}
