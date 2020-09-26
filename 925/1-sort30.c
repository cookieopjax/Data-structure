#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isIdentical(int a,int *b){
    int identical = 0;
    for(int i=0;i<30;i++)
        if(a == *(b+1))
            identical = 1;
    if(identical == 0)
        return 0;
    else
        return 1;
}

void bubbleSort(int *arr, int len) {
    for (int i = len-1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (*(arr+j) < *(arr+j+1)) {
				int temp = *(arr+j+1);
				*(arr+j+1) = *(arr+j);
				*(arr+j) = temp;
			}
		}
	}
}

int main(){
    int *sortArray = (int*) malloc(30 * sizeof(int));
    int i = 0;
    int temp;

    srand(time(NULL));

    while(1){
        if(i==30)break;
        temp = (rand()%100)+1;
        if(isIdentical(temp,sortArray))
            continue;
        else{
            *(sortArray+i) = temp;
            i++;
        }
    }

    bubbleSort(sortArray,30);
    for(int i=0;i<30;i++)
        printf("%d ",*(sortArray+i));

    free(sortArray);
}
