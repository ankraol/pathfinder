#include "../inc/header.h"

int main(int argc, char **argv) {
    char *filename = argv[1];

    if (argc != 2) {
        write(2,
        "usage: ./pathfinder [filename]\n",
        mx_strlen("usage: ./pathfinder [filename]\n"));
        return 0;
    }
    mx_str_to_arr(argv[1], filename);
}
