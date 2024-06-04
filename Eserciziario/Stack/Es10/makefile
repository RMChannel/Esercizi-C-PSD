int: list.o main.o item-int.o stackList.o queueList.o btree.o
	gcc list.o item-int.o main.o stackList.o queueList.o btree.o -o stack.exe

stackList.o:
	gcc -c stackList.c

queueList.o:
	gcc -c queueList.c

item-int.o:
	gcc -c item-int.c

btree.o:
	gcc -c btree.c
	
main.o:
	gcc -c main.c

list.o: 
	gcc -c list.c

clean:
	rm -f *.o *.exe