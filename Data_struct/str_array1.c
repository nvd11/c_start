#include <stdio.h>
#include <stdlib.h>
#include "basefuncs.h"
#include "str_array1.h"

/*
*  below are the member functions of the struct
*/
static C_BOOL str_arr_add(STR_ARR *, const char *);
static C_BOOL str_arr_insert(STR_ARR *, int, const char *);
static C_BOOL str_arr_delete(STR_ARR *, int, const char **);
static C_BOOL str_arr_set_val(STR_ARR *, int, const char *);
static const char * str_arr_get_val(STR_ARR *, int);
static C_BOOL str_arr_is_empty(STR_ARR *);
static C_BOOL str_arr_is_full(STR_ARR *);
static void str_arr_print(STR_ARR *);

/*
* below are the non-member functions of the struct
*/
static C_BOOL str_arr_extend(STR_ARR *, int);
static void str_arr_judge_init(STR_ARR *);
static C_BOOL str_arr_free_array(const char **);

/* initail a string array */
STR_ARR * str_arr_new(int init_len){
	if (1 > init_len){
		base_error("initial len must great than 0!\n");
	}

	STR_ARR * pStrarr = (STR_ARR *)malloc(sizeof(STR_ARR));
	if (NULL == pStrarr){
		base_error("fail to assign memory to a string array!"); 
	}

	const char ** pAddr = (const char **)malloc(sizeof(const char *) * init_len);
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

	pStrarr->is_initialed = C_TRUE;
	return pStrarr;
}

/* free the string array */
C_BOOL str_arr_free(STR_ARR * pStrarr){
	if (NULL == pStrarr){
		printf("The string array is an empty pointer!!\n");
		return C_FALSE;
	}

	if (C_FALSE == str_arr_free_array(pStrarr->pAddr)){
		return C_FALSE;
	}

	free(pStrarr);
	pStrarr = NULL;
	return C_TRUE;
}
	
static C_BOOL str_arr_free_array(const char ** pAddr){
	if (NULL == pAddr){
		printf("the pAddr is empty already!!\n");
		return C_FALSE;
	}

	free(pAddr);
	pAddr = NULL;
	return C_TRUE;
}

/* extend the length of array */
static C_BOOL str_arr_extend(STR_ARR * pStrarr, int len){
	const char ** pAddr = (const char **)realloc(pStrarr->pAddr, sizeof(const char *) * (pStrarr->max_len + len));
	if (NULL == pAddr){
		printf("fail to extend memory!!\n");
		return C_FALSE;
	}

	pStrarr->pAddr = pAddr;

	int i;
	for (i=0; i<len; i++){
		pStrarr->pAddr[pStrarr->max_len + i] = NULL;
	}

	(pStrarr->max_len)+=len;
	return C_TRUE;
}

/* judge whether the string array is initialed */
static void str_arr_judge_init(STR_ARR * pStrarr){
	if (C_FALSE == pStrarr->is_initialed){
		base_error("The string array is not initialed yet!");
	}
}

/* add a string to tail of the the array */
static C_BOOL str_arr_add(STR_ARR * pStrarr, const char * pStr){
	if (C_TRUE == pStrarr->is_full(pStrarr)){
		if (C_FALSE == str_arr_extend(pStrarr, (int)(pStrarr->max_len / 2))){
			return C_FALSE;
		}
	}

	pStrarr->pAddr[pStrarr->cur_len] = pStr;
	pStrarr->cur_len++;
	return C_TRUE;
}

/* insert a string to any place of the the array */
static C_BOOL str_arr_insert(STR_ARR * pStrarr, int index, const char * pStr){
	str_arr_judge_init(pStrarr);

	if (0 > index || (pStrarr->cur_len - 1) < index){
		printf("index is over scope!!\n");
		return C_FALSE;
	}

	if (C_TRUE == pStrarr->is_full(pStrarr)){
		if (C_FALSE == str_arr_extend(pStrarr, (int)(pStrarr->max_len / 2))){
			return C_FALSE;
		}
	}

	int i;
	for (i = pStrarr->cur_len - 1; i >= index; i--){
		pStrarr->pAddr[i + 1] = pStrarr->pAddr[i];
	}

	pStrarr->pAddr[index] = pStr;	
	pStrarr->cur_len++;
	return C_TRUE;
}

/* delete a node, an return to output parameter */
static C_BOOL str_arr_delete(STR_ARR * pStrarr, int index, const char ** pPStr){
	str_arr_judge_init(pStrarr);
	if (0 > index || index > pStrarr->max_len - 1){
		printf("index is over scope!!\n");
		return C_FALSE;
	}

	*pPStr = pStrarr->pAddr[index];
	int i;
	for (i = index; i < pStrarr->max_len - 1; i++){
		pStrarr->pAddr[i] = pStrarr->pAddr[i + 1];
	}

	pStrarr->cur_len--;
	return C_TRUE;
}

/* change val of an element of array */
static C_BOOL str_arr_set_val(STR_ARR * pStrarr, int index, const char * pStr){
	str_arr_judge_init(pStrarr);

	if (0 > index || (pStrarr->cur_len - 1) < index){
		printf("set_val: index is over scope!\n");
		return C_FALSE;
	}

	pStrarr->pAddr[index] = pStr;
	return C_TRUE;
}

/* get string from the array by index */
static const char * str_arr_get_val(STR_ARR * pStrarr, int index){
	str_arr_judge_init(pStrarr);

	if (0 > index || index > pStrarr->max_len - 1){
		printf("index is over scope!!\n");
		return NULL;
	}

	return pStrarr->pAddr[index];
}

/* whether the string is empty */
static C_BOOL str_arr_is_empty(STR_ARR * pStrarr){
	str_arr_judge_init(pStrarr);
	if (0 == pStrarr->cur_len){
			return C_TRUE;
	}
	return C_FALSE;
}

/* whether the string is full */
static C_BOOL str_arr_is_full(STR_ARR * pStrarr){
	str_arr_judge_init(pStrarr);
	if (pStrarr->cur_len >=  pStrarr->max_len){
		return C_TRUE;
	}
	return C_FALSE;
}

/* printf all the string of the array */
static void str_arr_print(STR_ARR * pStrarr){
	if (C_TRUE == pStrarr->is_empty(pStrarr)){
		printf("the string array is empty");
		return;
	}
	
	int i;
	for (i=0; i < pStrarr->cur_len; i++){
		if (NULL != pStrarr->pAddr[i]){
			printf("%s", pStrarr->pAddr[i]);
		}else{
			printf("NULL");
		}

		if (i < pStrarr->cur_len - 1){
			printf(", ");
		}
	}
	printf("\n");
	return;
}
