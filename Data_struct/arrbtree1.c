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
 * member functions announce
 */
static int arrbtree1_total_count(ARR_BTREE_P *);
static void  arrbtree1_clear(ARR_BTREE_P *);
static C_BOOL arrbtree1_is_empty(ARR_BTREE_P *);
static int arrbtree1_getdepth(ARR_BTREE_P *);
static C_BOOL  arrbtree1_add_rootnode(ARR_BTREE_P *, int, char *);
static PERSON_BT_ARR *  arrbtree1_get_rootnode(ARR_BTREE_P *);
static PERSON_BT_ARR *  arrbtree1_get_parent(ARR_BTREE_P *, PERSON_BT_ARR *);
static PERSON_BT_ARR *  arrbtree1_get_leftchild(ARR_BTREE_P *, PERSON_BT_ARR *);
static PERSON_BT_ARR *  arrbtree1_get_rightchild(ARR_BTREE_P *, PERSON_BT_ARR *);
static PERSON_BT_ARR * arrbtree1_get_leftbrother(ARR_BTREE_P * pTree, PERSON_BT_ARR * pNode);
static PERSON_BT_ARR * arrbtree1_get_rightbrother(ARR_BTREE_P * pTree, PERSON_BT_ARR * pNode);

static PERSON_BT_ARR * arrbtree1_getnode(ARR_BTREE_P * , int);
static void arrbtree1_arr_print(ARR_BTREE_P * );
static int arrbtree1_getindex_by_node(ARR_BTREE_P *, PERSON_BT_ARR *);


/*
* not member functions announce
*/
static C_BOOL arrbtree1_extend(ARR_BTREE_P *, int);
static void arrbtree1_recur_rm_nodes(ARR_BTREE_P *, PERSON_BT_ARR *);

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

	pTree->count = 0;
	pTree->max_arrlen = init_count + 1;

	pTree->total_count = arrbtree1_total_count;
	pTree->clear = arrbtree1_clear;
	pTree->is_empty = arrbtree1_is_empty;
	pTree->depth = arrbtree1_getdepth;
	pTree->add_root = arrbtree1_add_rootnode;
	pTree->get_root = arrbtree1_get_rootnode;
	pTree->get_parent = arrbtree1_get_parent;
	pTree->get_leftchild = arrbtree1_get_leftchild;
	pTree->get_rightchild = arrbtree1_get_rightchild;
	pTree->get_leftbrother = arrbtree1_get_leftbrother;
	pTree->get_rightbrother = arrbtree1_get_rightbrother;

	pTree->getnode = arrbtree1_getnode;
	pTree->arr_print = arrbtree1_arr_print;

	pTree->is_initialed = C_TRUE;
	return pTree;
};


/*************************************************
* below are the difinition of non member functions
***************************************************/


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


/* extend the max length of the array , the parameter len is the length after extend */
static C_BOOL arrbtree1_extend(ARR_BTREE_P * pTree, int len){
	if (C_TRUE != pTree->is_initialed){
		base_error("This object is not initialed yet!");
	}

	if (len <= pTree->max_arrlen){
		printf("the length must greater then old length!\n");
		return C_FALSE;
	}

	PERSON_BT_ARR * pold = pTree->pArr;
	pTree->pArr = (PERSON_BT_ARR *)realloc(pTree->pArr, sizeof(PERSON_BT_ARR) * len);
	if (NULL == pTree->pArr){
		printf("fail to assign memory to extend the array!\n");
		pTree->pArr = pold;
		return C_FALSE;
	}

	int i;
	for (i=pTree->max_arrlen + 1; i <= len; i++){
		pTree->pArr[i].is_valid = C_FALSE;
	}

	pTree->max_arrlen = len;
	return C_TRUE;
}

/* get the index by node, if not existed , return -1 */
int arrbtree1_get_node_idx(ARR_BTREE_P * pTree, PERSON_BT_ARR * pNode){
	if (C_TRUE != pTree->is_initialed){
		base_error("This object is not initialed yet!");
	}

	if (C_TRUE != pNode->is_valid){
		printf("the node is invalid!!\n");
		return -1;
	}

	PERSON_BT_ARR pRoot = pTree->pArr[1];
	int index = pNode - &pRoot + 1;
	if ( 1 > index || pTree->max_arrlen < index){
		return -1;
	}
	return index;
}

/* destroy a binary tree container */
void arrbtree1_free(ARR_BTREE_P * pTree){
	if (C_TRUE != pTree->is_initialed){
		base_error("This object is not initialed yet!");
	}

	free(pTree->pArr);
	free(pTree);
	return;
}

