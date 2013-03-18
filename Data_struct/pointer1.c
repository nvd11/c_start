#include <stdio.h>

void f(int i){
	i = 100;
}

void f2(int *p){  //It does not define a formal parameter which named *p, it just define a formal parameter named p, and it's type is int *
		  //It also can type as f2(int * p) or f2(int* p)
	*p = 100;
}

int para1(void){

	int i = 9;
	printf("i=%d \n",i); 

	f(i);

	printf("i=%d \n",i);

	f2(&i);

	printf("i=%d \n",i);

	printf("para done\n");
	return 0;
}
