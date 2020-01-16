#include "../inc/header.h"

static void print(t_path **path, int i, int j) {
    char *p = NULL;

    p = mx_itoa(path[j][i].dist);
    write(1, p, mx_strlen(p));
        if (malloc_size(p))
            free(p);
}

static void one_route(int *matrix, int i, int j, t_path **path) {
    int prev1 = j;
    int prev2 = j;

    while (prev2 != i) {
        prev1 = i;
            while (matrix[prev1] != prev2) {
                prev1 = matrix[prev1];
            }
            print(path, prev1, prev2);
                if (prev1 != i)
                    write(1, " + ", 3);
                prev2 = prev1;
    }
}

void mx_similar_dist(int *matrix, int i, int j, t_path **path) {
    write(1, "Distance: ", mx_strlen("Distance: "));
        if (matrix[i] == j) {
            print(path, i, j);
            write(1, "\n", 1);
        }
        else {
            one_route(matrix, i, j, path);
            write(1, " = ", 3);
            print(path, i, j);
            write(1, "\n", 1);
        }
}
