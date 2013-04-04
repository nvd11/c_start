#include <stdio.h>
#include "arrlist.h"
#include "stdlib.h"




int malloc_41(int ** pa, int len){
	*pa = (int *)realloc(*pa, sizeof(int)* (len));
	return 0;
}


int array1_1(){

	struct Arrlist arr1;
	struct Arrlist * parr1;

	parr1 = &arr1;
	
	Arr_init(parr1,10);
	char empty =Arr_is_empty(parr1);


	printf("len is %d\n",parr1->len);
	printf("is empty is %c\n",empty);

	int i;
	for (i=0;i<parr1->len;i++){
		Arr_add(parr1,(i+1) * 3);
	}

	printf("cur_len is %d\n",parr1->cur_len);
	Arr_set(parr1, 9,Arr_get(parr1,8));
	Arr_set(parr1, 10,100);


	Arr_insert(parr1, 10,11111);
	Arr_insert(parr1, 3,11111);
	Arr_insert(parr1, 3,22222);
	Arr_delete(parr1, 4);
	
	Arr_show(parr1);
	//Arr_extend(parr1);

	for (i=0; i<200; i++){
		Arr_add(parr1,(i+1)*4);
	
	}
	
    	printf("cur_len is %d\n",parr1->cur_len);
	printf("len is %d\n",parr1->len);
	Arr_show(parr1);
	printf("\n");
	
	Arr_invert(parr1);		
	Arr_show(parr1);
	printf("\n");
	

	Arr_sort(parr1);	
	Arr_show(parr1);
	printf("\n");

	printf("array1_main done\n");
	return 0;
}	

int array1_main(){
	int i=0;
	i=array1_1();	
	return 0;
}
