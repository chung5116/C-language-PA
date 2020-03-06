#include<stdio.h>
#include"FileHandler.h"
#include<string.h>
#include<stdbool.h>
#include<math.h>


int main() {
	char *str = readAllTextFromFile("./love.txt");
	char number[30];
	int where = 0;
	for (; str[where] != '\n'; where++) {
		number[where] = str[where];
	}
	where++;
	int number_int = atoi(number);
	for (int i = 1; i <= number_int; i++) {
		char s1[30];
		char s2[30];
		int num1 = 0;
		int num2 = 0;
		int tmp = 0;
		bool con = true;
		for (; str[where] != '\n'; where++) {
			if (str[where] != '0' && str[where] != '1') {
				printf("Pair #%d:Love is not all you need!\n", i);
				con = false;
				break;
			}
			s1[tmp] = str[where];
			tmp++;
		}
		if (con == true) {
			s1[tmp] = '\0';
			int howmanyS1 = tmp;
			where++;
			tmp = 0;
			for (; str[where] != '\n'&& str[where] != '\0'; where++) {
				if (str[where] != '\0') {
					if (str[where] != '0' && str[where] != '1') {
						printf("Pair #%d:Love is not all you need!\n", i);
						con = false;
						break;
					}
				}
				s2[tmp] = str[where];
				tmp++;
			}
			if (con == true) {
				s2[tmp] = '\0';
				if (s1[0] == '0' || s2[0] == '0') {
					printf("Pair #%d:Love is not all you need!\n", i);
					con = false;
					break;
				}
				int howmanyS2 = tmp;
				where++;
				if (con == true) {
					int tobemub = 0;
					for (int i = howmanyS1 - 1; i >= 0; i--) {
						num1 = num1 + (int)(s1[i] - '0')*pow(2, tobemub);
						tobemub++;
					}
					tobemub = 0;
					for (int i = howmanyS2 - 1; i >= 0; i--) {
						num2 = num2 + (int)(s2[i] - '0')*pow(2, tobemub);
						tobemub++;
					}
					int kkk;
					if (num1 <= num2) {
						kkk = num1;
					}
					else {
						kkk = num2;
					}

					int node = 2;
					bool love = false;
					while (node != kkk + 1) {
						if (num1%node == 0 && num2%node == 0) {
							printf("Pair #%d:All you need is love!\n", i);
							love = true;
							break;
						}
						node++;
					}
					if (love == false) {
						printf("Pair #%d:Love is not all you need!\n", i);
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}