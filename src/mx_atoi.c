#include "../inc/header.h"

int mx_atoi(char *s) {
    int mult = 1;
    int number = 0;
    int add = 0;

    for (int i = 0; i < mx_strlen(s) - 1; i++) {
        mult = mult * 10;
    }
    for (int i = 0; i < mx_strlen(s); i++) {
        add = (s[i] - 48) * mult;
        number = number + add;
        mult = mult / 10;
    }
    return number;
}
