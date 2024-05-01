//
// Created by wengj on 26/04/2024.
//

#include <stdio.h>
#include "column2.h"

int main2() {
    COLUMN *mycol = create_column(CHAR, "My column");
    char a = 'A', c = 'C';
    insert_value(mycol, &a);
    insert_value(mycol, NULL);
    insert_value(mycol, &c);
    return 0;
}