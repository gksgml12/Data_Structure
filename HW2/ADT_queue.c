#include "ADT_queue.h"

Queue* create_queue(){
	Queue* queue =(Queue*)malloc(sizeof(Queue));
	if(!queue)
		return NULL;
	queue->count =0;
	queue->front =NULL;
	queue->rear =NULL;
	return queue;
} 

bool enqueue(STACK* queue,void* in){
	Queue_NODE* node =(Queue_NODE*)malloc(sizeof(Queue_NODE));
	if(node == NULL)
		return false;
	node->data_ptr =in;
	node->next = NULL;
	if(queue->count==0)
	queue->front =node;
	else
		queue->rear->next=node;
	queue->rear =node;
	(queue->count)++;
	return true;
}

void* dequeue(STACK* queue){
	if(queue-> count ==0)
		return NULL;
	STACK_NODE* tmp = queue->front;
	void* data_out=queue->front->data_ptr;
	if(queue->count==1){
		queue->front =NULL;
		queue->rear =NULL;
	}
	else
		queue->front=queue->front->next;
	free(tmp);
	(stack -> count)--;
	return data_out;
}

void* queue_hook_front(Queue* queue){
	if(queue->count==0) retrun NULL;
	else return queue->front->data_ptr;
}
void* queue_hook_rear(Queue* queue){
	if(queue->count==0) retrun NULL;
	else return queue->rear->data_ptr;
}
void destroy_queue(QUEUE* queue){
	while(queue->count==0){
		free(queue->front->data_ptr);
		dequeue(queue);
	}
}