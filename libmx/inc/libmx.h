#ifndef _LIBMIX_H_
#define _LIBMIX_H_

#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>
#include <fcntl.h>
#include <stdbool.h>

typedef struct s_list {
	int **value;
	struct s_list *next;
}		t_list;


int mx_strcmp(const char *s1, const char *s2);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
char *mx_itoa(int number);
void mx_strdel(char **str);
void mx_del_strarr(char ***arr);
char **mx_strsplit(const char *s, char c);
char *mx_file_to_str(const char *file);
int mx_count_words(const char *str, char c);
void mx_push_front(t_list **list, int **value);
t_list *mx_create_node(int **value);
void mx_pop_front(t_list **head);
void mx_push_back(t_list **list, int **value);

#endif
