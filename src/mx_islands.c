#include "../inc/header.h"

char **mx_islands (char **arr) {
    int v = mx_atoi(arr[0]);
    char **island = (char **)malloc(sizeof(char *) * v + 1);

    for (int j = 1, i = 0; j < mx_size_arr(arr) && i < v; j++) {
        for (; j % 3 != 0; j++) {
            if (mx_check(island, arr[j]) == 0) {
                island[i] = mx_strnew(mx_strlen(arr[j]));
                    for (int c = 0; arr[j][c] != '\0'; c++) {
                        island[i][c] = arr[j][c];
                    }
                    i++;
            }
        }
    }
    island[v] = NULL;
    return island;
}
