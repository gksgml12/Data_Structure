#include "ADT_llist.h"

//#define SORT 0 //sort

#define D_SIZE 8

int compare1(void* x, void* y) {
    return *((int*)x) - *((int*)y);
}

void print1(void* x)
{
    int* xp = (int*)x;
    printf(" - int data %d\n", *xp);
}

typedef struct point{
    double x;
    double y;
} POINT;

void sort_list(LLIST* list, void* data);

int main() {
    FILE* fnode = fopen("node.in", "w");
    FILE* flink = fopen("link.in", "w");

    LLIST* list = create_list(compare1, print1);
    int i;

    POINT path[D_SIZE] = {
        {35.885663, 128.6142},
        {35.888741, 128.609344},
        {35.887057, 128.610213},
        {35.886988, 128.611832},
        {35.890204, 128.609753},
        {35.892413, 128.609242},
        {35.891764, 128.609924},
        {35.887085, 128.609089},
    };

#ifndef SORT

    for(i = 0; i < D_SIZE; i++) {
        fprintf(fnode, "%lf %lf\n", path[i].x, path[i].y);
    }
    for(i = 0; i < D_SIZE-1; i++) {
        fprintf(flink, "%lf %lf %lf %lf\n", path[i].x, path[i].y, path[i+1].x, path[i+1].y);
    }

#else



#endif

   return 0;
}

void sort_list(LLIST* list, void* data) {

}
