#include "quicksort.h"
void swap(int * array, int left, int right)
{
    int temp = array[left];
    array[left] = array[right];
    array[right] = temp;
}

int partition(int * array, int left, int right)
{
    int pivot = array[(left+right)/2];
    while(left <= right){
        while(array[left] < pivot){left++;}
        while(array[right] > pivot){right--;}
        //this will get through our "sorted part"
        if(left <= right){
            swap(array, left, right);
            left++;
            right--;
        }
    }
    return left;
}

void quick_sort(int * array, int left, int right)
{
    int index = partition(array, left, right);
    //if left is less than index, sort left
    if(left < index -1)
    {
        quick_sort(array, left, index-1);
    }
    if(index < right)
    {
        quick_sort(array, index, right);
    }
    //if right is less than index, sort right
}


void q1sort()
{
    int size = 7;
    int array[7] = {1,2,5,0,3,4,9};
    quick_sort(array, 0, size-1);
    for(int i=0; i<size; i++)
    {
        printf("%d\n", array[i]);
    }
}

