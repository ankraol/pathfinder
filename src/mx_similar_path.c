#include "../inc/header.h"

static void delete_list(t_list **list, int size) {
    t_list *p1 = *list;
    t_list *p2 = *list;

    while ((*p1).next != NULL) {
        p1 = (*p1).next;
    }
    while (p1 != *list) {
        p2 = *list;
        while ((*p2).next != p1) {
            p2 = (*p2).next;
        }
        mx_matrix_clean(&(*p1).value, size);
        free(p1);
        (*p2).next = NULL;
        p1 = p2;
    }
    mx_matrix_clean(&(*p1).value, size);
    free(p1);
    list = NULL;
}

static int **copy_path(t_path **path, int size, int o) {
    int **copy = mx_chart(size, size, -1);

    for (int i = 0; i < size; i++) {
        copy[0][i] = path[o][i].prev;
            if (path[o][i].next != NULL) {
                t_path *p = path[o][i].next;
                    for (int j = 1; p != NULL; j++) {
                        copy[j][i] = p->prev;
                        p = (*p).next;
                    }
            }
    }
    return copy;
}

void mx_similar_path(t_path **path, char **names, int i, int j) {
    t_list *list = NULL;
    t_index index;
    t_list *p = NULL;
    int size = 0;

    for (int i = 0; path[i]; i++) {
        size++;
    }
    index.i = i;
    index.o = j;
    index.ind = size;
    list = *(mx_find_w(copy_path(path, size, j), index, &list));
    p = list;
    mx_sort_list(&p, i, j);
        while (p) {
            mx_borders();
            mx_destination(names[j], names[i]);
            mx_similar_route((*p).value[0], i, j, names);
            mx_similar_dist((*p).value[0], i, j, path);
            mx_borders();
            p = (*p).next;
        }
        delete_list(&list, size);
}
