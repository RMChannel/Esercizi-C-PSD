int: list.o main.o item-piatto.o piatto.o queueList.o
	gcc list.o item-piatto.o main.o piatto.o queueList.o -o queue.exe

queueList.o:
	gcc -c queueList.c

piatto.o:
	gcc -c piatto.c

queueArray.o:
	gcc -c queueArray.c

item-piatto.o:
	gcc -c item-piatto.c
	
main.o:
	gcc -c main.c

list.o: 
	gcc -c list.c

clean:
	rm -f *.o *.exe