#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

char map[100][100] = { 0 };
void findrecursive(int row, int col, int length, int rangerow, int rangecol);

void createmap(char buffer[100],int line,int colnum) {
	for (int i = 0; i < colnum; i++) {
		map[line][i] = buffer[i];
	}
}

void find(int row, int col,int rangerow,int rangecol) {
	bool iscontinue = true;
	char middle = map[row][col];
	//
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if (row + i<0 && row + i>rangerow && col + j<0 && col + j>rangecol) {
				iscontinue = false;
				break;
			}
			else if (map[row + i][col + j] != middle) {
				iscontinue = false;
				break;
			}
		}
	}
	if (iscontinue == false) {
		printf("1\n");
		return;
	}
	else {
		findrecursive(row, col, 3, rangerow, rangecol);  
	}

}


void findrecursive(int row, int col, int length, int rangerow, int rangecol) {   //成功  失敗直接印
	bool iscontinue = true;
	char middle = map[row][col];
	int x = (length / 2) + 1;
	for (int i = -x; i <= x; i++) {
		for (int j = -x; j <= x; j++) {
			if (row + i<0 && row + i>rangerow && col + j<0 && col + j>rangecol) {
				iscontinue = false;
				break;
			}
			else if (map[row + i][col + j] != middle) {
				iscontinue = false;
				break;
			}
		}
	}
	if (iscontinue == false) {
		printf("%d\n",length);
		return;
	}
	else {
		findrecursive(row, col, length+2, rangerow, rangecol);
	}
}


int main() {
	char buffer[100];
	FILE*fp;
	int err = fopen_s(&fp, "input.txt", "r");
	int nomatter;
	int rownum, colnum, testnum;
	int test1, test2;
	fscanf_s(fp, "%d", &nomatter);
	for (int k = 0; k < nomatter;k++) {
		fscanf_s(fp, "%d %d %d", &rownum, &colnum, &testnum);
		printf("%d %d %d\n", rownum, colnum, testnum);
		fgets(buffer, 100, fp);
		for (int i = 0; i < rownum; i++) {
			fgets(buffer, 100, fp);
			//fscanf_s(fp, "%s", buffer);
			createmap(buffer, i, colnum);
		}
		for (int i = 0; i < testnum; i++) {
			fscanf_s(fp, "%d %d", &test1, &test2);
			find(test1, test2, rownum, colnum);
		}
	}

	system("PAUSE");
}