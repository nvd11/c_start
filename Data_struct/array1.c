#include <stdio.h>
#include "arrlist.h"

int array1_main(){
	
	struct Arrlist arr1;
	Arr_init(&arr1,10);
	int i =Arr_is_empty(&arr1);
	printf("len is %d\n",arr1.len);
	printf("is empty is %d\n",i);
	printf("array1_main done\n");
	return 0;
}
