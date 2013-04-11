#include <stdio.h>
#include "arrlist.h"
#include "linklist1.h"
#include <stdlib.h>




int malloc_41(int ** pa, int len){
	*pa = (int *)realloc(*pa, sizeof(int)* (len));
	return 0;
}


int array1_1(){

	struct Arrlist * parr1;

	parr1 = Arr_init(10);
	
	char empty =Arr_is_empty(parr1);


	printf("len is %d\n",parr1->len);
	printf("is empty is %c\n",empty);
	printf("\n");

	int i;
	for (i=0;i<parr1->len;i++){
		Arr_add(parr1,(i+1) * 3);
	}

	printf("cur_len is %d\n",parr1->cur_len);
	printf("\n");

	Arr_set(parr1, 9,Arr_get(parr1,8));
	Arr_set(parr1, 10,100);

	Arr_insert(parr1, 10,11111);
	Arr_insert(parr1, 3,11111);
	Arr_insert(parr1, 3,22222);
	Arr_delete(parr1, 4);
	
	Arr_show(parr1);

	for (i=0; i<20; i++){
		Arr_add(parr1,(i+1)*4);
	
	}
	
    	printf("cur_len is %d\n",parr1->cur_len);
	printf("len is %d\n",parr1->len);
	printf("\n");

	Arr_show(parr1);
	printf("\n");
	
	Arr_invert(parr1);		
	Arr_show(parr1);
	printf("\n");
	
	Arr_sort(parr1);	
	Arr_show(parr1);
	printf("\n");

	return 0;
}	

int array1_2(){
	struct Arrlist * parr1;

	parr1 = Arr_init(10);
	Arr_add(parr1,3);
	Arr_add(parr1,2);
	Arr_add(parr1,1);
	Arr_add(parr1,6);
	Arr_add(parr1,5);
	Arr_add(parr1,0);
	Arr_add(parr1,1);
	Arr_add(parr1,7);
	Arr_add(parr1,0);
	Arr_add(parr1,4);

	Arr_show(parr1);
	printf("\n");


	Arr_sort(parr1);

	printf("\n");
	return 0;

}

int link_1(){
	//const char *n = "gateman poon";
	PERSON * p1 = person_new(1,"Jason Poon" );

	LINKPERSON * plink1 = link_create(10);
	//LINKPERSON * plink2;
	//link_traverse(plink2);

	//PERSON * p3;
	//printf("id is %d, name is %s\n",p3->id, p3->name);
	
	free(p1);
	p1 = link_getnode(plink1, 3);

	link_insert(plink1, link_getnode(plink1,4), person_new(24, "Gateman"));
	link_insertbyindex(plink1, 5, person_new(11, "Nedved"));
	link_remove(plink1, link_getnode(plink1,7));
	link_delete(plink1, 7);
	link_add(plink1, person_new(12, "Cindy"));
	link_add(plink1, person_new(24, "Gateman"));
	link_add(plink1, person_new(11, "Nvd11"));
	link_add(plink1, person_new(49, "Lulu"));
	link_add(plink1, person_new(47, "Alice"));
	link_traverse(plink1);

	printf("will be sort now!\n\n");
	link_sort(plink1);
	link_traverse(plink1);
	//link_clear(plink1);
	link_free(plink1);
	//link_traverse(plink1);

	//printf("id is %d, name is %s\n",p1->id, p1->name);
	printf("link1 done\n");
	return 0;

}
int array1_main(){
	int i=0;
	//i=link_1();
	i=array1_1();
	printf("array1_main done\n");
	return 0;
}
