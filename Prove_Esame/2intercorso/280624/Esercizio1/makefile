link: main.o btree.o list.o item-int.o
	gcc main.o btree.o list.o item-int.o -o main.exe

main.o:
	gcc -c main.c

btree.o:
	gcc -c btree.c

list.o:
	gcc -c list.c

item-int.o:
	gcc -c item-int.c

clean:
	rm -f *.exe *.o