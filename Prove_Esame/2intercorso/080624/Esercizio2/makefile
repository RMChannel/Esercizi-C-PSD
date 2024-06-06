link: btree.o main.o list.o item-int.o
	gcc btree.o main.o list.o item-int.o -o btree.exe

btree.o:
	gcc -c btree.c

main.o:
	gcc -c main.c

item-int.o:
	gcc -c item-int.c

list.o:
	gcc -c list.c

clean:
	rm -f *.exe *.o