link: clean main.o spesa.o item.o
	gcc main.o spesa.o item.o -o main.exe

main.o:
	gcc -c main.c

spesa.o:
	gcc -c spesa.c

item.o:
	gcc -c item.c

clean:
	rm -f *.exe *.o