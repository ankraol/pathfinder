NAME = pathfinder

DIROBJ = obj

SRC = src/mx_atoi.c \
	src/mx_chart.c \
	src/mx_check.c \
	src/mx_dist_ind.c \
	src/mx_get_index_name.c \
	src/mx_islands.c \
	src/mx_matrix.c \
	src/mx_min.c \
	src/mx_short_path.c \
	src/mx_size_arr.c \
	src/mx_vertex_check.c \
	src/mx_str_to_arr.c \
	src/main.c \
	src/mx_printpath.c \
	src/mx_sort_prev.c \
	src/mx_borders.c \
	src/mx_destination.c \
	src/mx_simple_route.c \
	src/mx_line_invalid.c \
	src/mx_existence_check.c \
	src/mx_data_matrix.c \
	src/mx_find_shortest.c \
	src/mx_letter_check.c \
	src/mx_symbol_check.c \
	src/mx_delete_path.c \
	src/mx_white_spaces_check.c \
	src/mx_line_error_print.c \
	src/mx_flow_check.c \
	src/mx_similar_path.c \
	src/mx_route_out.c \
	src/mx_dist_out.c \
	src/mx_extra_route_check.c \
	src/mx_matrix_copy.c \
	src/mx_find_w.c \
	src/mx_matrix_clean.c \
	src/mx_sort_list.c \
	src/mx_similar_dist.c \
	src/mx_similar_route.c \

OUT = mx_atoi.o \
	mx_chart.o \
	mx_check.o \
	mx_dist_ind.o \
	mx_get_index_name.o \
	mx_islands.o \
	mx_matrix.o \
	mx_min.o \
	mx_short_path.o \
	mx_size_arr.o \
	mx_vertex_check.o \
	mx_str_to_arr.o \
	main.o \
	mx_printpath.o \
	mx_sort_prev.o \
	mx_borders.o \
	mx_destination.o \
	mx_simple_route.o \
	mx_line_invalid.o \
	mx_existence_check.o \
	mx_data_matrix.o \
	mx_find_shortest.o \
	mx_letter_check.o \
	mx_symbol_check.o \
	mx_delete_path.o \
	mx_white_spaces_check.o \
	mx_line_error_print.o \
	mx_flow_check.o \
	mx_similar_path.o \
	mx_route_out.o \
	mx_dist_out.o \
	mx_extra_route_check.o \
	mx_matrix_copy.o \
	mx_find_w.o \
	mx_matrix_clean.o \
	mx_sort_list.o \
	mx_similar_dist.o \
	mx_similar_route.o \

CLANG = -std=c11 -Wall -Wextra -Werror -Wpedantic

INC = inc/header.h

LIBMX = libmx/libmx.a

all: install

install: 
	@mkdir -p $(DIROBJ)
	@clang $(CLANG) -c $(SRC) -I $(INC)
	@mv $(OUT) $(DIROBJ)
	@make all -C libmx
	@clang $(CLANG) $(SRC) $(LIBMX) -o $(NAME) -I $(INC)

uninstall: clean
	@rm -rf $(NAME)
	@make uninstall -C libmx

clean:
	@rm -rf $(DIROBJ)
	@rm -rf $(OUT)
	@make clean -C libmx

reinstall: uninstall install
