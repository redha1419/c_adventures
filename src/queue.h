#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
#include "maths.h"
// A structure to represent a stack 
typedef struct queue 
{ 
    int front; 
    int back;
    int size;
    unsigned capacity; 
    int* array; 
}queue_int; 
void test_queue();
queue_int * create_queue(unsigned capacity); 
void enqueue(queue_int * queue, int val);
int dequeue(queue_int * queue);
#endif /* QUEUE_H */