#include "../inc/header.h"

static int letter_cycle(char **check, int j, int i, int trig) {
    if (trig == 1) {
        if (mx_letter_check(check, j, i, 1) == -1) {
            return -1;
        }
        while((check[j][i] > 64 && check[j][i] < 91)
            || (check[j][i] > 96 && check[j][i] < 123))
        {
        i++;
        }
    }
    if (trig == 2) {
        if(mx_letter_check(check, j, i, 2) == -1) {
            return -1;
        }
        while((check[j][i] > 47 && check[j][i] < 58)){
            i++;
        }
    }
    return i;
}

static int error_cases(char **check, int j, int i, int trig) {
    char symbol;

    if (i == -1) {
            return -1;
    }
    if (trig == 1) {
        symbol = '-';
    }
    if (trig == 2) {
        symbol = ',';
    }
    if (mx_symbol_check(check, j, i, symbol) == -1) {
        return -1;
    }
    else
        i++;
    return i;
}

int mx_flow_check(char **check, int i, int j, int trig) {
    int prev = i;

    i = letter_cycle(check, j, i, 1);
        if (i == prev) {
            mx_line_error_print(j + 1);
            return -1;
        }
        i = error_cases(check, j, i, trig);
            if (i == -1)
                return -1;
        return i;
}
