int: btree.o mainInt.o list.o item-int.o stackArray.o
	gcc btree.o mainInt.o list.o item-int.o stackArray.o -o btree.exe

string: btree.o mainString.o list.o item-string.o stackArray.o
	gcc btree.o mainString.o list.o item-string.o stackArray.o -o btree.exe

btree.o:
	gcc -c btree.c

stackArray.o:
	gcc -c stackArray.c

mainInt.o:
	gcc -c mainInt.c

mainString.o:
	gcc -c mainString.c

item-int.o:
	gcc -c item-int.c

item-string.o:
	gcc -c item-string.c

list.o:
	gcc -c list.c

clean:
	rm -f *.exe *.o