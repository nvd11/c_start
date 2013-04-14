#include <stdio.h>
#include "stuck1.h"
#include "stdlib.h"
#include "string.h"



static void st_error(const char * pErr);

PERSON_ST * person_st_new(int id, char * pname){
	PERSON_ST * pnode = (PERSON_ST *)malloc(sizeof(PERSON_ST));
	if (NULL == pnode){
		st_error("fail to assign memory to new node");
	}
	pnode->id=id;
	strncpy(pnode->name, pname+0,15);
	return pnode;
}

void person_st_print(PERSON_ST * pnode){
	printf("id is %d, name is %s\n",pnode->id, pnode->name);
}


//create a stuck with dynamic linklist
STPERSON * st_create(void){
	STPERSON * pSt = (STPERSON *)malloc(sizeof(STPERSON));
	pSt->phead = (PERSON_ST *)malloc(sizeof(PERSON_ST));
	if (NULL == pSt->phead){
		st_error("fail to assign memory to headnode");
	}

	pSt->pbuttom = (PERSON_ST *)malloc(sizeof(PERSON_ST));
	if (NULL == pSt->pbuttom){
		st_error("fail to assign memory to buttom");
	}

	pSt->pbuttom = (PERSON_ST *)malloc(sizeof(PERSON_ST));

	pSt->phead->id=0;
	pSt->pbuttom->id=-1;
	pSt->phead->pnext = pSt->pbuttom;
	pSt->pbuttom->pnext=NULL;
	pSt->len=0;
	pSt->is_inited = TRUE;
	return pSt;
}


//judge whether the stuck is empty (phead->pnext == pbutton)
BOOL st_is_empty(STPERSON * pSt){
	if (TRUE != pSt->is_inited){
		st_error("the stuck is not initialed yet");
	}

	if (pSt->phead->pnext == pSt->pbuttom){
		return TRUE;
	}

	return FALSE;
}


//push a new element into the stuck
BOOL st_push(STPERSON * pSt, PERSON_ST * pnode){
	if (TRUE != pSt->is_inited){
		printf("the stuck is not initialed yet\n");
		return FALSE;
	}

	pnode->pnext = pSt->phead->pnext;
	pSt->phead->pnext = pnode;
	pSt->len++;
	return TRUE;
}

//traverse the stuck to print all the elements
void st_print(STPERSON * pSt){
	if (TRUE != pSt->is_inited){
		printf("the stuck is not initialed yet, fail to print it\n");
		return;
	}

	if (TRUE == st_is_empty(pSt)){
		printf("the stuck is empty!\n");
		return;
	}

	PERSON_ST * pnode = pSt->phead;
	while (pSt->pbuttom != pnode->pnext){
		pnode = pnode->pnext;
		person_st_print(pnode);
	}
}


//pop a top element out from the stuck
BOOL st_pop(STPERSON * pSt, PERSON_ST ** pOutput){
	if (TRUE != pSt->is_inited){
		printf("the stuck is not initialed yet\n");
		return FALSE;
	}

	if (TRUE == st_is_empty(pSt)){
		printf("the stuck is empty!\n");
		return FALSE;
	}

	*pOutput = pSt->phead->pnext; //ptop
	pSt->phead->pnext = (*pOutput)->pnext;

	pSt->len--;
	return TRUE;
}

//traverse the stuck to free all the elements
BOOL st_free(STPERSON * pSt){
	st_clear(pSt);

	free(pSt->phead);
	free(pSt->pbuttom);

	free(pSt);
	pSt=NULL;
	return TRUE;
}

BOOL st_clear(STPERSON * pSt){
	if (TRUE != pSt->is_inited){
		printf("the stuck is not initialed yet\n");
		return FALSE;
	}

	PERSON_ST * pnode = pSt->phead;
	PERSON_ST * pAfter = pnode->pnext;
	//free(pnode); do not free phead;
	while (pSt->pbuttom != pAfter){ //do not free the pbuttom
		pnode=pAfter;
		printf("free pnode which id is %d\n",pnode->id);
		pAfter=pnode->pnext;
		free(pnode);
	}

	//free(pSt); do not free the stuck
	pSt->phead->pnext = pSt->pbuttom;
	pSt->len=0;
	return TRUE;
}

static void st_error(const char * pErr){
	printf("%s\n",pErr);
	exit(-1);
}
