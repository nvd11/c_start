#include <stdio.h>
#include <malloc_1.h>

int array_main(){
	int i;
	i=malloc_main();		
	printf("array_mian done!\n");
	return 0;
}


int array1(){
	int A[10]={10,1,2,3,4,5,6,7,8,9};
	int *p;

        A[0]=11;
	p=A;
	
	printf("A[0] is %d\n", *p);

	p=p+1;
	printf("A[1] is %d\n", *p);

	p=p+1;
	printf("A[2] is %d\n", *p);

	p=A;   //set the index to 0
	p+=3;  //set the index to 3

	printf("A[3]-A[9] are ");

	int i;
	for (i=3; i<=9; i++){
		printf("%d,", *p);		
		p++;
	}
	printf("\n");

	p=A;   //set the index to 0
	printf("A[0] is %d\n", *p);
	printf("A[2] is %d\n", *(p+2));
	printf("A[8] is %d\n", *(p+8));

	
	p++;
	printf("%d\n",*p);
	return 0;
}


int array2(){

	int B[3][4] = {{ 0, 1, 2, 3},
		       {10,11,12,13},
		       {20,21,22,23}};
			
		       
	int *p2;
	//p2=B[0];
	p2=B[0]; //p2=&B[0][0]

	printf("B[0][0] is %d\n", *p2);

        *p2=99;
	printf("B[0][0] is %d\n", *p2);

        p2++;
	printf("B[0][1] is %d\n", *p2);

        p2+=1*4+1;
	printf("B[2][2] is %d\n", *p2);

	

	printf("array2 done\n");
        return 0;
}

int array3(){

	int B[3][4] = {{ 0, 1, 2, 3},
		       {10,11,12,13},
		       {20,21,22,23}};
	int *p3;

        p3 = *(B+1)+2;
	printf("B[1][2] is %d\n", *p3);

        p3 = *(B+2)+1;
	printf("B[2][1] is %d\n", *p3);

	printf("array3 done\n");
	return 0;
}

int array4(){
	int B[3][4] = {{ 0, 1, 2, 3},
		       {10,11,12,13},
		       {20,21,22,23}};


	int (*p4)[4];

        p4=B;

        printf("B[1][2] is %d\n", *(p4[1]+2));
        printf("B[2][1] is %d\n", *(p4[2]+1));
	printf("array4 done\n");
	return 0;
}

int array5(){
	int B[3][4] = {{ 0, 1, 2, 3},
		       {10,11,12,13},
		       {20,21,22,23}};


	int *p5[3];

	int i;
	for (i=0; i <3 ;i++){
		p5[i] = B[i];
	}
        printf("B[1][2] is %d\n", *(p5[1]+2));
        printf("B[2][1] is %d\n", *(p5[2]+1));
	printf("array5 done\n");
	return 0;
}

int array6(){
	int A[]={1,2,3,4,5};

        printf("A[3] is %d\n", A[3]);
        return 0;
}
