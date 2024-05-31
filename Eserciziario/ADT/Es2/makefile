link: main.o libreria.o libro.o
	gcc main.o libreria.o libro.o -o main.exe -Wall

main.o:
	gcc -c main.c -Wall

libreria.o:
	gcc -c libreria.c

libro.o:
	gcc -c libro.c

clean:
	rm -f *.exe *.o