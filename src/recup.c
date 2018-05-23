/*
** EPITECH PROJECT, 2018
** duo_stumper
** File description:
** recup
*/

#include "my.h"

char *recup_word(char **av)
{
	FILE *stream;
	char *line = NULL;
	size_t len = 32;

	stream = fopen(av[1], "r");
	if (stream == NULL)
		exit (84);
	if (getline(&line, &len, stream) != -1)
		return (line);
	free(line);
	fclose(stream);
	return (NULL);
}
