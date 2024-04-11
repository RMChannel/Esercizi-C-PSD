playlist: song.o playlist.o main.o list.o item-song.o
	gcc song.o playlist.o main.o list.o item-song.o -o main.exe

song.o:
	gcc -c song.c

main.o:
	gcc -c main.c

playlist.o:
	gcc -c playlist.c

list.o:
	gcc -c list.c

item-song.o:
	gcc -c item-song.c

clean:
	rm -f *.exe *.o