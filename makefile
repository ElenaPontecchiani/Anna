CC=g++
CCFLAGS=-Wall -march=x86-64 -std=c++11
PROG_NAME=prog

prog :  main basx basxMath
	$(CC) $(CCFLAGS) -o $(PROG_NAME) main.o basx.o basxMath.o

main :  main.cpp basx.h matrix.h square_matrix.h diagonal_matrix.h
	$(CC) $(CCFLAGS) -c main.cpp -o main.o

basx:	basx.cpp basx.h
	$(CC) $(CCFLAGS) -c basx.cpp -o basx.o

basxMath :	basxMath.cpp basxMath.h
		$(CC) $(CCFLAGS) -c basxMath.cpp -o basxMath.o



clean:
	rm *.o
	echo ".o files cleaned"

run_wash: prog
	make clean
	clear
	./prog
