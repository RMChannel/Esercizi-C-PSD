link: main.o list.o item_int.o
	gcc main.o list.o item_int.o -o main.exe

main.o:
	gcc -c main.c

list.o:
	gcc -c list.c

item_int.o:
	gcc -c item_int.c

clean:
	rm -f *.exe *.o