#include "../inc/header.h"

static void narrow_route(t_path **path, char **names, int i, int j) {
    mx_borders();
    mx_destination(names[j], names[i]);
    mx_route_out(names, path, i, j);
    mx_dist_out(path, i, j);
    mx_borders();
}

static void simple_path(t_path **path, char **names, int i, int j) {
    char *p = mx_itoa(path[j][i].dist);

    mx_borders();
    mx_destination(names[j], names[i]);
    mx_simple_route(names[j], names[i]);
    write(1, "Distance: ", mx_strlen("Distance: "));
    write(1, p, mx_strlen(p));
    write(1, "\n", mx_strlen("\n"));
    mx_borders();
        if (malloc_size(p)) {
            free(p);
        }
}

void mx_printpath(char **names, t_path **path, int v) {
    int i = 0;
    int j = 0;

    for (; j < v - 1; j++) {
        for (i = 0; i < v; i++) {
            if (i > j) {
                if (path[j][i].prev == j && path[j][i].next == NULL) {
                    simple_path(path, names, i, j);
                }
                if (path[j][i].next != NULL || path[j][i].prev != j) {
                    if (mx_extra_route_check(path, i, j) != 0)
                        mx_similar_path(path, names, i, j);
                    else
                        narrow_route(path, names, i, j);
                }
            }
        }
    }
}
