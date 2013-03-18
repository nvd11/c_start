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


void show_array_1(int *p, int len){
	p[0]=-1;
	int i;
	printf(" a is ");
	for (i=0;i<len;i++){
		printf("%d ",p[i]);
	}	
	printf("\n ");
}
	
int array_point_1(){
	int a[5] = {1,2,3,4,5};

	show_array_1(a,5);	
	printf("array_point done\n");
}
