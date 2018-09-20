#include "maths.h"
int RAND_ON = 0; // only global var, fix later lol
void rotate_matrix() //for the command line input
{
    int m = get_random_int(10) + 1; //from 1 - 10, no zeros so we added 1
    int n = get_random_int(10) + 1; //we are getting our random size rows and cols
    int max_value = 2;
    int** matrix = create_random_matrix(m, n, max_value);
    printf("Original:\n");
    display_matrix(matrix, m, n);
    printf("\n");
    //rotate it
    int** matrix_new = create_random_matrix(n, m, max_value);
    for(int i=0; i<n; i++) // to number of rows
    {
        for(int j=0; j<m; j++) //to number of cols
        {
            matrix_new[i][j] = matrix[m-1-j][i];
        }
    }
    printf("\nRotated by 90 degrees:\n");
    display_matrix(matrix_new, n, m);
    destroy_matrix(matrix, m);
    destroy_matrix(matrix_new, n);
}
int **create_random_matrix(int m, int n, int max_value)
{
    int **matrix = (int **)malloc(m * sizeof(int *));  //we create an array of pointer of size m (number of rows)
    for (int i=0; i<m; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int)); //now we allocate memory for each row (the number of cols), each pointer in our array of pointers will now point to "n" number of integers in memory 
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            matrix[i][j] = get_random_int(max_value); //random value from 0 to max (exclusive)
        }
    }
    return matrix;
}

void display_matrix(int** matrix, int m, int n)
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
           printf("%d, ", matrix[i][j]); 
        }
        printf("\n");
    }
}

/* 
* get_random_int
* this will return a number from 0 -> n
* exclusive, will never give back n
*/
int get_random_int(int n)
{
    if(RAND_ON == 0){
        srand(time(NULL));
        RAND_ON = 1;
    }
    return (rand() % n);
}

void destroy_matrix(int** matrix, int m){
    for (int i = 0; i < m; i++)
    {
        int* currentIntPtr = matrix[i];
        free(currentIntPtr);
    }
}