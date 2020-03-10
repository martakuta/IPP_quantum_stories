#ifndef DECLARE_STORY_H
#define DECLARE_STORY_H

#include <stdio.h>
#include <stdlib.h>
#include "trie_structure.h"

void add_zero (node **root);

void add_one (node **root);

void add_two (node **root);

void add_three (node **root);

void add_element (node **root, char element);

int declare_story (node **root, char *story, long long length);

#endif