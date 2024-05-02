link: main.o btree.o item_string.c
	gcc main.o btree.o item_string.c -o btree.exe

main.o:
	gcc -c main.c

btree.o:
	gcc -c btree.c

item_string.o:
	gcc -c item_string.c

clean:
	rm -f *.exe *.o