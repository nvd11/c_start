#include <stdio.h>
#include "arrlist.h" 
void bf_1();

int basefuncs_main(){
	bf_1();	
	printf("basefuncs done!!\n");
	return 0;
}


void bf_1(){
	ARRINT * parr1 = Arr_init(10);
	Arr_add(parr1,10);
	Arr_add(parr1,20);
	Arr_show(parr1);
}
