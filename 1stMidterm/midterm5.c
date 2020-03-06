#include<stdio.h>
#include<string.h>

int main() {
	char in[80];
	printf("Enter message to be encrypted: ");
	fgets(in, sizeof(in), stdin);

	int shiftamount;
	printf("Enter shift amount(1~26): ");
	scanf_s("%d", &shiftamount);

	int i = 0;
	while (in[i] != '\n') {
		if ((122 >= in[i] && in[i] >= 97)) {
			if (in[i] + shiftamount > 122) {
				printf("%c", 97+in[i]+shiftamount - 122-1);
			}
			else {
				printf("%c", in[i]+shiftamount);
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


	return 0;
}