linl: main.o list.o item-string.o
	gcc main.o list.o item-string.o -o main.exe

main.o:
	gcc -c main.c

list.o:
	gcc -c list.c

item-string.o:
	gcc -c item-string.c

clean:
	rm -f *.exe *.o