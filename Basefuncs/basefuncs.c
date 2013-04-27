#include "bool_me.h"
#include <stdio.h>
#include "basefuncs.h"
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void base_error(const char * pErr){
	printf("%s\n", pErr);
	exit(-1);
}

BOOL base_log(const char * plog, const char * logfile, const char * WAind){
	if (0 != strcmp("a",WAind) && 0 != strcmp("w",WAind)){
		printf("WAind parameter must be a or w!\n");
		return FALSE;
	}

	FILE * pfile = fopen(logfile, WAind);
	if (NULL == pfile){
		printf("errno:%d\nstrerror: %s\n", errno, strerror(errno));
		return FALSE;
	}

	fprintf(pfile, plog);
	if ( 0 != errno ){
		printf("errno:%d\nstrerror: %s\n", errno, strerror(errno));
		return FALSE;
	}

	fclose(pfile);
	return TRUE;
}
