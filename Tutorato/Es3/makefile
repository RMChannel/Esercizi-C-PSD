link: main.o candidato.o concorso.o item-candidato.o list.o
	gcc main.o candidato.o concorso.o item-candidato.o list.o -o main.exe

link2: main2.o candidato.o concorso.o item-candidato.o list.o
	gcc main2.o candidato.o concorso.o item-candidato.o list.o -o main.exe

main.o:
	gcc -c main.c

main2.o:
	gcc -c main2.c

candidato.o:
	gcc -c candidato.c

concorso.o:
	gcc -c concorso.c

item-candidato.o:
	gcc -c item-candidato.c

list.o:
	gcc -c list.c

clean:
	rm -f *.exe *.o