/*
 *  recursion : traverse the binary tree to remove a binary tree
 *  use the "postorder traverse" method
*/
static void arrbtree1_recur_rm_nodes(ARR_BTREE_P * pTree, PERSON_BT_ARR * pNode){
	PERSON_BT_ARR * pchild;

	/* step1, remove the left child tree */
	pchild = pTree->get_leftchild(pTree, pNode);
	if (NULL != pchild){
		arrbtree1_recur_rm_nodes(pTree, pchild);
	}

	/* step2, remove the right child tree */
	pchild = pTree->get_rightchild(pTree, pNode);
	if (NULL != pchild){
		arrbtree1_recur_rm_nodes(pTree, pchild);
	}

	/* step3, remove the root node */
	pNode->is_valid = C_FALSE;
	pTree->count--;

	return;
}

/********************************************
* below are the difinition of member functions
*********************************************/


/* count of total of elements of the binary tree(or array) */
static int arrbtree1_total_count(ARR_BTREE_P * pTree){
	if (C_TRUE != pTree->is_initialed){
		base_error("This object is not initialed yet!");
	}

	return pTree->max_arrlen -1;
}

/* clear all the nodes from the tree */
static void  arrbtree1_clear(ARR_BTREE_P * pTree){
	if (C_TRUE != pTree->is_initialed){
		base_error("This object is not initialed yet!");
	}

	if ( 0 == pTree->count){
		return;
	}

	arrbtree1_recur_rm_nodes(pTree, pTree->get_root(pTree));
	return;
}

