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
static C_BOOL arrbtree1_is_contained(ARR_BTREE_P *, PERSON_BT_ARR *);
static C_BOOL  arrbtree1_add_rootnode(ARR_BTREE_P *, PERSON_BT_ARR *);
static PERSON_BT_ARR *  arrbtree1_get_rootnode(ARR_BTREE_P *);
static PERSON_BT_ARR *  arrbtree1_get_parent(ARR_BTREE_P *, PERSON_BT_ARR *);
static PERSON_BT_ARR *  arrbtree1_get_leftchild(ARR_BTREE_P *, PERSON_BT_ARR *);
static PERSON_BT_ARR *  arrbtree1_get_rightchild(ARR_BTREE_P *, PERSON_BT_ARR *);
static PERSON_BT_ARR * arrbtree1_get_leftbrother(ARR_BTREE_P * pTree, PERSON_BT_ARR * pNode);
static PERSON_BT_ARR * arrbtree1_get_rightbrother(ARR_BTREE_P * pTree, PERSON_BT_ARR * pNode);
static C_BOOL arrbtree1_insert_child(ARR_BTREE_P *, PERSON_BT_ARR *,char , PERSON_BT_ARR *);
static C_BOOL arrbtree1_delete_node(ARR_BTREE_P *, PERSON_BT_ARR *, PERSON_BT_ARR *);
static C_BOOL arrbtree1_remove_node(ARR_BTREE_P *, char,PERSON_BT_ARR *);
static C_BOOL arrbtree1_move_node(ARR_BTREE_P *, PERSON_BT_ARR *, char, PERSON_BT_ARR *);
static PERSON_BT_ARR * arrbtree1_getnode(ARR_BTREE_P * , int);
static C_BOOL arrbtree1_is_leaf(ARR_BTREE_P * pTree, PERSON_BT_ARR * pNode);
static void arrbtree1_arr_print_name(ARR_BTREE_P * );


/*
* not member functions announce
*/
static void arrbtree1_judge_init(ARR_BTREE_P *);
static C_BOOL arrbtree1_extend(ARR_BTREE_P *, int);
static void arrbtree1_recur_rm_nodes_by_idx(ARR_BTREE_P *, int);
static void arrbtree1_recur_mv_nodes_by_idx(ARR_BTREE_P *, int, char, int);
static int arrbtree1_recur_get_idx(ARR_BTREE_P * pTree, PERSON_BT_ARR * pNode, int index);
static void arrbtree1_mv_one_node_by_idx(ARR_BTREE_P *, int *, char, int);
static C_BOOL arrbtree1_is_ancestor_by_idx(int, int);
static C_BOOL arrbtree1_get_depth_by_idx(int);


/*************************************************
* below are the difinition of non member functions
***************************************************/

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

	PERSON_BT_ARR ** pArr = (PERSON_BT_ARR **)malloc(sizeof(PERSON_BT_ARR *) * (init_count+1));
	if (NULL == pArr){
		base_error("fail to assign memory to an array for a binary tree!!");
	}

	/* set all the elements NULL */
	int i;
	for (i=0; i <= init_count; i++){
		pArr[i] = NULL;
	}

	pTree->pArr = pArr;
	pTree->count = 0;
	pTree->max_arrlen = init_count;
	pTree->total_count = arrbtree1_total_count;
	pTree->clear = arrbtree1_clear;
	pTree->is_empty = arrbtree1_is_empty;
	pTree->is_contained = arrbtree1_is_contained;
	pTree->depth = arrbtree1_getdepth;
	pTree->add_root = arrbtree1_add_rootnode;
	pTree->get_root = arrbtree1_get_rootnode;
	pTree->get_parent = arrbtree1_get_parent;
	pTree->get_leftchild = arrbtree1_get_leftchild;
	pTree->get_rightchild = arrbtree1_get_rightchild;
	pTree->get_leftbrother = arrbtree1_get_leftbrother;
	pTree->get_rightbrother = arrbtree1_get_rightbrother;
	pTree->insert_child = arrbtree1_insert_child;
	pTree->delete_node = arrbtree1_delete_node;
	pTree->remove_node = arrbtree1_remove_node;
	pTree->move_node = arrbtree1_move_node;
	pTree->getnode = arrbtree1_getnode;
	pTree->is_leaf = arrbtree1_is_leaf;
	pTree->arr_print_name = arrbtree1_arr_print_name;

	pTree->is_initialed = C_TRUE;
	return pTree;
};

