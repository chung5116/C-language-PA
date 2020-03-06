#include<stdio.h>

int main() {
	int num =0;
	long long int f0 = 0;
	long long int f1 = 1;
	long long int fx = 0;
	printf("Enter number: ");
	scanf_s("%d", &num);
	if (num == 1)
		printf("%dst Fibonacci number is: 1",num);
	else if (num != 1) {
		for (int i = 0; i < num - 1; i++) {
			fx = f1 + f0;
			f0 = f1;
			f1 = fx;
			
		}
		printf("%dth Fibonacci number is: %lli", num, fx);
	}

	return 0;
}