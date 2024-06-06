link: main.o list.o stacklist.o item_string.o
	gcc main.o list.o stacklist.o item_string.o -o main.exe

main.o:
	gcc -c main.c

list.o:
	gcc -c list.c

stacklist.o:
	gcc -c stacklist.c

item_string.o:
	gcc -c item_string.c

clean:
	rm -f *.exe *.o