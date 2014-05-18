#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist1.h"

static void link_error(const char * pstr);
static void person_print(PERSON * pnode);
static void link_exchange(PERSON * pPB, PERSON * pAB);

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
	pLink->is_inited = C_TRUE;

	if (len==0){
		return pLink;
	}

	int i;
	//char * name[16];
	PERSON * pnode;
	for(i=0;i<len;i++){
		char name[16];
		sprintf(name,"node%d",i+1);
		pnode = person_new(i+1,name);
		if (C_FALSE == link_add(pLink,pnode)){
			link_error("fail to add nodes!");
		}
	}

	return pLink;
}


C_BOOL link_add(LINKPERSON * pLink, PERSON * pnode){
	if (C_TRUE != pLink->is_inited){
		link_error("the linklist is not inited yet");
	}

	if (NULL == pnode){
		printf("pnode is empty!\n");
		return -1;
	}

	//judge whether pnode is existed in the linklist already
	if (link_getindex(pLink,pnode) > -1){
		printf("the node is existed in linklist already!\n");
		return C_FALSE;
	}

	pLink->ptail->pnext = pnode;
	pnode->pnext = NULL;
	pLink->ptail = pnode;
	pLink->len++;
	return C_TRUE;
}

void link_traverse(LINKPERSON * pLink){
	if (C_TRUE != pLink->is_inited){
		link_error("the linklist is not inited yet");
	}

	if (C_TRUE == link_is_empty(pLink)){
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
	if (C_TRUE != pLink->is_inited){
		link_error("the linklist is not inited yet");
	}

	if ( index < 0 || index > (pLink->len -1)){
		printf("index is over the limit\n");
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
	if (C_TRUE != pLink->is_inited){
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





C_BOOL link_is_empty(LINKPERSON * pLink){
	if (C_TRUE != pLink->is_inited){
		link_error("the linklist is not inited yet");
	}

	if (NULL == pLink->phead->pnext){
		return C_TRUE;
	}

	return C_FALSE;
}

C_BOOL link_insert(LINKPERSON * pLink, PERSON * pPre, PERSON * pnode){
	if (C_TRUE != pLink->is_inited){
		link_error("the linklist is not inited yet");
	}

	if (NULL == pPre || NULL == pnode){
		printf("pPre or pnode is empty!\n");
		return C_FALSE;
	}

	if (0 > link_getindex(pLink,pPre)){
		printf("pPre is not existed in linklist!\n");
		return C_FALSE;
	}

	if (-1 < link_getindex(pLink,pnode)){
		printf("pnode is existed in linklist already!\n");
		return C_FALSE;
	}

	pnode->pnext = pPre->pnext;
	pPre->pnext = pnode;

	if (NULL == pnode->pnext){
		pLink->ptail = pnode;
	}

	pLink->len++;
	return C_TRUE;
}

C_BOOL link_insertbyindex(LINKPERSON * pLink, int index, PERSON * pnode){
	if (C_TRUE != pLink->is_inited){
		link_error("the linklist is not inited yet");
	}

	return link_insert(pLink, link_getnode(pLink, index), pnode);
}

C_BOOL link_remove(LINKPERSON * pLink, PERSON * pnode){
	if (C_TRUE != pLink->is_inited){
		link_error("the linklist is not inited yet");
	}

	if (NULL == pnode){
		printf("pnode is empty!\n");
		return -1;
	}

	PERSON * pPre = pLink->phead;
	while (NULL != pPre->pnext ){
		if (pPre->pnext == pnode){
			pPre->pnext = pnode->pnext;
			if (NULL == pPre->pnext){ // pnode is ptail;
				pLink->ptail = pPre;
				pLink->len--;
				return C_TRUE;
			}
		}

		pPre = pPre->pnext;
	}

	return C_FALSE; //pnode is not existed in the linklist before.
}

C_BOOL link_delete(LINKPERSON * pLink, int index){
	if (C_TRUE != pLink->is_inited){
		link_error("the linklist is not inited yet");
	}

	PERSON * pnode = link_getnode(pLink, index);
	if (NULL == pnode){
		return C_FALSE;
	}

	if (C_TRUE == link_remove(pLink, pnode)){
		free(pnode);
		return C_TRUE;
	}

	return C_FALSE;

}


//clear a Linklist
C_BOOL link_clear(LINKPERSON * pLink){
	if (C_TRUE != pLink->is_inited){
		link_error("the linklist is not inited yet");
	}

	pLink->phead-> pnext = NULL;
	pLink->ptail = pLink->phead;
	pLink->len=0;
	return C_TRUE;
}

C_BOOL link_free(LINKPERSON * pLink){
	if (C_TRUE != pLink->is_inited){
		link_error("the linklist is not inited yet");
	}

	PERSON * pnode = pLink->phead;
	PERSON * pAfter =pnode->pnext;

	//printf("free pnode which id is %d\n",pnode->id);
	free(pnode); //free phead
	while(NULL != pAfter){
		pnode=pAfter;
		//printf("free pnode which id is %d\n",pnode->id);
		pAfter = pnode->pnext;
		free(pnode);
	}

	free(pLink);
	return C_TRUE;

}
static void link_error(const char * pstr){
	printf("%s\n", pstr);
	exit(-1);
}

static void person_print(PERSON * pnode){
	printf("id is %d, name is %s\n", pnode->id, pnode->name );
}


//sort by id
void link_sort(LINKPERSON * pLink){
	if (C_TRUE != pLink->is_inited){
		link_error("the linklist is not inited yet");
	}

	if (pLink->len < 2){
		return;
	}

	PERSON * pPre; //phead
	PERSON * pAfter;

	PERSON * pPB; //used to save the node address which before the pPre
	PERSON * pAB; //used to save the node address which before the pAfter
	PERSON * m;

	for (pPB=pLink->phead,pPre=pLink->phead->pnext; NULL != pPre->pnext; pPB=pPre,pPre=pPre->pnext){
		for (pAB=pPre,pAfter=pPre->pnext; NULL != pAfter; pAB=pAfter,pAfter=pAfter->pnext){
			if (pPre->id > pAfter->id){
				link_exchange(pPB,pAB);
				m = pPre;
				pPre = pAfter;
				pAfter = m;
			};
		}
	}
}

static void link_exchange(PERSON * pPB, PERSON * pAB){
	//this function will exchange the place of the next nodes of pPB and pAB
	//if pPB->pnext == pPre ; pAB->pnext == pAfter
	//after exchange, pPre and pAfter will exchange their index in the linklist

	PERSON * m;
	//first , exchange their Pre node;
	m = pPB->pnext;
	pPB->pnext = pAB->pnext;
	pAB->pnext = m;

	//then . exchange their next node;
	m=pPB->pnext->pnext;
	pPB->pnext->pnext = pAB->pnext->pnext;
	pAB->pnext->pnext = m;
}

void link_sort2(LINKPERSON * pLink){
	if (C_TRUE != pLink->is_inited){
		link_error("the linklist is not inited yet");
	}

	if (pLink->len < 2){
		return;
	}

	PERSON * pPre = pLink->phead; //phead
	PERSON * pAfter;

	PERSON * pBB; //used to save the node address which before the pBfore
	PERSON * pAB; //used to save the node address which before the pAfter

	int m;
	while(NULL != pPre->pnext){
		pBB=pPre;
		pPre = pPre->pnext;
		pAB=pPre;
		pAfter = pPre->pnext;
		while(NULL != pAfter){
			if (pPre->id > pAfter->id){
				m = pPre->id;
				pPre->id = pAfter->id;
				pAfter->id = m;
			}
			pAB = pAfter;
			pAfter = pAfter->pnext;
		}
	}
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
