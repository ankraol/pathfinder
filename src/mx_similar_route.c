#include "../inc/header.h"

void mx_similar_route(int *matrix, int i, int j, char **names) {
    int prev1 = j;
    int prev2 = j;

    write(1, "Route: ", mx_strlen("Route: "));
        while (prev2 != i) {
            prev1 = i;
            while (matrix[prev1] != prev2) {
                prev1 = matrix[prev1];
            }
            write(1, names[prev2], mx_strlen(names[prev2]));
            write(1, " -> ", 4);
            prev2 = prev1;
        }
        write(1, names[i], mx_strlen(names[i]));
        write(1, "\n", 1);
}
