helloworld: file1.o file2.o
	gcc file1.o file2.o -o helloworld

file1.o: file1.c  
	gcc -c file1.c -I ./headfiles/ -o file1.o  #need -I option


file2.o: file2.c 
	gcc -c file2.c -I ./headfiles/ -o file2.o

clean:
	rm -rf *.o helloworld 
