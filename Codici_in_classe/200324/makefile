int: utils.o array.o main.o item_int.o
	gcc utils.o array.o main.o item_int.o -o array.out

char: utils.o array.o main.o item_char.o
	gcc utils.o array.o main.o item_char.o -o array.out

string: utils.o array.o main.o item_string.o
	gcc utils.o array.o main.o item_string.o -o array.out

studenti: utils.o array.o main.o item_studenti.o
	gcc utils.o array.o main.o item_studenti.o -o array.out

utils.o: 
	gcc -c utils.c

item_int.o:
	gcc -c item_int.c

item_char.o:
	gcc -c item_char.c

item_string.o:
	gcc -c item_string.c

item_studenti.o:
	gcc -c item_studenti.c
	
array.o: 
	gcc -c array.c

main.o:
	gcc -c main.c

clean:
	rm *.o *.out