link: main.o btree.o item_string.o list.o stack_list.o queueList.o
	gcc main.o btree.o item_string.o list.o stack_list.o queueList.o -o main.exe
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

stack_list.o:
	gcc -c stack_list.c

queueList.o:
	gcc -c queueList.c

clean:
	rm -f *.exe *o