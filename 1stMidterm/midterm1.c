#include<stdio.h>


int main() {
	int layer = 0;
	printf("Enter layer: ");
	scanf_s("%d", &layer);
	if (layer <= 0) {
		printf("invalid input");
		return;
	}
	int x = 0;
	for (int i = layer; i != 0; i--) {
		for (int k = 0; k < x; k++) {
			printf(" ");
		}
		x++;
		for (int k = 0; k < 2 * i - 1; k++) {
			printf("*");
		}
		printf("\n");
	}






	return 0;
}