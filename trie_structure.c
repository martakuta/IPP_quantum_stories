#include "trie_structure.h"

node *create_node() {

    node *root = malloc(sizeof(node));
    if (root == NULL)
        exit(1);

    root->zero = NULL;
    root->one = NULL;
    root->two = NULL;
    root->three = NULL;
    root->left_list = NULL;
    root->right_list = NULL;
    root->represent = root;
    root->energy = 0;
    return root;
}

int go_to_the_next_element (node **root, int number) {

    switch(number) {
        case (int)('0'):
            *root = (*root)->zero;
            break;
        case (int)('1'):
            *root = (*root)->one;
            break;
        case (int)('2'):
            *root = (*root)->two;
            break;
        case (int)('3'):
            *root = (*root)->three;
            break;
        default:
            break;
    }

    if (*root == NULL)
        return NOT_EXIST;
    else
        return EXIST;
}

void free_tree (node **root) {

    if ((*root)->zero != NULL) {
        free_tree(&((*root)->zero));
    }
    if ((*root)->one != NULL) {
        free_tree(&((*root)->one));
    }
    if ((*root)->two != NULL) {
        free_tree(&((*root)->two));
    }
    if ((*root)->three != NULL) {
        free_tree(&((*root)->three));
    }

    free(*root);
}