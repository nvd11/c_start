#include <stdio.h>
#include <math.h>
#include "arrlist.h"
#include "linklist1.h"
#include "stuck1.h"
#include "linkqueue1.h"
#include "arrbtree1.h"
#include "arrqueue1.h"
#include "arrstuck1.h"
#include <stdlib.h>
#include <base_math.h>




int malloc_41(int ** pa, int len){
	*pa = (int *)realloc(*pa, sizeof(int)* (len));
	return 0;
}


int array1_1(){
	struct Arrlist * parr1;
	struct Arrlist * parr2;

	parr1 = Arr_init(10);
	parr2 = Arr_init(10);
	
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
	//link_traverse(plink1);

	//printf("id is %d, name is %s\n",p1->id, p1->name);
	printf("link1 done\n");
	return 0;

}

int stuck_1(){
	PERSON_ST * pnode = person_st_new(1,"Jasonabc1234567890111111110");
	person_st_print(pnode);
	free(pnode);

	STPERSON * pst1 = st_create();
	st_push(pst1,person_st_new(1, "Jason"));
	st_push(pst1,person_st_new(2, "Cindy"));
	st_push(pst1,person_st_new(3, "Gateman"));
	st_push(pst1,person_st_new(4, "Fiana"));
	st_print(pst1);

	printf("top twice\n\n");
	st_pop(pst1, &pnode);
	person_st_print(pnode);
	free(pnode);

	st_pop(pst1, &pnode);
	person_st_print(pnode);
	free(pnode);

	printf("top done\n\n");

	st_print(pst1);

	st_clear(pst1);
	st_free(pst1);
	printf("stuck_1 done\n");
	return 0;
}

int linkqueue1(){

	PERSON_LQ * pnode = person_lq_new(1,"JasonPoon111212121212");
	person_lq_print(pnode);
	free(pnode);

	LQPERSON * plq1 = lqperson_new();
	//LQPERSON * plq2 = lqperson_new();
	lq_Enqueue(plq1, person_lq_new(1,"Jason"));
	lq_Enqueue(plq1, person_lq_new(2,"Cindy"));
	lq_Enqueue(plq1, person_lq_new(3,"Fiana"));
	lq_Enqueue(plq1, person_lq_new(4,"Gateman"));

	lq_print(plq1);

	int i=0;
	int j=plq1->len-1;
	for (i=0; i < j; i++){
		lq_Dequeue(plq1,&pnode);
		printf("the out node is\n");
		person_lq_print(pnode);
		printf("\n");
		free(pnode);
	}

	lq_print(plq1);
	lq_Dequeue(plq1,&pnode);
	printf("the out node is\n");
	person_lq_print(pnode);
	printf("\n");
	free(pnode);

	lq_print(plq1);
	lq_Enqueue(plq1, person_lq_new(1,"Jason"));
	lq_Enqueue(plq1, person_lq_new(2,"Cindy"));
	lq_Enqueue(plq1, person_lq_new(3,"Fiana"));
	lq_Enqueue(plq1, person_lq_new(4,"Gateman"));


	lq_print(plq1);

	printf("now clear the linkqueuei!\n");
	lq_clear(plq1);
	lq_print(plq1);

	lq_free(plq1);

	printf("linkq1 done\n");
	return 0;
}