/*
* initial a node with dynamic memory assigned
*/
PERSON_BT_ARR * personbt1_new(int id, char * pname){
	PERSON_BT_ARR * pNode = (PERSON_BT_ARR *)malloc(sizeof(PERSON_BT_ARR));
	if (NULL == pNode){
		base_error("fail to assign memory to a node!!");
	}

	pNode->id = id;
	strncpy(pNode->name, pname+0, ARRBTREE1_NM_LEN);

	return pNode;
}

/* judge whether the tree object is initialed */
static void arrbtree1_judge_init(ARR_BTREE_P * pTree){
	if (C_TRUE != pTree->is_initialed){
		base_error("This object is not initialed yet!");
	}
}

/* extend the max length of the array , the parameter len is the length after extend */
static C_BOOL arrbtree1_extend(ARR_BTREE_P * pTree, int len){
	arrbtree1_judge_init(pTree);

	if (len <= pTree->max_arrlen){
		printf("the length must greater then old length!\n");
		return C_FALSE;
	}

	PERSON_BT_ARR ** pold = pTree->pArr;
	pTree->pArr = (PERSON_BT_ARR **)realloc(pTree->pArr, sizeof(PERSON_BT_ARR *) * len);
	if (NULL == pTree->pArr){
		printf("fail to assign memory to extend the array!\n");
		pTree->pArr = pold;
		return C_FALSE;
	}

	int i;
	for (i=pTree->max_arrlen + 1; i <= len; i++){
		pTree->pArr[i]=NULL;
	}

	pTree->max_arrlen = len;
	return C_TRUE;
}

/* get the index by node, if not existed , return -1 */
int arrbtree1_get_idx_by_node(ARR_BTREE_P * pTree, PERSON_BT_ARR * pNode){
	arrbtree1_judge_init(pTree);

	if(pTree->count == 0){
		return -1;
	}

	return arrbtree1_recur_get_idx(pTree, pNode, 1);
}

/*
 * recursion : get the index of a node , if not existed, return -1
 * use "preorder traverse" maehod
 */
static int arrbtree1_recur_get_idx(ARR_BTREE_P * pTree, PERSON_BT_ARR * pNode, int index){
	if (index > pTree->max_arrlen){
		printf("arrbtree1_recur_get_idx, overflow\n");
		return -1;
	}

	/* step 1, visit the root node */
	if (pNode == pTree->pArr[index]){
		return index;
	}

	int index_r;
	/* step2, visit the left child tree */
	index *= 2;
	if (NULL != pTree->pArr[index]){
		index_r = arrbtree1_recur_get_idx(pTree, pNode, index);
		if (-1 != index_r)
			return index_r;
	}

	/* step3, visit the right child tree */
	index++;
	if (NULL != pTree->pArr[index]){
		index_r = arrbtree1_recur_get_idx(pTree, pNode, index);
		if (-1 != index_r)
			return index_r;
	}

	return -1;
}

/* destroy a node and free its memory */
void personbt1_free(PERSON_BT_ARR * pNode){
	if (NULL != pNode){
		free(pNode);
		pNode = NULL;
	}
	return;
}

/* destroy a binary tree container */
void arrbtree1_free(ARR_BTREE_P * pTree){
	arrbtree1_judge_init(pTree);
	if (NULL != pTree->pArr){
		/* free and remove all nodes */
		pTree->arr_print_name(pTree);
		pTree->clear(pTree);

		free(pTree->pArr);
		pTree->pArr = NULL;
	}
	free(pTree);
	pTree = NULL;
	return;
}

/*
 *  recursion : traverse the binary tree to remove a binary tree
 *  use the "postorder traverse" method
*/
static void arrbtree1_recur_rm_nodes_by_idx(ARR_BTREE_P * pTree, int index){
	int index_c = index * 2;

	/* step1, remove the left child tree */
	if (index_c <= pTree->max_arrlen && NULL != pTree->pArr[index_c]){
		arrbtree1_recur_rm_nodes_by_idx(pTree,index_c);
	}

	/* step2, remove the right child tree */
	index_c++;
	if (index_c <= pTree->max_arrlen && NULL != pTree->pArr[index_c]){
		arrbtree1_recur_rm_nodes_by_idx(pTree,index_c);
	}

	/* step3, remove and free the root node */
	personbt1_free(pTree->pArr[index]);
	pTree->pArr[index] = NULL;
	pTree->count--;

	return;
}

