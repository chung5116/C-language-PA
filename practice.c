#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int* cal1(char s1[100], char s2[100], char  ops[1], int pointcarry);
void cal2(char s1[100], char s2[100], char  ops[1], int point1, int point2);


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


void  cal2(char s1[100], char s2[100], char  ops[1], int point1, int point2) {
	int pnum1[255], pnum2[255], psum[255], preturnpsum[255];
	int pl1,pl2;
	int m_point1 = point1;
	int m_point2 = point2;
	if (point1 > 0) {
		for (pl1 = 0; s1[m_point1 + 1] != '\0';) {
			pnum1[pl1] = s1[m_point1 + 1] - '0';
			pl1++; m_point1++;
		}
	}
	else {
		pnum1[0] = 0;
		pl1 = 1;
	}
	if (point2 > 0) {
		for (pl2 = 0; s2[m_point2 + 1] != '\0'; ) {
			pnum2[pl2] = s2[m_point2 + 1] - '0';
			pl2++; m_point2++;
		}
	}
	else {
		pnum2[0] = 0;
		pl2 = 0;
	}
	int carry = 0;
	int k = 0;
	if (pl1 > pl2) {
		for (int tmp = pl2; tmp < pl1; tmp++) {
			pnum2[tmp] = 0;
		}
		pl2 = pl1;
	}
	else if (pl2 > pl1) {
		for (int tmp = pl1; tmp < pl2; tmp++) {
			pnum1[tmp] = 0;
		}
		pl1 = pl2;
	}
	int i = pl1 - 1;
	int j = pl2 - 1;

	if (ops[0] == '+') {
		for (; i >= 0 && j >= 0; i--, j--, k++) {
			psum[k] = (pnum1[i] + pnum2[j] + carry) % 10;
			carry = (pnum1[i] + pnum2[j] + carry) / 10;
		}
		int n = 0;
		k--;
		for (n = 0; k >= 0; k-- && n++) {
			preturnpsum[n] =psum[k];
		}
		preturnpsum[++n] = -1;
		n--;
		while (preturnpsum[n] == 0) {
			preturnpsum[n] = -1;
			n--;
		}
		
	}
	else if (ops[0] == '-') {
		for (; i >= 0 && j >= 0; i--, j--, k++) {
			if ((pnum1[i] - pnum2[j] + carry) < 0) {
				psum[k] = (pnum1[i] - pnum2[j] + carry) + 10;
				carry = -1;
			}
			else {
				psum[k] = (pnum1[i] - pnum2[j] + carry);
				carry = 0;
			}
		}
		int n = 0;
		k--;
		for (n = 0; k >= 0; k-- && n++) {
			preturnpsum[n] = psum[k];
		}
		preturnpsum[++n] = -1;
		n--;
		while (preturnpsum[n] == 0) {
			preturnpsum[n] = -1;
			n--;
		}
	}
	int* result = cal1(s1, s2, ops, carry);
	while (result[0] == 0) {
		int sp = 0;
		while(result[sp] != -1) {
			result[sp] = result[sp + 1];
			sp++;
		}
	}
	for (int s = 0; result[s] != -1; s++) {
		if (result[s] == -87) {
			printf("-");
		}
		else
			printf("%d", result[s]);
	}
	printf(".");
	for (int s = 0; preturnpsum[s] != -1; s++) {
		printf("%d", preturnpsum[s]);
	}
	printf("\n");

}

