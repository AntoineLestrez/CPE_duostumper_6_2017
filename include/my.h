/*
** EPITECH PROJECT, 2018
** CPE_duostumer
** File description:
** my.h
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct game {
	char *word;
	char *play;
	char *word_p;
	int len;
	int n_try;
}game_t;

char *recup_word(char **av);
int play(game_t *game);
int check_size(game_t *game, char *line);
void check_letter(game_t *game, char *line);
void check_letter_word(game_t *game, char *line, int i);
void clean_word_p(game_t *game);
int check_end(game_t *game);
