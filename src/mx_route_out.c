#include "../inc/header.h"

void mx_route_out(char **names, t_path **path, int i, int j) {
    int prev = i;
    int prev1 = j;

    write(1, "Route: ", mx_strlen("Route: "));
    write(1, names[j], mx_strlen(names[j]));
    write(1, " -> ", mx_strlen(" -> "));
        while (prev1 != path[j][i].prev) {
            prev = i;
            while (path[j][prev].prev != prev1) {
                prev = path[j][prev].prev;
            }
            write(1, names[prev], mx_strlen(names[prev]));
            write(1, " -> ", mx_strlen(" -> "));
            prev1 = prev;
        }
        write(1, names[i], mx_strlen(names[i]));
        write(1, "\n", 1);
}
