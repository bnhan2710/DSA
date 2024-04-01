#include <stdio.h>
#include <stdlib.h>

const int MAX_SIZE = 100;

struct _ElementType {
	char *name;
	unsigned long ID;
};

typedef struct _ElementType *Student;
typedef int Position;

struct _ListInfo {
	unsigned long count;
	unsigned long max_size;
	Student list;
};
typedef struct _ListInfo *StudentList;

void Insert(StudentList L, Student e, Position p) {
	Position current;
	if (p > L->count || L->count == MAX_SIZE) exit(1);
		current = L->count;
	while (current != p) {
		L->list[current] = L->list[current-1];
		current--;
	}
	L->list[current] = *e;
	L->count++;
}

void Show(StudentList L) {
	for (Position i=0;i<L->count;i++)
	{
		printf("*** %d ID=%d    Name:%s \n",i+1,L->list[i].ID,L->list[i].name);
	}
}

int main () {
	StudentList stdList;
	stdList = (StudentList)malloc(sizeof(struct _ListInfo));
	stdList->max_size = MAX_SIZE;
	stdList->count = 0;
	
	
	stdList->list = (Student)malloc(stdList->max_size*sizeof(struct _ElementType));
	
	Student std1 = (Student)malloc(sizeof(struct _ElementType));
	std1->name = "Nguyen Van A";
	std1->ID = 202301;
	
	Student std2 = (Student)malloc(sizeof(struct _ElementType));
	std2->name = "Do B";
	std2->ID = 202302;
	
	Insert(stdList, std1, 0);
	Insert(stdList, std2, 0);	
		
	Show(stdList);
	return 0;
}