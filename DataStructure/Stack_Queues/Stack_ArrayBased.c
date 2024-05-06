#include <stdio.h>
#include <stdlib.h>

#define EMPTY_POS -1
#define MIN_SIZE 10
struct Stack {
    int value;
    int top;
    int capacity;
    int *array;
};
typedef struct Stack *Stack;
Stack create_stack(int capacity) {
    if(capacity < MIN_SIZE){}
}

void make_null(struct Stack *S) {
    S->top = EMPTY_POS;
}

int is_full(struct Stack *S) {
    return S->top == S->capacity - 1;
}

int is_empty(struct Stack *S) {
    return S->top == EMPTY_POS;
}

void push(struct Stack *S, int e) {
    if (!is_full(S)) {
        S->top++;
        S->array[S->top] = e;
    }
    
}

int pop(struct Stack *S) {  
    if (!is_empty(S)) {
        int v = S->array[S->top];
        S->top--;
        return v;
    }
}


void show_stack(struct Stack *S) {
    if (!is_empty(S)) {
        for (int i = 0; i <= S->top; i++) {
            printf("%d ", S->array[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack *S = create_stack(10);
    make_null(S);
    push(S, 10);
    push(S, 20);
    push(S, 30);
    push(S, 40);
    push(S, 50);
    show_stack(S);
    printf("Value of the top node is:%d\n", pop(S));
    printf("Value of the top node is:%d\n", pop(S));
    show_stack(S);
    return 0;
}