int arrqueue1(){
	AQ_PERSON * paq1 = aq_person_new(6);
	//AQ_PERSON * paq2 = aq_person_new(6);
	paq1->en_queue(paq1, 1, "Jason");
	paq1->en_queue(paq1, 2, "Gateman");
	paq1->en_queue(paq1, 3, "Youyi");
	paq1->en_queue(paq1, 4, "Snow");
	paq1->en_queue(paq1, 5, "Moon");
	paq1->en_queue(paq1, 6, "Crystal");
	paq1->en_queue(paq1, 7, "AI");
	paq1->print(paq1);
	paq1->print_arr_id_st(paq1);
	printf("\n");

	PERSON_AQ node;

	paq1->de_queue(paq1, &node);
	printf("the dequeue object is:\n");
	person_aq_print(&node);
	printf("\n");

	paq1->en_queue_by_struct(paq1, &node);

	paq1->de_queue(paq1, &node);
	printf("the dequeue object is:\n");
	person_aq_print(&node);
	printf("\n");

	paq1->en_queue_by_struct(paq1, &node);

	paq1->de_queue(paq1, &node);
	printf("the dequeue object is:\n");
	person_aq_print(&node);
	printf("\n");

	paq1->en_queue_by_struct(paq1, &node);

	paq1->de_queue(paq1, &node);
	printf("the dequeue object is:\n");
	person_aq_print(&node);
	printf("\n");

	paq1->en_queue_by_struct(paq1, &node);

	paq1->print_arr_id_st(paq1);

	paq1->en_queue(paq1, 8, "Cindy");
	paq1->en_queue(paq1, 9, "Inzaghi");

	paq1->print_arr_id_st(paq1);
	paq1->print(paq1);
	aq_person_free(paq1);
	printf("len of array queue is %d\n",paq1->len(paq1));
	printf("arrqueue1_main done\n");
	return 0;
}

int arrstuck1(){
	INT_STUCK * pIst = ast_int_new();
	int i;
	for (i=0; i<9; i++){
		pIst->push(pIst,i);
	}

	int out;
	pIst->pop(pIst, &out);
	printf("the pop element is %d\n", out);


	pIst->push(pIst,9);
	pIst->push(pIst,10);
	pIst->push(pIst,11);
	pIst->push(pIst,12);

	pIst->print(pIst);
	return 0;
}

int arrbtree_1(){

	ARR_BTREE_P * pTree = arrbtree1_new(13);

	PERSON_BT_ARR * Nedved = personbt1_new(1, "Pavel");
	PERSON_BT_ARR * Jason = personbt1_new(2, "Jason");
	PERSON_BT_ARR * Peter = personbt1_new(3, "Peter");
	PERSON_BT_ARR * Crystal = personbt1_new(4, "David");
	PERSON_BT_ARR * Hebe = personbt1_new(5, "Hebe");
	PERSON_BT_ARR * Lulu = personbt1_new(6, "Lulu");
	PERSON_BT_ARR * Cindy = personbt1_new(7, "Cindy");
	PERSON_BT_ARR * Pippo = personbt1_new(7, "Pippo");



	pTree->add_root(pTree, Nedved);
	pTree->insert_child(pTree, Jason, 'L', Nedved);
	pTree->insert_child(pTree, Peter, 'R', Jason);
	pTree->insert_child(pTree, Crystal, 'L', Jason);
	pTree->insert_child(pTree, Hebe, 'R', Nedved);
	pTree->insert_child(pTree, Lulu, 'R', Hebe);
	pTree->insert_child(pTree, Cindy, 'R', Peter);
	pTree->insert_child(pTree, Pippo, 'L', Lulu);

	pTree->arr_print_name(pTree);
	printf("count of tree is %d\n", pTree->count);
	printf("current max_len of tree is %d\n", pTree->max_arrlen);
	arrbtree1_free(pTree);


	printf("arrbtree_1 done\n");
	return 0;
}

int arrbtree_2(){
	ARR_BTREE_P * pTree = arrbtree1_new(14);

	arrbtree1_extend(pTree, 27);
	pTree->arr_print_name(pTree);
	arrbtree1_free(pTree);
	printf("arrbtree_1 done\n");
	return 0;
}
int array1_main(){
	int i=0;
	i=arrbtree_2();
	//i=array1_1();
	//i=stuck_1();
	//i = linkqueue1();
	//i = arrqueue1();
	//i = arrstuck1();
	printf("array1_main done\n");
	return 0;
}
