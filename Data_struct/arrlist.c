#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arrlist.h"

void Arr_init(struct Arrlist * pArr, int length){
	pArr->addr = (int *)malloc(sizeof(int) * length);
	
	if (NULL == pArr->addr){
		printf("fail to assgin memory!!!\n");	
		exit(-1);
	}

	pArr->len = length;
	pArr->cur_len = 0;
	pArr->increment = 10;

	return;
}


bool Arr_is_empty(struct Arrlist * pArr){
	if (0 == pArr->cur_len){
		return true;
	}
	return false;
}
