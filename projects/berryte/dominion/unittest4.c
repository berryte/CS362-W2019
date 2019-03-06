/*
 * Author: Terence Berry
 * Date: 1/29/19
 * File: unittest4.c
 * Description: Unit testing a function in dominion.c.  Function to test is
 * UpdateCoins.  Updates buying power for player
 * Test: parameters with negative numbers and cards played
 *
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main(){
	//variables for tests
	struct gameState t1;
	int seed = 1000;
	int numPlayer = 2;
	int kCards[10] = {adventurer, smithy, council_room, mine, village, embargo, cutpurse, steward, remodel, feast};
	
	//initialize game
	int test = initializeGame(numPlayer, kCards, seed, &t1);
	assert(test ==0);
	
	printf("\n------------ Testing UpdateCoins Function -------------\n");
/* Cannot have negative players
	printf("\n\nTest 1: Negative Player");
	t1.handCount[0] = 2;
        t1.hand[0][0] = copper;
	int game = updateCoins(-9, &t1, 0);
	assert(game == 0); //Error should be thrown
	assert(t1.coins == 1);
	printf("Test Pass");
*/
	printf("\n\nTest 1: Negative Bonus");
	t1.handCount[0] = 1;
        t1.hand[0][0] = copper;
	int game = updateCoins(0, &t1, -1);
	assert(game == 0); //Error should be thrown
	assert(t1.coins == 0);
	printf("\nBug Found");

	printf("\n\nTest 2: Play Copper + Bonus of 2");
	t1.handCount[0] = 1;
	t1.hand[0][0] = copper;
	game = updateCoins(0, &t1, 2);
	assert(game == 0);
	assert(t1.coins == 3);
	printf("\nTest Pass");

	printf("\n\nTest 3: Play Gold Without Bonus");
	t1.handCount[0] = 1;
	t1.hand[0][0] = gold;
	game = updateCoins(0, &t1, 0);
	assert(game == 0);
	assert(t1.coins == 3);	
	printf("\nTest Pass");

	printf("\n\n--- Testing Complete for UpdateCoins Function ---\n\n");
	return 0;
}

