#include "../inc/header.h"

static int dub_check(int *matrix, t_list **list, int from, int to) {
    t_list *p = *list;
    int prev = to;

    while(p) {
        while (prev != from) {
            if (p->value[0][prev] != matrix[prev]) {
                break;
            }
            if (matrix[prev] == from)
                return 0;
            prev = matrix[prev];
        }
        prev = to;
        p = p->next;
    }
    return 1;
}

static int check_extra(int **matrix, int i, int j) {
    int prev = i;
    while (prev != j) {
        if (matrix[1][prev] != -1) {
            return 1;
        }
        prev = matrix[0][prev];
    }
    return 0;
}

static void rec(int **matrix, t_index index, t_list **list) {
    int **copy = NULL;
    int prev = index.i;
    int k = 1;

    while (prev != index.o) {
        while (matrix[1][prev] != -1) {
            for (k = 1; matrix[k + 1][prev] != -1; k++);
            copy = mx_matrix_copy(matrix, prev, matrix[k][prev], index.ind);
            matrix[k][prev] = -1;
            list = mx_find_w(copy, index, list);
            matrix[k][prev] = -1;
        }
        prev = matrix[0][prev];
    }
}

t_list **mx_find_w(int **matrix, t_index index, t_list **list) {
    int check;

    if (check_extra(matrix, index.i, index.o) == 1) {
        rec(matrix, index, list);
    }
    if (check_extra(matrix, index.i, index.o) == 0) {
        check = dub_check(matrix[0], list, index.o, index.i);
            if (check == 1) {
                mx_push_front(list, matrix);
            }
            if (check == 0) {
                mx_matrix_clean(&matrix, index.ind);
            }
    }
    return list;
}
