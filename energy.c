#include "energy.h"

int new_energy (node **root, char *story, long long length, unsigned long long energy) {

    if (energy == 0)
        return ERROR;

    long long i=0;
    while (i<=length && go_to_the_next_element(root, story[i])) {
        i++;
    }

    if (i==length+1) {
        (find(*root))->energy = energy;
        printf("OK\n");
        return CORRECT;
    }
    else {
        return ERROR;
    }
}

int read_energy (node **root, char *story, long long length) {

    long long i=0;
    while (i<=length && go_to_the_next_element(root, story[i])) {
        i++;
    }

    if (i==length+1) {

        if ((find(*root))->energy != 0) {
            printf("%llu\n", (find(*root))->energy);
            return CORRECT;
        }
        else {
            return ERROR;
        }
    }
    else {
        return ERROR;
    }
}

int is_energy_under_limit (int *number) {

    int maximum[20] = {1,8,4,4,6,7,4,4,0,7,3,7,0,9,5,5,1,6,1,5};

    for (int i=0; i<20; i++) {

        if (number[i] < maximum[i])
            return CORRECT;
        else if (number[i] > maximum[i])
            return ERROR;
    }

    return CORRECT;
}

void convert_energy (int *number, unsigned long long *energy, int length) {

    unsigned long long power10 = 1;

    for (int i=length-1; i>=0; i--) {
        (*energy) += number[i] * power10;
        power10 *= 10;
    }
}

int number_has_20_digits (int sign, unsigned long long *energy, int *number) {

    if (sign == (int)('\n')) {

        if (is_energy_under_limit(number)) {
            convert_energy(number, energy, 20);
            return CORRECT;
        }
        else {
            return ERROR;
        }
    }
    else {
        //if number has more than 20 digits
        return ERROR;
    }
}

int energy_value (int sign, unsigned long long *energy, int *number, int length) {
    //(2^64)-1 has 20 digits, it is exactly the range of unsigned long long

    if (length == 20) {
        //at least 20
        int is_correct = number_has_20_digits (sign, energy, number);
        free(number);
        return is_correct;
    }

    else if (length == 0) {
        free(number);
        return ERROR;
    }

    //else means that length is in range [1,19]
    else {
        convert_energy(number, energy, length);
        free(number);
        return CORRECT;
    }
}

int scan_energy (unsigned long long *energy) {

    int *number = malloc(20*sizeof(int));
    if (number == NULL)
        exit(1);

    int i=0;
    int sign = getchar();
    if (sign != (int)(' ')) {
        free(number);
        return ERROR;
    }

    sign = getchar();
    while (sign == (int)('0')) {
        sign = getchar();
    }
    ungetc((char)(sign), stdin);

    while ((sign=getchar()) >= (int)('0') && sign <= (int)('9') && i<20) {
        number[i] = sign - (int)('0');
        i++;
    }
    ungetc((char)(sign), stdin);

    int is_correct = energy_value(sign, energy, number, i);
    return is_correct;
}
