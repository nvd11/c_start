#include <bool_me.h>

#ifndef __STR_ARRAY_H_
#define __STR_ARRAY_H_

	typedef struct string_array{
		char ** pArr;
		int cur_len;
		int max_len;
		int increment;
	} STR_ARR;
	
#endif
