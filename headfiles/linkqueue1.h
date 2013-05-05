/*
 * linkqueue1.h
 *
 *  Created on: 2013-4-15
 *      Author: gateman
 */
#include <bool_me.h>
#ifndef __LINKQUEUE1_H_
#define __LINKQUEUE1_H_

	struct person_linkqueue1{
		int id;
		char name[16];
		struct person_linkqueue1 * pNext;
	};

	typedef struct person_linkqueue1 PERSON_LQ;

	struct linkqueue1_person{
		PERSON_LQ * pHead;
		PERSON_LQ * pRear;
		int len;
		C_BOOL is_inited;
	};

	typedef struct linkqueue1_person LQPERSON;

	//create a new node with dynamic memory assigned
	PERSON_LQ * person_lq_new(int id, char * pname);

	//print the information of a node
	void person_lq_print(PERSON_LQ * pnode);

	//create a stuck with dynamic linklist
	LQPERSON * lqperson_new(void);

	//judge whether the link_queue is empty
	C_BOOL lq_is_empty(LQPERSON * pLq);

	//add an element into the queue
	void lq_Enqueue(LQPERSON * pLq, PERSON_LQ * pnode);

	//remove an element from the queue, and get the element
	C_BOOL lq_Dequeue(LQPERSON * pLq, PERSON_LQ ** pOutput);

	//traverse the queue to print all the elements
	void lq_print(LQPERSON * pLq);

	//put out and free all the elements from the queue
	void lq_clear(LQPERSON * pLq);

	//free all the elements, and free the queue
	void lq_free(LQPERSON * pLq);

#endif /* LINKQUEUE1_H_ */
