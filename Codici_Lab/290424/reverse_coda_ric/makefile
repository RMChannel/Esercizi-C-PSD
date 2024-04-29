link: main.o item_int.o list.o queueList.o
	gcc main.o item_int.o list.o queueList.o -o main.exe

main.o:
	gcc -c main.c

item_int.o:
	gcc -c item_int.c

queueList.o:
	gcc -c queueList.c

list.o:
	gcc -c list.c

clean:
	rm -f *.exe *.o