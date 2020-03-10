#ifndef TRIE_STRUCTURE_H
#define TRIE_STRUCTURE_H

#include <stdio.h>
#include <stdlib.h>

#define EXIST 1
#define NOT_EXIST 0
#define ERROR 0
#define CORRECT 1
#define NEW_SIZE 3/2


typedef struct node {

    struct node *zero;
    struct node *one;
    struct node *two;
    struct node *three;
    struct node *left_list;
    struct node *right_list;
    struct node *represent; //representative
    unsigned long long energy;

} node;

node *create_node ();

int go_to_the_next_element (node **root, int number);

void free_tree (node **root);

#endif
