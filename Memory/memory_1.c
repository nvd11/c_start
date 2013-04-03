#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student * Create_list();
void memory_1();
void Show_list(struct Student * pst);

int memory_main(){
	memory_1();	
	printf("memory main done\n");
	return 0;
}

struct Student{
	int sid;
	int age;
	char name[100];
};

void memory_1(){
	struct Student * p = Create_list();
	p->sid = 11;
	p->age = 24;
	strcpy(p->name,"JasonPoon");
	Show_list(p);
}

struct Student * Create_list(){
	struct Student * pst;
	pst = (struct Student *)malloc(sizeof(struct Student)*1);
	return pst;
}

void Show_list(struct Student * pst){
	printf("sid is %d, name is %s, age is %d\n",pst->sid, pst->name, pst->age);
}
