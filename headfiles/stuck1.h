#include "bool_me.h"
#ifndef __STUCK1_H_
#define __STUCK1_H_
	struct person_st{ //node
		int id;
		char name[16];
		struct person_st * pnext;
	};

	typedef struct person_st PERSON_ST;

	struct stuck_person{ //struct
		PERSON_ST * phead; //address of the headnode of the linklist
		PERSON_ST * pbuttom; // buttom of the stuck
		int len;
		C_BOOL is_inited;
	};

	typedef struct stuck_person STPERSON;

	//init a new node with dynamic memory
	PERSON_ST * person_st_new(int id, char * pname);

	//printf the infomation of a node
	void person_st_print(PERSON_ST * pnode);

	//create a stuck with dynamic linklist
	STPERSON * st_create(void);

	//judge whether the stuck is empty (phead->pnext == pbutton)
	C_BOOL st_is_empty(STPERSON * pSt);

	//push a new element into the stuck
	C_BOOL st_push(STPERSON * pSt, PERSON_ST * pnode);

	//pop a top element out from the stuck
	C_BOOL st_pop(STPERSON * pSt, PERSON_ST ** pOutput);

	//traverse the stuck to print all the elements
	void st_print(STPERSON * pSt);

	//put out and free all the elements from the stuck;
	C_BOOL st_clear(STPERSON *pSt);

	//traverse the stuck to free all the elements, and free the stuck itself
	C_BOOL st_free(STPERSON * pSt);

#endif
