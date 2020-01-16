#include "../inc/header.h"

int mx_symbol_check(char **check, int j, int i, char symbol) {
    if(i == 0) {
        mx_line_error_print(j + 1);
        return -1;
    }
    if (symbol == '-') {
        if (check[j][i] != '-') {
            mx_line_error_print(j + 1);
            return -1;
        }
    }
    if (symbol == ',') {
        if(check[j][i] != ',') {
            mx_line_error_print(j + 1);
            return -1;
        }
    }
    return 0;
}
