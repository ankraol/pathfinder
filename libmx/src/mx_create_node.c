#include "../inc/libmx.h"

t_list *mx_create_node(int **value) {
	t_list *head = NULL;
	head = malloc(sizeof(t_list));
	head->value = value;
	head->next = NULL;
	return head;
}
