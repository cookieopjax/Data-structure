#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Nodes{
    int coefficient;
    int power;
    struct Nodes *next;
}node;

void Insert(int coefficients, int powers, node **head) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->coefficient = coefficients;
    newNode->power = powers;
    newNode->next = NULL;

	if (*head == NULL) {
        printf("first one\n");
        *head = newNode;
		return ;
	}

	node *current = *head;
	while ((current!= NULL)||(current == *head)) {
        //traveral();
        //printf("-->(new(%d,%d),cur(%d,%d)---",newNode->coefficient,newNode->power,current->coefficient,current->power);
        if((newNode->power) == (current->power)) {
            //printf("重複ㄌ\n");
            current->coefficient += newNode->coefficient;
            return;
        }

        if((newNode->power)>((*head)->power)) {//insert head *4 3 (insert 5)
            //printf("投\n");
            *head = newNode;
            (*head)->next = current;
            return;

        }

		if( ((newNode->power)<(current->power)) && (current->next == NULL) ){//only pushback 5 4 (insert 3)
            //printf(" 我是最後面的\n");
            current->next = newNode;
            newNode->next = NULL;
            return;
        }

        if( ((newNode->power)<(current->power)) && ((newNode->power)>(current->next->power)) ) {//insert middle 5 3 (insert:4)
            //printf(" 我在中間喔\n ");
            newNode->next = current->next;
            current->next = newNode;
            return;
		}
        printf("*\n");
        current = current->next;
	}
}
void traveral(node **head) {
	if (head == NULL) {
		printf("The list is empty！\n");
		return;
	}

	node *current = *head;
    printf("多項式為:");
	while (current != NULL) {
		printf("%d^%d ",current->coefficient, current->power);
		current = current->next;
	}
	printf("\n");
}


int main() {
    int coe, pow;

    while(1){
        printf("輸入多項式1(係數 次方):");
        scanf("%d %d",&coe,&pow);
        node *head = NULL;

        if(coe == 0){
            traveral(&head);
            break;
        }

        Insert(coe, pow, &head);
    }



}
