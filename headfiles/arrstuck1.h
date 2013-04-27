/*
 * arrstuck1.h
 *
 *  Created on: 2013-4-24
 *      Author: gateman
 */
#include "bool_me.h"
#ifndef __ARRSTUCK1_H_
#define __ARRSTUCK1_H_

	struct arrstuck1{
		int * pArr;  //address of array (int type)
		int arrlen;  //the maxlen of th array
		int top; //index of the top + 1
		int buttom; //index of buttom , default is 0
		const char * stname; //name of stuck, haha ,used to print the log to logfile
		int (* len)(struct arrstuck1 *);   //get the length
		int (* TopVal)(struct arrstuck1 *);  //get the top value
		int (* ButtomVal)(struct arrstuck1 *);  //get the top value
		BOOL (* is_empty)(struct arrstuck1 *);
		BOOL (* is_full)(struct arrstuck1 *);
		BOOL (* push)(struct arrstuck1 *, int);   //push an element to the stuck
		BOOL (* pop)(struct arrstuck1 *, int *); //pop the topelemnt to the stuck
		void (* print)(struct arrstuck1 *); //print from buttom to top
		void (* print_from_top)(struct arrstuck1 *); //print from top to buttom
		char * (* print_from_top_s)(struct arrstuck1 *); //print from top to buttom to String
		void (* clean)(struct arrstuck1 *); //remove all elements
		BOOL is_inited; //judge whether the arraystuck is initialed
	};

	typedef struct arrstuck1 INT_STUCK;

	//initail
	INT_STUCK * ast_int_new();
	//free
	BOOL ast_free(INT_STUCK *);

#endif /* __ARRSTUCK1_H_ */
