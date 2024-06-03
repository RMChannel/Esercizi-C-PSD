int: list.o main.o item_string.o queueList.o
	gcc list.o item_string.o main.o queueList.o -o queue.exe

queueList.o:
	gcc -c queueList.c

queueArray.o:
	gcc -c queueArray.c

item_int.o:
	gcc -c item_int.c

item_string.o:
	gcc -c item_string.c
	
main.o:
	gcc -c main.c

list.o: 
	gcc -c list.c

clean:
	rm -f *.o *.exe