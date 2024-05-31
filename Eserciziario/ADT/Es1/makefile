link: main.o playlist.o song.o
	gcc main.o playlist.o song.o -o main.exe

main.o:
	gcc -c main.c

playlist.o:
	gcc -c playlist.c

song.o:
	gcc -c song.c

clean:
	rm -f *.exe *.o