#include "equal_stories.h"

node *go_to_the_left_list_end (node *root, node *beginning) {

    if (root->left_list == NULL)
        return root;
    else
        return go_to_the_left_list_end(root->left_list, beginning);
}

node *go_to_the_right_list_end (node *root, node *beginning) {

    if (root->right_list == NULL)
        return root;
    else
        return go_to_the_right_list_end(root->right_list, beginning);
}

node *find (node *root) {

    if (root->represent == root)
        return root;
    else
        return root->represent = find(root->represent);
}

void union_representations (node *first, node *second) {

    (find(first))->represent = find(second);

    node *left_end_of_first = go_to_the_left_list_end(first, first);
    node *right_end_of_second = go_to_the_right_list_end(second, second);

    left_end_of_first->left_list = right_end_of_second;
    right_end_of_second->right_list = left_end_of_first;
}

int union_stories (node *first, node *second) {
    //representation of first will be represented by representation of second

    if ((find(first))->energy == 0) {

        if ((find(second))->energy == 0) {
            //first and second stories don't have energies
            return ERROR;
        }

        else {
            //first story doesn't have energy, but second has

            (find(first))->energy = (find(second))->energy;
            union_representations(first, second);

            return CORRECT;
        }
    }

    else if ((find(second))->energy == 0) {
        //second story doesn't have energy, but first has

        (find(second))->energy = (find(first))->energy;
        union_representations(first, second);

        return CORRECT;
    }

    else {
        //first and second stories have energies

        unsigned long long new_energy=0;
        if (((find(first))->energy)%2 == 1 && ((find(second))->energy)%2 == 1)
            new_energy += 1;
        new_energy += ((find(first))->energy)/2 + ((find(second))->energy)/2;

        (find(first))->energy = new_energy;
        (find(second))->energy = new_energy;

        union_representations(first, second);

        return CORRECT;
    }
}

int both_stories_are_valid (node *first, node *second) {

    if (first == second) {
        printf("OK\n");
        return CORRECT;
    }

    if (find(second) == find(first)) {
        //to make cycles impossible I shouldn't equal stories when they have the same representation

        if ((second->represent)->energy == 0)
            return ERROR;

        printf("OK\n");
        return CORRECT;
    }

    if (union_stories(first, second)) {
        printf("OK\n");
        return CORRECT;
    }
    else {
        return ERROR;
    }
}

int equal (node **root, char *story1, char *story2, long long length1, long long length2) {

    node *root_copy = *root;
    long long i=0;

    while (i<=length1 && go_to_the_next_element(root, story1[i])) {
        i++;
    }

    if (i == length1+1) {

        node *first = *root;
        *root = root_copy;
        i=0;

        while (i<=length2 && go_to_the_next_element(root, story2[i])) {
            i++;
        }

        if (i == length2+1) {

            //it means that both stories are valid
            node *second = *root;
            return both_stories_are_valid(first, second);
        }
        else {
            return ERROR;
        }
    }
    else {
        return ERROR;
    }
}