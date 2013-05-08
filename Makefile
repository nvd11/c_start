CC=gcc
EXEC=main
OBJS=main.o sort.o array_funcs.o malloc_1.o array.o array1.o char_array.o bisearch.o bit32_64.o pointer1.o struct1.o memory_1.o arrlist.o linklist1.o stuck1.o linkqueue1.o arrqueue1.o arrstuck1.o arrbtree1.o recursion.o hanoi.o basefuncs.o base_math.o fork1.o base_exec.o
HEADPATH=./headfiles/


all: cleanall ${EXEC}

$(EXEC): ${OBJS}
	${CC} ${OBJS} -o ${EXEC} -lm

main.o: main.c  
	${CC} -c -g $< -I ${HEADPATH} -o $@

#######################################
sort.o:	sort/sort.c
	${CC} -c -g $< -I ${HEADPATH} -o $@

#array
array_funcs.o: ArrayPoint/array_funcs.c
	${CC} -c -g $< -I ${HEADPATH} -o $@

malloc_1.o: ArrayPoint/malloc_1.c
	${CC} -c -g $< -I ${HEADPATH} -o $@

array.o: ArrayPoint/array.c
	${CC} -c -g $< -I ${HEADPATH} -o $@

array1.o: Data_struct/array1.c
	${CC} -c -g $< -I ${HEADPATH} -o $@ 

char_array.o: char/char_array.c
	${CC} -c -g $< -I ${HEADPATH} -o $@

bisearch.o: bisearch/bisearch.c
	${CC} -c -g $< -I ${HEADPATH} -o $@

bit32_64.o: bit/bit32_64.c
	${CC} -c -g $< -I ${HEADPATH} -o $@

pointer1.o: Data_struct/pointer1.c
	${CC} -c -g $< -I ${HEADPATH} -o $@

struct1.o: Data_struct/struct1.c
	${CC} -c -g $< -I ${HEADPATH} -o $@

memory_1.o: Memory/memory_1.c
	${CC} -c -g $< -I ${HEADPATH} -o $@

arrlist.o: Data_struct/arrlist.c
	${CC} -c -g $< -I ${HEADPATH} -o $@

linklist1.o: Data_struct/linklist1.c
	${CC} -c -g $< -I ${HEADPATH} -o $@

stuck1.o: Data_struct/stuck1.c
	${CC} -c -g $< -I ${HEADPATH} -o $@
	
linkqueue1.o: Data_struct/linkqueue1.c
	${CC} -c -g $< -I ${HEADPATH} -o $@
	
arrqueue1.o: Data_struct/arrqueue1.c
	${CC} -c -g $< -I ${HEADPATH} -o $@
	
arrstuck1.o: Data_struct/arrstuck1.c
	${CC} -c -g $< -I ${HEADPATH} -o $@
	
arrbtree1.o: Data_struct/arrbtree1.c
	${CC} -c -g $< -I ${HEADPATH} -o $@
	
recursion.o: Data_struct/Recursion/recursion.c
	${CC} -c -g $< -I ${HEADPATH} -o $@
	
hanoi.o: Data_struct/Recursion/hanoi.c
	${CC} -c -g $< -I ${HEADPATH} -o $@
	
basefuncs.o: Basefuncs/basefuncs.c
	${CC} -c -g $< -I ${HEADPATH} -o $@

base_math.o: Basefuncs/base_math.c
	${CC} -c -g $< -I ${HEADPATH} -o $@

fork1.o: Process/fork1.c
	${CC} -c -g $< -I ${HEADPATH} -o $@
	
base_exec.o: Basefuncs/base_exec.c
	${CC} -c -g $< -I ${HEADPATH} -o $@
	
cleanall:
	rm -rf ${EXEC} *.o

clean:
	rm -rf *o


###  $< ==> means the first one of the objs which are depended ex main.c of line 12
###  $@ ==> means the current obj
###  $^ ==> means all the objs which are depended
