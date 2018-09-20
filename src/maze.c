#include "maze.h"

char** create_matrix(char* file_name, int ROW, int COL) //will return to us a pointer to other char pointers
{
    //create our blank 2D-array of chars
    char** maze=malloc(ROW*sizeof(char*)); //make all lists in lists
    for(int i=0; i<ROW; ++i)
    {
        maze[i] = malloc(COL*sizeof(double)); //allocate the number of items in the lists created
    }

    FILE *file;
    file=fopen(file_name, "r");

    for(int i=0; i<ROW; i++)
    {
        for(int j=0; j<COL; j++) 
        {
            if (!fscanf(file, "%c", &maze[i][j])) //once we cant do this, we will break
            {
                break;
            }
            //printf("%c", maze[i][j]); //Use lf format specifier, \n is for new line
        }
        //printf("\n");
    }
    fclose(file);
    return maze;
}

void print_matrix (char** matrix, int ROW, int COL)
{
    printf("\n");
    for (int r=0; r<ROW; r++)
    {
        for (int c=0; c<COL; c++)
        {
            printf("%c", matrix[r][c]);
        }
    }
    printf("\n");
    printf("\n");
}

int solve_maze(char ** maze, int x, int y){
    //our directions
    char right = maze[x][y+1];
    char left = maze[x][y-1];
    char up = maze[x-1][y];
    char down = maze[x+1][y];

    if(maze[x][y] != 'S')
    {
        maze[x][y] = '.';
        printf("went to=> %d, %d\n", x, y);
    }

    if(right == 'G' || left == 'G' || up == 'G' || down == 'G')
    {
        return 1;
    }
    
    int solved = 0;
    if(right == ' ' && !solved)
    {
        solved = solve_maze(maze, x, y+1);
    }
    if(left == ' ' && !solved)
    {
        solved = solve_maze(maze, x, y-1);
    }
    if(up == ' ' && !solved)
    {
        solved = solve_maze(maze, x-1, y);
    }
    if(down == ' ' && !solved)
    {
        solved = solve_maze(maze, x+1, y);
    }
    return solved;
}

void test_maze()
{
    //my hardcoded ness
    const int ROW = 11;
    const int COL = 11;
    int start_x = 2;
    int start_y = 2;
    char * file_name = "../res/maze2.txt";


    char** maze = create_matrix(file_name, ROW, COL);
    printf("\nDONE READING IN MAZE\n");
    print_matrix(maze, ROW, COL);
    solve_maze(maze,start_x, start_y);
    print_matrix(maze, ROW, COL);
}