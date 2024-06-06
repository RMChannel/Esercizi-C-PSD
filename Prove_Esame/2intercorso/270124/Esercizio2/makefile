link: btree.o item-int.o main.o list.o
	gcc btree.o item-int.o main.o list.o -o main.exe

btree.o:
	gcc -c btree.c

main.o:
	gcc -c main.c

list.o:
	gcc -c list.c

item-int.o:	
	gcc -c item-int.c

clean:
	rm -f *.exe *.o