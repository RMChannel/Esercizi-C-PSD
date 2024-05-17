link: main.o btree.o list.o item-int.o stackList.o
	gcc main.o btree.o list.o item-int.o stackList.o -o main.exe
	./main.exe
	rm *.o *.exe

main.o:
	gcc -c main.c

btree.o:
	gcc -c btree.c

list.o:
	gcc -c list.c

item-int.o:
	gcc -c item-int.c

stackList.o:
	gcc -c stackList.c

clean:
	rm *.o *.exe