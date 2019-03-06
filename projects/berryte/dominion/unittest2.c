/*
 * Author: Terence Berry
 * Date: 1/29/19
 * File: unittest2.c
 * Description: Unit testing a function in dominion.c.  Function to test is
 * isGameOver.  Used to see if the game is over
 * Test: supply count for province and 3 other supply counts
 *
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
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
	assert(test == 0); //should compile correctly

	printf("\n------------ Testing isGameOver Function -------------\n");

	//Begin test of negative supplies
	printf("\n\nTest 1: Negative Province Count\n");
	t1.supplyCount[province] = -1;
	int game1 = isGameOver(&t1);
	assert(game1 == 0); //game should be over (I believe is a bug)
	printf("Bug Found");

	printf("\n\nTest 2: Zero Province Count");
	t1.supplyCount[province] = 0;
	int game2 = isGameOver(&t1);
	assert(game2 == 1); //game should be over
	printf("\nTest Pass");

	printf("\n\nTest 3: Supplies are above 0");
	t1.supplyCount[province] = 1;
	int game3 = isGameOver(&t1);
	assert(game3 == 0); //game should continue over
	printf("\nTest Pass");

	printf("\n\nTest 4: 3 Supplies are under 0");
	t1.supplyCount[0] = -1;
	t1.supplyCount[1] = -1;
	t1.supplyCount[2] = -1;
	int game4 = isGameOver(&t1);
	assert(game4 == 0); //game should be over (I believe is a bug)
	printf("\nBug Found");

	printf("\n\nTest 5: 3 Supplies are at 0");
	t1.supplyCount[0] = 0;
	t1.supplyCount[1] = 0;
	t1.supplyCount[2] = 0;
	int game5 = isGameOver(&t1);
	assert(game5 == 1); //game should be over
	printf("\nTest Pass");

	printf("\n\n--- Testing Complete for isGameOver Function ---\n\n");
	return 0;
}
