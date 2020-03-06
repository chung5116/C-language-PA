#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DOWN 0 /*signal down move*/
#define RIGHT 1 /*signal right move*/
#define UP 2 /*signal up move*/
#define LEFT 3 /*signal left move*/

#define POSSIBLE_ZEROS 100 /*global value to cap the loops in the mazeGenerator function. Too many loops and it will create an open room*/

  /*declare the function prototypes*/
void mazeTraversal(char maze[12][12], int xCoord, int yCoord, int xStart2, int yStart2, int direction, int MovCount); /*recursive function to walkthrough the maze and account for random generation entry and exit points*/
int edges(int x, int y); /*function to check the surrounding for walls*/
int validMove(const char maze[][12], int r, int c); /*function to signal an opening valid move */

void mazeGenerator(char maze[][12], int* xPtr, int* yPtr); /*maze generator function with pointers to modify the array elements*/


int main(void){
	int x, y, i, j;

	char maze[12][12]; /*initialize the maze */
	for (i = 0; i < 12; i++) { 
		for (j = 0; j < 12; j++) { 
			maze[i][j] = '#'; 
		}
	}
	
	int xStart; //initialize the starting point 
	int yStart;
	mazeGenerator(maze, &xStart, &yStart);

	/*
	x = xStart;
	y = yStart;

	printf("\n\n\n\n\n");
	mazeTraversal(maze, x, y, xStart, yStart, RIGHT, 1); //一開始向又
	*/
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 12; j++) {
			printf("%c", maze[i][j]);
		}
		printf("\n");
	}
	return 0;  
} 

void mazeTraversal(char maze[12][12], int xCoord, int yCoord, int xStart2, int yStart2, int direction, int MovCount)
{ 
	static int flag = 0; 
	maze[xCoord][yCoord] = 'X';
	if (edges(xCoord, yCoord) && xCoord != xStart2 && yCoord != yStart2) { /*check for successful completion not at the starting coordinates*/
		printf("\n\nMaze successfully exited!!!!\n");
		return;
	} 
	else if (xCoord == xStart2 && yCoord == yStart2 && flag == 1) {
		printf("\n\nArrived back at the starting location\n");
	}
	else { 
		int count;
		int move; 
		flag = 1; /* assign 1 to flag */

		for (move = direction, count = 0; count < 4; count++, move++, move %= 4) { /*for loop to cycle through 0123 (the assigned directions). modulo operator to keep the numbers at 0123 regardless of where the loop starts*/

			switch (move) { 
			case DOWN:
				if (validMove(maze, xCoord + 1, yCoord)) {
					mazeTraversal(maze, xCoord + 1, yCoord, xStart2, yStart2, LEFT, MovCount++); /*if move is valid recursively call mazeTraversal again adding one move "down" on the x value of the array and starting with the next direction to the right (clockwise)*/
					return; /*return control to main function when recursion is finished to avoid looping back to the start*/
				}
				break; 

			case RIGHT:
				if (validMove(maze, xCoord, yCoord + 1)) { 
					mazeTraversal(maze, xCoord, yCoord + 1, xStart2, yStart2, DOWN, MovCount++); 
					return; 
				} 
				break; 

			case UP:
				if (validMove(maze, xCoord - 1, yCoord)) { 
					mazeTraversal(maze, xCoord - 1, yCoord, xStart2, yStart2, RIGHT, MovCount++);
					return; 
				} 
				break; 
			case LEFT:
				if (validMove(maze, xCoord, yCoord - 1)) { 
					mazeTraversal(maze, xCoord, yCoord - 1, xStart2, yStart2, UP, MovCount++); 
					return; 
				} 
				break; 
			} 
		} 
	}
}

int validMove(const char maze[][12], int r, int c) /*check if a move is valid function (r is x and c is y)*/
{ 
	return (r >= 0 && r <= 11 && c >= 0 && c <= 11 && maze[r][c] != '#'); 
} 

int edges(int x, int y) /* function to check if we have made it to the edge */
{ 
	if ((y == 11) && (x >= 0 && x <= 11)) { /*if statement to check if we reached the top or bottom edge of a column */
		return 1;
	} 
	else {
		return 0; /*if no edge, return false*/
	} 
} 


void mazeGenerator(char maze[][12], int* xPtr, int* yPtr)
{
	int in;
	int out;
	int x, y, j, i;

	srand(time(NULL)); /*seed random number generator*/
	in = 1+rand() % 10; /*generate random numbers between 1 and 4 (four walls) as the starting point */
	out = 1+rand() %10; /*generate random numbers between 1 and 4 (four walls) as the exit point */
	*xPtr = in;
	*yPtr = 0;
	maze[in][0] = '.'; /*assign entry*/
	maze[out][11] = '.';/*assign exit*/


/* Add zeros to maze grid randomly*/
	for (i = 1; i < 70; i++) { /*for loop set to one hundred for the possible number of spaces. fill up the inside of the maze with random points of open space and loop it one hundred times. **NOTE There is a tiny tiny chance that it loops through all the points and creates gets rid of all the walls but that is very very unlikely. Capping the loops keep that possibility slim*/
		x = 1 + rand() % (10);
		y = 1 + rand() % (10);
		maze[x][y] = '.';
	} /*end for loop */

} 