#include <stdio.h>
#include <string.h>

int char_array1(){

char a;
a='a';
printf("char a is %c\n",a);


char b[]="bac";
printf("char b is %s\n",b);
printf("sizeof(b) is %d\n",sizeof(b));


char *p;
p=b;

int i;
for (i=0;i<=3;i++){
	printf("%c\n",*(p+i));
}


printf("char_array1\n");

return 0;


}

int char_array2(){

	char c[5];
	//c={'c','d','e','f','d'}; //wrong
	c[0]='a';c[1]='b';c[2]='c';c[3]='d';c[4]='e';	
	printf("char c is %s\n",c);
	printf("sizeof(c) is %d\n",sizeof(c));

	int d[3][4];
	//d={'c','d','e','f','d'}; //ok, at the same time. length has been set to 5
	//d={'c','d','e','f','d'}; //wrong, after length is set, cannot set the array value once again as this.

	printf("char_array2\n");
	return 0;
}

int char_array3(){
	char c[]={'c','d','e','f','d'}; //right

	int i;
	for (i=0;i<=(sizeof(c) -1);i++){
		printf("c[%d] is %c\n",i,c[i]);
	}

	printf("char c is %s\n",c);
	printf("sizeof(c) is %d\n\n",sizeof(c));

	
	char d[6]={'c','d','e','f','d'}; //string
	char *p;
	p=d;
	for (i=0;i<=(sizeof(d) -1);i++){
		printf("d[%d] is %c\n",i,*(p+i)); //*(p+i) = p[i]
	}

	printf("char d is %s\n",d);
	printf("sizeof(d) is %d\n\n",sizeof(d));

	printf("char_array3\n");
	return 0;
}

int char_array4(){

	char c[]={'c','d','e','\000','d','g','\000'}; //right
	printf("char c is %s\n",c);
	printf("sizeof(c) is %d\n",sizeof(c));
       	printf("strlen(c) is %d\n\n",strlen(c));

	char d[]="cdefdg"; //string
	printf("char d is %s\n",d);
	printf("sizeof(d) is %d\n",sizeof(d));
       	printf("strlen(d) is %d\n\n",strlen(d));

	char e[6]="cdefdg"; //not string
	printf("char e is %s\n",e);
	printf("sizeof(e) is %d\n",sizeof(e));
       	printf("strlen(e) is %d\n\n",strlen(e));


	printf("char_array4\n");
	return 0;

}


int char_array5(){
	char c[]="abcdef"; //string
	printf("sizeof(c) is %d\n",sizeof(c));
       	printf("strlen(c) is %d\n",strlen(c));
	printf("c[0] is %c\n",*c );
	printf("c[1] is %c\n",c[1]); printf("c[2] is %c\n\n",*(c+2)); //2 method to get the element value 

	char *p;
	p=c;
        p[3]='k'; //right
	printf("char c is %s\n",p);
	printf("sizeof(p) is %d\n",sizeof(p));
       	printf("strlen(p) is %d\n",strlen(p));
	printf("p[0] is %c\n",*p );
	printf("p[1] is %c\n",p[1]);
	printf("p[2] is %c\n\n",*(p+2)); //2 method to get the element value


        char *q="abcdef";  //right
	printf("char q is %s\n",q);
	printf("sizeof(q) is %d\n",sizeof(q));
       	printf("strlen(q) is %d\n\n",strlen(q));
	printf("q[0] is %c\n",*q );
	printf("q[1] is %c\n",q[1]);
	printf("q[2] is %c\n\n",*(q+2)); //2 method to get the element value

      

	printf("char_array5\n");
	return 0;
}

int getlen(char* a){
	return sizeof(a);
}


int char_array6(){
	char c[]="abcdefghikjlmn"; //string
	char *p;
	p=c;	
	
	printf("sizeof(c) is %d\n",sizeof(c));
	printf("sizeof(p) is %d\n\n",sizeof(p));

	char *q;
	int *r;

	printf("sizeof(q) is %d\n",sizeof(q));
	printf("sizeof(r) is %d\n\n",sizeof(r));

	printf("sizeof(int) is %d\n\n",sizeof(int));
	printf("sizeof(long) is %d\n\n",sizeof(long));
	printf("sizeof(char) is %d\n\n",sizeof(char));

	printf("getlen(c) is %d\n",getlen(c));
	printf("getlen(p) is %d\n\n",getlen(p));
	
	printf("char_array6\n");
	return 0;
}



