#include "../inc/header.h"

void mx_matrix_clean(int ***matrix, int v) {
    for (int i = 0; i < v; i++) {
        if ((*matrix)[i] != NULL) {
            if (malloc_size(*matrix)) {
                free((*matrix)[i]);
            }
            (*matrix)[i] = NULL;
        }
    }
    if (malloc_size(*matrix)) {
        free(*matrix);
    }
    *matrix = NULL;
}
