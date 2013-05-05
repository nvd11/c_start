#include <stdio.h>
#include "sort.h"
#include "array.h"
#include "array1.h"
#include "char_array.h"
#include "bit32_64.h"
#include "pointer1.h"
#include "struct1.h"
#include "memory_1.h"
#include "recursion.h"
#include "fork1.h"
#include "gtk_win1.h"

int i;

int main(int argc, char *argv[]){
	/*
	printf("argc is %d\n", argc);
	for (i=0; i<= argc -1; i++){
		printf("the %dth parameter is: %s\n",i,argv[i]);
	}
	*/
	//i = gtk_win1(argc,argv);


	//i = sort(); // sort.h
	//i = array_main(); // array.h
	//i = array1_main(); // array1.h

	i = recur_main(); // recursion.h  //hanoi

	//i = fork1_main(); // fork1.h

	//i = basefuncs_main();
	//i = memory_main(); // memory.h 
 

	//i = char_array1(); // char_array.h
	//i = char_array2(); // char_array.h
	//i = char_array3(); // char_array.h
	//i = char_array4(); // char_array.h
	//i = char_array5(); // char_array.h
	//i = char_array6(); // char_array.h

	//i = bisearch1(); // bisearch.h
	//i=bit32_64();
	//i = showsize();
	//i = para1();
	//i = array_point_1();
	//i = struct1(); 
	//i = struct3();
	//i = pointer_main();
		

	//printf("Please type any key to exit...\n");
	//scanf("%d",&i);
	return i;
}
