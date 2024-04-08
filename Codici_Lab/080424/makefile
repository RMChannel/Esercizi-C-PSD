song: item_song.o list.o main.o song.o playlist.o
	gcc item_song.o list.o main.o song.o playlist.o -o main.exe -Wall

int: item_int.o list.o main2.o
	gcc item_int.o list.o main2.o -o main.exe

string: item_string.o list.o main2.o
	gcc item_string.o list.o main2.o -o main.exe

item_song.o:
	gcc -c item_song.c

item_string.o:
	gcc -c item_string.c

item_int.o:
	gcc -c item_int.c

main.o:
	gcc -c main.c

main2.o:
	gcc -c main2.c

song.o:
	gcc -c song.c

playlist.o:
	gcc -c playlist.c

list.o:
	gcc -c list.c

clean:
	rm -f *.exe *.o