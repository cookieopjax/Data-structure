#include<stdio.h>
#include<string.h>
#include <ctype.h>
void bubbleSort(char *a[],int n){
	int i,j;
	char *temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1;j++){
			if(strcmp(a[j],a[j+1])>0){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

char toUpper(char str[]){
	int i = 0;
	while(str[i]){
      str[i] = toupper(str[i]);
      i++;
   	}
}

int main(){
	char a[300][300];
	char input[20];
	char output[300][300];
	int countOutput[300];
	int counter = 0;
	FILE* fp_r = fopen("input_1.txt", "r");
    FILE* fp_w = fopen("write.txt", "w");

	if(fp_r == NULL || fp_w == NULL){
        printf("開檔失敗!\n");
        return -1;
    }

    while(fscanf(fp_r, " %s", input) != EOF){
        //printf("%s ",input);
        toUpper(input);
        //printf("(%s) ",input);
    	strcpy(a[counter],input);
        counter++;
    }
    printf("\n處理完成\n");

    int n = counter;
	char temp[500];
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(strcmp(a[i],a[j])>0){
				strcpy(temp,a[i]);
				strcpy(a[i],a[j]);
				strcpy(a[j],temp);
			}
		}
	}
	printf("counter=%d\n",counter);
	int finalCounter = 0;

	for(int i=0;i<counter;i++){
		int flag = 0;
		int j=0;
		for(;j<finalCounter;j++){
			printf("now");
			if(strcmp(a[i],output[j])==0)
				flag = 1;
		}

		if(flag == 1){
			countOutput[j]++;
			printf("1");
		}
		else{
			printf("2");
			strcpy(a[i],output[finalCounter]);
			countOutput[finalCounter] = 1;
			finalCounter++;
		}

	}


    for(int i=0;i<finalCounter;i++){
		printf("%s\n",output[i]);
	}
	for(int i=0;i<finalCounter;i++){
		printf("%s\n",countOutput[i]);
	}

    fclose(fp_r);
    fclose(fp_w);

}
