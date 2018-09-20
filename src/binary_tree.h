#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include "maths.h"
// A structure to represent a stack 
typedef struct tree_node {
    struct tree_node *left;
    struct tree_node *right;
    int val;
} tree_node;
void trees_menu();
#endif /* BINARY_TREE_H */