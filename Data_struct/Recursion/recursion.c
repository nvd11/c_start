/*
 * recursion.c
 *
 *  Created on: 2013-4-23
 *      Author: gateman
 */

#include <stdio.h>
#include "recursion.h"
#include "hanoi.h"


void f1();
void g();
void k();

void f1(){
	printf("it's f1\n");
	g();
}

void g(){
	printf("it's g\n");
	k();
}

void k(){
	printf("it's k\n");
	f1();   //call back f1()
}


void f3(int * i){
	printf("it's f3, i is %d\n",*i);
	*i = *i +1;
	if (*i < 10){
		f3(i);
	}
}

void f4(int i){
	printf("it's f4, i is %d\n",i);
	if (i<10){
		f4(i+1);
	}
}

void sum100(){
	int i;
	int s;
	for (i=1; i != 101; i++){
		s+=i;
	}

	printf("sum of 1 ~ 100 is %d\n", s);
}


int fac(int n){
	int i;
	int f=1;
	for (i=1; i!=(n +1); i++){
		f= f *i;
	}
	return f;
}

int fac_rec(int n){
	if (n==1){
		return 1;
	}
	return n * fac_rec(n-1);
}

int recur_100(int n){
	if (n==1){
		return 1;
	}
	return n + recur_100(n-1);
}

int recur_main(void){
	int i=0;
	//f3(&i);
	//f4(1);
	//sum100();

//	int s=0;
//	int i=1;
//	recur_100(i, &s);
//	printf("f is %d\n", fac_rec(10));
	i = hanoi_main();
	printf("sum of 1 ~ 100 is %d\n", recur_100(100));
	printf("recur_main done!\n");
	return 0;
}

