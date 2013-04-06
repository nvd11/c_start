#include "bool_me.h"
#ifndef __LINKTABLE1_H_H
#ifndef __LINKTABLE1_H_H

	struct person{
		int id;
		char * name[];
		struct person * pnext;
	};
	
	typedef struct person PERSON;

	PERSON link_create(void); //assign a piece of memory to the head_node, and return address of head node

















#endif
