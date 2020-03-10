#ifndef REMOVE_OR_VALID_STORY_H
#define REMOVE_OR_VALID_STORY_H

#include <stdio.h>
#include <stdlib.h>
#include "trie_structure.h"
#include "equal_stories.h"

void delete_parent_indicator (node **parent, char number);

int go_to_last_element (node **root, char *story, int length);

void change_representations (node *previous_node, node *new_node);

void left_list_has_sth (node *left, node *root);

void right_list_has_sth (node *right, node *root);

void two_lists_have_sth (node *left, node *right, node *root);

void remove_node (node **root);

void remove_subtree (node **root);

int remove_story (node **root, char *story, int length);

int valid_story (node **root, char *story, int length);

#endif
