#include <stdio.h>

void f(int i){
	i = 100;
}

void f2(int *p){  //It does not define a formal parameter which named *p, it just define a formal parameter named p, and it's type is int *
		  //It also can type as f2(int * p) or f2(int* p)
	*p = 100;
}

int para1(void){

	int i = 9;
	printf("i=%d \n",i); 

	f(i);

	printf("i=%d \n",i);

	f2(&i);

	printf("i=%d \n",i); printf("para done\n");
	return 0;
}


void show_array_1(int *p, int len){
	p[0]=-1;
	int i;
	printf(" a is ");
	for (i=0;i<len;i++){
		printf("%d ",p[i]);
	}	
	printf("\n ");
	
}
	
int array_point_1(){
	int a[5] = {1,2,3,4,5};

	show_array_1(a,5);	
	printf("array_point done\n");
	return 0;
}



int pointer1(){
	char * p= "ab";	
	char * p2 =  p+1;

	printf ("char p is %s\n",p);		
	printf ("p is %p\n",p);		
	printf ("p2 is %p\n",p2);		

	int * p3= (int *)123111111;	
	int * p4 =  p3+1;

	printf ("p is %p\n",p3);		
	printf ("p2 is %p\n",p4);		

	printf("pointer1 done\n");
	printf("\n");

	return 0;
}

int pointer2(){
	char *last = "sd";
	char *ap = (char *)last + sizeof(last);
	char *ap2 = (char *)&last + sizeof(last);
	char **ap3 = (char **)&last + sizeof(last);
	char **ap4 = &last + sizeof(last);
	char *bp = last + sizeof(last);
	char *cp = (char *)(last + sizeof(last));

	printf ("last is %p\n",last);		
	printf ("ap is %p\n",ap);		
	printf ("ap2 is %p\n",ap2);		
	printf ("ap3 is %p\n",ap3);		
	printf ("ap4 is %p\n",ap3);		
	printf ("bp is %p\n",bp);		
	printf ("cp is %p\n",cp);		
	printf("\n");
	return 0;
}
	
int pointer3(){
	int abc =123;
	int *last = &abc;
	int *ap = (int *)last + 2;
	int *bp = last + 2;
	int *cp = (int *)(last + 2); 
	printf ("last is %p\n",last);		
	printf ("ap is %p\n",ap);		
	printf ("bp is %p\n",bp);		
	printf ("cp is %p\n",cp);		
	printf("\n");
	return 0;
}
	
int pointer4(){
	int abc =97;
	char *ap = (char *) &abc;

	printf ("ap is %p\n",ap);		
	printf ("*ap is %c\n",*ap);		

	abc=-143;
	printf ("*ap is %c\n",*ap);		

	abc=831;
	printf ("*ap is %c\n",*ap);		

	abc=2147483647;
	printf ("*ap is %c\n",*ap);		

	abc=2147483648;
	printf ("*ap is %c\n",*ap);		

	
	printf("\n");
	return 0;
}
	
int pointer5(){
	int i =97;
	int * p = &i;
	char * q = (char *)&i;

	printf ("*p is %d\n",*p);		
	printf ("*q is %d\n",*q);		
	printf ("*q is %c\n",*q);		


	
	printf("\n");
	return 0;
}
	
int pointer6(){
	int i = 24930;

	int * p = &i;
	char * q = (char *)&i;

	printf ("*p is %d\n",*p);		
	printf ("*q is %c\n",*q);		
	printf ("*(q+1) is %c\n",*(q+1));		

	printf("\n");
	return 0;

}

int pointer7(){
	int i = -24930;

	int * p = &i;
	char * q = (char *)&i;

	printf ("*p is %d\n",*p);		
	printf ("*q is %c\n",*q);		
	printf ("*(q+1) is %c\n",*(q+1));		

	printf("\n");
	return 0;

}

int mem1(){
	int i = 2;
	int ii = -3;
	int aii = -2147483648;
        int iii = i + ii;
        return 0;
}

int pointer_main(){
	int i;
        i = mem1(); 
	return 0;

}
