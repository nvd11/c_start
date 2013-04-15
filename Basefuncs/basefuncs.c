#include <stdio.h>
#include "basefuncs.h"
#include <stdlib.h>

void base_error(const char * pErr){
	printf("%s\n", pErr);
	exit(-1);
}
