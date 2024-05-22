int: list.o main.o item_int.o keyString.o hashtable.o entry.o item_entry.o
	gcc list.o item_int.o keyString.o main.o hashtable.o entry.o item_entry.o -o main.exe
	./main.exe
	rm -f *.o *.exe

keyString.o:
	gcc -c keyString.c

item_entry.o:
	gcc -c item_entry.c

hashtable.o:
	gcc -c hashtable.c

entry.o:
	gcc -c entry.c

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