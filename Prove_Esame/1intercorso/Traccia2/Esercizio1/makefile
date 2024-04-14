link: main.o stack.o list.o item.o
	gcc main.o stack.o list.o item.o -o main.exe

main.o:
	gcc -c main.c

stack.o:
	gcc -c stack.c

list.o:
	gcc -c list.c

item.o:
	gcc -c item.c

clean:
	rm -f *.o *.exe