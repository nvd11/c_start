#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#include "arrlist.h"

static BOOL Arr_extend(struct Arrlist * pArr, int increment);

void Arr_init(struct Arrlist * pArr, int length){
	pArr->paddr = (int *)malloc(sizeof(int) * length);
		
	if (NULL == pArr->paddr){
		printf("fail to assgin memory!!!\n");	
		exit(-1);
	}

	pArr->len = length;
	pArr->cur_len = 0;
	pArr->increment = 10;

	return;
}


BOOL Arr_is_empty(struct Arrlist * pArr){
	if (0 == pArr->cur_len){
		return TRUE;
	}
	return FALSE;
}

BOOL Arr_is_full(struct Arrlist * pArr){
	if (pArr->len == pArr->cur_len){
		return TRUE;
	}
	return FALSE;
}

void Arr_show(struct Arrlist * pArr){
	if (TRUE == Arr_is_empty(pArr)){
		printf("It's an empty Arrlist\n");
		return;
	}
	
	int i;
	for (i=0; i < (pArr->cur_len - 1); i++){
 		printf("%d, ", pArr->paddr[i]);
	}		

	printf("%d\n", pArr->paddr[pArr->cur_len -1]);
	return;
}	

BOOL Arr_add(struct Arrlist * pArr, int val){
	if (TRUE == Arr_is_full(pArr)){
		if (FALSE == Arr_extend(pArr, pArr->increment)){ 
			return FALSE;
		}
	}
	
	pArr->paddr[pArr->cur_len] = val; // assign the value
	pArr->cur_len++;		
	return TRUE;
}


static BOOL Arr_extend(struct Arrlist * pArr, int increment){
	
	pArr->paddr = (int *)realloc(pArr->paddr, sizeof(int) * (pArr->cur_len + increment));

	if (NULL == pArr->paddr){
		return FALSE;
	}
	
	pArr->len += increment;
	return TRUE;
}
