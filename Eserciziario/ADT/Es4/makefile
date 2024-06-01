link: main.o auto.o catalogo.o
	gcc main.o auto.o catalogo.o -o main.exe

main.o:
	gcc -c main.c

catalogo.o:
	gcc -c catalogo.c

auto.o:
	gcc -c auto.c

clean:
	rm -f *.exe *.o