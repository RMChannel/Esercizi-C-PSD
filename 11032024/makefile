driver: vettore.o driver.o
	gcc vettore.o driver.o -o driver.exe

driver2: vettore.o driver2.o
	gcc vettore.o driver2.o -o driver2.exe

driver3: vettore.o driver3.o
	gcc vettore.o driver3.o -o driver3.exe

vettore.o:
	gcc -c vettore.c

driver.o:
	gcc -c driver.c

driver2.o:
	gcc -c driver2.c

driver3.o:
	gcc -c driver3.c

clean:
	rm -f driver2.o driver.o vettore.o driver.exe driver2.exe driver3.exe driver3.o