/*
** EPITECH PROJECT, 2017
** bsq
** File description:
** Contains the prototypes of the project's functions.
*/

#ifndef BSQ_H
#define BSQ_H

#include "const.h"
#include "struct.h"
#include "macro.h"

//load_map.c
unsigned short get_nbr(char const *str);
unsigned short read_line(int fd, char *str);
void get_dimensions(map_t *map, char const *file_name);
char *load_to_int_array(map_t *map);
map_t *load_map(char const *file_name, char **file);

//map_testing.c
int test_first_line(char const *first_line);
int test_map(char *map, int lines, int cols);

//rate.c
int smallest_outof(int a, int b, int c);
void rate(map_t *map);

#endif
