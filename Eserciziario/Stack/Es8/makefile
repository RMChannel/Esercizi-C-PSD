string: list.o main.o item_string.o stackList.o
	gcc list.o item_string.o main.o stackList.o -o stack.exe

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

clean:
	rm -f *.o *.exe