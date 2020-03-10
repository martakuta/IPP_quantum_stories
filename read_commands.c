#include "read_commands.h"

int scan_story (char **story, long long *length) {

    long long size = 1;
    int sign = getchar();

    if (sign != (int)(' ')) {
        ungetc((char)(sign), stdin);
        return ERROR;
    }

    while ((sign=getchar()) != (int)(' ') && sign != (int)('\n') && sign != EOF) {

        if (sign < (int)('0') || sign > (int)('3')) {
            return ERROR;
        }

        else if (*length <= size) {
            size = NEW_SIZE*size +1;
            *story = realloc((*story), size*sizeof(char));
        }

        *((*story)+(*length)) = (char)(sign);
        (*length)++;
    }
    ungetc(sign, stdin);

    if (*length == 0)
        return ERROR;

    (*length)--;

    return CORRECT;
}

int is_equal_correct (node **root, char *story1, long long length1) {

    int sign = getchar();
    ungetc((char)(sign), stdin);

    if (sign == (int)(' ')) {

        char *story2 = malloc(sizeof(char));
        if (story2 == NULL)
            exit(1);

        long long length2 = 0;
        if (scan_story(&story2, &length2)) {

            sign = getchar();
            ungetc((char)(sign), stdin);

            if (sign == (int)('\n')) {
                int is_correct = equal(root, story1, story2, length1, length2);
                free(story2);
                return is_correct;
            }
            else {
                free(story2);
                return ERROR;
            }
        }
        else {
            free(story2);
            return ERROR;
        }
    }

    else {
        return ERROR;
    }
}

int is_energy_correct (node **root, char *story, long long length) {

    int sign = getchar();
    ungetc((char)(sign), stdin);

    if (sign == (int)(' ')) {

        unsigned long long energy=0;

        if (scan_energy(&energy)) {
            int is_correct = new_energy(root, story, length, energy);
            return is_correct;
        }
        else {
            return ERROR;
        }
    }

    //else means that sign have to be '\n'
    else {

        if (read_energy(root, story, length)) {
            return CORRECT;
        }
        else {
            return ERROR;
        }
    }
}

int choose_command (char *command, node **root, char *story, long long length) {

    if (!strcmp(command, "DECLARE"))
        return declare_story(root, story, length);
    else if (!strcmp(command, "REMOVE"))
        return remove_story(root, story, length);
    else if (!strcmp(command, "VALID"))
        return valid_story(root, story, length);
    else if (!strcmp(command, "ENERGY"))
        return is_energy_correct(root, story, length);
    else if (!strcmp(command, "EQUAL"))
        return is_equal_correct(root, story, length);
    else
        return ERROR;
}

int read_story (node **root, char *command) {

    char *story = malloc(sizeof(char));
    if (story == NULL)
        exit(1);

    long long length=0;

    if (scan_story(&story, &length)) {

        int sign = getchar();
        if (sign == (int)('\n') || sign == (int)(' ')) {

            ungetc((char)(sign), stdin);
            int is_correct = choose_command(command, root, story, length);

            free(story);
            return is_correct;
        }
        else {
            free(story);
            return ERROR;
        }
    }
    else {
        free(story);
        return ERROR;
    }
}

void scan_rest_of_incorrect_command () {

    int sign = getchar();
    while (sign != (int)('\n') && sign != EOF)
        sign = getchar();

    fprintf(stderr, "ERROR\n");
}

void read_one_command (node **root) {

    int sign = getchar();

    if (sign != (int)('D') && sign != (int)('E') && sign != (int)('R') && sign != (int)('V')) {
        while (sign != (int)('\n') && sign != EOF)
            sign = getchar();
        fprintf(stderr, "ERROR\n");
    }
    else {
        ungetc((char)(sign), stdin);

        char *command = malloc(10*sizeof(char));
        if (command == NULL)
            exit(1);
        if (scanf("%s", command) != 1)
            exit(1);

        node *root_copy = *root;

        //in time of read_story each correct action is doing
        if (!read_story(root, command)) {
            scan_rest_of_incorrect_command();
        }

        *root = root_copy;
        free(command);
    }
}

void read_many_commands (node **root) {

    int sign;
    while ((sign=getchar()) != EOF) {

        if (sign != (int)('\n')) {

            if (sign == (int)('#')) {
                while (sign != '\n')
                    sign = getchar();
            }
            else {
                ungetc((char) (sign), stdin);
                read_one_command(root);
            }
        }
    }
}