/*
 * Author: Terence Berry
 * Date: 1/29/19
 * File: cardtest4.c
 * Description: Unit testing a card function in dominion.c.
 * Card function: playMine - exchange an inferior treasure card for the next one up
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

	printf("\n------------ Testing Mine Card Function -------------\n");
	printf("\nTest 1: Verify that Mine is Discarded\n");
	test1.hand[player][0] = mine; //add mine to hand
	int coppers = 0;
	int i;
	int index; //index of copper
	//find number of coppers
	for(i = 0; i < test1.handCount[player]; i++){
		if(test1.hand[player][i] == copper){
			coppers++;
			index = i;
		}
	}
	for(i = 0; i < test1.deckCount[player]; i++){
		if(test1.deck[player][i] == copper){
			coppers++;
		}
	}
	int run = playMine(&test1, index, silver, player, 0);
	assert(run == 0);
	if(test1.hand[player][0] != mine && test1.discard[player][0] == mine){
		printf("Test Pass\n");
	}
	else{
		printf("Bug Found\n");
	}
	
	printf("\nTest 2: Verify that Card is Trashed\n");
	int postC = 0;
	for(i = 0; i < test1.handCount[player]; i++){
		if(test1.hand[player][i] == copper){
			postC++;
		}
	}
	for(i = 0; i < test1.deckCount[player]; i++){
		if(test1.deck[player][i] == copper){
			postC++;
		}
	}
	if(postC == coppers -1){
		printf("Test Pass\n");
	}
	else{
		printf("Bug Found\n");
	}
	
	printf("\nTest 3: Choice 1 Not in Hand\n");
	test1.hand[player][0] = mine; //add mine to hand
	int run2 = playMine(&test1, 20, silver, player, 0);
        assert(run2 == -1);
	printf("Test Pass\n");	

	printf("\nTest 4: Exchange Estate -> Gold\n");
	test1.hand[player][0] = mine; //add mine to hand
	for(i = 0; i < test1.handCount[player]; i++){
		if(test1.hand[player][i] == estate){
			index = i;
		}
	}
	int run3 = playMine(&test1, index, gold, player, 0);
        assert(run3 == -1);
        printf("Test Pass\n");
	printf("\nTest 5: Exchange Copper -> Gold\n");
	test1.hand[player][0] = mine; //add mine to hand
	for(i = 0; i < test1.handCount[player]; i++){
                if(test1.hand[player][i] == copper){
                        index = i;
		}
        }
	int run4 = playMine(&test1, index, gold, player, 0);
        if (run4 == 0){
		printf("Bug found\n");
	}
	else{
		printf("Test Pass\n");
	}

	printf("\n------------ Finished Testing Mine Card Function -------------\n");
	return 0;
}
