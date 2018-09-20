#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
struct node_h{
    int key;
    int val;
    struct node_h *next;
};
struct table{
    int size;
    struct node_h **list;
};

struct table *createTable(int size){
    struct table *t = (struct table*)malloc(sizeof(struct table));
    t->size = size;
    t->list = (struct node_h**)malloc(sizeof(struct node_h*)*size);
    int i;
    for(i=0;i<size;i++)
        t->list[i] = NULL;
    return t;
}
int hashCode(struct table *t,int key){
    if(key<0) //negative case
        return -(key%t->size);
    return key%t->size;
}

void insertH(struct table *t,int key,int val){

    //to see if it already exists
    int pos = hashCode(t,key); //we give our key and corresponfing value and get the index we can put it in our array
    struct node_h *list = t->list[pos]; //node_h at that index
    struct node_h *temp = list; //temp is the node_h at our index
    while(temp){ // while temp isnt null
        if(temp->key==key){ //if that nodes key is our key, replace the value carrying
            temp->val = val;
            return;
        }
        temp = temp->next;
    }



    struct node_h *newNode = (struct node_h*)malloc(sizeof(struct node_h)); //create a new node_h
    newNode->key = key; //else we create our new Node
    newNode->val = val;
    newNode->next = list;
    t->list[pos] = newNode;
}


int lookup(struct table *t,int key){
    int pos = hashCode(t,key);
    struct node_h *list = t->list[pos];
    struct node_h *temp = list;
    while(temp){
        if(temp->key==key){
            return temp->val;
        }
        temp = temp->next;
    }
    return -1;
}

void hash_map(){
    struct table *t = createTable(5);
    insertH(t,2,3);
    insertH(t,5,4);
    insertH(t,5,5);
    printf("%d\n",lookup(t,5));
    printf("%d\n",lookup(t,2));
}