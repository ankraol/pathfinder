#include "../inc/libmx.h"

void mx_push_back(t_list **list, int **value) {
	if(*list == 0) {
	  *list = mx_create_node(value);
	  return;
	 }
	 t_list *copy = *list;

	 while(copy->next != NULL) {
	  copy = copy->next;
	 }
	 copy->next = mx_create_node(value);
	 copy = copy->next;
}
