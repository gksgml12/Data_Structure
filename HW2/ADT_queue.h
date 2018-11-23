#ifndef ADT_QUEUE
#define ADT_QUEUE
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	void* data_ptr;
	struct node* next;
}Queue_NODE;

typedef struct{
	int count;
	STACK_NODE* front;
	STACK_NODE* rear;
}Queue;

Queue* create_queue(); 
bool enqueue(Queue* queue,void* in);
void* dequeue(Queue* queue);
void* queue_hook_front(Queue* queue);
void* queue_hook_rear(Queue* queue);
void destroy_queue(QUEUE* queue);

#endif