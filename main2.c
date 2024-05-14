//
// Created by wengj on 26/04/2024.
//

#include <stdio.h>
#include "column2.h"



int main() {
    COLUMN *mycol = create_column(CHAR, "Column 1");
    char a = 'A', c = 'C';
    insert_value(mycol, &a);
    insert_value(mycol, NULL);
    insert_value(mycol, &c);
    delete_column(&(*mycol));
    print_col(mycol);

    //printf("%d", nb_occurences(mycol, 33));
}