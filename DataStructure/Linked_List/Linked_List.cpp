#include <stdio.h>
#include <stdlib.h>

struct Symbol {
  char *name;
  unsigned long val;
};

struct Node {
	struct Node *next;
	struct Symbol *element;
};

int main()
{
	struct Symbol oneSym;
	struct Symbol twoSym;
	struct Symbol threeSym;
	
	struct Node *nodeA;
	struct Node *nodeB;
	struct Node *nodeC;
	struct Node *nodeP;
	
	oneSym.name = "one"; oneSym.val = 1;	
	twoSym.name = "two"; twoSym.val = 2;
	threeSym.name = "three"; threeSym.val = 3;
	
	nodeA =  (Node*)malloc(sizeof(struct Node));
	nodeB =  (Node*)malloc(sizeof(struct Node));
	nodeC =  (Node*)malloc(sizeof(struct Node));
	
	nodeA->next = nodeB; nodeA->element = &oneSym;
	nodeB->next = nodeC; nodeB->element = &twoSym;
	nodeC->next = NULL; nodeC->element = &threeSym;
	
	nodeP = nodeA;
	
	while (nodeP!=NULL)
	{
		printf("%p (%s) points to %p\n", nodeP,nodeP->element->name,nodeP->next);
		nodeP = nodeP->next;
	}

	return 0;
}