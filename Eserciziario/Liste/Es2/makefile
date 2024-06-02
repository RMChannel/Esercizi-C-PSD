Es1: list.o main1.o item_string.o
	gcc list.o item_string.o main1.o -o list.exe

Es2: list.o main2.o item_string.o
	gcc list.o item_string.o main2.o -o list.exe

Es3: list.o main3.o item_string.o
	gcc list.o item_string.o main3.o -o list.exe

Es4: list.o main4.o item_string.o
	gcc list.o item_string.o main4.o -o list.exe

item_string.o:
	gcc -c item_string.c
	
main1.o:
	gcc -c main1.c

main2.o:
	gcc -c main2.c

main3.o:
	gcc -c main3.c

main4.o:
	gcc -c main4.c

list.o: 
	gcc -c list.c

clean:
	rm -f *.o *.exe