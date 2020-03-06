#include<stdio.h>
#include"FileHandler.h"
#include<stdbool.h>
#include<string.h>

struct players {
	char id[30];
	char name[30];
	//char* name;
	char age[5];
	char score[30];
	//char* score;
};


int main() {
	char*str = readAllTextFromFile("./input.txt");		//infor
	int where = 0;
	int howmanystudent;
	int tmp = 0;
	char temp[10];
	struct players playarray[50];
	while (str[where] != '\n') {
		temp[tmp] = str[where];
		where++;
		tmp++;
	}
	where++;
	howmanystudent = atoi(temp);
	int*idptr[20];
	char* nameptr[20];
	int* ageptr[20];
	char*scoreptr[20];
	for (int i = 0; i < howmanystudent; i++) {
		char idarray[5];
		char namearray[30];
		char agearray[3];
		char scorearray[30];
		int tmpin = 0;
		while (str[where] != ','&& str[where] != '\n'){
			playarray[i].id[tmpin] = str[where];
			idarray[tmpin] = str[where];
			where++;
			tmpin++;
		}
		int idint = atoi(idarray);
		playarray[i].id[tmpin] = '\0';
		where++;
		tmpin = 0;
		while (str[where] != ','&& str[where] != '\n') {
			playarray[i].name[tmpin]= str[where];
			namearray[tmpin] = str[where];
			where++;
			tmpin++;
		}
		namearray[tmpin] = '\0';
		playarray[i].name[tmpin] = '\0';
		where++;
		tmpin = 0;
		while (str[where] != ','&& str[where] != '\n') {
			playarray[i].age[tmpin] = str[where];
			agearray[tmpin] = str[where];
			where++;
			tmpin++;
		}
		playarray[i].age[tmpin] = '\0';
		int ageint = atoi(agearray);
		where++;
		tmpin = 0;
		while (str[where] != ','&& str[where] != '\n' && str[where] != '\0') {
			playarray[i].score[tmpin] = str[where];
			scorearray[tmpin] = str[where];
			where++;
			tmpin++;
		}
		scorearray[tmpin] = '\0';
		playarray[i].score[tmpin] = '\0';
		where++;
		tmpin = 0;
		/*playarray[i].id = idint;
		playarray[i].name = namearray;
		playarray[i].age = ageint;
		playarray[i].score = scorearray;*/
		//struct  players  fff= { 10,"john",22,22.156 };
	}
	
	char*cmd = readAllTextFromFile("./cmd.txt");
	
	int nwhere = 0;
	char ID[8];
	int wh = 0;
	while (cmd[nwhere] != '\0') {
		wh = 0;
		while (cmd[nwhere]!='\n'&&cmd[nwhere] != '\0'){
			ID[wh] = cmd[nwhere];
			wh++;
			nwhere++;
		}
		ID[wh] = '\0';
		nwhere++;
		//playarray[i].id == ID
		int isnot = 0;
		for (int i = 0; i < howmanystudent; i++) {
			if (strcmp(playarray[i].id,ID)==0){
				printf("ID: %s\n", playarray[i].id);
				printf("Name: %s\n", playarray[i].name);
				printf("Age: %s\n", playarray[i].age);
				printf("Score: %s\n\n", playarray[i].score);
				break;
			}
			else {
				isnot++;
			}
			if (isnot == howmanystudent) {
				printf("Player data not found\n\n");
				break;
			}
		}

	}
	
	




	system("PAUSE");
	return 0;
}