#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include "FileHandler.h"


struct node {
	int key;
	bool ismark;
};

struct node bingo[5][5];

bool  isbingo(int after) {
	bool isbingo = true;
	//¾î
	for (int i = 0; i < 5; i++) {
		isbingo = true;
		if (i != 2) {
			for (int j = 0; j < 5; j++) {
				if (bingo[i][j].ismark == false) {
					isbingo = false;
					break;
				}
			}
		}
		else {
			for (int j = 0; j < 2; j++) {
				if (bingo[i][j].ismark == false) {
					isbingo = false;
					break;
				}
			}
			for (int j = 3; j < 5; j++) {
				if (bingo[i][j].ismark == false) {
					isbingo = false;
					break;
				}
			}
			if (isbingo == true) {
				printf("Bingo after %d numbers announced", after+1);
				return true;
			}
		}
		if (isbingo == true) {
			printf("Bingo after %d numbers announced", after);
			return true;
		}
	}

	//ª½
	for (int j = 0; j < 5; j++) {
		isbingo = true;
		if (j != 2) {
			for (int i = 0; i < 5; i++) {
				if (bingo[i][j].ismark == false) {
					isbingo = false;
					break;
				}
			}
		}
		else {
			for (int i = 0; i < 2; j++) {
				if (bingo[i][j].ismark == false) {
					isbingo = false;
					break;
				}
			}
			for (int i = 3; i < 5; j++) {
				if (bingo[i][j].ismark == false) {
					isbingo = false;
					break;
				}
			}
			if (isbingo == true) {
				printf("Bingo after %d numbers announced", after + 1);
				return true;
			}
		}
		if (isbingo == true) {
			printf("Bingo after %d numbers announced", after);
			return true;
		}
	}

	//¾î
	isbingo = true;
	for (int k = 0; k < 5; k++) {
		if (k != 2) {
			if (bingo[k][k].ismark == false) {
				isbingo = false;
				break;
			}
		}
	}
	if (isbingo == true) {
		printf("Bingo after %d numbers announced", after+1);
		return true;
	}
	isbingo = true;
	for (int k = 4; k >= 0; k--) {
		if (k != 2) {
			if (bingo[k][k].ismark == false) {
				isbingo = false;
				break;
			}
		}
	}
	if (isbingo == true) {
		printf("Bingo after %d numbers announced", after + 1);
		return true;
	}
	return false;

}


int afterhowmanynum = 0;

bool marknumber(int data[50], int howmaydata) {
	for (int i = 0; i < howmaydata; i++) {
		int key = data[i];
		afterhowmanynum++;
		if (key > 0 && key < 16) {
			for (int j = 0; j < 5; j++) {
				if (bingo[j][0].key == key) {
					bingo[j][0].ismark = true;
				}
			}
		}
		else if (key > 15 && key < 31) {
			for (int j = 0; j < 5; j++) {
				if (bingo[j][1].key == key) {
					bingo[j][1].ismark = true;
				}
			}
		}
		else if (key > 30 && key < 46) {
			for (int j = 0; j < 5; j++) {
				if (bingo[j][2].key == key) {
					bingo[j][2].ismark = true;
				}
			}
		}
		else if (key > 45 && key < 61) {
			for (int j = 0; j < 5; j++) {
				if (bingo[j][3].key == key) {
					bingo[j][3].ismark = true;
				}
			}
		}
		else if (key > 60 && key < 76) {
			for (int j = 0; j < 5; j++) {
				if (bingo[j][4].key == key) {
					bingo[j][4].ismark = true;
				}
			}
		}
		if (isbingo(afterhowmanynum)) {
			return true;
		}
	}
	return false;
}



int main() {
	char buffer[100];
	int howmaydata = 0;
	int temp = 0;
	int row = 0;
	errno_t err;
	FILE* fp;
	err = fopen_s(&fp, "input.txt", "r");
	if (!fp) {
		printf("Error opening file");
		return;
	}
	while (!feof(fp)) {
		//fread(buffer, 100, fp);
		fgets(buffer, 100, fp);
		temp = 0;
		howmaydata = 0;
		int data[50];
		while (buffer[temp] != '\0') {			//¤@¦æ
			int intemp = 0;
			char numchar[4];
			while (buffer[temp] != ' ' && buffer[temp] != '\n') {
				numchar[intemp] = buffer[temp];
				intemp++;
				temp++;
			}
			numchar[intemp] = '\0';
			temp++;
			data[howmaydata] = atoi(numchar);
			howmaydata++;
		}
		if (row < 5) {
			for (int j = 0; j < howmaydata; j++) {
				if (row == 2) {
					if (j >= 2) {
						bingo[row][j + 1].key = data[j];
						bingo[row][j + 1].ismark = false;
						bingo[row][2].ismark = false;
						bingo[row][2].key = -1;
					}
					else {
						bingo[row][j].key = data[j];
						bingo[row][j].ismark = false;
					}
				}
				else {
					bingo[row][j].key = data[j];
					bingo[row][j].ismark = false;
				}
			}
		}
		else {
			if (marknumber(data, howmaydata)) {
				break;
			}
		}
		row++;
	}

	system("PAUSE");
	return 0;
}