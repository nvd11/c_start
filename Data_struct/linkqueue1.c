/*
 * linkqueue1.c
 *
 *  Created on: 2013-4-15
 *      Author: gateman
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkqueue1.h"
#include "basefuncs.h"


//create a new node with dynamic memory assigned
PERSON_LQ * person_lq_new(int id, char * pname){
	PERSON_LQ * pnode = (PERSON_LQ *)malloc(sizeof(PERSON_LQ));
	if (NULL == pnode){
		base_error("fail to assign memory to a new node!");
	}

	pnode->id = id;
	strncpy(pnode->name, pname+0, 15);
	pnode->pNext=NULL;
	return pnode;
}


//print the information of a node
void person_lq_print(PERSON_LQ * pnode){
	printf("id is %d, name is %s\n",pnode->id, pnode->name);
}


//create a stuck with dynamic linklist
LQPERSON * lqperson_new(void){
	LQPERSON * pLq = (LQPERSON *)malloc(sizeof(LQPERSON));
	if (NULL == pLq){
		base_error("fail to assign memory to a linkqueue!");
	}

	pLq->pHead = person_lq_new(-1,"Head");
	pLq->pRear = pLq->pHead; //empty queue;
	pLq->len=0;
	pLq->is_inited = C_TRUE;
	return pLq;
}


//judge whether the link_queue is empty
C_BOOL lq_is_empty(LQPERSON * pLq){
	if (C_TRUE != pLq->is_inited){
		base_error("the linkqueue is not initailed yet!");
	}

	if (pLq->pRear == pLq->pHead){
		return C_TRUE;
	}

	return C_FALSE;
}


//add an element into the queue
void lq_Enqueue(LQPERSON * pLq, PERSON_LQ * pnode){
	if (C_TRUE != pLq->is_inited){
		base_error("the linkqueue is not initailed yet!");
	}

	pLq->pRear->pNext = pnode;
	pLq->pRear = pnode;
	pnode->pNext=NULL;

	pLq->len++;
}


//traverse the queue to print all the elements
void lq_print(LQPERSON * pLq){
	if (C_TRUE != pLq->is_inited){
		base_error("the linkqueue is not initailed yet!");
	}

	if (C_TRUE == lq_is_empty(pLq)){
		printf("the linkqueue is empty!\n");
	}

	PERSON_LQ * pnode = pLq->pHead;
	while(NULL != pnode->pNext){
		pnode=pnode->pNext;
		person_lq_print(pnode);
	}
}


//remove an element from the queue, and get the element
C_BOOL lq_Dequeue(LQPERSON * pLq, PERSON_LQ ** pOutput){
	if (C_TRUE != pLq->is_inited){
		base_error("the linkqueue is not initailed yet!");
	}

	if (C_TRUE == lq_is_empty(pLq)){
		printf("the linkqueue is empty!\n");
		return C_FALSE;
	}

	*pOutput = pLq->pHead->pNext;
	pLq->pHead->pNext = (*pOutput)->pNext;

	//if it's the last one
	if(pLq->pRear == *pOutput){
		pLq->pRear = pLq->pHead; //empty
	}

	pLq->len--;
	return C_TRUE;
}

//put out and free all the elements from the queue
void lq_clear(LQPERSON * pLq){
	if (C_TRUE != pLq->is_inited){
		base_error("the linkqueue is not initailed yet!");
	}

	PERSON_LQ * pnode = pLq->pHead;
	PERSON_LQ * pnext = pnode->pNext;
	while(NULL != pnext){
		pnode = pnext;
		pnext = pnode->pNext;
		free(pnode);
	}

	pLq->pHead->pNext=NULL;
	pLq->pRear = pLq->pHead;
	pLq->len=0;
}


//free all the elements, and free the queue
void lq_free(LQPERSON * pLq){
	lq_clear(pLq);
	free(pLq->pHead);
	free(pLq);
}