/*
 *  recursion : traverse the binary tree to move a child binary tree to another parent node
 *  use the "preorder traverse" method
 *  it has a pre-condition:  the parent node's right or left child(depends on which side will be move to)
 *  must be empty.
*/
static void arrbtree1_recur_mv_nodes_by_idx(ARR_BTREE_P * pTree, int index, char side, int index_p){
	int index_c = index * 2;

	/* step 1, move the root node to new parent */
	arrbtree1_mv_one_node_by_idx(pTree, &index, side, index_p);

	/* step 2, move the left childtree to the node in new place */
	if (NULL != pTree->pArr[index_c]){
		arrbtree1_recur_mv_nodes_by_idx(pTree, index_c, 'L', index);
	}

	/* step 3, move the right childtree to the node in new place */
	index_c++;
	if (NULL != pTree->pArr[index_c]){
		arrbtree1_recur_mv_nodes_by_idx(pTree, index_c, 'R', index);
	}
	return;
}

static void arrbtree1_mv_one_node_by_idx(ARR_BTREE_P * pTree, int * index, char side, int index_p){
	int index_c;
	if ('L' == side){
		index_c = index_p * 2;	
	}
	else{
		index_c = index_p * 2 + 1;
	}

	/*
	* here, it's needed to judge whether the movement will overload the size of array,
	* if yes, we need to extend the array.
	*/
	if (index_c > pTree->max_arrlen){
		if (C_FALSE == arrbtree1_extend(pTree, index_c * 2 + 1)){ //extend to its right child
			base_error("fail to assign memory during moving nodes\n");
		}
	}

	pTree->pArr[index_c] = pTree->pArr[*index];
	pTree->pArr[*index] = NULL;
	*index = index_c;
	return;
}

/* judge whether node is another node's ancestor */
static C_BOOL arrbtree1_is_ancestor_by_idx(int index_a, int index_c){
	while(index_c > 1 || arrbtree1_get_depth_by_idx(index_a) > arrbtree1_get_depth_by_idx(index_c)){
		if((int)(index_c/2) == index_a){
			return C_TRUE;
		}
	}
	return C_FALSE;	
}

static C_BOOL arrbtree1_get_depth_by_idx(int index){
	/*
	 * log2 is logarithm function with base 2.
	 * floor return the largest integral which is not greater than parameter  ex. floor(1.5) = 1
	 * ceil return the smallest integral which is not less then parameter
	 */

	if(index < 1){
		return -1;
	}

	return floor(log2(index)) + 1;
}

/********************************************
* below are the difinition of member functions
*********************************************/


/* count of total of elements of the binary tree(or array) */
static int arrbtree1_total_count(ARR_BTREE_P * pTree){
	arrbtree1_judge_init(pTree);
	return pTree->max_arrlen -1;
}

/* clear and free all the nodes from the tree */
static void  arrbtree1_clear(ARR_BTREE_P * pTree){
	arrbtree1_judge_init(pTree);

	if ( 0 == pTree->count){
		return;
	}

	/* 1 is the index of root node */
	arrbtree1_recur_rm_nodes_by_idx(pTree, 1);
	return;
}

/* judge whether the binary tree is empty binary tree */
static C_BOOL arrbtree1_is_empty(ARR_BTREE_P * pTree){
	arrbtree1_judge_init(pTree);

	if (pTree->count > 0){
		return C_FALSE;
	}
	return C_TRUE;
}

/* number of floors(valid nodes) of the binary tree */
static int arrbtree1_getdepth(ARR_BTREE_P * pTree){
	arrbtree1_judge_init(pTree);

	/* get the max index of valid nodes */
	int i = pTree->max_arrlen;
	while(i > 0 || NULL == pTree->pArr[i]){
		i--;
	}

	return arrbtree1_get_depth_by_idx(i);
}

/* judge whether a node is contained in the tree */
static C_BOOL arrbtree1_is_contained(ARR_BTREE_P * pTree, PERSON_BT_ARR * pNode){
	if (0 > arrbtree1_get_idx_by_node(pTree, pNode)){
		return C_FALSE;
	}

	return C_TRUE;
}

