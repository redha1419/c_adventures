#include "reverse_string.h"

void recursive_reverse(char *str){
    if(*str){
        recursive_reverse(str + 1);
        printf("%c", *str); 
    }
}

void reverse_string(){
   char a[] = "reza shahriari"; 
   recursive_reverse(a); 
}

