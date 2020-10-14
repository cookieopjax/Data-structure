#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Nodes{
    int coefficient;
    int power;
    struct Nodes *next;
}node;

node *head = NULL;
node *heads = NULL;

void Insert(int coefficients, int powers){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->coefficient = coefficients;
    newNode->power = powers;
    newNode->next = NULL;

	if (head == NULL) {
		head = newNode;
		return ;
	}
	node *current = head;
	while ((current!= NULL)||(current == head)){
        //printf("/迴圈time/\n");
        //traveral();
        //printf("-->(new(%d,%d),cur(%d,%d)---",newNode->coefficient,newNode->power,current->coefficient,current->power);
        if((newNode->power) == (current->power)) {
            //printf("重複ㄌ\n");
            current->coefficient += newNode->coefficient;
            return;
        }

        if((newNode->power)>(head->power)) {//insert head *4 3 (insert 5)
            //printf("投\n");
            head = newNode;
            head->next = current;
            return;

        }

		if( ((newNode->power)<(current->power)) && (current->next == NULL) ){//only pushback 5 4 (insert 3)
            //printf(" 我是最後面的\n");
            current->next = newNode;
            newNode->next = NULL;
            return;
        }
        /*
        if((newNode->power)<(current->power) && (current->next->next == NULL)) {
            printf(" 我是最後面的2\n");
            current->next->next= newNode;
            newNode->next = NULL;
            return;
        }*/
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
void traveral() {
	if (head == NULL) {
		printf("The list is empty！\n");
		return;
	}

	node *current = head;
    printf("多項式為:");
	while (current != NULL) {
		printf("%d^%d ",current->coefficient, current->power);
		current = current->next;
	}
	printf("\n");
}

void Inserts(int coefficients, int powers){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->coefficient = coefficients;
    newNode->power = powers;
    newNode->next = NULL;

	if (heads == NULL) {
		heads = newNode;
		return ;
	}
	node *current = heads;
	while ((current!= NULL)||(current == heads)){
        //printf("/迴圈time/\n");
        traveral();
        printf("-->(new(%d,%d),cur(%d,%d)---",newNode->coefficient,newNode->power,current->coefficient,current->power);
        if((newNode->power) == (current->power)) {
            printf("重複ㄌ\n");
            current->coefficient += newNode->coefficient;
            return;
        }

        if((newNode->power)>(heads->power)) {//insert head *4 3 (insert 5)
            printf("投\n");
            heads = newNode;
            heads->next = current;
            return;

        }

		if( ((newNode->power)<(current->power)) && (current->next == NULL) ){//only pushback 5 4 (insert 3)
            printf(" 我是最後面的\n");
            current->next = newNode;
            newNode->next = NULL;
            return;
        }
        /*
        if((newNode->power)<(current->power) && (current->next->next == NULL)) {
            printf(" 我是最後面的2\n");
            current->next->next= newNode;
            newNode->next = NULL;
            return;
        }*/
        if( ((newNode->power)<(current->power)) && ((newNode->power)>(current->next->power)) ) {//insert middle 5 3 (insert:4)
            printf(" 我在中間喔\n ");
            newNode->next = current->next;
            current->next = newNode;
            return;
		}
        printf("*\n");
        current = current->next;
	}
}
void traverals() {
	if (heads == NULL) {
		printf("The list is empty！\n");
		return;
	}

	node *current = heads;
    printf("多項式為:");
	while (current != NULL) {
		printf("%d^%d ",current->coefficient, current->power);
		current = current->next;
	}
	printf("\n");
}

void add(){

}
int main() {
    int coe, pow;

    while(1){
        printf("輸入多項式1(係數 次方):");
        scanf("%d %d",&coe,&pow);

        if(coe == 0){
            traveral();
            break;
        }

        Insert(coe, pow);
    }

    while(1){
        printf("輸入多項式2(係數 次方):");
        scanf("%d %d",&coe,&pow);

        if(coe == 0){
            traverals();
            break;
        }

        Inserts(coe, pow);
    }
    printf("相加結果:");


}
