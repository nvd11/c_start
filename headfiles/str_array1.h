#include <bool_me.h>

#ifndef __STR_ARRAY1_H_
#define __STR_ARRAY1_H_

	typedef struct string_array{
		char ** pAddr;
		int cur_len;
		int max_len;
		int increment;

		/* add a string to tail of the the array */
		C_BOOL (* add)(struct string_array *, const char *);

		/* insert a string to any place of the the array */
		C_BOOL (* insert)(struct string_array *, int, const char *);

		/* delete a node, an return to output parameter */
		C_BOOL (* delete)(struct string_array *, int, const char **);

		/* change val of an element of array */
		C_BOOL (* set_val)(struct string_array *, int, const char *);

		/* get string from the array by index */
		char * (* get_val)(struct string_array *, int);

		/* whether the string is empty */
		C_BOOL (* is_empty)(struct string_array *); 

		/* printf all the string of the array */
		void (* print)(struct string_array *);

			
	} STR_ARR;

	/* initail a string array */
	STR_ARR * str_arr_new(int);

	
#endif
