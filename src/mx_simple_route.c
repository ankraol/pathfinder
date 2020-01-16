#include "../inc/header.h"

void mx_simple_route(char *from, char *to) {
    write(1, "Route: ", mx_strlen("Route: "));
    write(1, from, mx_strlen(from));
    write(1, " -> ", mx_strlen(" -> "));
    write(1, to, mx_strlen(to));
    write(1, "\n", 1);
}
