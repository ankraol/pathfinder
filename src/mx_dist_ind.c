#include "../inc/header.h"

int mx_dist_ind(int *str, int min, int size) {
    for (int i = 0; i < size; i++) {
        if (str[i] == min) {
            return i;
        }
    }
    return -1;
}
