#include "../inc/header.h"

static void swap(t_list *p1, t_list *p2) {
    int **swap = NULL;

    swap = (*p1).value;
    (*p1).value = (*p2).value;
    (*p2).value = swap;
}

static int find_end(t_list *p1, int prev0, int dest) {
    int prev1 = dest;

    while ((*p1).value[0][prev1] != prev0) {
        prev1 = (*p1).value[0][prev1];
    }
    return prev1;
}

static void compare(t_list *p1, t_list *p2, int from, int dest) {
    int prev1 = from;
    int prev2 = from;
    int prev01 = from;
    int prev02 = from;

    while (prev01 != dest && prev02 != dest) {
        prev1 = find_end(p1, prev01, dest);
        prev2 = find_end(p2, prev02, dest);
            if (prev2 < prev1) {
                swap(p1, p2);
                return;
            }
            if (prev2 > prev1)
                return;
            prev01 = prev1;
            prev02 = prev2;
    }
}

void mx_sort_list(t_list **list, int dest, int from) {
    t_list *p1 = *list;
    t_list *p2 = (*p1).next;

    if (!p2) {
        return;
    }
    while (p1 != p2) {
        p2 = (*p1).next;
        while (p2) {
            compare(p1, p2, from, dest);
            p2 = (*p2).next;
        }
        p1 = (*p1).next;
    }
}
