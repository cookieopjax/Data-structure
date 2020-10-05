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

char change(char str[]){
	int i = 0;
	while(str[i]){
      str[i] = toupper(str[i]);
      i++;
   	}
}

int main(){
	char a[300][300];
	char input[20];
	int counter = 0;
	FILE* fp_r = fopen("input_1.txt", "r");
    FILE* fp_w = fopen("output.txt", "w");

	if(fp_r == NULL || fp_w == NULL){
        printf("開檔失敗!\n");
        return -1;
    }

    while(fscanf(fp_r, " %s", input) != EOF){
        change(input);
    	strcpy(a[counter],input);
        counter++;
    }

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
	printf("單字                     出現次數\n------------------------------------\n");
	int count = 1;
	for(int i=0;i<counter-1;i++){
		if(strcmp(a[i],a[i+1])==0){
			count++;
		}
		else{
			printf("%s",a[i]);
			for (int j=0;j<(27-strlen(a[i]));j++) {
				printf(" ");
			}
			printf("%d\n",count);
			count = 1;
		}

	}

	for (int i = 0; i < counter; i++) {
		fprintf(fp_w, "%s\n",a[i]);
	}
    fclose(fp_r);
    fclose(fp_w);

}
