test: main.o btree.o item_string.o queueList.o list.o stackList.o
	gcc main.o btree.o item_string.o queueList.o list.o stackList.o -o main.exe
	./main.exe
	rm -f *.exe *.o

main: main.o btree.o item_string.o queueList.o list.o stackList.o
	gcc main.o btree.o item_string.o queueList.o list.o stackList.o -o main.exe

main.o:
	gcc -c main.c

btree.o:
	gcc -c btree.c

item_string.o:
	gcc -c item_string.c

queueList.o:
	gcc -c queueList.c

list.o:
	gcc -c list.c

stackList.o:
	gcc -c stackList.c

clean:
	rm -f *.exe *.o