/* add root_node */
static C_BOOL  arrbtree1_add_rootnode(ARR_BTREE_P * pTree, PERSON_BT_ARR * pNode){
	if (C_TRUE == pTree->is_contained(pTree, pNode)){
		printf("the node is existed in the tree already!\n");
		return C_FALSE;
	}

	if (NULL != pTree->pArr[1]){
		printf("the root node is existed already!\n");
		return C_FALSE;
	}

	pTree->pArr[1] = pNode;
	pTree->count++;
		
	return C_TRUE;
}

/* get the root node*/
static PERSON_BT_ARR *  arrbtree1_get_rootnode(ARR_BTREE_P * pTree){
	arrbtree1_judge_init(pTree);
	return pTree->pArr[1];
} 

/* get the parent node of a node */
static PERSON_BT_ARR *  arrbtree1_get_parent(ARR_BTREE_P * pTree, PERSON_BT_ARR * pNode){
	int index = arrbtree1_get_idx_by_node(pTree, pNode);

	if (0 > index){
		printf("the node is not existed in the binary tree\n!");
		return NULL;
	}

	/* not the rootnode of the binary tree */
	if (1 < index){
		return pTree->pArr[(int)(index / 2)];
	}

	return NULL;
} 

/* get the left child node of node, if there's no left child then return NULL */
static PERSON_BT_ARR *  arrbtree1_get_leftchild(ARR_BTREE_P * pTree, PERSON_BT_ARR * pNode){
	int index = arrbtree1_get_idx_by_node(pTree, pNode);

	if (0 > index){
		printf("the node is not existed in the binary tree\n!");
		return NULL;
	}

	return pTree->pArr[index * 2];
} 

/* get the right child node of node, if there's no right child then return NULL */
static PERSON_BT_ARR *  arrbtree1_get_rightchild(ARR_BTREE_P * pTree, PERSON_BT_ARR * pNode){
	int index = arrbtree1_get_idx_by_node(pTree, pNode);

	if (0 > index){
		printf("the node is not existed in the binary tree\n!");
		return NULL;
	}

	return pTree->pArr[index * 2 + 1];
} 

/* get the left brother(close to) node of node, if there's no left brother then return NULL */
static PERSON_BT_ARR * arrbtree1_get_leftbrother(ARR_BTREE_P * pTree, PERSON_BT_ARR * pNode){
	int index = arrbtree1_get_idx_by_node(pTree, pNode);

	if (0 > index){
		printf("the node is not existed in the binary tree\n!");
		return NULL;
	}

	/* not the rootnode of the binary tree and index is and odd number */
	if ((1 < index) && (1 == index % 2)){
		return pTree->pArr[index - 1];
	}

	return NULL;
} 

/* get the right brother(close to) node of node, if there's no right brother then return NULL */
static PERSON_BT_ARR * arrbtree1_get_rightbrother(ARR_BTREE_P * pTree, PERSON_BT_ARR * pNode){
	int index = arrbtree1_get_idx_by_node(pTree, pNode);

	if (0 > index){
		printf("the node is not existed in the binary tree\n!");
		return NULL;
	}

	/* not the rootnode of the binary tree and index is and even number */
	if ((1 < index) && (0 == index % 2)){
		return pTree->pArr[index + 1];
	}

	return NULL;
}

/* Insert childtree under a node with parameter left or right */
static C_BOOL arrbtree1_insert_child(ARR_BTREE_P * pTree, PERSON_BT_ARR * pNode, char side, PERSON_BT_ARR * pParentNode){
	if ('L' != side && 'R' != side){
		printf("please input 'L' or 'R' for side parameter.\n");
		return C_FALSE;
	}

	if (C_TRUE == pTree->is_contained(pTree, pNode)){
		printf("the node will be inserted is in the tree already!\n");
		return C_FALSE;
	}

	int index_p = arrbtree1_get_idx_by_node(pTree, pParentNode);
	int index_c;

	if (0 > index_p){
		printf("the parent node is not existed in the binary tree!\n");
		printf("abc\n");
		return C_FALSE;
	}

	if ('L' == side){
		index_c = index_p * 2;
	}
	else{
		index_c = index_p * 2 + 1;
	}

	/*
	 * if childindex is over the max length of the array, it's necessary to extend the array
	 * here, we just set the length to fit the rightchildindex of childindex
	 */
	if (index_c > pTree->max_arrlen){
		if (C_TRUE != arrbtree1_extend(pTree, index_c * 2 + 1)){
			return C_FALSE;
		}
	}

	if (NULL != pTree->pArr[index_c]){
		printf("the node have %c child already!\n", side);
		return C_FALSE;
	}

	pTree->pArr[index_c] = pNode;

	pTree->count++;
	return C_TRUE;
}

