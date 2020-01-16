#include "../inc/header.h"

static int check_list(t_path *head, int ind) {
    t_path *check = head;

    while (check != NULL) {
        if (check->prev == ind) {
            return 1;
        }
        check = check->next;
    }
    return 0;
}

static void same_path(t_path path, t_path *head, int ind, int dist) {
    while (head->next != NULL) {
        head = head->next;
    }
    if (check_list(&path, ind) != 1) {
        head->next = (t_path *)malloc(sizeof(t_path));
        head->next->dist = dist;
        head->next->prev = ind;
        head->next->next = NULL;
    }
}

static void dist_change(t_path **path, int **m, t_index index, int dist) {
    int i = index.i;
    int o = index.o;
    int ind = index.ind;

    if (path[o][ind].dist == 2147483647
        || m[ind][i] == 2147483647)
    {
    dist = 2147483647;
    }
    if ((dist < path[o][i].dist) && path[o][i].trig != 1) {
        path[o][i].dist = dist;
        path[o][i].prev = ind;
            if (path[ind][i].prev != ind)
                path[o][i].prev = path[ind][i].prev;
    }
}

void mx_find_shortest(int **matrix, t_path **path, int v, int o) {
    int dist;
    int ind = mx_min(path[o], v);
    t_index index;

    for (int i = 0; i < v; i++) {
        index.i = i;
        index.o = o;
        index.ind = ind;
        dist = path[o][ind].dist + matrix[ind][i];
        dist_change(path, matrix, index, dist);
            if (dist == path[o][i].dist && path[o][i].prev != ind
            && dist != 2147483647)
            {
                if (path[ind][i].prev != ind) {
                    if (o > i)
                        same_path(path[i][o], &path[i][o], ind, dist);
                    ind = path[ind][i].prev;
                }
                same_path(path[o][i], &path[o][i], ind, dist);
            }
    }
}
