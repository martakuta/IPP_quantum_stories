#ifndef ENERGY_H
#define ENERGY_H

#include <stdio.h>
#include <limits.h>
#include "trie_structure.h"
#include "read_commands.h"
#include "equal_stories.h"

int new_energy (node **root, char *story, long long length, unsigned long long energy);

int read_energy (node **root, char *story, long long length);

int is_energy_under_limit (int *number);

void convert_energy (int *number, unsigned long long *energy, int length);

int number_has_20_digits (int sign, unsigned long long *energy, int *number);

int energy_value (int sign, unsigned long long *energy, int *number, int length);

int scan_energy (unsigned long long *energy);

#endif
