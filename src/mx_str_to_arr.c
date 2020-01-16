#include "../inc/header.h"

static void printing_data(char **data, int v) {
    char **names = mx_islands(data);
    int **matrix = mx_matrix(data, names, v);

    if (matrix == 0) {
        return;
    }
    t_path **path = mx_short_path(matrix, v);
    mx_printpath(names, path, v);
    mx_delete_path(&path, v);
    mx_del_strarr(&names);
    mx_matrix_clean(&matrix, v);
}

void mx_str_to_arr(const char *file, char *filename) {
    char *str = mx_file_to_str(file);
    char **data = NULL;

    if (mx_existence_check(str, filename) == 1)
        return;
    if (mx_line_invalid(str) == -1)
        return;
    data = mx_data_matrix(str);
        if (data == NULL)
            return;
        if (mx_vertex_check(data, mx_atoi(data[0])) == -1) {
            write(2, "error: invalid number of islands\n",
            mx_strlen("error: invalid number of islands\n"));
            return;
        }
        if (mx_vertex_check(data, mx_atoi(data[0])) == 2)
            return;
        printing_data(data, mx_atoi(data[0]));
        free(str);
}
