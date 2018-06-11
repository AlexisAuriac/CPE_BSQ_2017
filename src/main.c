/*
** EPITECH PROJECT, 2017
** bsq
** File description:
** Main file.
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "bsq.h"

void draw_solved_map(map_t const *map, char * const file)
{
	int i = map->pos_biggest + map->pos_biggest / map->cols;
	int pos_init = i;

	while (i > pos_init - map->biggest * (map->cols + 1)) {
		for (int j = i ; i - j < map->biggest ; j--)
			file[j] = 'x';
		i = i - (map->cols + 1);
	}
	write(1, file, map->lines * (map->cols + 1));
}

int main(int ac, char **av)
{
	char *file = NULL;
	map_t *map = NULL;

	if (ac != 2)
		return (84);
	map = load_map(av[1], &file);
	rate(map);
	draw_solved_map(map, file);
	close(map->file);
	free(map->values);
	free(map);
	free(file);
	return (0);
}
