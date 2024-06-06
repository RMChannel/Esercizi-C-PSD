link: main.o list.o stackList.o item_string.o
	gcc main.o list.o stackList.o item_string.o -o main.exe

main.o:
	gcc -c main.c

list.o:
	gcc -c list.c

stackList.o:
	gcc -c stackList.c

item_string.o:
	gcc -c item_string.c

clean:
	rm -f *.exe *.o