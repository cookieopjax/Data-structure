#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    char name[20];
    int score;
    struct node *next;
}node;

node *head = NULL;

void Insert(int num, char *names){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->score = num;
    strcpy(newnode->name,names);
    newnode->next = NULL;

	if (head == NULL) {
		head = newnode;
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
		printf("%s,%d",current->name,current.score);
		current = current->next;
	}
	printf("\n--------------------------------------------\n");
}

int main() {
    int menu;
    int scores = 0;
    char names[20] = {0};
    while(1) {
        printf("\n[1]Insert [2]Delete [3]Change_Score [4]Print [0]End : ");
        scanf(" %d",&menu);
        if(menu == 1){
            printf("Insert a name : \n");
            scanf("%s",names);
            printf("Insert score :\n");
            scanf("%d",&scores);
            Insert(scores,names);
        }
        else if(menu == 4){
            traveral();
        }

    }
}
