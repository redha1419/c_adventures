#ifndef MATHS_H
#define MATHS_H
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void rotate_matrix();
int** create_random_matrix(int m, int n, int max_value);
void display_matrix(int** matrix, int m, int n);
int get_random_int(int n);
void destroy_matrix(int** matrix, int m);
#endif /* MATHS_H */