/* judge whether the binary tree is empty binary tree */
static C_BOOL arrbtree1_is_empty(ARR_BTREE_P * pTree){
	if (C_TRUE != pTree->is_initialed){
		base_error("This object is not initialed yet!");
	}

	if (pTree->count > 0){
		return C_FALSE;
	}
	return C_TRUE;
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

/* set root_node */
static C_BOOL  arrbtree1_add_rootnode(ARR_BTREE_P * pTree, int id, char * pname){
	if (C_TRUE != pTree->is_initialed){
		base_error("This object is not initialed yet!");
	}

	PERSON_BT_ARR * pNode = &(pTree->pArr[1]);
	if (C_TRUE == pNode->is_valid){
		printf("the root node is existed already!\n");
		return C_FALSE;
	}

	pNode->id = id;
	strncpy(pNode->name, pname+0, ARRBTREE1_NM_LEN); //define as 16
	pNode->is_valid = C_TRUE;
	pTree->count++;
		
	return C_TRUE;
}

/* get the root node*/
static PERSON_BT_ARR *  arrbtree1_get_rootnode(ARR_BTREE_P * pTree){
	if (C_TRUE != pTree->is_initialed){
		base_error("This object is not initialed yet!");
	}

	return pTree->getnode(pTree,1);
} 

/* get the parent node of a node */
static PERSON_BT_ARR *  arrbtree1_get_parent(ARR_BTREE_P * pTree, PERSON_BT_ARR * pNode){
	if (C_TRUE != pTree->is_initialed){
		base_error("This object is not initialed yet!");
	}

	int index = arrbtree1_get_node_idx(pTree, pNode);
	PERSON_BT_ARR * pParent;

	if (0 > index){
		printf("the node is not existed in the binary tree\n!");
		return NULL;
	}

	/* not the rootnode of the binary tree */
	if (1 < index){
		return pTree->getnode(pTree, (int)(index/2));
	}

	return NULL;
} 

/* get the left child node of node, if there's no left child then return NULL */
static PERSON_BT_ARR *  arrbtree1_get_leftchild(ARR_BTREE_P * pTree, PERSON_BT_ARR * pNode){
	if (C_TRUE != pTree->is_initialed){
		base_error("This object is not initialed yet!");
	}

	int index = arrbtree1_get_node_idx(pTree, pNode);

	if (0 > index){
		printf("the node is not existed in the binary tree\n!");
		return NULL;
	}

	return  pTree->getnode(pTree, index * 2);
} 

/* get the right child node of node, if there's no right child then return NULL */
static PERSON_BT_ARR *  arrbtree1_get_rightchild(ARR_BTREE_P * pTree, PERSON_BT_ARR * pNode){
	if (C_TRUE != pTree->is_initialed){
		base_error("This object is not initialed yet!");
	}

	int index = arrbtree1_get_node_idx(pTree, pNode);

	if (0 > index){
		printf("the node is not existed in the binary tree\n!");
		return NULL;
	}

	return pTree->getnode(pTree, index * 2 + 1);
} 

/* get the left brother(close to) node of node, if there's no left brother then return NULL */
static PERSON_BT_ARR * arrbtree1_get_leftbrother(ARR_BTREE_P * pTree, PERSON_BT_ARR * pNode){
	if (C_TRUE != pTree->is_initialed){
		base_error("This object is not initialed yet!");
	}

	int index = arrbtree1_get_node_idx(pTree, pNode);

	if (0 > index){
		printf("the node is not existed in the binary tree\n!");
		return NULL;
	}

	/* not the rootnode of the binary tree and index is and odd number */
	if ((1 < index) && (1 == index % 2)){
		return pTree->getnode(pTree, index -1);
	}

	return NULL;
} 

/* get the right brother(close to) node of node, if there's no right brother then return NULL */
static PERSON_BT_ARR * arrbtree1_get_rightbrother(ARR_BTREE_P * pTree, PERSON_BT_ARR * pNode){
	if (C_TRUE != pTree->is_initialed){
		base_error("This object is not initialed yet!");
	}

	int index = arrbtree1_get_node_idx(pTree, pNode);

	if (0 > index){
		printf("the node is not existed in the binary tree\n!");
		return NULL;
	}

	/* not the rootnode of the binary tree and index is and even number */
	if ((1 < index) && (0 == index % 2)){
		return pTree->getnode(pTree, index -1);
	}

	return NULL;
}

/* Insert childtree under a node with parameter left or right */
static C_BOOL arrbtree1_insert_child(ARR_BTREE_P * pTree, PERSON_BT_ARR * pNode, char side, int id, char * pname){
	if (C_TRUE != pTree->is_initialed){
		base_error("This object is not initialed yet!");
	}

	if ('L' != side && 'R' != side){
		printf("please input 'L' or 'R' for side parameter.\n");
		return C_FALSE;
	}

	int index = arrbtree1_get_node_idx(pTree, pNode);
	int childindex;
	PERSON_BT_ARR * pchild;

	if (0 > index){
		printf("the node is not existed in the binary tree\n!");
		return C_FALSE;
	}

	if ('L' == side){
		childindex = index * 2;
	}
	else{
		childindex = index * 2 + 1;
	}

	/*
	 * if childindex is over the max length of the array, it's necessary to extend the array
	 * here, we just set the length to fit the rightchildindex of childindex
	 */
	if (childindex > pTree->max_arrlen){
		if (C_TRUE != arrbtree1_extend(pTree, childindex * 2 + 1)){
			return C_FALSE;
		}
	}

	pchild = &(pTree->pArr[childindex]);
	if (C_FALSE != pchild->is_valid){
		printf("the node have %c child already!\n", side);
		return C_FALSE;
	}

	pchild->id = id;
	strncpy(pchild->name, pname+0, ARRBTREE1_NM_LEN);
	pchild->is_valid = C_TRUE;

	pTree->count++;
	return C_TRUE;
}

/* delete childtree under a node with parameter left or right , and with an output parameter to get the deleted node*/
static C_BOOL arrbtree1_delete_node(ARR_BTREE_P * pTree, PERSON_BT_ARR * pNode, PERSON_BT_ARR * poutput){
	if (C_TRUE != pTree->is_initialed){
		base_error("This object is not initialed yet!");
	}

	int index = arrbtree1_get_node_idx(pTree, pNode);

	if (0 > index){
		printf("the node is not existed in the binary tree\n!");
		return C_FALSE;
	}

	return C_TRUE;
}	

/* move a childtree under another node */
static C_BOOL arrbtree1_move_child(ARR_BTREE_P * pTree, PERSON_BT_ARR * pNode, PERSON_BT_ARR * pParent){
	return C_TRUE;
}

/* get the specified node by btree number, if fail, return NULL */
static PERSON_BT_ARR * arrbtree1_getnode(ARR_BTREE_P * pTree, int index){
	if (C_TRUE != pTree->is_initialed){
		base_error("This object is not initialed yet!");
	}

	if (1 > index || pTree->max_arrlen < index){
		printf("the index is over scope\n!");
		return NULL;
	}

	if (C_TRUE == pTree->pArr[index].is_valid){
		return &(pTree->pArr[index]);
	}

	return NULL;
}

/* print the btree by number */
static void arrbtree1_arr_print(ARR_BTREE_P * pTree){
	return;
}

