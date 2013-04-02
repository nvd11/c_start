#ifndef __ARRLIST_H_
#define __ARRLIST_H_
	
#define BOOL char
#define TRUE '1'
#define FALSE '0'
	struct Arrlist{
		int * addr;
		int len;
		int cur_len;
		int increment;
	};

	void Arr_init(struct Arrlist * pArr, int length);  //inital an arraylist
	BOOL Arr_add();   // add an element to the end of array
        BOOL Arr_insert(); // insert an element to any place
	BOOL Arr_delete(); // delete an element
	int Arr_get();  //get the index of an element by value
	BOOL Arr_is_empty(struct Arrlist * pArr); 
	void Arr_sort();
	void Arr_show(); 
			
#endif
