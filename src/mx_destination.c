#include "../inc/header.h"

void mx_destination(char *from, char *to) {
    write(1, "Path: ", mx_strlen("Path: "));
    write(1, from, mx_strlen(from));
    write(1, " -> ", mx_strlen(" -> "));
    write(1, to, mx_strlen(to));
    write(1, "\n", 1);
}
