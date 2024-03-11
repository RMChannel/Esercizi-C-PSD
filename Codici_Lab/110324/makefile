driverEs1: vettore.o driverEs1.o
	gcc vettore.o driverEs1.o -o driverEs1.exe

driverEs2: vettore.o driverEs2.o
	gcc vettore.o driverEs2.o -o driverEs2.exe

driverEs3: vettore.o driverEs3.o
	gcc vettore.o driverEs3.o -o driverEs3.exe

vettore.o:
	gcc -c vettore.c

driverEs1.o:
	gcc -c driverEs1.c

driverEs2.o:
	gcc -c driverEs2.c

driverEs3.o:
	gcc -c driverEs3.c

clean:
	del -f driverEs1.o driverEs2.o driverEs3.o vettore.o driverEs1.exe driverEs2.exe driverEs3.exe