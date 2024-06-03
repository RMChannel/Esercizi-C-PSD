link: btree.o main.o list.o item-string.o
	gcc btree.o main.o list.o item-string.o -o btree.exe

btree.o:
	gcc -c btree.c

main.o:
	gcc -c main.c

item-string.o:
	gcc -c item-string.c

list.o:
	gcc -c list.c

clean:
	rm -f *.exe *.o