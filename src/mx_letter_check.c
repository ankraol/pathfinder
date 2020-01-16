#include "../inc/header.h"

int mx_letter_check(char **check, int j, int i, int trig) {
    if (trig == 1) {
        if ((check[j][i] < 65 && check[j][i] > 90)
            || (check[j][i] < 97 && check[j][i] > 122))
        {
            mx_line_error_print(j + 1);
            return -1;
        }
    }
    if (trig == 2) {
        if((check[j][i] < 48 || check[j][i] > 57)
            || (check[j][i] == 48 && check[j][i + 1] == '\0')) {
            mx_line_error_print(j + 1);
            return -1;
        }
    }
    return 0;
}
