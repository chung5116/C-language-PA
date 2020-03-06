#include<stdio.h>


int main() {
	int firstmatrix[3][3];
	int secondmatrix[3][3];
	int mutiple[3][3] = { 0 };
	int i = 0;
	int j = 0;
	int k = 0;
	printf("The first matrix :\n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			scanf_s("%d", &firstmatrix[i][j]);
		}
	}
	printf("The second matrix :\n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			scanf_s("%d", &secondmatrix[i][j]);
		}
	}
	printf("The mutiple result is : \n");
	for (k = 0; k < 3; k++) {
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				mutiple[k][i] = mutiple[k][i] + (firstmatrix[k][j])*(secondmatrix[j][i]);
			}
		}
	}
	for (k = 0;k < 3; k++) {
		for (i = 0; i < 3; i++) {
			if (mutiple[k][i] >= 100) {
				printf("%d ", mutiple[k][i]);
			}
			else if (mutiple[k][i] >= 10) {
				printf("0%d ", mutiple[k][i]);
			}
			else if (mutiple[k][i] >=0) {
				printf("00%d ", mutiple[k][i]);
			}
		}
		printf("\n");
	
	}
	return 0;
}