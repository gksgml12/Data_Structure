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

LLIST* create_list();
bool add_node_at(LLIST* list,unsigned int index,void* in);
bool del_node_at(LLIST* list,unsigned int index);
void* get_data_at(LLIST* list,unsigned int index);
int find_data(LLIST* ptr_list, void* search_data);
#endif