/*
 * Author: Terence Berry
 * Date: 1/29/19
 * File: cardtest1.c
 * Description: Unit testing a card function in dominion.c.
 * Card function: playAdventurer - look up to 2 treasure cards.  Discard all
 * others.  
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
	int temp[MAX_HAND]; //temprarily stores the players hand to later discard
	struct gameState game, testGame;
	int numPlayers = 2;
	int seed = 1000;
	int cards[10] = {adventurer, smithy, council_room, mine, village, embargo, cutpurse, steward, remodel, feast}; 
	//start the game
	int game1 = initializeGame(numPlayers, cards, seed, &game);
	memcpy(&testGame, &game, sizeof(struct gameState)); //copy to testing struct
	assert(game1 == 0);

	printf("\n------------ Testing Adventurer Card Function -------------\n");
	printf("\nTest 1: Verify 2 Cards Added to Hand and Removed from Deck\n");
	int tCards = 0; //treasure cards in hand
	int i;
	for(i = 0; i < testGame.handCount[player]; i++){
		if(testGame.hand[player][i] == copper || testGame.hand[player][i] == silver || testGame.hand[player][i] == gold){
			tCards++;
		}
	}
	int dtc = 0; //treasure cards in deck
	for(i = 0; i < testGame.deckCount[player]; i++){
                if(testGame.deck[player][i] == copper || testGame.deck[player][i] == silver || testGame.deck[player][i] == gold){
                        dtc++;
                }
        }
	int deckPrev = testGame.deckCount[player];
	int handPrev = testGame.handCount[player];
	playAdventurer(&testGame, player, temp);
	int deck = testGame.deckCount[player];
	int diff = deckPrev - deck;
        printf("Previous Deck:%d  Post Deck:%d\n", deckPrev, deck);
        int hand = testGame.handCount[player];
	diff = hand - handPrev;
        printf("Previous Hand:%d Post Hand:%d\n", handPrev, hand);
	if(diff != 2){
		printf("Bug Found\n");
	}
	else{
		printf("Test Pass\n");
	}

	printf("\nTest 2: 2 Treasure Cards Added to Hand\n");
	int tCards2 = 0;
	for(i = 0; i < testGame.handCount[player]; i++){
                if(testGame.hand[player][i] == copper || testGame.hand[player][i] == silver || testGame.hand[player][i] == gold){
                        tCards2++;
                }
        }
        int dtc2 = 0; //treasure cards in deck
        for(i = 0; i < testGame.deckCount[player]; i++){
                if(testGame.deck[player][i] == copper || testGame.deck[player][i] == silver || testGame.deck[player][i] == gold){
                        dtc2++;
                }
        }
	printf("Treasure Cards in Hand before Adventurer: %d\n", tCards);
	printf("Treasure Cards in Hand after Adventurer: %d\n", tCards2);
	printf("Treasure Cards in Deck before Adventurer: %d\n", dtc);
        printf("Treasure Cards in Deck after Adventurer: %d\n", dtc2);
	if(diff != 2){
                printf("Bug Found\n");
        }
        else{
                printf("Test Pass\n");
        }

	printf("\nTest 3: No Change if No Treasure is Deck\n");
	playAdventurer(&testGame, player, temp);
	int tCards3 = 0;
        for(i = 0; i < testGame.handCount[player]; i++){
                if(testGame.hand[player][i] == copper || testGame.hand[player][i] == silver || testGame.hand[player][i] == gold){
                        tCards3++;
     		}
	}
        int dtc3 = 0; //treasure cards in deck
        for(i = 0; i < testGame.deckCount[player]; i++){
                if(testGame.deck[player][i] == copper || testGame.deck[player][i] == silver || testGame.deck[player][i] == gold){
                        dtc3++;
                }
        }
        printf("Treasure Cards in Hand before Adventurer: %d\n", tCards2);
        printf("Treasure Cards in Hand after Adventurer: %d\n", tCards3);
        printf("Treasure Cards in Deck before Adventurer: %d\n", dtc2);
        printf("Treasure Cards in Deck after Adventurer: %d\n", dtc3);
	if(tCards2 == tCards3){
		printf("Test Pass\n");
	}
	else{
		printf("Bug Found\n");
	}


	printf("\n------------ Finished Testing Adventurer Card Function -------------\n");
	return 0;
}

