CC=gcc
OBJS=main.o sort.o array_funcs.o malloc_1.o array.o array1.o char_array.o bisearch.o bit32_64.o pointer1.o struct1.o memory_1.o arrlist.o
HEADPATH=./headfiles/
EXEC=main


$(EXEC): ${OBJS}
	${CC} ${OBJS} -o ${EXEC}

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

cleanall:
	rm -rf ${EXEC} *.o
clean:
	rm -rf *o

###  $< ==> means the first one of the objs which are depended ex main.c of line 12
###  $@ ==> means the current obj
###  $^ ==> means all the objs which are depended
