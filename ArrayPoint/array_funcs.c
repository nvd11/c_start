#include <stdio.h>
#include <stdio.h>

int input_array_int(){


	printf("abc");
	return 0;
}

int p_array_int_1(int * p, int len){
	int i;
	for (i=0; i<len; i++){
		if (i < (len -1)) {
			printf("%d, ",*p); 	
		}
		else{
			printf("%d\n",*p); 	
		}
		p++;
	}
	return 0;
}

int p_array_int(int * p, int len){
	return 0;
}