/* delete and free a node with its childtree , and with an output parameter to get the info deleted node*/
static C_BOOL arrbtree1_delete_node(ARR_BTREE_P * pTree, PERSON_BT_ARR * pNode, PERSON_BT_ARR * poutput){
	int index = arrbtree1_get_idx_by_node(pTree,pNode);
	if (0 > index){
		printf("the node is not existed in the tree!\n");
		return C_FALSE;
	}

	arrbtree1_recur_rm_nodes_by_idx(pTree, index);
	return C_TRUE;
}	

/* remove an node out from a tree, but don't free it */
static C_BOOL arrbtree1_remove_node(ARR_BTREE_P * pTree, char side,PERSON_BT_ARR * pNode){
	if (C_TRUE != pTree->is_leaf(pTree, pNode)){
		printf("the node is not a leaf node or not existed in the binary tree!\n");
		return C_FALSE;
	}

	int index = arrbtree1_get_idx_by_node(pTree, pNode);
	pTree->pArr[index] = NULL;

	return C_TRUE;
}

/* move a childtree under another node */
static C_BOOL arrbtree1_move_node(ARR_BTREE_P * pTree, PERSON_BT_ARR * pNode, char side, PERSON_BT_ARR * pParent){
	if ('L' != side && 'R' != side){
		printf("please input 'L' or 'R' for side parameter.\n");
		return C_FALSE;
	}

	int index = arrbtree1_get_idx_by_node(pTree,pNode);
	if (0 > index){
		printf("the node is not existed in the tree!\n");
		return C_FALSE;
	}

	int index_p = arrbtree1_get_idx_by_node(pTree,pParent);
	if (0 > index_p){
		printf("the node will be move to is not existed in the binary tree\n!");
		return C_FALSE;
	}

	int index_c;
	if ('L' == side){
		index_c = index_p * 2;
	}
	else{
		index_c = index_p * 2 + 1;
	}

	if (NULL != pTree->pArr[index_c]){
		printf("the Parent node has the %c child already!\n",side);
		return C_FALSE;
	}

	if (C_FALSE != arrbtree1_is_ancestor_by_idx(index_p,index)){
		printf("the new parent node is the ancestor of the node will move!\n");
		return C_FALSE;
	}

	/* recursion to mv the node and his childtrees to new place */
	arrbtree1_recur_mv_nodes_by_idx(pTree, index, side, index_p);
	return C_TRUE;

}

/* get the specified node by btree number, if fail, return NULL */
static PERSON_BT_ARR * arrbtree1_getnode(ARR_BTREE_P * pTree, int index){
	arrbtree1_judge_init(pTree);

	if (1 > index || pTree->max_arrlen < index){
		printf("the index is over scope\n!");
		return NULL;
	}

	return pTree->pArr[index];
}

/* judge whether a node is a leaf node */
static C_BOOL arrbtree1_is_leaf(ARR_BTREE_P * pTree, PERSON_BT_ARR * pNode){
	if (NULL != pTree->get_leftchild(pTree,pNode) || NULL != pTree->get_rightchild(pTree, pNode)){
		return C_FALSE;
	}

	return C_TRUE;
}

/* print the btree by number */
static void arrbtree1_arr_print_name(ARR_BTREE_P * pTree){
	arrbtree1_judge_init(pTree);

	printf("the names of nodes sort by index is:\n");
	int i;
	int len = pTree->max_arrlen;
	for (i=1; i <= len; i++){
		if (NULL != pTree->pArr[i]){
			printf("%s",pTree->pArr[i]->name);
		}else{
			printf("NULL");		
		}

		if (i<len)
			printf(", ");
	}
	printf("\n\n");
	return;
}

