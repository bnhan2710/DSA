#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct HeapNode {
    int value;
};

struct HeapRecord {
    int length;
    int heap_size;
    struct HeapNode *heap_array;
};

typedef struct HeapRecord *Heap;

Heap create_heap(int length) {
    Heap H = malloc(sizeof(struct HeapRecord));
    if (H == NULL) {
        printf("Not enough memory!\n");
        return NULL;
    }
    H->heap_array = malloc(sizeof(struct HeapNode) * (length + 1));
    if (H->heap_array == NULL) {
        printf("Not enough memory!\n");
        return NULL;
    }
    H->length = length;
    H->heap_size = length;
    return H;
}

void max_heapify(Heap H, int i) {
    int l = 2 * i;
    int r = 2 * i + 1;
    int largest = i;
    if (l <= H->heap_size && H->heap_array[l].value > H->heap_array[largest].value)
        largest = l;
    if (r <= H->heap_size && H->heap_array[r].value > H->heap_array[largest].value)
        largest = r;
    if (largest != i) {
        struct HeapNode temp = H->heap_array[i];
        H->heap_array[i] = H->heap_array[largest];
        H->heap_array[largest] = temp;
        max_heapify(H, largest);
    }
}

void build_max_heap(Heap H) {
    for (int i = H->heap_size / 2; i > 0; i--)
        max_heapify(H, i);
}

void heap_sort(Heap H) {    
    for (int i = H->heap_size; i > 1; i--) {
        struct HeapNode temp = H->heap_array[1];
        H->heap_array[1] = H->heap_array[i];
        H->heap_array[i] = temp;
        H->heap_size--;
        max_heapify(H, 1);
    }
}

void show_heap(Heap H) {
    if(H->heap_size == 0){
        printf("The heap is empty!\n");
        return;
    }
    printf("The heap: ");
    for (int i = 1; i <= H->heap_size; i++)
        printf("%d ", H->heap_array[i].value);
    printf("\n");   

}

int main(){
    Heap H = create_heap(10);
    build_max_heap(H);
    int data[10] = {4,1,3,2,16,9,10,14,8,7};
    for(int i = 0; i < 10; i++){
        H->heap_array[i+1].value = data[i];
    }
    show_heap(H);
    max_heapify(H, 2);
    show_heap(H);
    heap_sort(H);
    show_heap(H);
    return 0;
}
