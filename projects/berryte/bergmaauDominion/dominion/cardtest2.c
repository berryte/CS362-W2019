/*
 * Author: Terence Berry
 * Date: 1/29/19
 * File: cardtest2.c
 * Description: Unit testing a card function in dominion.c.
 * Card function: playSmithy - Draw 3 cards from deck and discard
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
	//variables for the game setup
	int player = 0; //first player
	struct gameState test1;
	int numPlayers = 2;
	int seed = 1000;
	int cards[10] = {adventurer, smithy, council_room, mine, village, embargo, cutpurse, steward, remodel, feast}; 
	//start the game
	int game1 = initializeGame(numPlayers, cards, seed, &test1);
	test1.whoseTurn = player;
	assert(game1 == 0);

	printf("\n------------ Testing Smithy Card Function -------------\n");
	printf("\nTest 1: Verify that only 3 Cards were Drawn\n");
	
	test1.hand[player][0] = smithy; // add smithy to hand
	int sHand = test1.handCount[player]; //starting hand count
	int sDeck =  test1.deckCount[player]; // starting deck count
	int sDiscard =  test1.discardCount[player]; //starting discard count
	
	smithyEffect(&test1, 0);
	
	//verfiy 3 cards were drawn from the deck 
	if(sDeck - test1.deckCount[player] == 3){
		printf("Test Pass\n");
	}
	else{
		printf("Bug Found\n");
	}

	printf("\nTest 2: Discard to Increment by 1\n");
	if(test1.discardCount[player] - sDiscard == 1 && test1.handCount[player] - sHand == 2){
		printf("Test Pass\n");
	}
	else{
		printf("Bug Found\n");
	} 
	
	printf("\nTest 3: Verify Smithy is Discarded\n");
	test1.hand[player][0] = smithy; // add smithy to hand 
	/*Since we just initialized the game and played one smithy, playing another smithy should
	  deplete the deck 5 + 2 (after discarded smithy) + 2( after discarded smithy) = 9.  
	  There should be a smithy in the discard. 
	*/
	smithyEffect(&test1, 0);
	if(test1.handCount[player] == 9 && test1.deckCount[player] == 0 && test1.discard[player][0] == smithy){
		printf("Test Pass\n");
	}
	else{
		printf("Bug Found\n");
	}



	printf("\n------------ Finished Testing Smithy Card Function -------------\n");
	return 0;
}
