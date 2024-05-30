#include <stdio.h>

#define EMPTY_POS -1
#define MIN_SIZE 5
#define EMPTY_VALUE -1000000

struct ElementType {
	int value;
};

struct StackRecord {
	unsigned int capacity;
	int tos;
	struct ElementType *stack_array;
};

typedef struct StackRecord *Stack;

int is_empty(Stack S) {
	return S->tos == EMPTY_POS;
}

int is_full(Stack S) {
	return S->tos == S->capacity - 1;
}

void make_null(Stack S) {
	S->tos = EMPTY_POS;
}

void dispose(Stack S) {
	if (S!=NULL) {
		free(S->stack_array);
		free(S);
	}
}

Stack create_stack(unsigned int capacity){
	if (capacity < MIN_SIZE) {
		printf("The stack's capacity is at least %d\n",MIN_SIZE);
		return NULL;
	}
	Stack S = malloc(sizeof(struct StackRecord));
	if (S == NULL) {
		printf("Not enough memory!!!\n");
		return;
	}
	S->stack_array = malloc(sizeof(struct ElementType)*capacity);
	if (S->stack_array == NULL) {
		printf("Not enough memory!!!\n");
		return;
	}
	S->capacity = capacity;
	S->tos = EMPTY_POS;
	return S;
}

void push(Stack S, struct ElementType e) {
	if (is_full(S)) {
		printf("The stack is full already!\n");
		return;
	}
	S->stack_array[++S->tos] = e;
}

struct ElementType pop(Stack S) {
	if (is_empty(S)) {
		printf("The stack is empty now!\n");
		struct ElementType e;
		e.value = EMPTY_VALUE;
		return e;
	}
	return S->stack_array[S->tos--];
}

struct ElementType top(Stack S) {
	if (is_empty(S)) {
		printf("The stack is empty now!\n");
		struct ElementType e;
		e.value = EMPTY_VALUE;
		return e;
	}
	return S->stack_array[S->tos];
}

void show_stack(Stack S) {
	if (is_empty(S)) {
		printf("The stack is empty!\n");
		return;
	}
	for (int i=S->tos;i>EMPTY_POS;i--)
		printf("%d ",S->stack_array[i]);
	printf("\n");
}

int main(int argc, char** argv) {
	struct ElementType e,e1,e2,e3,e4;
	e1.value = 5;e2.value = 7;e3.value = -19;e4.value = 17;
	Stack S = create_stack(100);
	push(S,e1); push(S,e2); push(S,e3); push(S,e4);
	show_stack(S);
	e = pop(S);
	printf("e = %d\n",e.value);
	show_stack(S);
	pop(S); pop(S);pop(S);pop(S);
	return 0;
}