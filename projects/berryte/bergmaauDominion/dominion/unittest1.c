/*
 * Author: Terence Berry
 * Date: 1/27/19
 * File: unittest1.c
 * Description: Unit testing a function in dominion.c.  Function to test is
 * initializeGame.  Used to start the game.
 * Test: parameters (namely number of players), kingdom cards, verify that
 * number of cards are set out correctly
 *
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main(){
	//variables to test
	struct gameState t1, t2, t3, t4, t5, t6;

	//dominion cards
	int dupCards[10] = {adventurer, smithy, council_room, mine, village, embargo, cutpurse, steward, remodel, mine}; //used to test if function takes in duplicate cards
	int kCards[10] = {adventurer, smithy, council_room, mine, village, embargo, cutpurse, steward, remodel, feast}; //correct cards

	//num of players
	int neg = -5; //should fail
	int zero = 0; //should fail
	int num1 = 1; //should fail
	int num2 = 2;
	int num3 = 3.2;
	int num4 = 4;
	int num5 = 5; //should fail

	//randomSeed
	int seed = -10;
	int seed4 = 1000;

	printf("\n------------ Testing InitializeGame Function -------------\n");

	//Begin test of players
	printf("\n\nTest 1: Number of Players");
	printf("\nTesting %d Players\n", neg);
	int test = initializeGame(neg, kCards, seed4, &t1);
	assert(test == -1);
	printf("Test Pass\n");
	printf("\nTesting %d Players\n", zero);
	int test1 = initializeGame(zero, kCards, seed4, &t1);
	assert(test1 == -1);
	printf("Test Pass\n");
	printf("\nTesting %d Player\n", num1);
	int test2 = initializeGame(num1, kCards, seed4, &t1);
	assert(test2 == -1);
	printf("Test Pass\n");
	printf("\nTesting %d Players\n", num2);
	int test3 = initializeGame(num2, kCards, seed4, &t1);
	assert(test3 == 0); //should be successful
	assert(t1.supplyCount[curse] == 10); //should create 10 curse cards
	assert(t1.supplyCount[estate] == 8);
      	assert(t1.supplyCount[duchy] == 8);
      	assert(t1.supplyCount[province] == 8);
	assert(t1.supplyCount[copper] == 60 - (7 * num2));
	assert(t1.supplyCount[silver] == 40);
	assert(t1.supplyCount[gold] == 30);
	assert(t1.outpostPlayed == 0);
	assert(t1.phase == 0);
	assert(t1.numActions == 1);
	assert(t1.numBuys == 1);
	assert(t1.playedCardCount == 0);
	assert(t1.whoseTurn == 0);
	assert(t1.handCount[t1.whoseTurn] == 5);
	assert(t1.discardCount[t1.whoseTurn] == 0);
	//other players hand
	assert(t1.handCount[1] == 0);
	assert(t1.discardCount[1] == 0);
	printf("Test Pass\n");

	printf("\nTesting %d Players\n", num3);
	int test4 = initializeGame(num3, kCards, seed4, &t2);
	assert(test4 == 0); //should be successful
	assert(t2.supplyCount[curse] == 20); //should create 20 curse cards
	assert(t2.supplyCount[estate] == 12);
      	assert(t2.supplyCount[duchy] == 12);
      	assert(t2.supplyCount[province] == 12);
	assert(t2.supplyCount[copper] == 60 - (7 * num3));
	assert(t2.supplyCount[silver] == 40);
	assert(t2.supplyCount[gold] == 30);
	assert(t2.outpostPlayed == 0);
	assert(t2.phase == 0);
	assert(t2.numActions == 1);
	assert(t2.numBuys == 1);
	assert(t2.playedCardCount == 0);
	assert(t2.whoseTurn == 0);
	assert(t2.handCount[t2.whoseTurn] == 5);
	assert(t2.discardCount[t2.whoseTurn] == 0);
	//other players hand
	assert(t2.handCount[1] == 0);
	assert(t2.discardCount[1] == 0);
	assert(t2.handCount[2] == 0);
	assert(t2.discardCount[2] == 0);
	printf("Test Pass\n");

	printf("\nTesting %d Players\n", num4);
	int test5 = initializeGame(num4, kCards, seed4, &t3);
	assert(test5 == 0); //should be successful
	assert(t3.supplyCount[curse] == 30); //should create 30 curse cards
	assert(t3.supplyCount[estate] == 12);
      	assert(t3.supplyCount[duchy] == 12);
      	assert(t3.supplyCount[province] == 12);
	assert(t3.supplyCount[copper] == 60 - (7 * num4));
	assert(t3.supplyCount[silver] == 40);
	assert(t3.supplyCount[gold] == 30);
	assert(t3.outpostPlayed == 0);
	assert(t3.phase == 0);
	assert(t3.numActions == 1);
	assert(t3.numBuys == 1);
	assert(t3.playedCardCount == 0);
	assert(t3.whoseTurn == 0);
	assert(t3.handCount[t3.whoseTurn] == 5);
	assert(t3.discardCount[t3.whoseTurn] == 0);
	//other players hand
	assert(t3.handCount[1] == 0);
	assert(t3.discardCount[1] == 0);
	assert(t3.handCount[2] == 0);
	assert(t3.discardCount[2] == 0);
	assert(t3.handCount[3] == 0);
	assert(t3.discardCount[3] == 0);
	printf("Test Pass\n");

	printf("\nTesting %d Players\n", num5);
	int test6 = initializeGame(num5, kCards, seed4, &t4);
	assert(test6 == -1);
	printf("Test Pass\n");

	//Begin test of wrong dominion decks
	printf("\nTest 2: Dominion cards");
	printf("\nTesting with Duplicate Cards\n");
	int deckTest1 = initializeGame(num2, dupCards, seed4, &t5);
	assert(deckTest1 == -1);
	printf("Test Pass\n");

	//Begin test of seed
	printf("\nTest 3: Seed Testing");
	printf("\nTesting with Negative Seed\n");
	int seedTest1 = initializeGame(num2, kCards, seed, &t6);
	assert(seedTest1 == 0);
	printf("Bug Found");

	printf("\n\n--- Testing Complete for InitializeGame Function ---\n\n");
	return 0;
}

