#ifndef LINKED_H
#define LINKED_H
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "maths.h"
typedef struct node {
  int val;
  struct node *next;
}node_int;
void linked_list_menu();
void print_list(node_int * head);
int get_length(node_int * head);
node_int * add_node(node_int * head, int val);
node_int * delete_node(node_int * head);
node_int * create_random_list();
#endif /* LINKED_H */
