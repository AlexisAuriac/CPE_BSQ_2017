/*
** EPITECH PROJECT, 2017
** bsq
** File description:
** Loads the file given in argument in an int array.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "bsq.h"

unsigned short get_nbr(char const *str)
{
	unsigned short result = 0;
	unsigned short len = my_strlen(str);

	for (short i = len - 1 ; i >= 0 ; i--)
		result += (str[i] - '0') * my_pow(10, len - i - 1);
	return (result);
}

unsigned short read_line(int fd, char * const str)
{
	unsigned short i = 0;

	read(fd, str, 1);
	for (i = 1 ; str[i - 1] != '\n' ; i++)
		read(fd, str + i, 1);
	str[i - 1] = '\0';
	return (i);
}

void get_dimensions(map_t *map, char const *file_name)
{
	struct stat file_stats;
	int offset = 0;
	char first_line[10] = "";

	offset = read_line(map->file, first_line);
	if (test_first_line(first_line))
		exit(84);
	map->lines = get_nbr(first_line);
	stat(file_name, &file_stats);
	map->cols = (file_stats.st_size - map->lines - offset) / map->lines;
}

char *load_to_int_array(map_t *map)
{
	char *file = NULL;
	unsigned short backslash = 0;

	file = malloc(sizeof(char) * (map->cols * map->lines + map->lines + 1));
	file[map->cols * map->lines + map->lines] = '\0';
	read(map->file, file, map->lines * map->cols + map->lines);
	if (test_map(file, map->lines, map->cols))
		exit(84);
	map->values = malloc(sizeof(short) * map->lines * map->cols);
	for (int i = 0 ; i < map->lines * (map->cols + 1) ; ++i) {
		if (file[i] == '.')
			map->values[i - backslash] = 1;
		else {
			if (file[i] == 'o')
				map->values[i - backslash] = 0;
			else
				backslash++;
		}
	}
	return (file);
}

map_t *load_map(char const *file_name, register char **file)
{
	map_t *map = malloc(sizeof(map_t));

	map->file = open(file_name, O_RDONLY);
	if (map->file == -1) {
		free(map);
		my_putchar('\'');
		my_putstr(file_name);
		my_putchar('\'');
		write(2, " could not be found\n", 20);
		exit(84);
	}
	get_dimensions(map, file_name);
	*file = load_to_int_array(map);
	return (map);
}
