#include <stdio.h>

int bsget(int value, int* array , int count){
	int curid;
	int endid = count - 1;   
	int startid = 0;
	int curval;
	int i=0;
	while(endid > startid){
		i++;
		curid= (startid + endid)/2;
		curval = array[curid];
		if  (curval >= value){
			if (curval == value){
				printf("done the while %d times\n",i);
				return curid;	
			}
			/*else*/
			endid = --curid; 		
		}
		else{                    //curval < value 
			startid = ++curid;
		}                      
	}
	
	//when endid == startid, handle the last one
	if (array[endid] == value){
		printf("done the while %d times\n",i);
		return endid;
	}	
	// not found
	
	printf("done the while %d times\n",i);
	return -1;
}

int bisearch1(){
	int a[1000];
	int sortid;
	int v;
	int i;
	int count = sizeof(a)/sizeof(*a);
	for (i=0;i<=count;i++){
		*(a+i)=2*i+4;   //*(a+i)==a[i]
	}

	v=1604;
	sortid=bsget(v,a,count);

	if (sortid !=-1){
		printf("sortid of %d is %d\n",v,sortid);
		printf("array[%d] is %d\n\n",sortid, a[sortid]);
	}
	else{
		printf("%d is not in the array\n",v);
	}

	printf("bisearch1 done\n");
	return 0;
}
