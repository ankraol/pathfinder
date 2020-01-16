#include "../inc/header.h"

int **mx_matrix(char **data, char **names, int v) {
    int a = 0;
    int b = 0;
    int **matrix = mx_chart(v, v, 2147483647);

    for (int j = 1; j < mx_size_arr(data); j = j + 3) {
        if (j % 3 > 0) {
            a = mx_get_index_name(data[j], names);
            b = mx_get_index_name(data[j + 1], names);
            matrix[a][b] = mx_atoi(data[j + 2]);
            matrix[b][a] = mx_atoi(data[j + 2]);
        }
    }
    if (malloc_size(data))
        mx_del_strarr(&data);
    return matrix;
}
