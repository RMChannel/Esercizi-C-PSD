int: list.o main.o item_int.o stackList.o queue.o
	gcc list.o item_int.o main.o stackList.o queue.o -o queue.exe
	./queue.exe
	rm *.o *.exe

stackList.o:
	gcc -c stackList.c

stackArray.o:
	gcc -c stackArray.c

item_int.o:
	gcc -c item_int.c

queue.o:
	gcc -c queue.c
	
main.o:
	gcc -c main.c

list.o: 
	gcc -c list.c

clean:
	rm -f *.o *.exe