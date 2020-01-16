#ifndef _HEADER_H_
#define _HEADER_H_

#include "../libmx/inc/libmx.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <malloc/malloc.h>

typedef struct s_path {
	int dist;
	int prev;
	int trig;
	struct s_path *next;
} t_path;

typedef struct s_route {
	int *route;
	struct s_route *next;
} t_route;

typedef struct s_index {
	int i;
	int o;
	int ind;
} t_index;

typedef struct s_path_matrix {
	int prev;
	struct s_path_matrix *next;
} t_path_matrix;

int mx_atoi(char *s);
int mx_check(char **arr, char *str);
char **mx_islands (char **arr);
int mx_size_arr(char **arr);
int **mx_chart(int v, int length, int numb);
int **mx_matrix(char **data, char **names, int v);
int mx_get_index_name(char *str, char **arr);
int mx_vertex_check(char **arr, int v);
int mx_min(t_path *str, int size);
int mx_dist_ind(int *str, int min, int size);
t_path **mx_short_path(int **matrix, int v);
void mx_str_to_arr(const char *file, char *filename);
void mx_printpath(char **names, t_path **path, int v);
void mx_sort_prev(t_path *p);
void mx_borders(void);
void mx_destination(char *from, char *to);
void mx_simple_route(char *from, char *to);
int mx_line_invalid(char *str);
int mx_existence_check(char *str, char *filename);
char **mx_data_matrix(char *str);
void mx_find_shortest(int **matrix, t_path **path, int v, int o);
int mx_letter_check(char **check, int j, int i, int trig);
int mx_symbol_check(char **check, int j, int i, char symbol);
void mx_delete_path(t_path ***path, int v);
int mx_white_spaces_check(char *str);
void mx_line_error_print(int line);
int mx_flow_check(char **check, int i, int j, int trig);
void mx_similar_path(t_path **path, char **names, int i, int j);
void mx_hard_out(t_list *out, t_path **path);
void mx_route_out(char **names, t_path **path, int i, int j);
void mx_dist_out(t_path **path, int i, int j);
int mx_extra_route_check(t_path **path, int i, int j);
int **mx_matrix_copy(int **matrix, int l, int extra, int size);
t_list **mx_find_w(int **matrix, t_index index, t_list **list);
void mx_matrix_clean(int ***matrix, int v);
void mx_sort_list(t_list **list, int dest, int from);
void mx_similar_dist(int *matrix, int i, int j, t_path **path);
void mx_similar_route(int *matrix, int i, int j, char **names);


#endif
