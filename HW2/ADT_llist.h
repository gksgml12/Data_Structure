#ifndef ADT_LLIST
#define ADT_LLIST
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	void* data_ptr;
	struct node* next;
}NODE;

typedef struct{
	int count;
	NODE* front;
	NODE* rear;
	NODE* pos
}LLIST;

Queue* create_list(); 
bool enqueue(Queue* queue,void* in);
void* dequeue(Queue* queue);
void* queue_hook_front(Queue* queue);
void* queue_hook_rear(Queue* queue);
void destroy_queue(QUEUE* queue);

#endif