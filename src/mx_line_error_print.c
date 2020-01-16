#include "../inc/header.h"

void mx_line_error_print(int line) {
    char *str = mx_itoa(line);

    write(2, "error: line ", mx_strlen("error: line "));
    write(2, str, mx_strlen(str));
    write(2, " is not valid\n", mx_strlen(" is not valid\n"));
        if (malloc_size(str))
            free(str);
}
