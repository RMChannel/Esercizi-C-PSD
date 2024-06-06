link: main.o queueList.o list.o item_string.o
	gcc main.o queueList.o list.o item_string.o -o main.exe

main.o:
	gcc -c main.c

queueList.o:
	gcc -c queueList.c

list.o:
	gcc -c list.c

item_string.o:
	gcc -c item_string.c

clean:
	rm -f *.exe *.o