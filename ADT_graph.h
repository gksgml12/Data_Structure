#ifndef ADT_GRAPH
#define ADT_GRAPH
#include "ADT_llist.h"
#include <stdlib.h>

typedef struct vertex{
	int data;
	LLIST* arc_list;
} VERTEX;

typedef struct arc{
	VERTEX* to_vertex;
} ARC;

typedef struct{
	LLIST* vertex_list;
} GRAPH;

int compare_vertex(void* x, void* y);
void print_vertex(void* x);
int compare_arc(void* x, void* y);
void print_arc(void* x);

GRAPH* create_graph();
bool g_insert_vertex(GRAPH* graph, int data);
bool g_insert_arc(GRAPH* graph, int from, int to);

bool g_delete_vertex(GRAPH* graph, int data);
void print_vertex_all(GRAPH* graph);
void print_arc_all(GRAPH* graph);

#endif