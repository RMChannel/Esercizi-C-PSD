main1: btree.o main.o list.o item-string.o queueList.o
	gcc btree.o main.o list.o item-string.o queueList.o -o btree.exe

main2: btree.o main2.o list.o item-int.o queueList.o
	gcc btree.o main2.o list.o item-int.o queueList.o -o btree.exe

main3: btree.o main3.o list.o item-int.o queueList.o
	gcc btree.o main3.o list.o item-int.o queueList.o -o btree.exe

main4: btree.o main4.o list.o item-int.o queueList.o
	gcc btree.o main4.o list.o item-int.o queueList.o -o btree.exe

btree.o:
	gcc -c btree.c

main.o:
	gcc -c main.c

main2.o:
	gcc -c main2.c

main3.o:
	gcc -c main3.c

queueList.o:
	gcc -c queueList.c

item-int.o:
	gcc -c item-int.c

item-string.o:
	gcc -c item-string.c

list.o:
	gcc -c list.c

clean:
	rm -f *.exe *.o