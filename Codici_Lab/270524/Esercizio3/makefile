link: main.o auto.o list.o catalogo.o
	gcc main.o auto.o list.o catalogo.o -o main.exe

main.o:
	gcc -c main.c

catalogo.o:
	gcc -c catalogo.c

auto.o:
	gcc -c auto.c

list.o:
	gcc -c list.c

clean:
	rm -f *.exe *.o