#include "bool_me.h"
#ifndef __STUCK1_H_
#define __STUCK1_H_
	struct person_st{ //node
		int id;
		char * name;
		struct person_st * pnext;
	};

	typedef struct person_st PERSON_ST;

	struct stuck_person{ //struct
		PERSON_ST * phead;
		PERSON_ST * pbuttom;
		int len;
		BOOL is_inited;
	};

	typedef struct stuck_person STPERSON;

	//init a new node with dynamic memory
	PERSON_ST * person_st_new(int id, char * pname);

	//printf the infomation of a node
	void person_st_printf(PERSON_ST * pnode);

	//create a stuck with dynamic linklist
	STPERSON * st_create();

	//judge whether the stuck is empty (phead->pnext == pbutton)
	BOOL st_is_empty(STPERSON * pSt);

	//push a new element into the stuck
	BOOL st_push(STPERSON * pSt, PERSON_ST * pPush);

	//pop a top element out from the stuck
	BOOL st_pop(STPERSON * pSt, PERSON_ST ** pOutput);

	//traverse the stuck to print all the elements
	BOOL st_print(STPERSON * pSt);

	//remove all the elements from stuck
	BOOL st_clear(STPERSON * pSt);

	//traverse the stuck to free all the elements
	BOOL st_free(STPERSON * pSt);

#endif
