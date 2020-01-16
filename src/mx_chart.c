#include "../inc/header.h"

int **mx_chart(int v, int length, int numb) {
    int **chart = (int **)malloc (sizeof(int *) * v + 1);

    for (int j = 0; j < v; j++) {
        chart[j] = (int *)malloc (sizeof(int) * length + 1);
            for (int i = 0; i < length; i++) {
                chart[j][i] = numb;
            }
    }
    chart[v] = NULL;
    return chart;
}
