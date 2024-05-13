test: main.o btree.o item_string.o
	gcc main.o btree.o item_string.o -o main.exe
	./main.exe
	rm -f *.exe *.o

main.o:
	gcc -c main.c

btree.o:
	gcc -c btree.c

item_string.o:
	gcc -c item_string.c

clean:
	rm -f *.exe *.o