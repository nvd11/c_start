#include <stdio.h>
#include "arrlist.h"
#include "stdlib.h"




int malloc_41(int ** pa, int len){
	*pa = (int *)realloc(*pa, sizeof(int)* (len));
}


int array1_1(){

	struct Arrlist arr1;
	struct Arrlist * parr1;

	parr1 = &arr1;
	
	Arr_init(parr1,10);
	char empty =Arr_is_empty(parr1);

	//parr1->paddr = (int *)realloc(parr1->paddr, 80);

	printf("len is %d\n",parr1->len);
	printf("is empty is %c\n",empty);

	int i;
	for (i=0;i<parr1->len;i++){
		Arr_add(parr1,(i+1) * 3);
	}

	//i = Arr_ext(&(parr1->paddr),80);

	//Arr_add(parr1,200);

	Arr_show(parr1);
		

	printf("array1_main done\n");
	return 0;
}	

int array1_main(){
	int i=0;
	i=array1_1();	
	return 0;
}
