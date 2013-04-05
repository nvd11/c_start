#include "bool_me.h"
#ifndef __ARRLIST_H_
#define __ARRLIST_H_

	struct Arrlist{
		int * paddr;
		int len;
		int cur_len;
		int increment;
		BOOL is_inited;
	};

	typedef struct Arrlist Arrint;

	void Arr_init(Arrint * pArr, int length);  //inital an arraylist
	BOOL Arr_add(Arrint * pArr, int val);   // add an element to the end of array
        BOOL Arr_insert(Arrint * pArr, int position, int val); // insert an element to any place
	BOOL Arr_delete(Arrint * pArr, int index); // delete an element
	int Arr_get(Arrint * pArr, int index);  //get the index of an element by value
	BOOL Arr_set(Arrint * pArr, int index, int val);  //set the value to specified element in the array 
	BOOL Arr_is_empty(Arrint * pArr); 
	BOOL Arr_is_full(Arrint * pArr); 
	void Arr_invert(Arrint * pArr); //invert the array
	void Arr_sort(Arrint * pArr);
	void Arr_show(Arrint * pArr); 
			
#endif
