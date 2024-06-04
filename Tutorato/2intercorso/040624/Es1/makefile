link: clean mainStack.o stackArray.o item.o
	gcc mainStack.o stackArray.o item.o -o main.exe
	./main.exe
	rm -f *.exe *.o

mainStack.o:
	gcc -c mainStack.c

stackArray.o:
	gcc -c stackArray.c

item.o:
	gcc -c item.c

clean:
	rm -f *.exe *.o