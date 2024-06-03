int: list.o main.o item_int.o queueList.o
	gcc list.o item_int.o main.o queueList.o -o queue.exe

string: main.o item_string.o queueArray.o
	gcc item_string.o main.o queueArray.o -o queue.exe

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