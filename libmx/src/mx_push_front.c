#include "../inc/libmx.h"

void mx_push_front(t_list **list, int **value) {
	 if (*list == NULL) {
	 	*list = mx_create_node(value);
	 	return;
	 }
	t_list * front = *list;
	*list = mx_create_node(value);
	(*list)->next = front;
}
