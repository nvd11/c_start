test.o: test.c ./headfiles/test2.h
	gcc -c -g test.c -I ./headfiles/ -o test.o
test2.o: test2.c ./headfiles/test2.h
	gcc -c -g test2.c -I ./headfiles/ -o test2.o
test: test.o test2.o
	gcc test.o test2.o -o test
clean:
	rm -rf *.o 
cleanall:
	rm -rf *.o test
