int: list.o main.o item_int.o
	gcc list.o item_int.o main.o -o list.exe

string: list.o main.o item_string.o
	gcc list.o item_string.o main.o -o list.exe

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