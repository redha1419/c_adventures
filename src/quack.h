#ifndef QUACK_H
#define QUACK_H
#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include "maths.h"
#include "queue.h"
// A structure to represent a stack using queues
typedef struct quack 
{  
    queue_int * queue;
}quack_int; 
void test_quack();
#endif /* QUACK_H */