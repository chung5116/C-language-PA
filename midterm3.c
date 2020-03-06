#include<stdio.h>
#include<string.h>
#include "FileHandler.h"


int main() {
	char* str = readAllTextFromFile("./input.txt");
	int herechar = 0;
	int temp1 = 0;
	int temp2 = 0;

	while (str[herechar] != '\0') {
		char numchar[10];
		char in[81];
		temp1 = 0;
		temp2 = 0;
		while (str[herechar] != '\n' && str[herechar] != '\0') {
			in[temp1] = str[herechar];
			temp1++;
			herechar++;
		}
		in[temp1] = '\0';
		herechar++;
		while (str[herechar] != '\n' && str[herechar] != '\0') {
			numchar[temp2] = str[herechar];
			temp2++;
			herechar++;
		}
		numchar[temp2] = '\0';
		herechar++;
		if (temp1 <= 80) {
			int shiftamount = atoi(numchar);
			if (shiftamount <= 26 && shiftamount > 0) {
				printf("Enter message to be encrypted: %s\n", in);
				printf("Enter shift amount(1~26): %d\n",shiftamount);

				int i = 0;
				while (in[i] != '\n' && in[i] != '\0') {
					if ((122 >= in[i] && in[i] >= 97)) {
						if (in[i] + shiftamount > 122) {
							printf("%c", 97 + in[i] + shiftamount - 122 - 1);
						}
						else {
							printf("%c", in[i] + shiftamount);
						}
					}
					else if (90 >= in[i] && in[i] >= 65) {
						if (in[i] + shiftamount > 90) {
							printf("%c", 65 + in[i] + shiftamount - 90 - 1);
						}
						else {
							printf("%c", in[i] + shiftamount);
						}
					}
					else {
						printf("%c", in[i]);
					}
					i++;
				}
				printf("\n\n");
			}
			else {
				printf("Cipher Error\n\n");
			}
		}
		else {
			printf("Cipher Error\n\n");
		}
	}

	system("PAUSE");
	return 0;
}