/*
** EPITECH PROJECT, 2018
** check.c
** File description:
** Check
*/

#include "my.h"

void clean_word_p(game_t *game)
{
	for (int i = 1; game->word_p[i] != '\0'; i++)
		game->word_p[i] = '*';
}

int check_size(game_t *game, char *line)
{
	int check = strlen(line) - 1;

	if (check > game->len) {
		printf("Word too long. Retry.");
		return (1);
	}
	else if (check < game->len) {
		printf("Word too short. Retry.");
		return (1);
	}
	return (0);
}

void suppr_int(game_t *game, char check, int i, char *line)
{
	while (i > 0) {
		if (game->word_p[i] == '?' && line[i] == check)
			game->word_p[i] = '*';
		i--;
	}
}

void check_letter(game_t *game, char *line)
{
	int i = 1;

	while (line[i] != '\0') {
		if (line[i] == game->word[i]) {
			game->word_p[i] = line[i];
			suppr_int(game, game->word[i], i, line);
		}
		else
			check_letter_word(game, line, i);
		i++;
	}
}

void check_letter_word(game_t *game, char *line, int i)
{
	int j = 1;

	while (game->word[j] != '\0') {
		if (game->word[j] == line[i] && game->word_p[j] != line[i])
			game->word_p[i] = '?';
		j++;
	}
}
