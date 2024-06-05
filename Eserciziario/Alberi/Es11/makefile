link: main.o btree.o item_string.o list.o
	gcc main.o btree.o item_string.o list.o -o main.exe
	./main.exe
	rm *.exe *.o

main.o:
	gcc -c main.c

btree.o:
	gcc -c btree.c

item_string.o:
	gcc -c item_string.c

list.o:
	gcc -c list.c

clean:
	rm -f *.exe *o