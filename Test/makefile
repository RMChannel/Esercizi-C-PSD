test: main.o btree.o item_int.o list.o
	gcc main.o btree.o item_int.o list.o -o main.exe
	./main.exe
	rm -f *.exe *.o

main: main.o btree.o item_int.o
	gcc main.o btree.o item_int.o -o main.exe

main.o:
	gcc -c main.c

btree.o:
	gcc -c btree.c

item_int.o:
	gcc -c item_int.c

queueList.o:
	gcc -c queueList.c

list.o:
	gcc -c list.c

stackList.o:
	gcc -c stackList.c

clean:
	rm -f *.exe *.o