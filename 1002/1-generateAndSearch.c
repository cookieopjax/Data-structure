#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int data;
    struct node *next;
}node;

node *head = NULL;

node* Create(int num){  //傳入要存入節點之參數
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = num;
    newnode->next = NULL;
    return newnode;
}

void Insert(int num){
    node *newNode = Create(num);

	if (head == NULL) {
		head = newNode;
		return;
	}

	node *last = head;
	while (last->next != NULL)
		last = last->next;
	last->next = newNode;
}

void traveral() {
	if (head == NULL) {
		printf("The list is empty！\n");
		return;
	}

	node *current = head;
    printf("List:");
	while (current != NULL) {
		printf("%d ",current->data);
		current = current->next;
	}
	printf("\n--------------------------------------------\n");
}

void Search(int findNum) {
    node *current = head;
    int index = 1;
    int flag = 0;
	while ((current != NULL)&&(flag == 0)) {
		if((current->data) == findNum){
            flag = 1;
		}
		else{
            current = current->next;
            index++;
            flag = 0;
		}
	}
	if(flag == 0)
        printf("Not in the List！\n\n");
    else
        printf("In the List！\nindex:%d\n\n",index);

}

int isIdentical(int a,int *b){
    int identical = 0;
    for(int i=0;i<10;i++)
        if(a == b[i])
            identical = 1;
    if(identical == 0)
        return 0;
    else
        return 1;
}

int main(){
    srand(time(NULL));
    int tempArray[10] = {0};
    int i = 0;
    int tempSerch;

    while(1){
        if(i==10)break;
        int temp = rand()%(20)+1;
        if(isIdentical(temp,tempArray)){
            continue;
        }
        else{
            tempArray[i] = temp;
            i++;
        }
    }

    for(int i=0;i<10;i++)
        Insert(tempArray[i]);

    traveral();


    while(1){
        printf("Search the number：");
        scanf("%d",&tempSerch);
        if(tempSerch==0){
            printf("Exit！");
            return 0;
        }
        Search(tempSerch);
    }
}
