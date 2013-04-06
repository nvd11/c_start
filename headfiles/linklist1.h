#include "bool_me.h"
#ifndef __LINKLIST1_H_H
#ifndef __LINKLIST1_H_H

	struct person{
		int id;
		char * name[];
		struct person * pnext;
	};
	
	typedef struct person PERSON;

	struct Link_person{   //just a struct for link
		

	PERSON link_create(int len); //assign a piece of memory to the head_node, and return address of head node

	void link_traverse(PERSON * phead);
	
















#endif
