#include <stdio.h>
int counter = 0;
void hanoi(int n, char A, char B, char C) {
	if(n == 1) {
        printf("移動套環 %c --> %c\n", A, C);
        counter++;
    }
    else {
        hanoi(n-1, A, C, B);
        hanoi(1, A, B, C);
        hanoi(n-1, B, A, C);
    }
}

int main() {
    int n;
    while(1){
    	counter = 0;
    	printf("請輸入圓盤數量 n (n=0 結束): ");
	    scanf("%d", &n);
	    if(n==0){
			return 0;
		}
	    else{
	    	hanoi(n, 'A', 'B', 'C');
	    	printf("\n移動次數 %d",counter);
	    	printf("\n\n-----------------------------------\n\n");
		}
	}
    return 0;
}
