/*
 * arrstuck1.c
 *
 *  Created on: 2013-4-24
 *      Author: gateman
 */

#include <stdio.h>
#include <stdlib.h>
#include "arrstuck1.h"
#include "basefuncs.h"


#define AST_INIT_LEN 10

static BOOL ast_int_is_empty(INT_STUCK * pIst);
static int ast_int_len(INT_STUCK * pIst);
static BOOL ast_int_is_full(INT_STUCK *);
static BOOL ast_int_push(INT_STUCK * pIst, int Val);
static BOOL ast_int_pop(INT_STUCK * pIst, int * pVal);
static int ast_int_top_val(INT_STUCK * pIst);
static int ast_int_buttom_val(INT_STUCK * pIst);
static BOOL ast_int_extend(INT_STUCK * pIst, int exlen);
static void ast_int_print(INT_STUCK * pIst);
static void ast_int_print_from_top(INT_STUCK * pIst);
static void ast_int_clean(INT_STUCK * pIst);

INT_STUCK * ast_int_new(){
	INT_STUCK * pIst = (INT_STUCK *)malloc(sizeof(INT_STUCK));
	if (NULL == pIst){
		base_error("fail to assign memory to an structure");
	}

	//array
	pIst->pArr = (int *)malloc(sizeof(int) * AST_INIT_LEN);
	if (NULL == pIst->pArr){
		base_error("fail to assign memory to an array stuck");
	}

	pIst->arrlen = AST_INIT_LEN;
	pIst->buttom =0;
	pIst->top = 0;
	pIst->is_empty = &ast_int_is_empty;
	pIst->is_full = &ast_int_is_full;
	pIst->len = &ast_int_len;
	pIst->ButtomVal = &ast_int_buttom_val;
	pIst->TopVal = &ast_int_top_val;
	pIst->push = &ast_int_push;
	pIst->pop = &ast_int_pop;
	pIst->print = &ast_int_print;
	pIst->print_from_top = &ast_int_print_from_top;
	pIst->clean = &ast_int_clean;
	pIst->is_inited = TRUE;

	return pIst;
}

static BOOL ast_int_is_empty(INT_STUCK * pIst){
	if (TRUE != pIst->is_inited){
		base_error("the array stuck is not initialed yet!");
	}

	if (pIst->top == pIst->buttom){
		return TRUE;
	}

	return FALSE;
}

static int ast_int_len(INT_STUCK * pIst){
	if (TRUE != pIst->is_inited){
		base_error("the array stuck is not initialed yet!");
	}

	return pIst->top - pIst->buttom;
}


static BOOL ast_int_is_full(INT_STUCK * pIst){
	if (TRUE != pIst->is_inited){
		base_error("the array stuck is not initialed yet!");
	}

	if (pIst->top == pIst->arrlen -1){
		return TRUE;
	}

	return FALSE;
}

//extend the max length of array
static BOOL ast_int_extend(INT_STUCK * pIst, int exlen){
	if (TRUE != pIst->is_inited){
		base_error("the array stuck is not initialed yet!");
	}

	if (exlen < 0){
		printf("the length of extend must >0!!\n");
		return FALSE;
	}

	int * pold = pIst->pArr;
	pIst->pArr = (int *)realloc(pIst->pArr, sizeof(int) * (pIst->arrlen + exlen));
	if (NULL == pIst->pArr){
		printf("fail to assign memory to extend array!\n");
		pIst->pArr = pold;
		return FALSE;
	}

	if(pold != pIst->pArr){
		free(pold);
	}

	pIst->arrlen += exlen;

	return TRUE;
}

static int ast_int_top_val(INT_STUCK * pIst){
	if (TRUE != pIst->is_inited){
		base_error("the array stuck is not initialed yet!");
	}

	if (TRUE == pIst->is_empty(pIst)){
		base_error("the array stuck is empty!");
	}

	return pIst->pArr[pIst->top -1];
}

static int ast_int_buttom_val(INT_STUCK * pIst){
	if (TRUE != pIst->is_inited){
		base_error("the array stuck is not initialed yet!");
	}

	if (TRUE == pIst->is_empty(pIst)){
		base_error("the array stuck is empty!");
	}

	return pIst->pArr[pIst->buttom];
}

static BOOL ast_int_push(INT_STUCK * pIst, int Val){
	if (TRUE != pIst->is_inited){
		base_error("the array stuck is not initialed yet!");
	}

	if (TRUE == pIst->is_full(pIst)){
		if (TRUE != ast_int_extend(pIst, pIst->arrlen / 2)){
			printf("fail to push as the array is full!\n");
			return FALSE;
		}
	}

	pIst->pArr[pIst->top] = Val;
	pIst->top++;
	return TRUE;
}


static BOOL ast_int_pop(INT_STUCK * pIst, int * pVal){
	if (TRUE != pIst->is_inited){
		base_error("the array stuck is not initialed yet!");
	}

	if (TRUE == pIst->is_empty(pIst)){
		printf("the array stuck is empty!\n");
		return FALSE;
	}

	*pVal = pIst->TopVal(pIst);
	pIst->top--;
	return FALSE;
}

static void ast_int_print(INT_STUCK * pIst){
	if (TRUE != pIst->is_inited){
		base_error("the array stuck is not initialed yet!");
	}

	if (TRUE == pIst->is_empty(pIst)){
		printf("the array stuck is empty!\n");
		return;
	}

	int i;
	for (i= pIst->buttom; i!= pIst->top; i++){
		printf("%d", pIst->pArr[i]);

		if (i != pIst->top -1){
			printf(", ");
		}
	}

	printf("\n\n");
}


static void ast_int_print_from_top(INT_STUCK * pIst){
	if (TRUE != pIst->is_inited){
		base_error("the array stuck is not initialed yet!");
	}

	if (TRUE == pIst->is_empty(pIst)){
		printf("the array stuck is empty!\n");
		return;
	}

	int i;
	for (i= pIst->top-1; i >= pIst->buttom; i--){
		printf("%d", pIst->pArr[i]);

		if (i != pIst->buttom){
			printf(", ");
		}
	}

	printf("\n\n");
}

static void ast_int_clean(INT_STUCK * pIst){
	if (TRUE != pIst->is_inited){
		base_error("the array stuck is not initialed yet!");
	}

	pIst->top = pIst->buttom;
	return;
}


BOOL ast_free(INT_STUCK * pIst){
	if (TRUE != pIst->is_inited){
		printf("the array stuck is not initialed yet!\n");
		return FALSE;
	}

	free(pIst->pArr);
	free(pIst);
	return TRUE;
}
