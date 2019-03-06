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

allTests: dominion.h rngs.o dominion.c cardtest1.c cardtest2.c randomtestcard1.c randomtestadventurer.c unittest1.c unittest2.c unittest3.c unittest4.c
	echo -e "Running Test Suite on Dominion...\n" > unittestresults.out
	gcc -o unittest1 dominion.c rngs.o unittest1.c $(CFLAGS)
	./unittest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	#cat dominion.c.gcov >> unittestresults.out
	gcc -o unittest2 dominion.c rngs.o unittest2.c $(CFLAGS)
	./unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	#cat dominion.c.gcov >> unittestresults.out
	gcc -o unittest3 dominion.c rngs.o unittest3.c $(CFLAGS)
	./unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	#cat dominion.c.gcov >> unittestresults.out
	gcc -o unittest4 dominion.c rngs.o unittest4.c $(CFLAGS)
	./unittest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	#cat dominion.c.gcov >> unittestresults.out
	gcc -o cardtest1 dominion.c rngs.o cardtest1.c $(CFLAGS)
	./cardtest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	#cat dominion.c.gcov >> unittestresults.out
	gcc -o cardtest2 dominion.c rngs.o cardtest2.c $(CFLAGS)
	./cardtest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	#cat dominion.c.gcov >> unittestresults.out
	#gcc -o cardtest3 dominion.c rngs.o cardtest3.c $(CFLAGS)
	#./cardtest3 >> unittestresults.out
	#gcov dominion.c >> unittestresults.out
	#cat dominion.c.gcov >> unittestresults.out
	#gcc -o cardtest4 dominion.c rngs.o cardtest4.c $(CFLAGS)
	#./cardtest4 >> unittestresults.out
	#gcov dominion.c >> unittestresults.out
	#cat dominion.c.gcov >> unittestresults.out
	gcc -o randomTestAdventurer dominion.c rngs.o randomtestadventurer.c $(CFLAGS)
	./randomTestAdventurer >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	gcc -o randomTest1 dominion.c rngs.o randomtestcard1.c $(CFLAGS)
	./randomTest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	#gcc -o randomTest2 dominion.c rngs.o randomtestcard2.c $(CFLAGS)
	#./randomTest2 >> unittestresults.out
	#gcov dominion.c >> unittestresults.out
	echo -e "End Test Suite on Dominion\n" >> unittestresults.out

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
