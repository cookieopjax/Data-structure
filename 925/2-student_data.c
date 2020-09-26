#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

typedef struct {
	char name[20];
	char gender;
	int num;
	int score1;
	int score2;
	float avg;
} STUDENT;

void Create(STUDENT* datas[]) {
	srand(time(NULL));

	char names[20] = "";
	int counter = 0;

	FILE* fp_r = fopen("name.txt", "r");
	FILE* fp_w = fopen("student.txt", "w");

	if (fp_r == NULL || fp_w == NULL) {
		printf("開檔失敗!\n");
		return;
	}

	while (fscanf(fp_r, "%s", names) != EOF) {
		//printf("讀入中%d,%s\n",counter,names);
		strcpy(datas[counter]->name, names);
		counter++;
	}

	for (int i = 0; i < 50; i++) {
		//號碼生成
		datas[i]->num = i + 1;
		//性別生成
		int temp = (rand() % 2) + 1;
		if (temp == 1)
			datas[i]->gender = 'M';
		else
			datas[i]->gender = 'F';
		//分數生成
		datas[i]->score1 = (rand() % (31)) + 70;
		datas[i]->score2 = (rand() % (31)) + 70;
		datas[i]->avg = ((float)datas[i]->score1 + (float)datas[i]->score2) / 2.0f;
	}

}


void Print_Student(STUDENT* data[]) {
	printf("學生姓名   號碼  性別\n");
	printf("---------------------\n");

	for (int i = 0; i < 50; i++)
		printf("%-12s %2d %3c\n", data[i]->name, data[i]->num, data[i]->gender);
	printf("\n");
}

void Print_Rank(STUDENT* data[]) {
	STUDENT* rank[50];

	for (int i = 0; i < 50; i++)
		rank[i] = data[i];

	int len = 50;
	for (int i = 0; i < len - 1; i++)
		for (int j = 0; j < len - 1 - i; j++)
			if (rank[j]->avg < rank[j + 1]->avg) {
				STUDENT* temp = rank[j];
				rank[j] = rank[j + 1];
				rank[j + 1] = temp;
			}
	printf("學生姓名  計概成績   微積分成績  平均成績   名次 \n");
	printf("--------------------------------------------\n");
	for (int i = 0; i < 50; i++)
		printf("%-12s %3d %10d %12.1f %5d\n", rank[i]->name, rank[i]->score1, rank[i]->score2, rank[i]->avg, i + 1);
}

void Print_Avg(STUDENT* data[]) {
	int all1 = 0, all2 = 0;
	int bigScore1 = 0, bigIndex1 = 0;
	int bigScore2 = 0, bigIndex2 = 0;


	for (int i = 0; i < 50; i++) {
		all1 = all1 + data[i]->score1;
		all2 = all2 + data[i]->score2;
	}

	float avg1 = (float)all1 / 50.0f;
	float avg2 = (float)all2 / 50.0f;
	
	for (int i = 0; i < 50; i++) {
		if (data[i]->score1 > bigScore1) {
			bigScore1 = data[i]->score1;
			bigIndex1 = i;
		}
		if (data[i]->score2 > bigScore2) {
			bigScore2 = data[i]->score2;
			bigIndex1 = i;
		}
	}

	printf(" 科目      平均成績    最高分學生   最高分成績   \n");
	printf("-------------------------------------------\n");
	printf("計概%13.2f %13s %10d\n", avg1, data[bigIndex1]->name, bigScore1);
	printf("微積分%11.2f %13s %10d\n", avg2, data[bigIndex2]->name, bigScore2);
}

int main() {
	int menu;
	int isCreated = 0;

	STUDENT* data[50];

	for (int i = 0; i < 50; i++) 
		data[i] = (STUDENT*)malloc(sizeof(STUDENT));
	
	while (1) {
		printf("\n[1]Create [2]Print_Student [3]Print_Rank [4]Print_Avg [0]End : ");
		scanf("%d", &menu);
		
		switch (menu) {
		case 1:  //原始資料產生
			Create(data);
			isCreated = 1;
			break;
		case 2:  //輸出學生資料
			if (isCreated)
				Print_Student(data);
			else
				printf("還未產生原始資料!");
			break;
		case 3:  //列印排序成績
			if (isCreated)
				Print_Rank(data);
			else
				printf("還未產生原始資料!");
			break;
		case 4:  //印出各科平均成績和該科目成績最高者
			if (isCreated)
				Print_Avg(data);
			else
				printf("還未產生原始資料!");
			break;
		case 0:  //結束程式執行
			printf("Exit!\n");
			exit(1);
			break;
		default:
			printf("Error!\n");
			break;
		}
	}
}
