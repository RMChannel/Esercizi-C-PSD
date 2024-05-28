link: btree.o main.o item-string.o
	gcc btree.o main.o item-string.o -o main.exe

btree.o:
	gcc -c btree.c

main.o:
	gcc -c main.c

item-string.o:
	gcc -c item-string.c

clean:
	del -f *.o *.exe