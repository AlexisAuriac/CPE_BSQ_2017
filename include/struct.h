/*
** EPITECH PROJECT, 2017
** bsq
** File description:
** Structures header file.
*/

#ifndef STRUCT_H
#define STRUCT_H

typedef struct map {
	int file;
	unsigned short lines;
	unsigned short cols;
	unsigned short *values;
	unsigned short biggest;
	unsigned int pos_biggest;
}map_t;

#endif
