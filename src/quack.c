#include "quack.h"
//this is a STACK implemented with queues
quack_int * create_quack(unsigned capacity) 
{ 
    quack_int * quack = (quack_int *) malloc(sizeof(quack)); 
    quack->queue = create_queue(capacity);
    return quack; 
}

void quack_push(quack_int * quack, int val){
    enqueue(quack->queue, val);
}

int quack_pop(quack_int * quack){
    int iters = quack->queue->size -1;
    for(int i=0; i<iters; i++){
        enqueue(quack->queue, dequeue(quack->queue));
    }
    return dequeue(quack->queue);
}

void test_quack(){
    quack_int * test = create_quack(10);
    quack_push(test, 5);
    quack_push(test, 10);
    printf("%d\n", quack_pop(test));
    printf("%d\n", quack_pop(test));
}