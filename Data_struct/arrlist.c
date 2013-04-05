#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#include "arrlist.h"

static BOOL Arr_extend(struct Arrlist * pArr, int increment);
static void Arr_error(char * pstr);
static void Arr_sort_dtl(int * piar, int len);
static int Arr_p_array(int * p, int len);
static void Arr_sort_dtlmaopao(int * piar, int len);
  


void Arr_init(struct Arrlist * pArr, int length){
	pArr->paddr = (int *)malloc(sizeof(int) * length);
		
	if (NULL == pArr->paddr){
		Arr_error("fail to assign memory!!");
	}

	pArr->len = length;
	pArr->cur_len = 0;
	pArr->increment = 10;

	pArr->is_inited = TRUE;

	return;
}


BOOL Arr_is_empty(struct Arrlist * pArr){
	if (TRUE != pArr->is_inited){
		Arr_error("Array is not inited yet!!");
	}

	if (0 == pArr->cur_len){
		return TRUE;
	}
	return FALSE;
}

BOOL Arr_is_full(struct Arrlist * pArr){
	if (TRUE != pArr->is_inited){
		Arr_error("Array is not inited yet!!");
	}

	if (pArr->len == pArr->cur_len){
		return TRUE;
	}
	return FALSE;
}

void Arr_show(struct Arrlist * pArr){
	if (TRUE != pArr->is_inited){
		Arr_error("Array is not inited yet!!");
	}

	if (TRUE == Arr_is_empty(pArr)){
		printf("It's an empty Arrlist\n");
		return;
	}
	
	int i;
	for (i=0; i < (pArr->cur_len - 1); i++){
 		printf("%d, ", pArr->paddr[i]);
	}		

	printf("%d\n", pArr->paddr[pArr->cur_len -1]);
	return;
}	

BOOL Arr_add(struct Arrlist * pArr, int val){
	if (TRUE != pArr->is_inited){
		Arr_error("Array is not inited yet!!");
	}

	if (TRUE == Arr_is_full(pArr)){
		if (FALSE == Arr_extend(pArr, pArr->increment)){ 
			return FALSE;
		}
	}
	
	pArr->paddr[pArr->cur_len] = val; // assign the value
	pArr->cur_len++;		
	return TRUE;
}




BOOL Arr_set(struct Arrlist * pArr, int index, int val){
	if (TRUE != pArr->is_inited){
		Arr_error("Array is not inited yet!!");
	}

	if((index < 0) || (index >= pArr->cur_len)){
		printf("the element is not existed yet\n");
		return FALSE;
	}

	pArr->paddr[index] = val;	
	return TRUE;
}

int Arr_get(struct Arrlist * pArr, int  index){
	if (TRUE != pArr->is_inited){
		Arr_error("Array is not inited yet!!");
	}

	if((index < 0) || (index >= pArr->cur_len)){
		printf("the element is not existed yet\n");
		return 0;
	}

	return pArr->paddr[index];	
}

BOOL Arr_insert(struct Arrlist * pArr, int position, int val){
	if (TRUE != pArr->is_inited){
		Arr_error("Array is not inited yet!!");
	}


	if((position < 0) || (position >= pArr->cur_len)){
		printf("the position is over the length of array, please use Arr_add instead\n");
		return FALSE;
	}
	
	if(TRUE == Arr_is_full(pArr)){
		if (FALSE == Arr_extend(pArr, pArr->increment)){ 
			return FALSE;
		}
	}

	int i;
	for (i=(pArr->cur_len -1); i>= position; i--){
		pArr->paddr[i+1] = pArr->paddr[i];
	}

	pArr->paddr[position] = val;
	pArr->cur_len++;
        return TRUE;

}


BOOL Arr_delete(struct Arrlist * pArr, int index){
	if (TRUE != pArr->is_inited){
		Arr_error("Array is not inited yet!!");
	}


	if((index < 0) || (index >= pArr->cur_len)) {
		printf("the element is not existed yet\n");
		return FALSE;
	}

	int i;
	for(i = (index + 1); i <= (pArr->cur_len -1); i++){
		pArr->paddr[i-1]=pArr->paddr[i];	
	}	
	
	pArr->paddr[pArr->cur_len-1]=0;
	pArr->cur_len--;
	return TRUE;

}

void Arr_invert(struct Arrlist * pArr){
	if (TRUE != pArr->is_inited){
		Arr_error("Array is not inited yet!!");
	}

	if (TRUE == Arr_is_empty(pArr)){
		return;
	}

	int i = 0;
	int j = pArr->cur_len -1;
	int m;	
	
	while(i<j){
		m = pArr->paddr[i];
		pArr->paddr[i] = pArr->paddr[j];
		pArr->paddr[j] = m;
		i++;
		j--;
	}
}
	
void Arr_sort(struct Arrlist * pArr){
	if (TRUE != pArr->is_inited){
		Arr_error("Array is not inited yet!!");
	}

	if (TRUE == Arr_is_empty(pArr)){
		return;
	}
	
	Arr_sort_dtlmaopao(pArr->paddr, pArr->cur_len);

}


static void Arr_sort_dtlmaopao(int * piar, int len){
	int i, j, m;
	for (i=0; i< len; i++){
		//printf("\n");
		//printf("i is %d\n",i);
		//Arr_p_array(piar,len);

		for (j=i+1; j< len; j++){
			//printf("mv is %d\n",piar[i]);
			//Arr_p_array(piar,len);
			if (piar[i] > piar[j]){
				m =piar[i];	
				piar[i] = piar[j];
				piar[j] = m;
					
			}
			//Arr_p_array(piar,len);
		}
	}	
}
static void Arr_sort_dtl(int * piar, int len){
	int i, j;
	int m = 0;
	int mv;
	int curval;
	int k;
	BOOL flag;
	for (i=0; i< len; i++){  //exec times
		m=0;
		if ((FALSE == flag)){
			m=i;	
		}	

		//printf("\n");
		//printf("i is %d\n",i);
		//Arr_p_array(piar,len);
		//printf("m is %d\n",m);
		flag=FALSE;
		mv = piar[m];
		//printf("mv is %d\n",mv);
		for (j=m+1; j< len; j++){ //from second to the last one
			if (mv > piar[j]){
				piar[m] = piar[j];
				//Arr_p_array(piar,len);

				for(k=j-1; k>m; k--){
					piar[k+1] = piar[k];
					//Arr_p_array(piar,len);
				}
				piar[m+1] = mv;
				//Arr_p_array(piar,len);
				m++;
				flag = TRUE;
			}
		} 
	} 

}


static void Arr_error(char * pstr){
	while (*pstr != '\0'){
		printf("%c",*pstr);	
		pstr++;
	}
	
	printf("\n");	
	exit(-1);
}

static BOOL Arr_extend(struct Arrlist * pArr, int increment){
	
	pArr->paddr = (int *)realloc(pArr->paddr, sizeof(int) * (pArr->cur_len + increment));

	if (NULL == pArr->paddr){
		return FALSE;
	}
	
	pArr->len += increment;
	return TRUE;
}


static int Arr_p_array(int * p, int len){
	int i;
	for (i=0; i<len; i++){
		if (i < (len -1)) {
			printf("%d, ",*p); 	
		}
		else{
			printf("%d\n",*p); 	
		}
		p++;
	}
	return 0;
}
