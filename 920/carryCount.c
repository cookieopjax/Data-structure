#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char num[30]) {
    int lens = strlen(num);
    for(int i=0;((i<lens/2));i++) {
        int temp = num[i];
        num[i] = num[lens-i-1];
        num[lens-i-1] = temp;
    }
}

int addZero(char num1[30],char num2[30]){
    int lens1 = strlen(num1);
    int lens2 = strlen(num2);
    if(lens1<lens2){
        for(int i=lens1;i<lens2;i++)
            num1[i] = '0';
        num1[lens2] = '\0';
        return lens2;
    }
    else if(lens2<lens1){
        for(int i=lens2;i<lens1;i++)
            num2[i] = '0';
        num2[lens1] = '\0';
        return lens1;
    }
    else
        return lens1;
}

int main(){
    char a[30],b[30],output[30];
    while(scanf("%s%s",a,b)){
        if((strcmp(a,"0")==0)&&(strcmp(b,"0")==0))
            return 0;
        memset(output,0,sizeof(output));
        int carryFlag = 0;
        int carryCounter = 0;

        reverse(a);
        reverse(b);
        int lens = addZero(a,b);

        for(int i=0;i<lens;i++){
            output[i] = (a[i]-48) + (b[i]-48) + carryFlag;

            if(output[i]>=10){
                carryFlag = 1;
                carryCounter++;
                output[i] = output[i] - 10;
                output[i] = output[i] + 48;
            }
            else{
                carryFlag = 0;
                output[i] = output[i] + 48;
            }

            if((i == lens-1)&&(carryFlag == 1)){
                output[lens] = 49;
                lens++;
                break;
            }
        }
        reverse(output);
        printf("%s\t\t\t共%d次進位\n",output,carryCounter);
    }
}
