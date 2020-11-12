#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)
#define STACKMAX 50

void push(char* stack, int* to, char op);
char pop(char* stack, int* top); 
bool isFull(int top);
bool isEmpty(int top);
void showAllStack(char* stack, int top);
void infix_to_postfix(char* infix, char* postfix, char* stack, int* top);
int precedence(char op);

int main() {
	char stack[STACKMAX] = { 0 };
	int top = -1;
	int* topPtr = &top;
	char infix[50] = { 0 };
	char postfix[50] = { 0 };
	while (true) {
		memset(infix, 0, sizeof(infix));
		memset(postfix, 0, sizeof(postfix));
		memset(stack , 0, sizeof(stack));
		top = -1;

		printf("請輸入中置式字串 : ");
		scanf("%s", infix);
		if (strcmp(infix, "0") == 0)return 0;
		infix_to_postfix(infix, postfix, stack, topPtr);
		printf("後置結果 : %s\n", postfix);

	}
	
}

void infix_to_postfix(char* infix, char* postfix, char* stack, int* top) {
	int postCount = 0;
	for (int i = 0; i < strlen(infix); i++) {
		switch (infix[i]) {
			case '(':
				push(stack, top, infix[i]);
				break;
			case '+': case '-': case '*': case '/': case '%':
				while (precedence(stack[(*top)]) >= precedence(infix[i])) {
					postfix[postCount] = pop(stack,top);
					postCount++;
				}
				push(stack, top, infix[i]);
				break;
			case ')':
				while (stack[(*top)] != '(') { // 遇 ) 輸出至 ( 
					postfix[postCount] = pop(stack, top);
					postCount ++;
				}
				(*top)--;  // 不輸出 ( 
				break;
			default:  // 運算元直接輸出 
				postfix[postCount] = infix[i];
				postCount++;
		}
	}
	while (!(isEmpty((*top)))) {
		postfix[postCount] = pop(stack, top);
		postCount++;
	}
	
	
}
int precedence(char op) {
	switch (op) {
		case '+': case '-': 
			return 1;
		case '*': case '/' : case '%': 
			return 2;
		default:            
			return 0;
	}
}
void push(char* stack, int* top, char op) {
	(*top)++;
	stack[(*top)] = op;
}
char pop(char* stack, int* top){
	char tempCh = stack[(*top)];
	stack[(*top)] = '\0';
	(*top)--;
	return tempCh;
}
bool isFull(int top) {
	if (top == STACKMAX)
		return true;
	else
		return false;
}
bool isEmpty(int top) {
	if (top <= -1)
		return true;
	else
		return false;
}
void showAllStack(char* stack, int top) {
	printf("stack = [");
	for (int i = 0; i <= top; i++) {
		printf("%c ", stack[i]);
	}
	printf("]\n");
}

