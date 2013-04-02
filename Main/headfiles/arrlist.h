#include <stdbool.h>
#ifndef __ARRLIST_H_
#define __ARRLIST_H_
	
	struct Arrlist{
		int * addr;
		int len;
		int cur_len;
		int increment;
	};

	void Arr_init(struct Arrlist * pArr, int length);  //inital an arraylist
	bool Arr_add();   // add an element to the end of array
        bool Arr_insert(); // insert an element to any place
	bool Arr_delete(); // delete an element
	int Arr_get();  //get the index of an element by value
	bool Arr_is_empty(struct Arrlist * pArr); 
	void Arr_sort();
	void Arr_show(); 
			
#endif
