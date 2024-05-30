#include <stdio.h>

struct ElementType {
	unsigned long v;	
};

struct Node {
	struct ElementType value;
	struct Node *next;
};

typedef struct Node *Stack;
typedef struct Node *StackNode;

int is_empty(Stack S){
	return S->next == NULL;
}

Stack create_stack(){
	Stack S = malloc(sizeof(struct Node));
	S->next = NULL;
	return S;
}

void make_null(Stack S){
	if (S!=NULL)
		S->next = NULL;
	else 
		printf("You must use create_stack first!\n");
}

void push(Stack S, struct ElementType e){
	StackNode node = malloc(sizeof(struct Node));
	node->value = e;
	node->next = S->next;
	S->next = node;
}

StackNode top(Stack S){
	if (is_empty(S)){
		printf("The stack is empty!\n");
		return NULL;
	} else {
		return S->next;
	}
}

void pop(Stack S){
	if (is_empty(S)){
		printf("The stack is empty!\n");
		return NULL;
	} else {
		StackNode firstNode = S->next;
		struct ElementType returnValue = S->next->value;
		S->next = S->next->next;
		free(firstNode);
	}
}

void show_stack(Stack S){
	printf("Current state of the stack is: ");
	if (is_empty(S))
		printf("Empty!!!");
	S = S->next;		
	while (S!=NULL)	{
		printf("%ld ", S->value.v);
		S = S->next;
	}
	printf("\n");
}

int main() {
	Stack S = create_stack();
	struct ElementType v1, v2, v3, v4;
	v1.v = 10; v2.v = -4; v3.v = 6; v4.v = 20;
	push(S,v1);push(S,v2);push(S,v3);push(S,v4);
	show_stack(S);
	pop(S);pop(S);
	show_stack(S);
	StackNode node = top(S);
	printf("Value of the top node is:%ld",node->value.v);
	return 0;
}