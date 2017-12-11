CC=g++
CCFLAGS=-Wall -march=x86-64
PROG_NAME=prog

prog :  main orario telefonata
	$(CC) $(CCFLAGS) -o $(PROG_NAME) main.o orario.o telefonata.o

main :  main.cpp orario.h
	$(CC) $(CCFLAGS) -c main.cpp -o main.o

orario: orario.cpp orario.h
	$(CC) $(CCFLAGS) -c orario.cpp -o orario.o

telefonata: telefonata.cpp telefonata.h orario.h
	$(CC) $(CCFLAGS) -c telefonata.cpp -o telefonata.o

clean:
	rm *.o
	echo ".o files cleaned"

run_wash: prog
	make clean
	clear
	./prog
