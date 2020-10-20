#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Nodes{
    int coefficient;
    int power;
    struct Nodes *next;
}node;

//node *head = NULL;

void Insert(int coefficients, int powers, node **head){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->coefficient = coefficients;
    newNode->power = powers;
    newNode->next = NULL;

	if (*head == NULL) {
		*head = newNode;
		return ;
	}
	node *current = *head;//ptr
	while ((current!= NULL)||(current == *head)){
        //printf("/迴圈time/\n");
        //traveral();
        //如何印head的值?<----
        //printf("->head(%d,%d),new(%d,%d),cur(%d,%d)-",(*head)->coefficient,(*head)->power,newNode->coefficient,newNode->power,current->coefficient,current->power);
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
        //printf("\n");
        current = current->next;
	}
}
void traveral(node **head) {
	if (*head == NULL) {
		printf("The list is empty！\n");
		return;
	}

	node *current = *head;
    printf("多項式為:");
	while (current!= NULL) {
		printf("%dx^%d ",current->coefficient, current->power);
		current = current->next;
	}
	printf("\n");
}

void add(node **head1, node **head2, node **headAfterAdd) {
    //9x^9+4x^5+3x^3+6x^2+8
    //5x^6+2x^3+5x+2
    printf("相加結果:");
    node *current = *headAfterAdd;
    node *cur1 = *head1;
    node *cur2 = *head2;
    node *newNode = (node*)malloc(sizeof(node));

    while ((cur1 != NULL)&&(cur2 != NULL)) {
        printf("我進while了\n");
        if(((cur1->power)>(cur2->power))||cur2 == NULL){
            printf("1>2\n");
            newNode->power = cur1->power;
            newNode->coefficient = cur1->coefficient;
            newNode->next = NULL;
            cur1 = cur1->next;
        }
        else if( ((cur1->power)<(cur2->power)) || cur1 == NULL){
            printf("1<2\n");
            newNode->power = cur2->power;
            newNode->coefficient = cur2->coefficient;
            newNode->next = NULL;
            cur2 = cur2->next;
        }
        else{
            printf("1=2\n");
            newNode->power = cur1->power;
            newNode->coefficient = cur1->coefficient + cur2->coefficient;
            newNode->next = NULL;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        if(*headAfterAdd == NULL){
            printf("ㄍ投\n");
            *headAfterAdd = newNode;
            current = *headAfterAdd;
        }
        else{
            printf("普普\n");
            current->next = newNode;
        }
        printf("==輸出偵錯用字串==\n");
        printf("cur (%d,%d)\n", current->coefficient, current->power);
        //printf("cur1 (%d,%d),cur2(%d,%d)\n", cur1->coefficient, cur1->power, cur2->coefficient, cur2->power);
    }
}
int main() {
    int coe, pow;
    node* heads = NULL;
    node* heads2 = NULL;
    node *heads3 = NULL;

    while(1){
        printf("輸入多項式1(係數 次方):");
        scanf("%d %d",&coe,&pow);

        if(coe == 0){
            traveral(&heads);
            break;
        }

        Insert(coe, pow, &heads);
    }

    while(1){
        printf("輸入多項式2(係數 次方):");
        scanf("%d %d",&coe,&pow);

        if(coe == 0){
            traveral(&heads2);
            break;
        }

        Insert(coe, pow, &heads2);
    }

    add(&heads, &heads2, &heads3);
    traveral(&heads3);
}
