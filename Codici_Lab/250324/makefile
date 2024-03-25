Max: point.o TestMaxDist.o
	gcc point.o TestMaxDist.o -o TestMaxDist.out

Coppie: point.o TestCoppie.o
	gcc point.o TestCoppie.o -o TestCoppie.out

Centroide: point.o TestCentroide.o
	gcc point.o TestCentroide.o -o TestCentroide.out

Move: point.o TestMovePunto.o
	gcc point.o TestMovePunto.o -o TestMovePunto.out

point.o:
	gcc -c point.c

TestMovePunto.o:
	gcc -c TestMovePunto.c

TestCentroide.o:
	gcc -c TestCentroide.c

TestCoppie.o:
	gcc -c TestCoppie.c

TestMaxDist.o:
	gcc -c TestMaxDist.c

clean:
	rm -f *.o *.out