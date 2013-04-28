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
#include <unistd.h>
#include <stdlib.h>
#include <basefuncs.h>

typedef INT_STUCK HANOITOWER;
static HANOITOWER * (* hanoi_new)() = ast_int_new;

#define HANOI_OP_FILE "/home/gateman/tmp/HANIO_OP_FILE.log"
static char * hanoi_move_str;

BOOL hanoi_push(HANOITOWER * pIst, int val);
BOOL hanoi_pop(HANOITOWER * pIst, int * pVal);
BOOL hanoi_move(HANOITOWER * pIst_from, INT_STUCK * pIst_to);
void hanoi_print(HANOITOWER * pIst);
int hanoi1();
int hanoi_m(HANOITOWER * , HANOITOWER * , HANOITOWER *, int);
int hanoi_len(HANOITOWER * pIst);

int hanoi_main(void){
	hanoi1();
	return 0;
}



int hanoi1(){
	HANOITOWER * pTa = hanoi_new();
	pTa->stname = "TowerA";
	HANOITOWER * pTb = hanoi_new();
	pTb->stname = "TowerB";
	HANOITOWER * pTc = hanoi_new();
	pTc->stname = "TowerC";

	hanoi_move_str = (char *)malloc(sizeof(char) * 50);
	int i;

	for (i=4; i >= 1; i--){
		hanoi_push(pTa, i);
	}


	base_log("start to move\n", HANOI_OP_FILE, "w");

	hanoi_m(pTa, pTb, pTc, pTa->len(pTa));

	printf("tower A is below\n");
	hanoi_print(pTa);
	printf("\ntower B is below\n");
	hanoi_print(pTb);
	printf("\ntower C is below\n");
	hanoi_print(pTc);

	ast_free(pTa);
	ast_free(pTb);
	ast_free(pTc);

	free(hanoi_move_str);
	printf("hanoi_new done\n");
	return 0;
}

int hanoi_m(HANOITOWER * pfrom, HANOITOWER * pmid, HANOITOWER *pto, int count){
	if (count == 1){
		hanoi_move(pfrom, pto);
		return 0;
	}

	hanoi_m(pfrom,pto,pmid,count-1);
	hanoi_move(pfrom, pto);
	hanoi_m(pmid,pfrom,pto,count-1);

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
			sprintf(hanoi_move_str, "move %d from %s to %s\n", val, pIst_from->stname, pIst_to->stname);
			base_log(hanoi_move_str, HANOI_OP_FILE, "a");
			return TRUE;
		}
	}

	return FALSE;
}

void hanoi_print(HANOITOWER * pIst){
	pIst->print_from_top(pIst);
}

int hanoi_len(HANOITOWER * pIst){
	return pIst->len(pIst);
}

