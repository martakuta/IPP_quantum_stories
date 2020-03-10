#ifndef EQUAL_STORIES_H
#define EQUAL_STORIES_H

#include <stdio.h>
#include "trie_structure.h"

node *go_to_the_left_list_end (node *root, node *beginning);

node *go_to_the_right_list_end (node *root, node *beginning);

node *find (node *root);

void union_representations (node *first, node *second);

int union_stories (node *first, node *second);

int both_stories_are_valid (node *first, node *second);

int equal (node **root, char *story1, char *story2, long long length1, long long length2);

#endif