int* cal1(char s1[100], char s2[100], char  ops[1],int pointcarry) {
	int num1[255], num2[255], sum[255];
	//int returnsum[255];
	int*returnsum = malloc(255*sizeof(int));
	int l1, l2;
	/* convert character to integer*/
	for (l1 = 0; s1[l1] != '\0' && s1[l1] != '.'; l1++)
		num1[l1] = s1[l1] - '0';

	for (l2 = 0; s2[l2] != '\0' && s2[l2] != '.'; l2++)
		num2[l2] = s2[l2] - '0';

	int carry = 0;
	int k = 0;
	int i = l1 - 1;
	int j = l2 - 1;
	if (ops[0] == '+') {
		for (; i >= 0 && j >= 0; i--, j--, k++) {
			sum[k] = (num1[i] + num2[j] + carry+pointcarry) % 10;
			carry = (num1[i] + num2[j] + carry) / 10;
			pointcarry = 0;
		}
		if (l1 > l2) {
			while (i >= 0) {
				sum[k++] = (num1[i] + carry) % 10;
				carry = (num1[i--] + carry) / 10;
			}
		}
		else if (l1 < l2) {
			while (j >= 0) {
				sum[k++] = (num2[j] + carry) % 10;
				carry = (num2[j--] + carry) / 10;
			}
		}
		else {
			if (carry > 0)
				sum[k++] = carry;
		}
		k--;
		int n = 0;
		for (n = 0; k >= 0; k-- && n++) {
			returnsum[n] = sum[k];
		}
		returnsum[++n] = -1;
	}
	else if (ops[0] == '-') {
		for (; i >= 0 && j >= 0; i--, j--, k++) {
			if ((num1[i] - num2[j] + carry+pointcarry) < 0) {
				sum[k] = (num1[i] - num2[j] + carry + pointcarry) + 10;
				carry = -1;
				pointcarry = 0;
			}
			else {
				sum[k] = (num1[i] - num2[j] + carry+pointcarry);
				carry = 0;
				pointcarry = 0;
			}
		}
		if (l1 > l2) {
			while (i >= 0) {
				if ((num1[i] + carry) < 0) {
					sum[k++] = (num1[i] + carry) + 10;
				}
				else {
					sum[k++] = (num1[i] + carry);
					carry = 0;
				}
				i--;
			}
		}
		if (carry == -1) {
			for (int ink = k-1; ink >= 0; ink--) {
				sum[ink] = (sum[ink] - 10) * -1;
			}
		}
		 if (l1 < l2) {
			while (j >= 0) {
					sum[k++] = num2[j];
					carry = -1;
					j--;
			}
			if (carry == -1) {
				sum[k++] = -87;
			}
		}
		k--;
		int n = 0;
		for (n = 0; k >= 0; k-- && n++) {
			returnsum[n] = sum[k];
		}
		returnsum[++n] = -1;
	}
	return returnsum;
}


int main() {

	char s1[255], s2[255];
	FILE* fp;
	int err = fopen_s(&fp, "input.txt", "r");
	int groups;			//how many groups
	char buffer[100];
	fscanf_s(fp, "%d", &groups);
	char tmp[2];
	fgets(buffer, 100, fp);
	for (int x = 1; x <= groups; x++) {
		char buffer[100] = { 0 };
		int num1size;
		int num2size;
		char ops[1];
		fgets(buffer, 100, fp);
		int i1 = 0;
		while (isdigit(buffer[i1])) {
			s1[i1] = buffer[i1];
			i1++;
		}
		num1size = i1;
		s1[i1] = '\0';
		ops[0] = buffer[i1];
		i1++;
		int m = 0;
		while (buffer[i1] != '\0' && buffer[i1] != '\n') {
			s2[m] = buffer[i1];
			i1++; m++;
		}
		num2size = m;
		s2[m] = '\0';


		int point1 = 0;
		int point2 = 0;
		for (int i = 0; s1[i] != '\0'; i++) {
			if (point(s1[i]))
				point1 = i;
		}
		for (int i = 0; s2[i] != '\0'; i++) {
			if (point(s2[i]))
				point2 = i;
		}
		if (point1 == 0 && point2 == 0) {
			int*result =  cal1(s1, s2, ops,0);
			int i = 0;
			while (result[0] == 0) {
				int sp = 0;
				while (result[sp] != -1) {
					result[sp] = result[sp + 1];
					sp++;
				}
			}
			while (result[i] != -1) {
				if (result[i] == -87) {
					printf("-");
					i++;
				}
				else {
					printf("%d", result[i]);
					i++;
				}
			}
			printf("\n");
		}
		else if (point1 != 0 && point2 != 0) {
			cal2(s1, s2, ops, point1, point2);
		}
		else if (point1 == 0 && point2 != 0) {
			cal2(s1, s2, ops, point1, point2);
		}
		else if (point1 == 0 && point2 == 0) {
			cal2(s1, s2, ops, point1, point2);
		}
	}
	return 0;
}