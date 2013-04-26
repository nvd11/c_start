/*
 * base_exec.c
 *
 *  Created on: 2013-4-26
 *      Author: gateman
 */

#include "base_exec.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define LOGFILE "/home/gateman/logs/c_exec.log"

int base_exec(char * pcmd){
	FILE * pf;
	pid_t pid = getpid();
	char pfilename[20];
	sprintf(pfilename, "/tmp/base_exec%d.sh",pid);

	pf=fopen(pfilename,"w"); //w is overwrite, a is add
	if (NULL == pf){
		printf("fail to open the file base_exec.sh!!!\n");
		return -1;
	}

	fwrite("#!/bin/bash\n", 12, 1, pf);
	fwrite(pcmd, strlen(pcmd),1, pf);
	fwrite("\n", 1,1, pf);

	fclose(pf);

	if (fork() ==0 ){
		//child processj
		char * execv_str[] = {"bash", pfilename, NULL};
		if (execv("/bin/bash",execv_str) < 0){
			perror("fail to execv");
			exit(-1);
		}
	}else{
		//current process
		wait();
		pf=fopen(LOGFILE,"a");

		if (NULL == pf){
			printf("fail to open the logfile !!!\n");
			return -1;
		}
		time_t t;
		struct tm * ptm;
		time(&t);
		ptm  = gmtime(&t);
		char cstr[24];
		sprintf (cstr, "time: %4d-%02d-%02d %02d:%02d:%02d\n", 1900+ptm->tm_year,ptm->tm_mon,ptm->tm_mday,ptm->tm_hour,ptm->tm_min,ptm->tm_sec);
		fwrite(cstr, strlen(cstr),1, pf);

		int uid = getuid();
		sprintf(cstr, "uid: %d\ncommand:\n",uid);
		fwrite(cstr, strlen(cstr),1, pf);

		fwrite(pcmd, strlen(pcmd),1, pf);
		fwrite("\n\n\n", 3,1, pf);
		fclose(pf);
		remove(pfilename);
		return 0;
	}
	return 0;
}


