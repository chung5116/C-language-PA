#include<stdio.h>
#include<string.h>
#include "FileHandler.h"


int main() {
	char* str = readAllTextFromFile("./input.txt");
	int herechar = 0;
	int temp = 0;
	while (str[herechar] != '\0') {		
		temp = 0;
		char in[15];
		while (str[herechar] != '\n' && str[herechar] != '\0') {
			in[temp] = str[herechar];
			temp++;
			herechar++;
		}
		if (temp <= 15) {
			in[temp] = '\0';
			herechar++;
			printf("Enter phone number: %s\n", in);
			int i = 0;
			while (in[i] != '\0') {
				if (in[i] >= 48 && in[i] <= 57) {
					printf("%c", in[i]);
				}
				else if (in[i] == 'A' || in[i] == 'B' || in[i] == 'C') {
					printf("2");
				}
				else if (in[i] == 'D' || in[i] == 'E' || in[i] == 'F') {
					printf("3");
				}
				else if (in[i] == 'G' || in[i] == 'H' || in[i] == 'I') {
					printf("4");
				}
				else if (in[i] == 'J' || in[i] == 'K' || in[i] == 'L') {
					printf("5");
				}
				else if (in[i] == 'M' || in[i] == 'N' || in[i] == 'O') {
					printf("6");
				}
				else if (in[i] == 'P' || in[i] == 'R' || in[i] == 'S') {
					printf("7");
				}
				else if (in[i] == 'T' || in[i] == 'U' || in[i] == 'V') {
					printf("8");
				}
				else if (in[i] == 'W' || in[i] == 'X' || in[i] == 'Y') {
					printf("9");
				}
				else if (in[i] == '-') {
					printf("%c", in[i]);
				}
				else {
					printf("invalid phone number\n\n");
					break;
				}
				i++;
			}
			printf("\n\n");
		}
		else {
			printf("invalid phone number\n\n");
		}
	}

	system("PAUSE");
	return 0;
}