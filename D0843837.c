//made by 資訊二甲 D0843837 李秉泓
#include <stdio.h>
#include <stdlib.h>
void printSquare(int **a, int n){
    printf("開始輸出陣列:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%3d ",a[i][j]);
        }
        printf("\n");
    }
}
int isfiled(int **a, int n){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i][j] == 0)
                return 0;
    return 1;
}
void generateSquare(int **a, int n, int x, int y,int counter){
    if(isfiled(a,n))return;

    int tempX = x;
    int tempY = y;

    //先估計座標位址，之後再檢查該座標是否有其他數
	tempX = x - 1;
	tempY = y - 1;
	if (tempX < 0) tempX = n - 1;
	if (tempY < 0) tempY = n - 1;

    if(!(a[tempX][tempY])){
        a[tempX][tempY] = counter;
        x = tempX;
        y = tempY;
        generateSquare(a,n,x,y,counter+1);
    }
    else{
        tempX = x;
        tempY = y;
        if(tempX + 1 == n)
            tempX = 0;
        else
            tempX++;

        a[tempX][tempY] = counter;
        x = tempX;
        y = tempY;
        generateSquare(a,n,x,y,counter+1);
    }
}

int main(){
    int n = 0;

    printf("請輸入奇數方塊邊長 : ");
    scanf("%d",&n);

    int **square = (int**)calloc(n,sizeof(int*));
    for(int i=0;i<n;i++)
        square[i] = (int*)calloc(n,sizeof(int));
    square[0][(n-1)/2] = 1;
    generateSquare(square,n,0,(int)((n-1)/2),2);
    printSquare(square,n);

}
