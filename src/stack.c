#include "stack.h"
//creates our memory for strucy and array memory as well 
stack_int * create_stack(unsigned capacity) 
{ 
    stack_int* stack = (stack_int *) malloc(sizeof(stack_int)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (int*) malloc(stack->capacity * sizeof(int)); 
    return stack; 
} 

// Stack is full when top is equal to the last index 
int is_full(stack_int * stack) {   return stack->top == stack->capacity - 1; } 
  
// Stack is empty when top is equal to -1 
int is_empty(stack_int * stack) {   return stack->top == -1;  } 

// Function to add an item to stack.  It increases top by 1 
void push(stack_int * stack, int item) 
{ 
    if (is_full(stack)) 
        return; 
    stack->array[++stack->top] = item; 
    //printf("%d pushed to stack\n", item); 
} 

// Function to remove an item from stack.  It decreases top by 1 
int pop(stack_int * stack) 
{ 
    if (is_empty(stack))
    {
        return INT_MIN; 
    }
    //printf("%d popped from stack\n",stack->array[stack->top]); 
    return stack->array[stack->top--]; 
} 

int peek(stack_int * stack)
{
    if (is_empty(stack))
    {
        return INT_MIN; 
    }
    return stack->array[stack->top];
}

void sort(stack_int * stack)
{
    //my algorithm
    //copy all contents to temp stack
    //pop from temp stack place in original stack
    //pop again and push in orig stack, if the value being pushed is larger then the current top val
    //then pop original stack and check again ...and again... and again and eventually push 

    //copying process
    stack_int * copy = create_stack(stack->capacity);
    while(!is_empty(stack))
    {
        push(copy, pop(stack)); //pop original stack and place in temp, till empty
    }

    //now we have a copy of our stack in "copy"
    //lets not be affraid to use two temporary stack
    //lets create a temp
    stack_int * temp = create_stack(stack->capacity);
    printf("started sort\n");
    while(!is_empty(copy))
    {
        if(peek(copy) <= peek(stack) || is_empty(stack)){
            push(stack, pop(copy));
            continue;
        }
        else //this means that the value we want to place is larger then the current top val of stack
        {
            while(peek(stack) < peek(copy) && !is_empty(stack)) //while top value of temp is larger than top value of stack
            {
                push(temp, pop(stack)); //take off the large value on the stack and put it back in temp, keep doing this until otherwise
            }
            push(stack, pop(copy)); // at this point the top value of copy is smaller then the top value of the stack
            //and now we push back, at each iteration we have to make usre our "temp" is empty
            while(!is_empty(temp)){
                push(stack,pop(temp));
            }
        }
    }

}

void test_stack_stort(){
    stack_int * my_stack = create_stack(10);
    push(my_stack, get_random_int(100));
    push(my_stack, get_random_int(100));
    push(my_stack, get_random_int(100));
    push(my_stack, get_random_int(100));
    push(my_stack, get_random_int(100));
    push(my_stack, get_random_int(100));
    push(my_stack, get_random_int(100));
    push(my_stack, get_random_int(100));
    sort(my_stack);
    int l = my_stack->top;
    for(int i=0; i<=l; i++){
        printf("%d\n",pop(my_stack));
    }
    
}

