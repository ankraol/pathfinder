#include "../inc/header.h"

int **mx_matrix_copy(int **matrix, int l, int extra, int size) {
    int **copy = mx_chart(size, size, -1);

    for (int i = 0; i < size; i++) {
        copy[0][i] = matrix[0][i];
            if (i == l) {
                copy[0][i] = extra;
            }
            else if (matrix[1][i] != -1) {
                for (int j = 0; matrix[j][i] != -1; j++) {
                    copy[j][i] = matrix[j][i];
                }
            }
    }
    return copy;
}
