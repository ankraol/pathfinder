#include "../inc/header.h"

int mx_check(char **arr, char *str) {
    int check = 0;

    for (int j = 0; arr[j] != NULL; j++) {
        if (mx_strcmp(arr[j], str) == 0) {
            return 1;
        }
    }
    return check;
}
