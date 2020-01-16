#include "../inc/header.h"

int mx_vertex_check(char **arr, int v) {
    int j = 1;
    int names = 0;
    int extra = 0;

    while (j < mx_size_arr(arr)) {
        while (j % 3 != 0) {
            names++;
            if (mx_check(arr + j + 1, arr[j]) != 0) {
                extra++;
            }
            j++;
        }
        j++;
    }
    if (names - extra != v)
        return -1;
    if ((names - extra == 1 && v == 1))
        return 2;
    return 0;
}
