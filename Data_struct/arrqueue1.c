/*
 * arrqueue1.c
 *
 *  Created on: 2013-4-19
 *      Author: gateman
 */
#include "bool_me.h"
#include "arrqueue1.h"
#include "basefuncs.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static int aq_len(AQ_PERSON * pAq);
static BOOL aq_is_full(AQ_PERSON * pAq);
static BOOL aq_is_empty(AQ_PERSON * pAq);
static BOOL aq_extend(AQ_PERSON * pAq, int exlen);
static BOOL aq_enqueue(AQ_PERSON * pAq, int id, char * pname);
static BOOL aq_enqueue_bystruct(AQ_PERSON * pAq, PERSON_AQ * pnode);
static BOOL aq_dequeue(AQ_PERSON * pAq, PERSON_AQ * pnode);
static void aq_print(AQ_PERSON * pAq);
static void aq_print_all_id_status(AQ_PERSON * pAq);
static BOOL is_in_queue(AQ_PERSON * pAq, int index);
void person_aq_print(PERSON_AQ * pnode);

//initail and return an array queue with dynamic memory assiganed
AQ_PERSON * aq_person_new(int arrlen){
	if (arrlen <= 1){
		printf("length of array must > 1!!\n");
		return NULL;
	}

	AQ_PERSON *  pAq;
	pAq = (AQ_PERSON *)malloc(sizeof(AQ_PERSON));
	if (NULL == pAq){
		base_error("fail to assign memory to a new array queue!!");
	}

	pAq->pArr = (PERSON_AQ *)malloc(sizeof(PERSON_AQ) * arrlen);
	if (NULL == pAq->pArr){
		base_error("fail to assign memory to a new array queue!!");
	}


	pAq->Front = 0;
	pAq->Rear = 0;
	pAq->arrlen = arrlen;

	pAq->len = aq_len;
	pAq->is_full = aq_is_full;
	pAq->is_empty = aq_is_empty;
	pAq->extend = aq_extend;
	pAq->en_queue = aq_enqueue;
	pAq->en_queue_by_struct = aq_enqueue_bystruct;
	pAq->de_queue = aq_dequeue;
	pAq->print = aq_print;
	pAq->print_arr_id_st = aq_print_all_id_status;

	pAq->is_inited = TRUE;
	return pAq;
}

//get the length of array queue
static int aq_len(AQ_PERSON * pAq){
	if (TRUE != pAq->is_inited){
		base_error("the array queue is not initialed!!");
	}

	return (pAq->Rear - pAq->Front + pAq->arrlen) % pAq->arrlen;
}

//judge whether the array queue is full
static BOOL aq_is_full(AQ_PERSON * pAq){
	if (TRUE != pAq->is_inited){
		base_error("the array queue is not initialed!!");
	}

	if ((pAq->Rear +1) % pAq->arrlen == pAq->Front){
		return TRUE;
	}

	return FALSE;
}

static BOOL aq_is_empty(AQ_PERSON * pAq){
	if (TRUE != pAq->is_inited){
		base_error("the array queue is not initialed!!");
	}

	if (pAq->Front == pAq->Rear){
		return TRUE;
	}

	return FALSE;
}

//add an elements to rear of queue by id and name
static BOOL aq_enqueue(AQ_PERSON * pAq, int id, char * pname){
	if (TRUE != pAq->is_inited){
		base_error("the array queue is not initialed!!");
	}

	if (TRUE == pAq->is_full(pAq)){
		if(FALSE == pAq->extend(pAq, pAq->arrlen/2)){
			return FALSE;
		}
	}

	pAq->pArr[pAq->Rear].id = id;
	strncpy(pAq->pArr[pAq->Rear].name, pname+0, 16);

	pAq->Rear = (pAq->Rear + 1) % pAq->arrlen;
	return TRUE;
}

static BOOL aq_enqueue_bystruct(AQ_PERSON * pAq, PERSON_AQ * pnode){
	return aq_enqueue(pAq, pnode->id, pnode->name);
}

//extend the max length of array queue
static BOOL aq_extend(AQ_PERSON * pAq, int exlen){
	PERSON_AQ * pold;
	pold = pAq->pArr;
	pAq->pArr = (PERSON_AQ *)realloc(pAq->pArr, sizeof(PERSON_AQ) * (pAq->arrlen + exlen));
	if (NULL == pAq->pArr){
		printf("fail to assign memory to extend the array!\n");
		pAq->pArr = pold;
		return FALSE;
	}

//	realloc will free the old memory automatically,
//	it's now allow to free it manual!!!
//	if (pAq->pArr != pold){
//		free(pold);
//	}

	if (pAq->Rear < pAq->Front){
		int i;
		for (i=pAq-> arrlen - pAq->Front; i>0; i--){
			pAq->pArr[pAq->Front+i-1+exlen] = pAq->pArr[pAq->Front + i - 1];
		}
		pAq->Front += exlen;
	}

	pAq->arrlen += exlen;
	return TRUE;
}

//dequeue
static BOOL aq_dequeue(AQ_PERSON * pAq, PERSON_AQ * pnode){
	if (TRUE != pAq->is_inited){
		base_error("the array queue is not initialed!!");
	}

	if (TRUE == pAq->is_empty(pAq)){
		printf("the array queue is empty!\n");
		return FALSE;
	}

	pnode->id = pAq->pArr[pAq->Front].id;
	strncpy(pnode->name, pAq->pArr[pAq->Front].name+0, 16);
	pAq->Front = (pAq->Front + 1) % pAq->arrlen;
	return TRUE;
}

//print all the elements of array queue
static void aq_print(AQ_PERSON * pAq){
	if (TRUE != pAq->is_inited){
		base_error("the array queue is not initialed!!");
	}

	if (TRUE == pAq->is_empty(pAq)){
		printf("the array queue is empty!\n");
	}

	int index;
	index = pAq->Front;
	while(index != pAq->Rear){
   	person_aq_print(&(pAq->pArr[index]));
		index = (index+1) % pAq->arrlen;
	}
}

//print all the id of element in the array, not only in queue
static void aq_print_all_id_status(AQ_PERSON * pAq){
	if (TRUE != pAq->is_inited){
		base_error("the array queue is not initialed!!");
	}

	if (TRUE == pAq->is_empty(pAq)){
		printf("the array queue is empty!\n");
		return;
	}


	int  index;
	for (index=0; index < pAq->arrlen; index++){
		if (TRUE == is_in_queue(pAq, index)){
			printf("%d", pAq->pArr[index].id);
		}
		else{
			printf("x");
		}

		if (index < pAq->arrlen -1){
			printf(", ");
		}
	}

	printf("\n");
	return;
}

//judge whether an element of the array is in the queue
static BOOL is_in_queue(AQ_PERSON * pAq, int index){
	int Front= pAq->Front;
	int Rear = pAq->Rear;
	if (Front == Rear){
		return FALSE;
	}
	else if (Front < Rear){
		if (index >= Front && index < Rear){
			return TRUE;
		}
		return FALSE;
	}
	else{ //Front > Rear
		if (index < Rear || index >= Front){
			return TRUE;
		}
		return FALSE;
	}
}

//print an structure object
void person_aq_print(PERSON_AQ * pnode){
	printf("id is %d, name is %s\n", pnode->id, pnode->name);
}

//free the memory of array queue
BOOL aq_person_free(AQ_PERSON * pAq){
	if (TRUE != pAq->is_inited){
		printf("the array queue is not initialed!!\n");
		return FALSE;
	}

	free(pAq->pArr);
	free(pAq);
	return TRUE;
}
