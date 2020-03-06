#include<stdio.h>
#include "FileHandler.h"

void copy(char* src, char *dist) {
	printf("Input char array: ");
	int i = 0;
	int k = 0;
	while (src[i] != '\n') {
		printf("%c", src[i]);
		dist[i] = src[i];
		i++;
	}
	dist[i] = '\0';
	printf("\n");
}

void append(char* target, char* text) {
	int i = 0;
	printf("\n");
	printf("Append text: ");
	printf("%s\n", text);
	printf("Append result: ");
	printf("%s%s\n", target,text);
	printf("\nOriginal char array: %s", target);
}

void split(char* src, char* target, char*split) {
	int i = 0;
	printf("\n\nSplit Char: %s\n", split);
	printf("Split result:\n");
	while (src[i]!='\0'){
		if (src[i ] == split[0]) {
			printf("\n");
			i++; //先略過split char
			if (src[i] >= 97 && src[i] <= 122) {
				printf("%c", src[i] - 32);
			}
			else {
				printf("%c", src[i]);
			}
			i++;
		}
		printf("%c", src[i]);
		i++;
	}
	i = 0;
	while (target[i] != '\0') {
		if (target[i] == split[0]) {
			i++; //先略過split char
			printf("\n");
			printf("%c", target[i]);
			i++;
		}
		printf("%c", target[i]);
		i++;
	}
}



int main() {
	char* str = readAllTextFromFile("./input.txt");
	int i = 0;			//dist的位置
	int k = 0;
	while (str[i] != '\n') {		//dist 第一行
		i++;
	}
	char* dist = malloc(i);       //dist 第一行
	copy(str, dist);
	int i1 = i;
	while (str[i + 1]!= '\n') {		//dist 第二行
		k++;
		i++;
	}

	char *text = malloc(k);		
	int k1 = 0;
	while (str[i1+1] != '\n') {
		text[k1] = str[i1+1];
		i1++;
		k1++;
	}
	text[k1] = '\0';
	append(dist,text);


	i1++;
	int i2 = i1;
	int k2 = 0;
	while (str[i1 + 1] != '\n') {   //第三航
		i1++;
		k2++;
	}
	char* splitchar = malloc(k2);
	k2 = 0;
	while (str[i2 + 1] != '\n') {
		splitchar[k2] = str[i2 + 1];
		i2++;
		k2++;
	}
	splitchar[k2] = '\0';
	split(dist, text, splitchar);

	printf("\n\nStudent ID: B10706009");
	int err = writeAllTextToFile("./writeTest.txt", dist);
	if (err != 0) {
		//printf("write file error");
	}
	else {
		//printf("write file sucess");
	}

	return 0;
	
}