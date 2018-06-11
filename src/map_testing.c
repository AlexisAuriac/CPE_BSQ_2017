/*
** EPITECH PROJECT, 2017
** bsq
** File description:
** Tests the map in several ways.
*/

#include "my.h"

int test_first_line(char const * const first_line)
{
	unsigned short len = my_strlen(first_line);

	for (int i = 0 ; i < len - 1 ; i++) {
		if (first_line[i] < '0' || first_line[i] > '9')
			return (84);
	}
	return (0);
}

int test_map(char const * const map, unsigned short lines, unsigned short cols)
{
	unsigned int len = my_strlen(map);
	register unsigned int i = 0;

	if (len == 0)
		return (84);
	for (i = lines * (cols + 1) - 1 ; i-- ; ) {
		if (map[i] != 'o' && map[i] != '.') {
			if ((i + 1) % (cols + 1) != 0 || map[i] != '\n')
				return (84);
		}
	}
	for (i = lines ; i != 1 ; i--) {
		if (map[i * (cols + 1) - 1] != '\n')
			return (84);
	}
	return (0);
}
