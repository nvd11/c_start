#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist1.h"

static void link_error(const char * pErr);



static void link_error(const char * pstr){
	while (*pstr !='\0'){
		printf("%c", *pstr);
		pstr++;
	}

	printf("\n");
	exit(-1);
}

PERSON * person_new(int id, char * pname){
	PERSON * pnode;
	pnode = (PERSON *)malloc(sizeof(PERSON));
	pnode->id = id;
	strcpy(pnode->name, pname);
	pnode->pnext = NULL;
}

BOOL link_init(LINKPERSON * pLink, int len){

	return TRUE;
}
