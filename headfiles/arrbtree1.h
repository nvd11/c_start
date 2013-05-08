/*
 * arrbtree1.h
 *
 *  Created on: 2013-5-6
 *      Author: gateman
 */
#include "bool_me.h"

#ifndef __ARRBTREE1_H_
#define __ARRBTREE1_H_

#ifndef ARRBTREE1_NM_LEN
#define ARRBTREE1_NM_LEN 16
#endif

typedef struct person_bt_arr{
	int id;
	char name[ARRBTREE1_NM_LEN];
	C_BOOL is_valid;
} PERSON_BT_ARR;

typedef struct arr_btree_person{

	/* judge whether this object is initail*/
	C_BOOL is_initialed;

	/* the array to contain the binary tree*/
	PERSON_BT_ARR * pArr;

	/* max length of the the array */
	int max_arrlen;

	/* current count of the valid elements */
	int count;

	/* count of total of elements of the binary tree(or array) */
	int (* total_count)(struct arr_btree_person *);

	/* clear all the nodes from the tree */
	void (* clear)(struct arr_btree_person *);

	/* judge whether the binary tree is empty binary tree */
	C_BOOL (* is_empty)(struct arr_btree_person *);

	/* number of floors of the binary tree */
	int (* depth)(struct arr_btree_person *);

	/* set root_node */
	C_BOOL (* add_root)(struct arr_btree_person *, int, char *);

	/* get the root node*/
	PERSON_BT_ARR * (* get_root)(struct arr_btree_person *); 

	/* get the parent node of a node */
	PERSON_BT_ARR * (* get_parent)(struct arr_btree_person *, PERSON_BT_ARR  *); 

	/* get the left child node of node, if there's no left child then return NULL */
	PERSON_BT_ARR * (* get_leftchild)(struct arr_btree_person *, PERSON_BT_ARR *); 

	/* get the right child node of node, if there's no right child then return NULL */
	PERSON_BT_ARR * (* get_rightchild)(struct arr_btree_person *, PERSON_BT_ARR *); 

	/* get the left brother(close to) node of node, if there's no left brother then return NULL */
	PERSON_BT_ARR * (* get_leftbrother)(struct arr_btree_person *, PERSON_BT_ARR *); 

	/* get the right brother(close to) node of node, if there's no right brother then return NULL */
	PERSON_BT_ARR * (* get_rightbrother)(struct arr_btree_person *, PERSON_BT_ARR *); 

	/* Insert childtree under a node with parameter left or right */
	C_BOOL (* insert_child)(struct arr_btree_person *, PERSON_BT_ARR *, char, int, char *);

	/* delete childtree under a node with parameter left or right , and with an output parameter to get the deleted node*/
	C_BOOL (* delete_node)(struct arr_btree_person *, PERSON_BT_ARR *, PERSON_BT_ARR *);

    /* move a childtree under another node */
	C_BOOL (* move_child)(struct arr_btree_person *, PERSON_BT_ARR *, PERSON_BT_ARR *);

	/* get the specified node by btree number, if fail, return NULL */
	PERSON_BT_ARR * (* getnode)(struct arr_btree_person *, int);

	/* print the btree by number */
	void (* arr_print)(struct arr_btree_person *);




} ARR_BTREE_P;



/*
 * initial a binary tree container
 * parameter is initial length , it can be extended
 */
ARR_BTREE_P * arrbtree1_new(int);

/* destroy a binary tree container */
void arrbtree1_free(ARR_BTREE_P *);

/* get the index by node, if not existed , return -1 */
int arrbtree1_get_node_idx(struct arr_btree_person *, PERSON_BT_ARR *);

/* get the parent index by index*/
int arrbtree1_get_p_idx(int);

/* get the left child index of a node by index */
int arrbtree1_get_lc_idx(int);

/* get the right child index of a node by index */
int arrbtree1_get_rc_idx(int);




#endif /* ARRBTREE1_H_ */