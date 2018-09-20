#ifndef STACK_H
#define STACK_H
#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include "maths.h"
// A structure to represent a stack 
typedef struct stack 
{ 
    int top; 
    unsigned capacity; 
    int* array; 
}stack_int; 
void test_stack_stort();
#endif /* STACK_H */