#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist1.h"

static void link_error(const char * pErr);
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

	if (NULL == pnode){
		printf("pnode is empty!\n");
		return -1;
	}

	//judge whether pnode is existed in the linklist already
	if (link_getindex(pLink,pnode) > -1){
		printf("the node is existed in linklist already!\n");
		return FALSE;
	}

	pLink->ptail->pnext = pnode;
	pnode->pnext = NULL;
	pLink->ptail = pnode;
	pLink->len++;
	return TRUE;
}

void link_traverse(LINKPERSON * pLink){
	if (TRUE != pLink->is_inited){
		link_error("the linklist is not inited yet");
	}

	if (TRUE == link_is_empty(pLink)){
		printf("the linklist is empty\n!");
		return;
	}

	PERSON * pnode;
	pnode = pLink->phead;  //phead

	while(NULL != pnode->pnext){
		pnode = pnode->pnext;
		person_print(pnode);
	}
	return;
}

PERSON * link_getnode(LINKPERSON * pLink, int index){
	if (TRUE != pLink->is_inited){
		link_error("the linklist is not inited yet");
	}

	if ( index < 0 || index > (pLink->len -1)){
		printf("index is over the limits");
		return NULL;	
	}
	
	int i;
	PERSON * pnode = pLink->phead;	
	for( i=0;i <= index ;i++){
		pnode = pnode->pnext;
			
	}  	

	return pnode;
}


int link_getindex(LINKPERSON * pLink, PERSON * pnode){
	if (TRUE != pLink->is_inited){
		link_error("the linklist is not inited yet");
	}

	if (NULL == pnode){
		printf("pnode is empty!\n");
		return -1;
	}

	PERSON * pn = pLink->phead;
	int i=0;
	while (NULL != pn->pnext){
		if (pn == pnode){
			return i;
		}
		i++;
		pn = pn->pnext;
	}

	return -1;
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

BOOL link_insert(LINKPERSON * pLink, PERSON * pBefore, PERSON * pnode){
	if (TRUE != pLink->is_inited){
		link_error("the linklist is not inited yet");
	}

	if (NULL == pBefore || NULL == pnode){
		printf("pBefore or pnode is empty!\n");
		return FALSE;
	}

	if (0 > link_getindex(pLink,pBefore)){
		printf("pBefore is not existed in linklist!\n");
		return FALSE;
	}

	if (-1 < link_getindex(pLink,pnode)){
		printf("pnode is existed in linklist already!\n");
		return FALSE;
	}

	pnode->pnext = pBefore->pnext;
	pBefore->pnext = pnode;

	if (NULL == pnode->pnext){
		pLink->ptail = pnode;
	}

	pLink->len++;
	return TRUE;
}

BOOL link_insertbyindex(LINKPERSON * pLink, int index, PERSON * pnode){
	if (TRUE != pLink->is_inited){
		link_error("the linklist is not inited yet");
	}

	return link_insert(pLink, link_getnode(pLink, index), pnode);
}

BOOL link_remove(LINKPERSON * pLink, PERSON * pnode){
	if (TRUE != pLink->is_inited){
		link_error("the linklist is not inited yet");
	}

	if (NULL == pnode){
		printf("pnode is empty!\n");
		return -1;
	}

	PERSON * pBefore = pLink->phead;
	while (NULL != pBefore->pnext ){
		if (pBefore->pnext == pnode){
			pBefore->pnext = pnode->pnext;
			if (NULL == pBefore->pnext){ // pnode is ptail;
				pLink->ptail = pBefore;
				pLink->len--;
				return TRUE;
			}
		}

		pBefore = pBefore->pnext;
	}

	return FALSE; //pnode is not existed in the linklist before.
}

BOOL link_delete(LINKPERSON * pLink, int index){
	if (TRUE != pLink->is_inited){
		link_error("the linklist is not inited yet");
	}

	PERSON * pnode = link_getnode(pLink, index);
	if (NULL == pnode){
		return FALSE;
	}

	if (TRUE == link_remove(pLink, pnode)){
		free(pnode);
		return TRUE;
	}

	return FALSE;

}


//clear a Linklist
BOOL link_clear(LINKPERSON * pLink){
	if (TRUE != pLink->is_inited){
		link_error("the linklist is not inited yet");
	}

	pLink->phead-> pnext = NULL;
	pLink->ptail = pLink->phead;
	pLink->len=0;
	return TRUE;
}

BOOL link_free(LINKPERSON * pLink){
	if (TRUE != pLink->is_inited){
		link_error("the linklist is not inited yet");
	}

	PERSON * pnode = pLink->phead;
	PERSON * pAfter =pnode->pnext;
	while(NULL != pAfter){
		pnode=pAfter;
		pAfter = pnode->pnext;
		free(pnode);
	}

	free(pLink);
	return TRUE;

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
