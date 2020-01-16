#include "../inc/header.h"

int mx_get_index_name(char *str, char **arr) {
    for (int j = 0; arr[j] != NULL; j++) {
        if (mx_strcmp(arr[j], str) == 0) {
            return j;
        }
    }
    return -1;
}
