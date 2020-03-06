#include<stdio.h>
#include<stdbool.h>

int main() {
	int num[10];
	int repeatnum[10];
	int repeatnumber = 1;
	bool repeat = false;
	int i = 0;
	int j = 0;
	int k = 0;
	printf("Please enter 10 number : \n");
	for (i = 0; i < 10; i++) {
		scanf_s("%d", &num[i]);
	}
	printf("The repeat number is : \n");
	for (i = 0; i < 10 - 1; i++) {
		for (j = i+1; j < 10 ; j++) {
			if (num[i] == num[j]) {
				
				for (k = 0; k < repeatnumber; k++) {
					if (num[i] == repeatnum[k]) {
						repeat = true;
					}
				}
				if (repeat == false) {
					repeatnum[repeatnumber-1] = num[i];
					repeatnumber++;
				}
				repeat = false;  //ªì©l¸Ü
			}
		}
	}
	if (repeatnumber-1 != 0) {
		for (i = 0; i < repeatnumber-1; i++) {
			if (i == repeatnumber - 2) {
				printf("%d", repeatnum[i]);
			}
			else {
				printf("%d, ", repeatnum[i]);
			}
		}
	}
	else {
		printf("No repeat number!");
	}
	return 0;
}