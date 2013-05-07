/*
 * arrbtree1.c
 *
 *  Created on: 2013-5-6
 *      Author: gateman
 */

#include "arrbtree1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <basefuncs.h>
#include <math.h>

/*
 * functions announce
 */
static int arrbtree1_total_count(ARR_BTREE_P *);
static int arrbtree1_getdepth(ARR_BTREE_P *);
static C_BOOL arrbtree1_setnode_by_obj(ARR_BTREE_P *, PERSON_BT_ARR *, int);
static C_BOOL arrbtree1_setnode(ARR_BTREE_P * , int , char * , int );
static PERSON_BT_ARR * arrbtree1_getnode(ARR_BTREE_P * , int );
static void arrbtree1_arr_print(ARR_BTREE_P * );
static int arrbtree1_getindex_by_id(ARR_BTREE_P *, int);
static int arrbtree1_getindex_by_node(ARR_BTREE_P *, PERSON_BT_ARR *);
static C_BOOL arrbtree1_extend(ARR_BTREE_P *, int);


/*
 * initial a binary tree container
 * parameter is initial length , it can be extended
 */
ARR_BTREE_P * arrbtree1_new(int init_count){
	if (0 >= init_count){
		base_error("initial-count must greater than 0!!");
	}

	ARR_BTREE_P * pTree = (ARR_BTREE_P *)malloc(sizeof(ARR_BTREE_P));
	if (NULL == pTree){
		base_error("fail to assign memory to a binary tree!!");
	}

	PERSON_BT_ARR * pArr = (PERSON_BT_ARR *)malloc(sizeof(PERSON_BT_ARR) * (init_count+1));
	if (NULL == pArr){
		base_error("fail to assign memory to an array for a binary tree!!");
	}

	/* set all the element invalid */
	int i;
	for (i=0; i <= init_count; i++){
		(pArr + i)->is_valid = C_FALSE;
	}

	pTree->count = init_count;
	pTree->max_arrlen = init_count + 1;
	pTree->total_count = arrbtree1_total_count;
	pTree->depth = arrbtree1_getdepth;
	//pTree->setnode = arrbtree1_setnode;
	//pTree->setnode_by_obj = arrbtree1_setnode_by_obj;
	pTree->getnode = arrbtree1_getnode;
	pTree->arr_print = arrbtree1_arr_print;

	pTree->is_initialed = C_TRUE;
	return pTree;
};



/* count of total of elements of the binary tree(or array) */
static int arrbtree1_total_count(ARR_BTREE_P * pTree){
	if (C_TRUE != pTree->is_initialed){
		base_error("This object is not initialed yet!");
	}

	return pTree->max_arrlen -1;
}

/* number of floors of the binary tree */
static int arrbtree1_getdepth(ARR_BTREE_P * pTree){
	if (C_TRUE != pTree->is_initialed){
		base_error("This object is not initialed yet!");
	}

	/*
	 * log2 is logarithm function with base 2.
	 * floor return the largest integral which is not greater than parameter  ex. floor(1.5) = 1
	 * ceil return the smallest integral which is not less then parameter
	 */
	return floor(log2(pTree->max_arrlen)) + 1;
}

/* get the parent index by index*/
int arrbtree1_get_p_idx(int index){
	/* invalid parameter */
	if (1 > index){
		return -1;
	}

	return (int)(index/2);
}

/* get the left child index of a node by index */
int arrbtree1_get_lc_idx(int index){
	/* invalid parameter */
	if (1 > index){
		return -1;
	}

	return index * 2;
}

/* get the right child index of a node by index */
int arrbtree1_get_rc_idx(int index){
	/* invalid parameter */
	if (1 > index){
		return -1;
	}

	return index * 2 + 1;
}

/* input an info of node into the binary tree with specified place */
static C_BOOL arrbtree1_setnode_by_obj(ARR_BTREE_P * pTree, PERSON_BT_ARR * pnode, int index){
	if (C_TRUE != pTree->is_initialed){
		base_error("This object is not initialed yet!");
	}

	if (index > pTree->max_arrlen -1){
		if (C_TRUE != arrbtree1_extend(pTree, arrbtree1_get_rc_idx(index) +1 - pTree->max_arrlen)){
			return C_FALSE;
		}
	}

	return C_TRUE;
}

/* input id and name into the binary tree with specified place */
static C_BOOL arrbtree1_setnode(ARR_BTREE_P * pTree, int id, char * pname, int index){
	return C_TRUE;
}

/* get the specified node by btree number, if fail, return NULL */
static PERSON_BT_ARR * arrbtree1_getnode(ARR_BTREE_P * pTree, int index){
	return NULL;
}

/* get the index by id, if not existed , return -1 */
static int arrbtree1_getindex_by_id(ARR_BTREE_P * pTree, int id){
	return 0;
}

/* get the index by node, if not existed , return -1 */
static int arrbtree1_getindex_by_node(ARR_BTREE_P * pTree, PERSON_BT_ARR * pnode){
	return 0;
}

/* print the btree by number */
static void arrbtree1_arr_print(ARR_BTREE_P * pTree){
	return;
}

/*
 * extend the max length of the array
 */
static C_BOOL arrbtree1_extend(ARR_BTREE_P * pTree, int len){
	return C_TRUE;
}

/* destroy a binary tree container */
C_BOOL arrbtree1_free(ARR_BTREE_P * pTree){
	return C_TRUE;
}
