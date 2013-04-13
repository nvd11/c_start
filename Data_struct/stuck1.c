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
	//strcpy(pnode->name, pname);
	pnode->name = pname;
	return pnode;
}

void person_st_print(PERSON_ST * pnode){
	printf("id is %d, name is %s\n",pnode->id, pnode->name);
}


//create a stuck with dynamic linklist
STPERSON * st_create(){
	STPERSON * pSt = (STPERSON *)malloc(sizeof(STPERSON));
	pSt->phead = (PERSON_ST *)malloc(sizeof(PERSON_ST));
	pSt->pbuttom = (PERSON_ST *)malloc(sizeof(PERSON_ST));

	pSt->phead->pnext = pSt->pbuttom;
	pSt->len=0;
	pSt->is_inited = TRUE;
	return pSt;
}






static void st_error(const char * pErr){
	printf("%s\n",pErr);
	exit(-1);
}
