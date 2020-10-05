#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Nodes{
    char name[20];
    int score;
    struct Nodes *next;
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
	last->next = newnode;
}

void traveral() {
	if (head == NULL) {
		printf("The list is empty！\n");
		return;
	}

	node *current = head;
    printf("name and score : ");
	while (current != NULL) {
		printf("%s(%d)  ",current->name,current->score);
		current = current->next;
	}
	printf("\n--------------------------------------------\n");
}

void change(char *changeName) {
    int nameExist = 0;
    int tempScore = 0;
    if (head == NULL) {
		printf("The list is empty！\n");
		return;
	}
    node *current = head;
    while (current != NULL) {
        if(strcmp(changeName,current->name) == 0){
            printf("New score : ");
            scanf("%d",&tempScore);
            current->score = tempScore;
            printf("Name: %s, Grade: %d\n",current->name,current->score);
            nameExist = 1;
            break;
        }
        else{
            current = current->next;
        }
    }
    if(!nameExist)
        printf("no correspond name!\n");
}

void deleteNode(char *deleteName){
    node *current = head;
    node *tempLastNode = NULL;
    int nameExist = 0;

    if(head == NULL) {
		printf("The list is empty！\n");
		return;
	}
    else if(strcmp(head->name,deleteName) == 0){
        node *oldHead = head;
        head = head->next;
        free(oldHead);
    }
    else{
        while (current != NULL) {
            if(strcmp(current->name,deleteName) == 0){
                tempLastNode->next = current->next;
                free(current);
                nameExist = 1;
                return;
            }
            tempLastNode = current;
            current = current->next;
    	}
        if(!nameExist)
            printf("no correspond name!\n");
    }
}
void sort(){
    if (head == NULL) {
		printf("The list is empty！\n");
		return;
	}

	node *current = head;

    while (current != NULL) {
        node *tempCurrent = current;
        node *maxNode = current;

        while (tempCurrent!= NULL){
            if(tempCurrent->score > maxNode->score)
                maxNode = tempCurrent;
            tempCurrent = tempCurrent->next;
        }

        int temp = 0;
        char temper[20] = {0};
        temp = current->score;
        current->score = maxNode->score;
        maxNode->score = temp;

        strcpy(temper,current->name);
        strcpy(current->name,maxNode->name);
        strcpy(maxNode->name,temper);

        printf("%s(%d) ",current->name,current->score);
        current = current->next;
    }
}

int main() {
    int menu;
    int scores = 0;
    char names[20] = {0};
    while(1) {
        printf("\n[1]Insert [2]Delete [3]Change_Score [4]Print [5]Sort [0]End : ");
        scanf(" %d",&menu);
        if(menu == 1){
            printf("Insert a name : ");
            scanf("%s",names);
            printf("Insert score :");
            scanf("%d",&scores);
            Insert(scores,names);
        }
        else if(menu == 2){
            char tempName[20] = {0};
            printf("Delete a name :");
            scanf("%s", tempName);
            deleteNode(tempName);
        }
        else if(menu == 3){
            char tempName[20] = {0};
            printf("Change score's name :");
            scanf("%s", tempName);
            change(tempName);
        }
        else if(menu == 4){
            traveral();
        }
        else if(menu == 5){
            sort();
        }
        else if (menu == 0) {
            return 0;
        }
    }
}
