#include <stdio.h>
#include <stdlib.h>
#include "basefuncs.h"
#include "str_array1.h"

static C_BOOL str_arr_add(STR_ARR *, const char *);
static C_BOOL str_arr_insert(STR_ARR *, int, const char *);
static C_BOOL str_arr_delete(STR_ARR *, int, const char **);
static C_BOOL str_arr_set_val(STR_ARR *, int, const char *);
static char * str_arr_get_val(STR_ARR *, int);
static C_BOOL str_arr_is_empty(STR_ARR *);
static C_BOOL str_arr_is_full(STR_ARR *);
static void str_arr_print(STR_ARR *);

/* initail a string array */
STR_ARR * str_arr_new(int init_len){
	if (1 > init_len){
		base_error("initial len must great than 0!\n");

	}

	STR_ARR * pStrarr = (STR_ARR *)malloc(sizeof(STR_ARR));
	if (NULL == pStrarr){
		base_error("fail to assign memory to a string array!"); 
	}

	char ** pAddr = (char **)malloc(sizeof(char *) * init_len);
	if (NULL == pAddr){
		base_error("fail to assign memory to a string array!");
	}

	int i;
	for (i=0; i<init_len; i++){
		pAddr[i] = NULL;
	}	

	pStrarr->pAddr = pAddr;
	pStrarr->cur_len = 0;
	pStrarr->max_len = init_len;
	
	pStrarr->add = str_arr_add;
	pStrarr->insert = str_arr_insert;
	pStrarr->delete = str_arr_delete;
	pStrarr->set_val = str_arr_set_val;
	pStrarr->get_val = str_arr_get_val;
	pStrarr->is_empty = str_arr_is_empty;
	pStrarr->is_full = str_arr_is_full;
	pStrarr->print = str_arr_print;

	return NULL;
}

/* add a string to tail of the the array */
static C_BOOL str_arr_add(STR_ARR * pStrarr, const char * pStr){
	return C_TRUE;
}

/* insert a string to any place of the the array */
static C_BOOL str_arr_insert(STR_ARR * pStrarr, int index, const char * pStr){
	return C_TRUE;
}

/* delete a node, an return to output parameter */
static C_BOOL str_arr_delete(STR_ARR * pStrarr, int index, const char ** pPStr){
	return C_TRUE;
}

/* change val of an element of array */
static C_BOOL str_arr_set_val(STR_ARR * pStrarr, int index, const char * pStr){
	return C_TRUE;
}

/* get string from the array by index */
static char * str_arr_get_val(STR_ARR * pStrarr, int index){
	return NULL;
}

/* whether the string is empty */
static C_BOOL str_arr_is_empty(STR_ARR * pStrarr){
	return C_TRUE;
}

/* whether the string is full */
static C_BOOL str_arr_is_full(STR_ARR * pStrarr){
	return C_TRUE;
}

/* printf all the string of the array */
static void str_arr_print(STR_ARR * pStrarr){
	return;
}

