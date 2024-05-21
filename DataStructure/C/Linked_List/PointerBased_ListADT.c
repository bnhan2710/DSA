#include <stdio.h>
#include <stdlib.h>
struct ElementType {
    unsigned ID;
    char *name;
};

struct Node {
    struct ElementType value;
    struct Node *next;
};

typedef struct Node *List;
typedef struct Node *Position;

Position Insert(List *pL , struct ElementType e, Position p){
    Position newItem;
    newItem = malloc(sizeof(struct Node));
    newItem->value = e;
    if (*pL == NULL || p == NULL){
        newItem->next = *pL;
        *pL = newItem;
    }
    else {
        newItem->next = p->next;
        p->next = newItem;
    }
    return newItem;
}

Position PushBack(List *pL, struct ElementType e){
    Position newItem;
    newItem = (Position)malloc(sizeof(struct Node));
    newItem->value = e;
    newItem->next = NULL;
    if (*pL == NULL){
        *pL = newItem;
    }
    else {
        Position p;
        p = *pL;
        while (p->next != NULL){
            p = p->next;
        }
        p->next = newItem;
    }
    return newItem;
}

void Display(List pL){
    int count = 1;
    while (pL != NULL)
    {
        printf("***%d        %d | %s \n",count, pL->value.ID, pL->value.name);
    printf("\n");
    pL = pL->next;
    count++;
    }
}
 
int main(){
    List pL = NULL;
    struct ElementType e1,e2,e3;
    e1.ID = 102230034;
    e1.name = "Huynh Nhu Bao Nhan ";
    e2.ID = 102230008;
    e2.name = "Nguyen Tan Dat";
    e3.ID = 102230007;
    e3.name = "Vo Van Cuong";
    Position p;
    p = Insert(&pL, e1, p);
    p = Insert(&pL, e2, p);
    p = Insert(&pL, e3, p);
    Display(pL);
    PushBack(&pL, e1);
    Display(pL);
    return 0;
} 