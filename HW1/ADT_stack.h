#include <stdio.h>

typedef struct node {
	void* data_ptr;
	struct node* link;
}STACK_NODE;

typedef struct{
	int count;
	STACK_NODE* top;
}STACK;

STACK* create_stack(); 
bool push(STACK* Stack,void* in);
void* pop(STACK* stack);




