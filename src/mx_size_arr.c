#include "../inc/header.h"

int mx_size_arr(char **arr) {
    int size = 0, j = 0;
        while (arr[j] != NULL) {
            j++;
            size++;
        }
        return size;
}
