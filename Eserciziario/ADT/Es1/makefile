link: main.o playlist.o song.o list.o
	gcc main.o playlist.o song.o list.o -o main.exe

main.o:
	gcc -c main.c

playlist.o:
	gcc -c playlist.c

song.o:
	gcc -c song.c

list.o:
	gcc -c list.c

clean:
	rm -f *.exe *.o