link: main.o queueList.o item_string.o list.o
	gcc main.o queueList.o item_string.o list.o -o main.exe

main.o:
	gcc -c main.c

queueList.o:
	gcc -c queueList.c

item_string.o:
	gcc -c item_string.c

list.o:
	gcc -c list.c

clean:
	rm -f *.exe *.o