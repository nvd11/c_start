#include "bool_me.h"
#ifndef __ARRLIST_H_
#define __ARRLIST_H_

	struct Arrlist{
		int * paddr;
		int len;
		int cur_len;
		int increment;
		C_BOOL is_inited;
	};

	typedef struct Arrlist ARRINT;

	ARRINT * Arr_init(int length);  //inital an arraylist
	C_BOOL Arr_add(ARRINT * pArr, int val);   // add an element to the end of array
        C_BOOL Arr_insert(ARRINT * pArr, int position, int val); // insert an element to any place
	C_BOOL Arr_delete(ARRINT * pArr, int index); // delete an element
	int Arr_get(ARRINT * pArr, int index);  //get the value of an element by index
	C_BOOL Arr_set(ARRINT * pArr, int index, int val);  //set the value to specified element in the array 
	C_BOOL Arr_is_empty(ARRINT * pArr); 
	C_BOOL Arr_is_full(ARRINT * pArr); 
	void Arr_invert(ARRINT * pArr); //invert the array
	void Arr_sort(ARRINT * pArr);
	void Arr_show(ARRINT * pArr); 
			
#endif
