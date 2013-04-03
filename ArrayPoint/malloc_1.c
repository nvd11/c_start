#include <stdio.h>
#include <array_funcs.h>
#include <stdlib.h>

int malloc_1();
int malloc_2();
int malloc_3();
int malloc_4(int ** pa, int len);

int malloc_main(){
	int i;
//	i = malloc_1();
	i = malloc_3();
	printf("malloc main done\n");
	return 0;
}


int malloc_1(){
	int b[]={4,6,7,8,9};
	int a[5] = {1,2,3,4,5};
	int i;
	i = p_array_int_1(a,5);	
	i = p_array_int_1(b,5);	
	return 0;
}


int malloc_2(){
	//int i;
	//int c = 7;
	//int a[c];

	//a[0] = 1;
	//
	//i = p_array_int_1(a,8);	
	return 0;
}


int malloc_3(){
	int len = 7;
	int * a = (int *)malloc(sizeof(int) * len);
	int i;
	for (i=0; i <len ; i++){
		a[i] = (i+1)*2;
	}	
	i = p_array_int_1(a,len); //a function to print the array which defined by user	
	printf("address is %p\n", a);
	
	len++;
	//a = (int *)realloc(a, sizeof(int)* (len));
	i = malloc_4(&a, len);
	a[len-1]= 40;
	i = p_array_int_1(a,len); //a function to print the array which defined by user	
	printf("address is %p\n", a);

	free(a);
	return 0;
}

int malloc_4(int ** pa, int len){
	*pa = (int *)realloc(*pa, sizeof(int)* (len));
	return 0;
}
