/*
** EPITECH PROJECT, 2017
** bsq
** File description:
** Rates each case of the array.
*/

#include <stdio.h>
#include "struct.h"

unsigned short smallest_outof(unsigned short a, unsigned short b,
			      unsigned short c)
{
	unsigned short smallest = (a < b) ? a : b;

	smallest = (smallest < c) ? smallest : c;
	return (smallest);
}

void rate(map_t * const map)
{
	unsigned short up = 0;
	unsigned short left = 0;
	unsigned short diag = 0;

	map->biggest = 0;
	for (int i = 0 ; i < map->lines * map->cols ; ++i) {
		if (map->values[i] != 0) {
			up = 0;
			left = 0;
			diag = 0;
			if (i >= map->cols)
				up = map->values[i - map->cols];
			if (i % map->cols != 0)
				left = map->values[i - 1];
			if (i >= map->cols && i % map->cols != 0)
				diag = map->values[i - map->cols - 1];
			map->values[i] = smallest_outof(up, left, diag) + 1;
			if (map->values[i] > map->biggest) {
				map->biggest = map->values[i];
				map->pos_biggest = i;
			}
		}
	}
}
