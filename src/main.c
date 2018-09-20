#include "maths.h"
#include "linked.h"
#include "stack.h"
#include "queue.h"
#include "quack.h"
#include "binary_tree.h"
#include "maze.h"
#include "hash.h"
#include "quicksort.h"
int main( int argc, const char* argv[] ) //for the command line input
{
    int input;
    printf( "Hello World!\n\n" );
    printf( "Welcome to Reza's C adventures! These mini programs may include simple sorting algorithms to complicated ML and Neural Network examples:\n" );
    //The list of activites:
    printf("1. Let's rotate a matrix!\n");
    printf("2. Lets have have fun with Linked Lists \n");
    printf("3. Lets have have fun with Stacks \n");
    printf("4. Lets have have fun with Queues \n");
    printf("5. just run a quick quack test \n");
    printf("6. Go to tree menu \n");
    printf("7. Maze runner \n");
    printf("E -> Exit\n");
    printf("What would you like to do? ");
    scanf("%d", &input);
    printf("\n");
    switch(input){
        case 1:
            rotate_matrix();
            break;
        case 2:
            linked_list_menu();
            break;
        case 3:
            test_stack_stort();
            break;
        case 4:
            test_queue();
            break;
        case 5:
            test_quack();
            break;
        case 6:
            trees_menu();
            break;
        case 7:
            test_maze();
            break;
        case 8:
            hash_map();
            break;
        case 9:
            q1sort();
            break;
        default:
            break;  
    }
    return EXIT_SUCCESS;
}
