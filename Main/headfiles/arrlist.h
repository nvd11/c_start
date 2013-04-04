#include "bool_me.h"
#ifndef __ARRLIST_H_
#define __ARRLIST_H_

	struct Arrlist{
		int * paddr;
		int len;
		int cur_len;
		int increment;
	};

	void Arr_init(struct Arrlist * pArr, int length);  //inital an arraylist
	BOOL Arr_add(struct Arrlist * pArr, int val);   // add an element to the end of array
        BOOL Arr_insert(struct Arrlist * pArr, int position, int val); // insert an element to any place
	BOOL Arr_delete(struct Arrlist * pArr, int position); // delete an element
	int Arr_get(struct Arrlist * pArr, int position);  //get the index of an element by value
	BOOL Arr_is_empty(struct Arrlist * pArr); 
	BOOL Arr_is_full(struct Arrlist * pArr); 
	void Arr_sort(struct Arrlist * pArr);
	void Arr_show(struct Arrlist * pArr); 
			
#endif
