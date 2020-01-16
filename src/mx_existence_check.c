#include "../inc/header.h"

int mx_existence_check(char *str, char *filename) {
    if(str == NULL) {
        write(2, "error: file ", mx_strlen("error: file "));
        write(2, filename, mx_strlen(filename));
        write(2, " does not exist\n", mx_strlen(" does not exist\n"));
        return 1;
    }
    if(*str == (char)NULL) {
        write(2, "error: file ", mx_strlen("error: file "));
        write(2, filename, mx_strlen(filename));
        write(2, " is empty\n", mx_strlen(" is empty\n"));
        return 1;
    }
    return 0;
}
