#include <stdio.h>

int bit32_64(){

char a[]="abcde";

char *p;

p=a;

//long int addr;

//addr=p;

printf("addr of a is %p\n",p);  //&(p[0])
printf("addr of b is %p\n",p+1);
printf("addr of c is %p\n",p+2);
printf("addr of d is %p\n",p+3);


printf(" \nbit done\n");
return 0;
}



int showsize(){

int i;
i=68888;

printf("sizeof(int) is %ld\n",sizeof(int));
printf("sizeof(long int) is %ld\n",sizeof(long int));
printf("sizeof(char) is %ld\n",sizeof(char));
printf("sizeof(unsigned int) is %ld\n",sizeof(unsigned int));



return 0;

}
