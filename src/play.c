/*
** EPITECH PROJECT, 2018
** duostumper
** File description:
** play
*/

#include "my.h"

void start_print(game_t *game)
{
	printf("*: invalid letter\n");
	printf("?: incorrectly placed letter\n");
	printf("Will you find the secret word?\n");
	printf("%s\n", game->word_p);
	printf("Round 1\n>");
}

void action(game_t *game, char *line)
{
	check_letter(game, line);
	printf("%s", game->word_p);
	if (check_end(game) == 0)
		clean_word_p(game);
	game->n_try--;
}

int check_end(game_t *game)
{
	for (int i = 1; game->word_p[i] != '\0'; i++)
		if (game->word_p[i] == '?' || game->word_p[i] == '*')
			return (0);
	return (1);
}

void print_round(int end, int round, game_t *game)
{
	if (end == 0 && game->n_try > 0)
		printf("\nRound %d", round);
}

int play(game_t *game)
{
	int end = 0;
	char *line = NULL;
	size_t len = 32;
	int round = 1;

	start_print(game);
	while ((end == 0
		&& game->n_try > 0 && getline(&line, &len, stdin) != -1)) {
		if (check_size(game, line) == 0) {
			action(game, line);
			round++;
			end = check_end(game);
			print_round(end, round, game);
		}
		if (end == 0 && game->n_try > 0)
			printf("\n>");
	}
	free(line);
	return (end);
}
