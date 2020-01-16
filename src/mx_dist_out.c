#include "../inc/header.h"

static void print(t_path **path, int start, int fin) {
    char *p = NULL;

    p = mx_itoa(path[start][fin].dist);
    write(1, p, mx_strlen(p));
        if (malloc_size(p))
            free(p);
}

void mx_dist_out(t_path **path, int i, int j) {
    int prev = i;
    int prev1 = j;

    write(1, "Distance: ", mx_strlen("Distance: "));
        while (prev1 != i) {
            prev = i;
                while (path[j][prev].prev != prev1) {
                    prev = path[j][prev].prev;
                }
                print(path, prev1, prev);
                    if (prev != i)
                        write(1, " + ", 3);
                    prev1 = prev;
        }
        write(1, " = ", 3);
        print(path, j, i);
        write(1, "\n", 1);
}
