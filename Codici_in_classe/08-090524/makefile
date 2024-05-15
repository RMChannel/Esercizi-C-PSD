link: bst.o main.o item_int.o queueList.o list.o
	gcc bst.o main.o item_int.o queueList.o list.o -o bst.exe
	./bst.exe
	rm -f *.o *.exe

bst.o:
	gcc -c bst.c

main.o:
	gcc -c main.c

item_int.o:
	gcc -c item_int.c

queueList.o:
	gcc -c queueList.c

list.o:
	gcc -c list.c

clean:
	rm -f *.o *.exe