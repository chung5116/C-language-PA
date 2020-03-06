#include<stdio.h>
#include<malloc.h>

void swap(float **p,int j) {
	float tmp = p[j][0];
	p[j][0] = p[j + 1][0];
	p[j + 1][0] = tmp;

	tmp = p[j][1];
	p[j][1] = p[j + 1][1];
	p[j + 1][1] = tmp;
}


int main() {
	int num = 0;
	float** points;
	printf("Enter number of points: ");
	scanf_s("%d", &num);
	if (num <= 0 || num > 10) {
		printf("invalid number of points");
		return;
	}
	points = (float**)malloc(num*sizeof(float));
	for (int i = 0; i < num; i++) {
		points[i] = (float*)malloc(2 * sizeof(float));
	}
	for (int i = 0; i < num; i++) {
		scanf_s("%f%f", &points[i][0], &points[i][1]);
	}

	for (int i = 0; i < num - 1; i++) {
		for (int j = 0; j < num - 1 - i; j++) {
			if (points[j][0] > points[j + 1][0]) {
				swap(points, j);
			}
		}
	}
	for (int i = 0; i < num - 1; i++) {
		for (int j = 0; j < num - 1 - i; j++) {
			if (points[j][0] == points[j + 1][0]) {
				if (points[j][1] > points[j + 1][1]) {
					swap(points, j);
				}
			}
		}
	}



	printf("\n");
	for (int i = 0; i < num; i++) {
		printf("%.2f %.2f\n", points[i][0], points[i][1]);
	}
	return 0;
}