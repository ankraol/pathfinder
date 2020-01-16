#include "../inc/header.h"

char **mx_data_matrix(char *str) {
    char **data = NULL;
    int size = mx_strlen(str);

    for (int i = 0; i < size; i++) {
        if (str[i] == '-' || str[i] == ',' || str[i] == '\n') {
            str[i] = '*';
        }
    }
    data = mx_strsplit(str, '*');
    return data;
}
