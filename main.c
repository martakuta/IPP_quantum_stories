#include <stdio.h>
#include <stdlib.h>
#include "trie_structure.h"
#include "read_commands.h"

int main() {
    node *root = create_node();
    read_many_commands(&root);
    free_tree(&root);
    return 0;
}