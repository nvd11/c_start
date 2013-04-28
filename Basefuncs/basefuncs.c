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

	fprintf(pfile,"%s",plog);
	if ( 0 != errno ){
		printf("errno:%d\nstrerror: %s\n", errno, strerror(errno));
		return FALSE;
	}

	fclose(pfile);
	return TRUE;
}

BOOL base_log_intarr(const char * arrnm, int * pArr, int len, const char * logfile, const char * WAind){
	if (0 != strcmp("a",WAind) && 0 != strcmp("w",WAind)){
		printf("WAind parameter must be a or w!\n");
		return FALSE;
	}

	if (len < 0){
		printf("length of array must greater or equal to 0!\n");
		return FALSE;
	}

	FILE * pfile = fopen(logfile, WAind);
	if (NULL == pfile){
		printf("errno:%d\nstrerror: %s\n", errno, strerror(errno));
		return FALSE;
	}


	fprintf(pfile, "%s: ", arrnm);
	if (len==0){
		fprintf(pfile, "blank array!\n");
		fclose(pfile);
		return TRUE;
	}

	int i;
	for (i=0; i !=len - 1; i++){
		fprintf(pfile, "%d, ", pArr[i]);
	}

	fprintf(pfile, "%d\n", pArr[len-1]);
	fclose(pfile);
	return TRUE;
}
