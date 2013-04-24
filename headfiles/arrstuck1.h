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
		int (* len)();   //get the length
		int (* TopVal)();  //get the top value
		int (* ButtomVal)();  //get the top value
		BOOL (* is_empty)();
		BOOL (* is_full)();
		BOOL (* push)();   //push an element to the stuck
		BOOL (* pop)(); //pop the topelemnt to the stuck
		void (* print)(); //print from buttom to top
		void (* print_from_top)(); //print from top to buttom
		void (* clean)(); //remove all elements
		BOOL is_inited; //judge whether the arraystuck is initialed
	};

	typedef struct arrstuck1 INT_STUCK;

	//initail
	INT_STUCK * ast_int_new();
	//free
	BOOL ast_free(INT_STUCK *);

#endif /* __ARRSTUCK1_H_ */
