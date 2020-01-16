#include "../inc/header.h"

void mx_borders(void) {
    for (int u = 0; u < 40; u++) {
        write(1, "=", mx_strlen("="));
    }
    write(1, "\n", mx_strlen("\n"));
}
