#include "../inc/header.h"

void mx_sort_prev(t_path *p) {
    int swap = 0;
    t_path *i = p;
    t_path *j = p->next;

        for (; i != NULL; i = i->next) {
            for (; j != NULL; j = j->next) {
                if (i->prev < j->prev) {
                    swap = i->prev;
                    i->prev = j->prev;
                    j->prev = swap;
                }
            }
        }
}
