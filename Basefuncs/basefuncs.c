#include "bool_me.h"
#include <stdio.h>
#include "basefuncs.h"
#include <stdlib.h>
#include <errno.h>

void base_error(const char * pErr){
	printf("%s\n", pErr);
	exit(-1);
}

BOOL base_log(const char * plog, const char * logfile, const char * WAind){
	if (0 != strcmp("a",WAind) && 0 != strcmp("w",WAind) && 0 != strcmp("r", WAind)){
		printf("WAind parameter must be a or w!\n");
		return FALSE;
	}

	FILE * pfile = fopen(logfile, WAind);
	if (NULL == pfile){
		//perror("perror");
		//printf("errno: %d, strerror: %s\n", errno, strerror(2));
		char * perr = "abc";
		//perr = strerror(errno);
		//printf("strerror: %d\n", sizeof(strerror(errno)));
		printf("strerror: %s\n", strerror(errno));
		printf("%s\n",perr);
		return FALSE;
	}

	fclose(pfile);
	return TRUE;
}
