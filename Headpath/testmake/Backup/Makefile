helloworld: file1.o file2.o
gcc file1.o file2.o -o helloword

file1.o:    file1.c ./headfiles/file2.h  
gcc file1.c -I ./headfiles/ -o file1.o  

file2.o:    file2.c ./headfiles/file2.h 
gcc file2.c -I ./headfiles/ -o file2.o

clean:
rm *.o 
