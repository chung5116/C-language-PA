#include<stdio.h>


int from_tower, to_tower, middle_tower;
void Towers(int N, char from_tower, char to_tower, char middle_tower);
int steppublic;
int nowstep;
int main() {
	int Num;
	int step;
	printf("How many disks do you select? ");
	scanf_s("%d", &Num);

	if (Num <= 0) {
		printf("Invalid disk number");
		return;
	}
	printf("Which step do you want to print?");
	scanf_s("%d", &step);
	steppublic = step;
	if(Num>0){
		Towers(Num, 'A','C','B');
	}
	if (step > nowstep) {
		printf("Step out of range!");
	}
	return 0;
}


void Towers(int N, char from_tower, char to_tower, char middle_tower) {
	if (N == 1) {
		nowstep++;
		if (steppublic == nowstep) {
			printf("Disk 1 moved from A to C");
		}
		return;
	}

	Towers(N - 1, from_tower, middle_tower, to_tower);
	nowstep++;
	if (steppublic == nowstep) {
		printf("Disk %d moved from %c to %c", N, from_tower, to_tower);
	}
	Towers(N - 1, middle_tower, to_tower, from_tower);
}