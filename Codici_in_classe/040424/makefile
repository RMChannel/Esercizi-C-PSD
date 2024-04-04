int: list.o main.o item_int.o stack_array.o
	gcc list.o item_int.o main.o stack_array.o -o stack.out

string: list.o main.o item_string.o stack_array.o
	gcc list.o item_string.o main.o stack_array.o -o stack.out

stack_array.o:
	gcc -c stack_array.c

stack_list.o:
	gcc -c stack_list.c

item_int.o:
	gcc -c item_int.c

item_string.o:
	gcc -c item_string.c
	
main.o:
	gcc -c main.c

list.o: 
	gcc -c list.c

clean:
	rm -f *.o *.out