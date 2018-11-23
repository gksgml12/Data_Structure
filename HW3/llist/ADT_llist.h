
#include <stdio.h>
#include <stdlib.h>

typedef struct node1 {
	void* data_ptr;
	struct node1* next;
}NODE;

typedef struct{
	int count;
	NODE* front;
	NODE* rear;
	NODE* pos;
}LLIST;

LLIST* create_list();
bool add_node_at(LLIST* list,unsigned int index,void* in);
bool del_node_at(LLIST* list,unsigned int index);
void* get_data_at(LLIST* list,unsigned int index);
int find_data(LLIST* list, void* search_data);
