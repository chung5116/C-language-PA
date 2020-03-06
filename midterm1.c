#include<stdio.h>
#include<string.h>
#include "FileHandler.h"


int main() {
	char* str = readAllTextFromFile("./input.txt");
	int herechar = 0;
	int temp = 0;
	char numchar[10];
	while (str[herechar] != '\0') {
		temp = 0;
		while( str[herechar] != '\n'&& str[herechar] != '\0') {
			numchar[temp] = str[herechar];
			temp++;
			herechar++;
		}
		herechar++;
		int num = atoi(numchar);
		long long int f0 = 0;
		long long int f1 = 1;
		long long int fx = 0;
		printf("Enter number: %d\n",num);
		if (num >= 0) {
			if(num==0)
				printf("0st Fibonacci number is: 0\n\n");
			if (num == 1)
				printf("1st Fibonacci number is: 1\n\n");
			else if (num != 1) {
				for (int i = 0; i < num - 1; i++) {
					fx = f1 + f0;
					f0 = f1;
					f1 = fx;

				}
				printf("%dth Fibonacci number is: %lli\n\n", num, fx);
			}
		}
		else {
			printf("invalid input\n");
		}
	}
	system("PAUSE");
	return 0;
}