#ifndef READ_COMMANDS_H
#define READ_COMMANDS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "declare_story.h"
#include "remove_or_valid_story.h"
#include "trie_structure.h"
#include "energy.h"
#include "equal_stories.h"

int scan_story (char **story, long long *length);

int is_equal_correct (node **root, char *story1, long long length1);

int is_energy_correct (node **root, char *story, long long length);

int choose_command (char *command, node **root, char *story, long long length);

int read_story (node **root, char *command);

void scan_rest_of_incorrect_command ();

void read_one_command (node **root);

void read_many_commands (node **root);

#endif