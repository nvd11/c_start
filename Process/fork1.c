/*
 * fork1.c
 *
 *  Created on: 2013-4-25
 *      Author: gateman
 */
#include <stdio.h>
#include "fork1.h"
#include <stdlib.h>
#include <unistd.h>
#include "base_exec.h"

int fork_1();


int fork1_main(void){
	fork_2();
	char * pstr = "ls /home/gateman";
	base_exec(pstr);
	printf("fork1 done!!!\n");
	return 0;
}


int fork_1(){
	int childpid;
	int i;

	if (fork() == 0){
		//child process
		for (i=1; i<=20; i++){
			printf("This is child process\n");
		}
		//exit(0);
	}else{
		//parent process
		wait(&childpid);	
		for(i=1; i<20; i++){
			printf("This is parent process\n");
		}
	}

}

int fork_2(){
	int childpid;
	int i;

	if (fork() == 0){
		//child process
		char * execv_str[] = {"echo", "executed by execv",NULL};
		if (execv("/usr/bin/echo",execv_str) <0 ){
			perror("error on exec");
			exit(0);
		}
	}else{
		//parent process
		wait(&childpid);
		printf("execv done\n\n");
	}

	if (fork() == 0){
		//child process
		char * execvp_str[] = {"echo", "executed by execvp",">>", "~/abc.txt",NULL};
		if (execvp("echo",execvp_str) <0 ){
			perror("error on exec");
			exit(0);
		}
	}else{
		//parent process
		wait(&childpid);
		printf("execvp done\n\n");
	}

	if (fork() == 0){
		//child process
		char * execve_str[] = {"env",NULL};
		char * env[] = {"PATH=/tmp", "USER=lei", "STATUS=testing", NULL};
		if (execve("/usr/bin/env",execve_str,env) <0 ){
			perror("error on exec");
			exit(0);
		}
	}else{
		//parent process
		wait(&childpid);
		printf("execve done\n\n");
	}


	if (fork() == 0){
		//child process
		if (execl("/usr/bin/echo","echo","executed by execl" ,NULL) <0 ){
			perror("error on exec");
			exit(0);
		}
	}else{
		//parent process
		wait(&childpid);
		printf("execv done\n\n");
	}


	if (fork() == 0){
		//child process
		if (execlp("echo","echo","executed by execlp" ,NULL) <0 ){
			perror("error on exec");
			exit(0);
		}
	}else{
		//parent process
		wait(&childpid);
		printf("execlp done\n\n");
	}

	if (fork() == 0){
		//child process
		char * execve_str[] = {"env",NULL};
		char * env[] = {"PATH=/tmp", "USER=lei", "STATUS=testing", NULL};
		if (execle("/usr/bin/env","env",NULL,env) <0){
			perror("error on exec");
			exit(0);
		}
	}else{
		//parent process
		wait(&childpid);
		printf("execle done\n\n");
	}

}
