#include "../inc/libmx.h"

void mx_pop_front(t_list **head) {
	    t_list *head2 = *head;
	    t_list *new_head = *head;
	    new_head = new_head->next;
	    *head = new_head;
	    free(head2);
	}
