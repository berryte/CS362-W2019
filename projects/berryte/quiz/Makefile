CFLAGS= -Wall -fpic -coverage -lm -std=c99

testme: testme.c 
	gcc -o testme testme.c $(CFLAGS)
	./testme
	gcov testme.c

clean:
	rm -f *.o
