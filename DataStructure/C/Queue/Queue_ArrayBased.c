#include <stdio.h>
#include <limits.h>

#define MIN_CAP 5
#define EMPTY_VALUE -INT_MAX

struct ElementType {
	int value;
};

struct QueueRecord {
	unsigned int capacity;
	int front;
	int rear;
	unsigned int count;
	struct ElementType *queue_array;
};

typedef struct QueueRecord *Queue;

int is_empty(Queue Q) {
	return Q->count == 0;
}

int is_full(Queue Q) {
	return Q->count == Q->capacity;
}

void reset(Queue Q) {
	Q->count = 0;
	Q->front = 1;
	Q->rear = 0;
}

void dispose(Queue Q) {
	if (Q!=NULL) {
		free(Q->queue_array);
		free(Q);
	}
}

Queue create_queue(unsigned int capacity) {
	if (capacity<MIN_CAP) {
		printf("The queue's capacity is at least %d!\n",MIN_CAP);
		return NULL;
	}
	Queue Q = malloc(sizeof(struct QueueRecord));
	if (Q == NULL) {
		printf("Not enough memory!\n,",MIN_CAP);
		return NULL;
	}
	Q->queue_array = malloc(sizeof(struct ElementType)*capacity);
	Q->capacity = capacity;
	reset(Q);
	return Q;
}

int increase(int index, unsigned int capacity) {
	index++;
	if (index == capacity) 
		index = 0;
	return index;
}

void enqueue(struct ElementType e, Queue Q) {
	if (is_full(Q)) {
		printf("The queue is full already!\n");
		return;
	}
	Q->rear = increase(Q->rear,Q->capacity);
	Q->queue_array[Q->rear] = e;
	Q->count++;
}

struct ElementType dequeue(Queue Q) {
	if (is_empty(Q)) {
		printf("The queue is empty!\n");
		struct ElementType return_value;
		return_value.value = EMPTY_VALUE;
		return return_value;
	}
	struct ElementType tmp = Q->queue_array[Q->front];
	Q->front = increase(Q->front,Q->capacity);
	Q->count--;
	return tmp;
}

void show_queue(Queue Q,int index) {
	if (is_empty(Q)) {
		printf("The queue is empty!\n");
		return;
	}
	if (index == Q->rear) {
		printf("%d ",Q->queue_array[index].value);
	} else {
		show_queue(Q, increase(index,Q->capacity));
		printf("%d ",Q->queue_array[index].value);
	}
}

int main () {
	struct ElementType e,e1,e2,e3,e4;
	e1.value = 2; e2.value = 4; e3.value = 1; e4.value = 3; 
	Queue Q = create_queue(10);
	Q->front = 8; Q->rear = 7;
	enqueue(e1,Q);enqueue(e2,Q);enqueue(e3,Q);enqueue(e4,Q);
	show_queue(Q,Q->front);
	printf("\n");
	
	e = dequeue(Q);
	printf("e = %d\n",e.value);
	show_queue(Q,Q->front);
	printf("\n");
	
	e = dequeue(Q);
	printf("e = %d\n",e.value);
	show_queue(Q,Q->front);
	printf("\n");
	
	e = dequeue(Q);
	printf("e = %d\n",e.value);
	show_queue(Q,Q->front);
	printf("\n");
	
	e = dequeue(Q);
	printf("e = %d\n",e.value);
	show_queue(Q,Q->front);
	printf("\n");
	
	return 0;
}