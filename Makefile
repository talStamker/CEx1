FLAG=-Wall -g
CC=gcc

#targets:
all: mats matd connection
#names
mats: libclassmatd.a
matd: libcalssmats.so 

#main
connection: main.o
	$(CC) $(FLAG) -o connection main.o ./libcalssmats.so -lm


#static andynamic library
libclassmatd.a: mat.o
	ar -rcs libclassmatd.a mat.o
libcalssmats.so: mat.o
	$(CC) -shared -o libcalssmats.so mat.o

# the order of function
mat.o:mat.c my_mat.h
	$(CC) $(FLAG) -c mat.c
main.o: main.c my_mat.h
	$(CC) $(FLAG) -c main.c

#clean all the file that created by make file
.PHONY:clean
clean: 
	rm -f *.o *.so *.a connection