link: main.o btree.o item-int.o list.o
	gcc main.o btree.o item-int.o list.o -o main.exe
	./main.exe
	rm -f *.o *.exe

main.o:
	gcc -c main.c

list.o:
	gcc -c list.c

btree.o:
	gcc -c btree.c

item-int.o:
	gcc -c item-int.c

clean:
	rm -f *.o *.exe