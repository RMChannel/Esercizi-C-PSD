link: main.o stack.o item-char.o
	gcc main.o stack.o item-char.o -o main.exe

main.o:
	gcc -c main.c

stack.o:
	gcc -c stack.c

item-char.o:
	gcc -c item-char.c

clean:
	del -f *.o *.exe