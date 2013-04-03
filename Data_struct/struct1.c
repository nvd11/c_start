#include <stdio.h>
#include <string.h>


struct Student{
	int sid;
	char name[10];
	int age;
};  //; is need

int struct1(void) {

	struct Student st = {1000, "Jason", 20};

	printf("%d %s %d\n",st.sid, st.name, st.age);

	st.sid = 99;
	//st.name="Cindy";    //error
	strcpy(st.name, "Cindy");
        st.age = 38;
	printf("%d %s %d\n",st.sid, st.name, st.age);

	printf("struct done\n");
	return 0;
}


int struct2(void) {
	struct Student st;
	struct Student *pst;

	pst=&st;
        pst->sid = 101;   //pst->sid is squard to (*pst).sid ==>  st.sid
        //pst->name -> "Moon"; //error
	strcpy(pst->name,"Moon");
        pst->age =28;

	printf("%d %s %d\n",pst->sid, pst->name, pst->age);
	return 0;
}

void sv(struct Student * pst);
void pv(struct Student * pst);

int struct3(void) {
	struct Student st;
	sv(&st);
	pv(&st);
	return 0;
}

void sv(struct Student * pst){
	pst->sid = 102;
	strcpy(pst->name, "Crystal");
	pst->age=24;
}

void pv(struct Student * pst){
	printf("%d %s %d\n",pst->sid, pst->name, pst->age);
}
