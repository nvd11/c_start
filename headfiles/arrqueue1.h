/*
 * arrqueue1.h
 *
 *  Created on: 2013-4-19
 *      Author: gateman
 */
#include "bool_me.h"
#ifndef __ARRQUEUE1_H_
#define __ARRQUEUE1_H_
	struct person_aq{
		int id;
		char name[16];
	};

	typedef struct person_aq PERSON_AQ;

	struct aq_person{
		PERSON_AQ * pArr;
		int Front;
		int Rear;
		int arrlen;
		BOOL is_inited;

		int (* len)(); //function member of a structure
		BOOL (* is_full)(); //judge whether array queue is full
		BOOL (* is_empty)(); //judge whether array queue is empty
		BOOL (* extend)(); //extend the max length of the array queue
		BOOL (* en_queue)(); //enqueue by id and name
		BOOL (* en_queue_by_struct)(); //enqueue by structure
		BOOL (* de_queue)(); //dequeue
		void (* print)(); //print info of all the elements in the array queue
		void (* print_arr_id_st)(); //print all the id of elements of the array
	};

	typedef struct aq_person AQ_PERSON;

	//initial and return an array queue with dynamic memory assigned
	AQ_PERSON * aq_person_new(int arrlen);

	//free the memory of array queue
	BOOL aq_person_free(AQ_PERSON * pAq);

	//print an structure object
	void person_aq_print(PERSON_AQ * pnode);




#endif /* ARRQUEUE1_H_ */

