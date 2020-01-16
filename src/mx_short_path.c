#include "../inc/header.h"

static t_path **empty_path(int **matrix, int v) {
    t_path **path = (t_path **) malloc(sizeof(t_path *) * v + 1);

    for (int o = 0; o < v; o++) {
        path[o] = (t_path *) malloc(sizeof(t_path) * v);
        for (int i = 0; i < v; i++) {
            path[o][i].dist = matrix[o][i];
            path[o][i].prev = o;
            path[o][i].trig = 0;
            (*(*(path + o) + i)).next = NULL;
        }
        path[o][o].trig = 1;
    }
    return path;
}

t_path **mx_short_path(int **matrix, int v) {
    t_path **path = NULL;

    path =  empty_path(matrix, v);
        for (int o = 0; o < v; o++) {
            for (int j = 0; j < v; j++) {
                mx_find_shortest(matrix, path, v, o);
            }
            path[o][o].dist = 0;
            path[o][o].prev = 0;
        }
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                t_path *p = &path[i][j];
                    if ((*p).next != NULL) {
                        mx_sort_prev(p);
                    }
            }
        }
        path[v] = NULL;
        return path;
}
