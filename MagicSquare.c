//made by 資訊二甲 D0843837 李秉泓
#include <stdio.h>
#include <stdlib.h>
void printSquare(int **a, int n){
    printf("開始輸出陣列:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%2d ",a[i][j]);
        }
        printf("\n");
    }
}
//向左上移動
void generateSquare(int **a, int n, int x, int y,int counter){
    /*if((x!=0)&&(y!=0)){//上面左邊皆有空間
        a[x-1][y-1] = counter;
        x = x - 1;
        y = y - 1;
        generateSquare(a,n,x,y,counter+1);
    }*/
    if(counter > n*n+1)
        return;
    printSquare(a,n);
    printf("\n====\n");
    int i, j;
    if(x-1 < 0)
        i = n-1;
    else
        i = x-1;
    if(y-1 < 0)
        j = n-1;
    else
        j = y-1;

    if(a[i][j])
        x = (++x) % n;
    else{
        x = i;
        y = (y-1<0) ? (n-1):--y;
    }
    a[x][y] = counter;

    generateSquare(a,n,x,y,counter+1);

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
    //printSquare(square,n);

}
