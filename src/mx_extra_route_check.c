#include "../inc/header.h"

int mx_extra_route_check(t_path **path, int i, int j) {
    t_path *p = NULL;
    int prev = i;
    int same = 0;
    int extra = 0;

    while (prev != j) {
        if (path[j][prev].next != NULL) {
            p = &path[j][prev];
                for (same = 0; p != NULL; same++) {
                    p = (*p).next;
                }
                if (extra != 0)
                    extra = extra * same;
                else if (extra == 0) {
                    extra = same;
                }
        }
        prev = path[j][prev].prev;
    }
    return extra;
}
