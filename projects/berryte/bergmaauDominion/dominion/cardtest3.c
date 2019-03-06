/*
 * Author: Terence Berry
 * Date: 1/29/19
 * File: cardtest3.c
 * Description: Unit testing a card function in dominion.c.
 * Card function: playCRoom - draw 4 cards, increase buy power and everyone draws a card
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
	assert(game1 == 0);

	printf("\n------------ Testing Council Room Card Function -------------\n");
	printf("\nTest 1: Verify that only 4 Cards were Drawn\n");
	
	test1.hand[player][0] = council_room; // add council_room to hand
	int sHand = test1.handCount[player]; //starting hand count
	int sDeck =  test1.deckCount[player]; // starting deck count
	int sDiscard =  test1.discardCount[player]; //starting discard count
	int numBuys = test1.numBuys;
	int otherplayer = test1.handCount[1]; //other players hand

	playCRoom(&test1, player, 0);

	if(sDeck - test1.deckCount[player] == 4){
		printf("Test Pass\n");
	}
	else{
		printf("Bug Found\n");
	}

	printf("\nTest 2: Verify Council Room was Discarded and Hand Count + 3\n");
	if(test1.handCount[player] - sHand == 3 && test1.discard[player][sDiscard] == council_room){
		printf("Test Pass\n");
	}
	else{
		printf("Bug Found\n");
	}
	printf("\nTest 3: Number of Buys + 1\n");
	if(test1.numBuys == 2 || test1.numBuys == numBuys + 1){
		printf("Test Pass\n");
	}
	else{
		printf("Bug Found\n");
	}
	
	printf("\nTest 4: All Other Players + 1 Card\n");
	//only one other player
	if(test1.handCount[1] == otherplayer + 1){
		printf("Test Pass\n");
	}
	else{
		printf("Bug Found\n");
	}
	
	printf("\n------------ Finished Testing Council Room Card Function -------------\n");
	return 0;
}
