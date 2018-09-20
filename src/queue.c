#include "queue.h"
//creates our memory for strucy and array memory as well 
queue_int * create_queue(unsigned capacity) 
{ 
    queue_int* queue = (queue_int *) malloc(sizeof(queue_int)); 
    queue->capacity = capacity; 
    queue->front = 0; //we start adding people at pos 0
    queue->back = 0; //we start adding people at pos 0
    queue->size = 0; //queue is empty lol
    queue->array = (int*) malloc(queue->capacity * sizeof(int)); 
    return queue; 
}

int isEmpty(queue_int * queue) // I AM SORRY, I HAD TO CHANGE THE CASING!!!
{
    return queue->size == 0;
}

int isFull(queue_int * queue)
{
    return queue->size == queue->capacity;
}

void enqueue(queue_int * queue, int val)
{
    if(!isFull(queue)) //if not full we can add a guy
    {
        queue->array[queue->back] = val;
        queue->back++;
        queue->size++;
    }
    else{
        printf("No more room in the queue, need to create larger queue\n");
    }
}

int dequeue(queue_int * queue)
{
    if(!isEmpty(queue)) //if not empty we can dequeue a guy
    { 
        int d_q = queue->front;
        queue->front++;
        if(queue->front >= queue->capacity)
        {
            queue->front = 0; // reset
        }
        queue->size--;
        return queue->array[d_q];
    }
    return INT_MIN;
}

void test_queue()
{
    queue_int * queue = create_queue(3);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));
    printf("%d dequeued from queue\n", dequeue(queue));

}