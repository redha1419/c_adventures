#include "linked.h"

void loop_detection();

void linked_list_menu(){
    int input = 0;
    node_int * head = NULL;
    printf("Hello welcome to linked lists!\n");
    while(input != 1668){
        printf("\n");
        printf("1. Print your current list!\n");
        printf("2. Add a node!\n");
        printf("3. Delete a node!\n");
        printf("4. Run a loop detection scenario!\n");
        printf("What would you like to do? ");
        scanf("%d", &input);
        printf("\n");
        int val; // for adding the node
        switch(input){
            case 1:
                print_list(head);
                break;
            case 2:
                printf("Number to add: ");
                scanf("%d",&val);
                head = add_node(head, val);
                break;
            case 3:
                head = delete_node(head);
                break;
            case 4:
                loop_detection();
                break;
            default:
                break;  
        }
    }
    //auto detroy at the end
    free(head);
}

int detect_bad_node(node_int * head){

    /* SUMMARY
    * we wil move fast ptr twice as fast as slow ptr
    * when slow ptr gets into the loop, fast ptr will be k nodes in the loop
    * therfore this means slow ptr is the (loop size - k) nodes from fast ptr
    * and meaning after we iterate (loop size - k) times they will meet at k nodes from the start of the loop
    * then we reset our slow ptr and go k times in the list and will collide with fast ptr again
    * thus we know the start of our loop
    */

    node_int * slow = head;
    node_int * fast = head;
    while(fast != NULL && fast->next != NULL){ //if head points to null or is null, list has finished, no loop
        slow = slow->next; //iterate first pointer
        fast = fast->next->next; //iterate second pointer twice 
        //boom they have collided
        if(slow == fast){// with enough iterations in a loop, someone who steps twice will eventually hit the person stepping once (like lapping in racing)
            break;
        }
    }

    //no meeting point, have gotten to the last node
    if(fast == NULL || fast->next == NULL){
        return -1; //to return if there is no loop
    }

    slow = head; //make one node from start
    int count = 0;
    while(slow != fast){ //while they havent reached each other
        slow = slow->next;
        count++;
        fast = fast->next;
    }
    return count;
}

//this needs to be refactored
void loop_detection(){
    //first lets create a random list
    node_int * head = create_random_list();
    
    //now we have to randomly and deliberatey make a node point to another
    int length = get_length(head);
    int bad_node = get_random_int(length); //will give us an index pos of our bad node [1,length)
    int bad_node_accomplist = get_random_int(bad_node)+1;
    //assuming first node cant be wrong lol , and not to length as our indices start from pos 0, and point back
    printf("now index %d points to index %d\n", bad_node, bad_node_accomplist);
    int pos = 0;
    node_int * itr_node_bad = head;
    node_int * itr_node_accomplist = head;
    while (pos < bad_node){itr_node_bad = itr_node_bad->next;pos++;} // assuming this will never be a null pointer
    pos = 0;
    while (pos < bad_node_accomplist){itr_node_accomplist = itr_node_accomplist->next;pos++;} // assuming this will never be a null pointer
    //now we have the bad node and its accomplist, lets do our magic
    itr_node_bad->next = itr_node_accomplist;
    //print_list(head);
    //boom now we have a list that has a infinite loop in it, now how can we detect it
    int bad_node_found = detect_bad_node(head);
    printf("%d is the created bad node index\n", bad_node_accomplist);
    printf("%d is the found bad node index\n", bad_node_found);
    if(bad_node_found == bad_node_accomplist)
    {
        printf("success");
    }else{
        printf("mission failed... we will get'em next time");
    }
    free(head);
}

node_int * create_random_list(){
    node_int * head = NULL;
    int length = get_random_int(10) + 1; //[1, 10]
    for(int i=0; i<length; i++){
        head = add_node(head, get_random_int(10));
    }
    printf("\n the randomly generated list is:\n");
    print_list(head);
    return head;
}


//private function not in header, only for this particular code to use for adding nodes only
node_int * create_node(int val){
    node_int * new_node = (node_int *)malloc(sizeof(node_int));
    new_node->next = NULL;
    new_node->val = val;
    return new_node;
}

node_int * add_node(node_int * head, int val){
    if(head == NULL){
        head = create_node(val);
    }else{
        //head will always be head, lets append to the tail
        node_int * itr_node = head;
        while(itr_node->next != NULL){itr_node = itr_node->next;}
        //initialization of our new node
        itr_node->next = create_node(val);
    }
    return head;
}

node_int * delete_node(node_int * head){
    if(head == NULL)
    {
        printf("List is empty \n");
    }
    else
    {
        //head will always be head, lets remove from the tail
        node_int * itr_node = head;
        if(itr_node->next == NULL){ //only one in there
            return NULL;
        }
        while(itr_node->next->next != NULL){itr_node = itr_node->next;}
        free(itr_node->next); //remove any memory assigned to it
        itr_node->next = NULL; //should be removed and assigned to NULL
    }
    return head;
}


void print_list(node_int * head){
    if(head == NULL)
    {
        printf("List is empty \n");
    }
    node_int * itr_node = head;
    while (itr_node != NULL) 
    {
        printf("%d\n", itr_node->val);
        itr_node = itr_node->next;
    }
}

int get_length(node_int * head){
    if(head == NULL)
    {
        return 0;
    }
    node_int * itr_node = head;
    int length = 0;
    while (itr_node != NULL) {length ++;itr_node = itr_node->next;}
    return length;
}