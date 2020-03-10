#include "declare_story.h"

void add_zero (node **root) {

    if ((*root)->zero == NULL) {
        node *help = create_node();
        (*root)->zero = help;
        *root = (*root)->zero;
    }
    else {
        *root = (*root)->zero;
    }
}

void add_one (node **root) {

    if ((*root)->one == NULL) {
        node *help = create_node();
        (*root)->one = help;
        *root = (*root)->one;
    }
    else {
        *root = (*root)->one;
    }
}

void add_two (node **root) {

    if ((*root)->two == NULL) {
        node *help = create_node();
        (*root)->two = help;
        *root = (*root)->two;
    }
    else {
        *root = (*root)->two;
    }
}

void add_three (node **root) {

    if ((*root)->three == NULL) {
        node *help = create_node();
        (*root)->three = help;
        *root = (*root)->three;
    }
    else {
        *root = (*root)->three;
    }
}

void add_element (node **root, char element) {

    switch(element) {
        case ('0'):
            add_zero(root);
            break;
        case ('1'):
            add_one(root);
            break;
        case ('2'):
            add_two(root);
            break;
        case ('3'):
            add_three(root);
            break;
        default:
            break;
    }
}

int declare_story (node **root, char *story, long long length) {

    int sign = getchar();
    if (sign != (int)('\n')) {
        return ERROR;
    }

    long long i=0;
    while (i<=length) {
        add_element(root, story[i]);
        i++;
    }

    printf("OK\n");
    return CORRECT;
}