int: list.o main.o item_int.o queueList.o
	gcc list.o item_int.o main.o queueList.o -o queue.exe

string: main.o item_string.o queueArray.o
	gcc item_string.o main.o queueArray.o -o queue.exe

stackList.o:
	gcc -c stackList.c

stackArray.o:
	gcc -c stackArray.c

item_int.o:
	gcc -c item_int.c

item_string.o:
	gcc -c item_string.c
	
main.o:
	gcc -c main.c

list.o: 
	gcc -c list.c

queueList.o:
	gcc -c queueList.c

queueArray.o:
	gcc -c queueArray.c

clean:
	rm -f *.o *.exe