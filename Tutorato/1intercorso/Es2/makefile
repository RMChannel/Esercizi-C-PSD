link: main.o item-string.o stack.o
	gcc main.o item-string.o stack.o -o main.exe

main.o:
	gcc -c main.c

stack.o:
	gcc -c stack.c

item-string.o:
	gcc -c item-string.c

clean:
	rm -f *.o *.exe