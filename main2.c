//
// Created by wengj on 26/04/2024.
//

#include <stdio.h>
#include "column2.h"


int main() {
    COLUMN *mycol = create_column(INT, "Column 1");
    int a = 33, c = 33;
    insert_value(mycol, &a);
    insert_value(mycol, &c);
    print_col(mycol);
    printf("%d", nb_occurences(mycol, 33));
}