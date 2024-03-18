3a: 3a.o vettore.o utils.o
	gcc 3a.o vettore.o utils.o -o 3a.out

3b: 3b.o vettore.o utils.o
	gcc 3b.o vettore.o utils.o -o 3b.out

3a.o:
	gcc -c 3a.c

3b.o:
	gcc -c 3b.c

vettore.o:
	gcc -c vettore.c

utils.o:
	gcc -c utils.c

clean:
	rm -f *.o *.out