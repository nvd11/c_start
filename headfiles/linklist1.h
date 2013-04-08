#include "bool_me.h"
#ifndef __LINKLIST1_H_H
#define __LINKLIST1_H_H

	struct person{
		int id;
		char name[16];
		struct person * pnext;
	};
	
	typedef struct person PERSON;

	struct Link_person{   //just a struct for linklist,  it is not a node of linklist
		PERSON * phead;   //address of the Headnode of linklist
		PERSON * ptail;  // address of the tailnode, yes it's not a neccssity, but it can make the operation easily
		int len; //numbers of the nodes which contains the userful data.it's not a neccssity, but it can make the operation easily
		BOOL is_inited; // judge whether the linklist is inited
	};
		

	typedef struct Link_person LINKPERSON;

	//init a new block()
	PERSON * person_new(int id,char *pname);

	//init a Linklist
	LINKPERSON * link_create(int len);

	//judge whether the linklist is empty
	BOOL link_is_empty(LINKPERSON * pLink);

	//add a node to the tail of Linklist
	BOOL link_add(LINKPERSON * plink, PERSON * pnode);
	
   //traverse the linklist to print all of the node of linklist;
	void link_traverse(LINKPERSON * pLink);

   //insert a node behind another node
	BOOL link_insert(LINKPERSON * pLink, PERSON * pBefore, PERSON * pnode);
	
   //insert a node behind another node
	BOOL link_insertbyindex(LINKPERSON * pLink, int index, PERSON * pnode);

   //remove a node from the linklist
	BOOL link_remove(LINKPERSON * pLink, PERSON * pnode);

   //delete a node from the linklist, and free the memory space of the node
	BOOL link_delete(LINKPERSON * pLink, int index);
	
	//get a the index of a node, if not existed, return -1
	int link_getindex(LINKPERSON * pLink, PERSON * pnode);
	
	//get the length of Linklist
	int link_getlength(LINKPERSON * pLink);	

	//clear a Linklist
	BOOL link_clear(LINKPERSON * pLink);
 
	//destroy a Linklist
	BOOL link_free(LINKPERSON * pLink);
	
	//sort by id
	void link_sort(LINKPERSON * pLink);

	//get a node from linklist by index
	PERSON * link_getnode(LINKPERSON * pLink, int index);

#endif
