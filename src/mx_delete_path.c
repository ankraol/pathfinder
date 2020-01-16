#include "../inc/header.h"

static void path_del(t_path **path) {
    if (*path != NULL){
        if (malloc_size(*path)) {
            free(*path);
        }
        *path = NULL;
    }
}

static void get_rid_of(t_path ***path, int i, int j) {
    t_path **next = &(*path)[j][i].next;
    t_path **prev = &(*path)[j][i].next;

    while ((*next)->next != NULL) {
        next = &(*next)->next;
    }
    while ((*next) != (*path)[j][i].next) {
        prev = &(*path)[j][i].next;
            while ((*prev)->next != (*next)) {
                prev = &(*prev)->next;
            }
            path_del(next);
            next = prev;
    }
    path_del(next);
}

static void delete_list(t_path ***path, int v) {
    for (int j = 0; j < v; j++) {
        for (int i = 0; i < v; i++) {
            if ((*path)[j][i].next != NULL) {
                get_rid_of(path, i, j);
            }
        }
    }
}

void mx_delete_path(t_path ***path, int v) {
    delete_list(path, v);
        for (int i = 0; i < v; i++) {
            path_del(&(*path)[i]);
            }
                if (malloc_size(*path)) {
                    free(*path);
                }
            *path = NULL;
}
