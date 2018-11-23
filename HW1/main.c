// ADT Stack
#include <stdio.h>
#include "ADT_stack.h"
#include "chart.h"

#define REVERSE 1 // reverse

int main() {



	// new type definition
	typedef struct {
		char name[20];
		int score;
	} STD;

	// prepare 5 data
	STD student[5] = {
		{"James", 95},
		{"Yoosoo", 87},
		{"Paul", 93},
		{"Peter", 76},
		{"Park", 100}
	};

#ifndef REVERSE
	generate_chart_header();
	//                    me                my boss            my score
	generate_chart_node(student[0].name, student[0].name, student[0].score); 
	generate_chart_node(student[1].name, student[0].name, student[1].score); 
	generate_chart_node(student[2].name, student[1].name, student[2].score); 
	generate_chart_node(student[3].name, student[2].name, student[3].score); 
	generate_chart_node(student[4].name, student[3].name, student[4].score); 
	generate_chart_footer();
#else
	STACK* stack_ptr;
	stack_ptr = create_stack();;

	int i = 0;
	for(i=0; i<5; i++){
		push(stack_ptr, &student[i]);
	}

	STD* boss = NULL;
	STD* std;
	generate_chart_header();
	while( (std = (STD*)pop(stack_ptr)) !=NULL){
		if(boss ==NULL)
			generate_chart_node(std->name,std->name,std->score);
		else
			generate_chart_node(std->name,boss->name,std->score);
		boss = std;
	}
	generate_chart_footer();

    // your code here.
    // partial codes are listed in homework introduction file (ppt file)
    // please refer to it.


#endif

    return 0;
}
