#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist1.h"

static void link_error(const char * pErr);
PERSON * person_new(int id, char * pname);
BOOL link_add(LINKPERSON * pLink, PERSON * pnode);
static void person_print(PERSON * pnode);


LINKPERSON * link_create(int len){
	LINKPERSON * pLink = (LINKPERSON *)malloc(sizeof(LINKPERSON));
	if (NULL == pLink){
		link_error("fail to assign memory to LINKPERSON");
	}

	PERSON * phead = (PERSON *)malloc(sizeof(PERSON));
	if (NULL == phead){
		link_error("fail to assign memory to headnode");
	}

	phead->pnext = NULL;
	pLink->phead = phead;
	pLink->ptail = phead;
	pLink->len = 0;
	pLink->is_inited = TRUE;

	if (len==0){
		return pLink;
	}

	int i;
	char * name[16];
	PERSON * pnode;
	for(i=0;i<len;i++){
		char name[16];
		sprintf(name,"node%d",i+1);
		pnode = person_new(i+1,name);
		if (FALSE == link_add(pLink,pnode)){
			link_error("fail to add nodes!");
		}
	}

	return pLink;
}


BOOL link_add(LINKPERSON * pLink, PERSON * pnode){
	if (TRUE != pLink->is_inited){
		link_error("the linklist is not inited yet");
	}

	//judge whether pnode is existed in the linklist already
	PERSON * pn = pLink->phead;
	while (NULL != pn->pnext){
		if (pn == pnode){
			printf("this node is existed in linklist already\n");
			return FALSE;
		}
		pn = pn->pnext;
	}

	pLink->ptail->pnext = pnode;
	pnode->pnext = NULL;
	pLink->ptail = pnode;
	return TRUE;
}

void link_traverse(LINKPERSON * pLink){
	if (TRUE != pLink->is_inited){
		link_error("the linklist is not inited yet");
	}

	if (TRUE == link_is_empty(pLink)){
		printf("the linklist is emptyi!");
		return;
	}

	PERSON * pnode;
	pnode = pLink->phead->pnext;  //phead->pnext

	while (NULL != pnode->pnext){
		person_print(pnode);
		pnode = pnode->pnext;
	}

	return;
}




BOOL link_is_empty(LINKPERSON * pLink){
	if (TRUE != pLink->is_inited){
		link_error("the linklist is not inited yet");
	}

	if (NULL == pLink->phead->pnext){
		return TRUE;
	}

	return FALSE;
}


static void link_error(const char * pstr){
	printf("%s\n", pstr);
	exit(-1);
}

static void person_print(PERSON * pnode){
	printf("id is %d, name is %s\n", pnode->id, pnode->name );
}

PERSON * person_new(int id, char * pname){
	PERSON * pnode;
	pnode = (PERSON *)malloc(sizeof(PERSON));
	if (NULL == pnode){
		link_error("fail to assign memory to PERSON");
	}

	pnode->id = id;
	strcpy(pnode->name, pname);
	pnode->pnext = NULL;
	return pnode;
}
