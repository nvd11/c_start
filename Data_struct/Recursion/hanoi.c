/*
 * hanoi.c
 *
 *  Created on: 2013-4-25
 *      Author: gateman
 */

#include <stdio.h>
#include "hanoi.h"
#include "bool_me.h"
#include "arrstuck1.h"

typedef INT_STUCK HANOITOWER;
static HANOITOWER * (* hanoi_new)() = ast_int_new;

BOOL hanoi_push(HANOITOWER * pIst, int val);
BOOL hanoi_pop(HANOITOWER * pIst, int * pVal);
BOOL hanoi_move(HANOITOWER * pIst_from, INT_STUCK * pIst_to);
void hanoi_print(HANOITOWER * pIst);

int hanoi_main(void){
	hanoi1();
	return 0;
}



int hanoi1(){
	HANOITOWER * pTa = hanoi_new();
	HANOITOWER * pTb = hanoi_new();
	HANOITOWER * pTc = hanoi_new();

	int i;

	for (i=32; i >= 1; i--){
		hanoi_push(pTa, i);
	}

	hanoi_print(pTa);
	hanoi_print(pTb);
	hanoi_print(pTc);

	printf("hanoi_new done\n");
	return 0;
}

BOOL hanoi_push(HANOITOWER * pIst, int val){
	if (TRUE != pIst->is_empty(pIst) && val >= pIst->TopVal(pIst)){
		printf("val is greater than top!\n");
		return FALSE;
	}

	pIst->push(pIst, val);
	return TRUE;
}

BOOL hanoi_pop(HANOITOWER * pIst, int * pVal){
	if (TRUE == pIst->is_empty(pIst)){
		printf("fail to pop as the stuck is empty!\n");
		return FALSE;
	}

	pIst->pop(pIst, pVal);
	return TRUE;
}

BOOL hanoi_move(HANOITOWER * pIst_from, INT_STUCK * pIst_to){
	int val;
	if (TRUE == hanoi_pop(pIst_from, &val)){
		if (TRUE == hanoi_push(pIst_to, val)){
			return TRUE;
		}
	}

	return FALSE;
}

void hanoi_print(HANOITOWER * pIst){
	pIst->print_from_top(pIst);
}

