#include "../inc/header.h"

int mx_min(t_path *str, int size) {
    int min = 2147483647;
    int index = 0;

    for (int i = 0; i < size; i++) {
        if (str[i].dist < min && str[i].trig == 0) {
            min = str[i].dist;
            index = i;
        }
    }
    str[index].trig = 1;
    return index;
}
