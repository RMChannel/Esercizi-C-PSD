link: main.o item_auto.o list.o auto.o catalogo.o
	gcc main.o item_auto.o list.o auto.o catalogo.o -o main.exe

main.o:
	gcc -c main.c

item_auto.o:
	gcc -c item_auto.c

list.o:
	gcc -c list.c

auto.o:
	gcc -c auto.c

catalogo.o:
	gcc -c catalogo.c

clean:
	rm -f *.exe *.o