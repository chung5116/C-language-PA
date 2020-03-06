#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "FileHandler.h"



void solveMaze(char** maze, int width) {
	int** wasHere = (int**)malloc(width * sizeof(int*));
	int** correctPath = (int**)malloc(width * sizeof(int*));
	int startRow ;
	int startCol = 0;					//開始
	int endRow ;
	int endCol = width - 1;				//結束

	for (int i = 0; i < width; i++) {
		wasHere[i] = (int*)malloc(width * sizeof(int));
		correctPath[i] = (int*)malloc(width * sizeof(int));
	}
	for (int i = 0; i < width; i++) {						//初始化
		for (int j = 0; j < width; j++) {
			wasHere[i][j] = 0;
			correctPath[i][j] = 0;
		}
	}

	/*行列跟 x,y坐標軸剛好相反，注意使用*/
	for (int i = 0; i < width; i++) {
		if (maze[i][0] == '.') {
			startRow = i;
		}
	}
	for (int i = 0; i < width; i++) {
		if (maze[i][width - 1] == '.') {
			endRow = i;
		}
	}

	int b = recursiveSolve(maze, wasHere, correctPath, endRow, endCol, startRow, startCol, width);
	if (b) {
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < width; j++) {
				if (correctPath[i][j] == 1) {
					printf("x");
				}
				else
					printf("%c", maze[i][j]);
			}
			printf("\n");
		}
	}
	else {
		printf("This maze has no solution");
	}
	for (int i = 0; i < width; i++) {
		free(wasHere[i]);
		free(correctPath[i]);
	}
	free(wasHere);
	free(correctPath);
}

int recursiveSolve(char** maze, int** wasHere, int** correctPath, int endRow, int endCol, int Row, int Col, int width) {
	if (Row == endRow && Col == endCol) {
		maze[Row][Col] = 'x';
		return 1;				//if reach the end
	}
	if (maze[Row][Col] == '#' || wasHere[Row][Col]) return 0;				//if you are on a wall

	wasHere[Row][Col] = 1;

	if (recursiveSolve(maze, wasHere, correctPath, endRow, endCol, Row - 1, Col, width)) {
		correctPath[Row][Col] = 1;
		return 1;
	}
	if (recursiveSolve(maze, wasHere, correctPath, endRow, endCol, Row + 1, Col, width)) {
		correctPath[Row][Col] = 1;
		return 1;
	}
	if (recursiveSolve(maze, wasHere, correctPath, endRow, endCol, Row, Col - 1, width)) {
		correctPath[Row][Col] = 1;
		return 1;
	}
	if (recursiveSolve(maze, wasHere, correctPath, endRow, endCol, Row, Col + 1, width)) {
		correctPath[Row][Col] = 1;
		return 1;
	}
	return 0;
}



int main() {
	char* str = readAllTextFromFile("./maze1.txt");
	int width = 0;
	while (str[width] != '\n') {				//row  = 寬度
		width++;
	}
	char** maze = (char**)malloc(width * sizeof(char*));	//bulid maze 二維動態矩陣
	for (int i = 0; i < width; i++) {
		maze[i] = (char*)malloc(width * sizeof(char));
	}

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < width; j++) {
			maze[i][j] = str[13 * i + j];
		}
	}
	solveMaze(maze, width);

	for (int i = 0; i < width; i++) {
		free(maze[i]);
	}
	free(maze);

	system("PAUSE");
	return 0;
}