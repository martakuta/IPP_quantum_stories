#include "remove_or_valid_story.h"

void delete_parent_indicator (node **parent, char number) {

    switch(number) {
        case ('0'):
            (*parent)->zero = NULL;
            break;
        case ('1'):
            (*parent)->one = NULL;
            break;
        case ('2'):
            (*parent)->two = NULL;
            break;
        case ('3'):
            (*parent)->three = NULL;
            break;
        default:
            break;
    }
}

int go_to_last_element (node **root, char *story, int length) {

    int i=0;
    while (i<length && go_to_the_next_element(root, story[i])) {
        i++;
    }

    int exist = 0;
    if (i == length) {

        node *parent = *root;
        exist = go_to_the_next_element(root, story[i]);
        if (exist)
            delete_parent_indicator(&parent, story[i]);
    }

    return (i==length && exist);
    //so if such a story exist function return true, otherwise false
}

void change_representations (node *previous_node, node *new_node) {

    node *left = previous_node->left_list;

    while (left != NULL && left != previous_node) {
        left->represent = new_node;
        left = left->left_list;
    }

    node *right = previous_node->right_list;

    while (right != NULL && right != previous_node) {
        right->represent = new_node;
        right = right->right_list;
    }
}

void left_list_has_sth (node *left, node *root) {

    if ((find(root)) == root) {
        change_representations(root, left);
        left->energy = (root)->energy;
        left->right_list = NULL;
    }
    else {
        change_representations(root, find(left));
        left->right_list = NULL;
    }
}

void right_list_has_sth (node *right, node *root) {

    if ((find(root)) == root) {
        change_representations(root, right);
        right->energy = (root)->energy;
        right->left_list = NULL;
    }
    else {
        change_representations(root, find(right));
        right->left_list = NULL;
    }
}


void two_lists_have_sth (node *left, node *right, node *root) {

    if ((find(root)) == root) {
        change_representations(root, right);
        right->energy = (root)->energy;
        left->right_list = right;
        right->left_list = left;
    }
    else {
        change_representations(root, find(right));
        left->right_list = right;
        right->left_list = left;
    }
}

void remove_node (node **root) {

    node *left = (*root)->left_list;
    node *right = (*root)->right_list;

    if (left == NULL && right != NULL) {
        right_list_has_sth(right, *root);
    }
    else if (right == NULL && left != NULL) {
        left_list_has_sth(left, *root);
    }
    else if (right != NULL && left != NULL) {
        two_lists_have_sth(left, right, *root);
    }

    free(*root);
}

void remove_subtree (node **root) {

    if ((*root)->zero != NULL)
        remove_subtree(&((*root)->zero));
    if ((*root)->one != NULL)
        remove_subtree(&((*root)->one));
    if ((*root)->two != NULL)
        remove_subtree(&((*root)->two));
    if ((*root)->three != NULL)
        remove_subtree(&((*root)->three));

    remove_node(root);
}

int remove_story (node **root, char *story, int length) {

    int sign = getchar();
    if (sign != (int)('\n'))
        return ERROR;

    if (go_to_last_element(root, story, length)) {
        //it will remove sth only if the given story prefix exist
        remove_subtree(root);
    }

    printf("OK\n");
    return CORRECT;
}

int valid_story (node **root, char *story, int length) {

    int sign = getchar();
    if (sign != (int)('\n'))
        return ERROR;

    int i=0;
    while (i<=length && go_to_the_next_element(root, story[i])) {
        i++;
    }

    if (i == length+1)
        printf("YES\n");
    else
        printf("NO\n");

    return CORRECT;
}
