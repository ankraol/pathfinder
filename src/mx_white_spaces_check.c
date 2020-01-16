#include "../inc/header.h"

static int double_newline(char *str, int trig) {
    int i = 0;
    int line = 1;

    while (str[i] != '\0') {
            if (str[i] == '\n') {
                line++;
            }
            if (str[i + 1] == '\n' && str[i] == '\n') {
                mx_line_error_print(line);
                return -1;
            }
            i++;
    }
    if (trig == 1){
        return i;
    }
        return line;
}

int mx_white_spaces_check(char *str) {
    int line = 0;
    int i = 0;

    if (str[0] == '0' && str[1] == '\0')
        return -1;
    if (str[0] < 48 || str[0] > 57) {
        mx_line_error_print(1);
            return -1;
    }
    i = double_newline(str, 1);
    if (i == -1)
        return -1;
    line = double_newline(str, 2);
        if (str[i - 1] != '\n') {
            mx_line_error_print(line);
                return -1;
        }
        return line;
}
