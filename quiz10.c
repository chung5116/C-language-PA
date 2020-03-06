#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<minmax.h>
#include<math.h>
#include"FileHandler.h"

char* cal1(char num1[100], char num2[100], char ops[1], int num1size, int num2size);
char* calculate(char num1[100], char num2[100], char ops[1], int num1size, int num2size);

bool isdigit(char num) {
	if (num == '+' || num == '-') {
		return false;
	}
	return true;
}

bool point(char p) {
	if (p == '.') {
		return true;
	}
	return false;
}

char* convertNumberIntoArray(unsigned int number) {
	char tmp[4];
	for (int i = 3; i>=0; i--) {
		tmp[i] = number % 10;
		number /= 10;
	}
	return tmp;
}


char* cal1(char num1[100], char num2[100], char  ops[1], int num1size, int num2size) {
	int carry = 0;
	int size1 = num1size;
	int tot = num1size;
	int size2 = num2size;
	int times = (int)min(ceil(size1 / 4), ceil(size2 / 4));
	char tmp1[4];
	char tmp2[4];
	char total[100];
	for (int i = 0; i < times; i++) {
		
		char* tmp3;
		for (int x = 3; x >= 0; size1--&&x--) {
			tmp1[x] = num1[size1-1];
		}
		for (int x = 3; x >=0; size2-- && x--) {
			tmp2[x] = num2[size2-1];
		}
		int int1 = atoi(tmp1);
		int int2 = atoi(tmp2);
		if (carry == 1)
			int1 = int1 + 1;
		else if (carry == -1)
			int2 = int2 - 1;
		int int3 = 0;
		if (ops[0] == '+') {						//­pºâ
			int3 = int1 + int2;
		}
		else
			int3 = int1 - int2;
		if (int3 >= 10000) {
			int3 = int3 - 10000;
			carry = 1;
		}
		else if (int3 < 0) {
			int3 = int3 + 10000;
			carry = -1;
		}
		tmp3 = convertNumberIntoArray(int3);
		for (int k = 3; k >= 0; k--&&tot--) {
			total[tot] = tmp3[k];
		}
		tot--;
		carry = 0;
	}
	if (size1 > 0 || size2 > 0) {

	}
	return total;
}




char* calculate(char num1[100], char num2[100], char ops[1],int num1size,int num2size) {
	int point1 = 0;
	int point2 = 0;
	for (int i = 0; num1[i] != '\0'; i++) {
		if (point(num1[i]))
			point1 = i;
	}
	for (int i = 0; num2[i] != '\0'; i++) {
		if (point(num2[i]))
			point2 = i;
	}
	if (point1 == 0 && point2 == 0) {
		return cal1(num1, num2, ops, num1size, num2size);
	}
	else if (point1 != 0 && point2 != 0) {

	}
	else if (point1 == 0 && point2 != 0) {

	}
	else if (point1 == 0 && point2 == 0) {

	}
}


int main() {
	FILE* fp;
	int err = fopen_s(&fp, "input.txt", "r");
	int groups;			//how many groups
	char buffer[100];
	fscanf_s(fp, "%d", &groups);
	char tmp[2];
	fgets(buffer, 100, fp);
	for (int x = 1; x <= groups; x++) {
		char buffer[100] = { 0 };
		char num1[100] = { 0 };
		char num2[100] = { 0 };
		int num1size;
		int num2size;
		char ops[1];
		fgets(buffer, 100, fp);
		int i = 0;
		while (isdigit(buffer[i])) {
			num1[i] = buffer[i];
			i++;
		}
		num1size = i;
		num1[i] = '\0';
		ops[0] = buffer[i];
		i++;
		int j = 0;
		while(buffer[i]!='\0'  && buffer[i]!='\n'){
			num2[j] = buffer[i];
			i++; j++;
		}
		num2size = j;
		num2[j] = '\0';
		printf("#%d:%s", x, calculate(num1, num2, ops, num1size, num2size));
	}
}