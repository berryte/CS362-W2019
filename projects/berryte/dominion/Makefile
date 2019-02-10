CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

randomTest: dominion.h rngs.o dominion.c randomtestcard1.c randomtestcard2.c randomtestadventurer.c
	echo -e "Running Random Test Suite on Dominion...\n" > randomtestresults.out
	gcc -o randomTestAdventurer dominion.c rngs.o randomtestadventurer.c $(CFLAGS)
	./randomTestAdventurer >> randomtestresults.out
	gcov dominion.c >> randomtestresults.out
	gcc -o randomTest1 dominion.c rngs.o randomtestcard1.c $(CFLAGS)
	./randomTest1 >> randomtestresults.out
	gcov dominion.c >> randomtestresults.out
	gcc -o randomTest2 dominion.c rngs.o randomtestcard2.c $(CFLAGS)
	./randomTest2 >> randomtestresults.out
	gcov dominion.c >> randomtestresults.out

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
