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

static int error_print_letter(int i, char **check, int j) {
    i = letter_cycle(check, j, i, 2);
        if (i == -1) {
            return -1;
        }
        if (check[j][i] != '\0') {
            mx_line_error_print(j + 1);
            return -1;
        }
        return i;
}

static int first_line_check(char **check) {
    for (int i = 0; check[0][i] != '\0'; i++) {
        if ((check[0][i] < 48 || check[0][i] > 57)) {
            mx_line_error_print(1);
            return -1;
        }
    }
    return 0;
}

static int test(char **check) {
    if (first_line_check(check) == -1)
        return -1;
    for (int j = 1; check[j] != NULL; j++) {
        for (int i = 0; check[j][i] != '\0'; ) {
            i = mx_flow_check(check, i, j, 1);
                if (i == -1) {
                    return -1;
                }
                i = mx_flow_check(check, i, j, 2);
                    if (i == -1) {
                        return -1;
                    }
                    i = error_print_letter(i, check, j);
                        if (i == -1) {
                            return -1;
                        }
        }
    }
    return 0;
}

int mx_line_invalid(char *str) {
    char **check = NULL;
    int count = mx_white_spaces_check(str);

    if (count == -1) {
        return -1;
    }
    check = mx_strsplit(str, '\n');
        if (test(check) == -1) {
            if (malloc_size(check)) {
                mx_del_strarr(&check);
            }
            return -1;
        }
        if (malloc_size(check)) {
            mx_del_strarr(&check);
        }
        return 0;
}
