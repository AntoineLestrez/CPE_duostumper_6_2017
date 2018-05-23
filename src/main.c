/*
** EPITECH PROJECT, 2018
** duo_stumper
** File description:
** main
*/

#include "my.h"

game_t *init_struct(game_t *game, char **av)
{
	game->word = recup_word(av);
	if (game->word == NULL)
		exit (84);
	game->len = strlen(game->word) - 1;
	game->word_p = strdup(game->word);
	for (int i = 1; i < game->len; i++)
		game->word_p[i] = '*';
	game->n_try = game->len;
	return (game);
}

int error_file(int ac, char **av)
{
	int fd;

	if (ac < 2)
		return (84);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (84);
	close(fd);
	return (0);
}

int main(int ac, char **av)
{
	game_t *game = malloc(sizeof(struct game));
	int result = 0;

	if (game == NULL)
		return (84);
	if (error_file(ac, av) == 84)
		return (84);
	init_struct(game, av);
	result = play(game);
	if (result != 0)
		printf("\nYou won!\n");
	else
		printf("\nYou lost!\n");
	free(game->word);
	free(game->word_p);
	free(game);
	return (0);
}
