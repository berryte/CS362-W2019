/* 
 * Author: Terence Berry
 * Date: 2/10/19
 * File: randomtestcard2.c
 * Description: Write an automated random test for council room card function
 * Card function: playCRoom - draw 4 cards, increase buy power and everyone draws a card,  
 *       
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Return random number within an upper and lower bound
int randomNum(int min, int max){ 
	int rNum = 0; //random number to return;
	/* rand() returns between 0 and max - 1*/
	rNum = (rand() % (max - min + 1)) + min; // get the range (max-min) add 1 and lower bound
	return rNum;
}

int main(){
	srand(time(NULL)); //to seed random num generator
	int numTests = 0;
	int cards[10] = {adventurer, smithy, council_room, mine, village, embargo, cutpurse, steward, remodel, feast};
	printf("\n------------ Testing Random Adventurer Card Function -------------\n");
	while(numTests != 200){
		printf("\nTest %d:\n", numTests + 1);
		int numPlayers = randomNum(2, MAX_PLAYERS); //can only accept 2-4 players
		//start game
		struct gameState testGame;
		initializeGame(numPlayers, cards, 1000, &testGame);
		
		//Random Card Numbers and how many in each pile
		int cardSize = 10; //we initially start with 10 cards 
		int numHand = randomNum(1, cardSize); //number of cards in hand (1 to cardSize)
		int numDeck = randomNum(0, cardSize - numHand) ; //num of cards in deck
		int numDiscard = cardSize - numHand - numDeck; //the rest	
	
		//Set up cards
		int i;
		for(i = 0; i < numPlayers; i++){
			int j;			
			//Reset cards 
			for(j = 0; j <= cardSize; j++){
				testGame.hand[i][j] = province; //fill in the card
				testGame.deck[i][j] = province;
				testGame.discard[i][j] = province;
			}
			testGame.handCount[i] = numHand;
			testGame.deckCount[i] = numDeck;
			testGame.discardCount[i] = numDiscard;
			// add smithy to hand of first player
			testGame.hand[i][0] = council_room;
		}

		//Play Council Room
		playCRoom(&testGame, 0, 0);

		//Run Tests
		printf("\tTest: 4 cards removed from Deck\n");
		if(numDeck >= 4){
			if(numDeck - 4 == testGame.deckCount[0]){
				printf("\t\tTest Successful!\n");
			}
			else{
				printf("\t\tTest Failed. %d removed from deck.\n", numDeck - testGame.deckCount[0]);
			}
		}
		else{//account for shuffle of discard pile into deck
			int diff = numDeck - 4;
			int newDeck;
			if(numDiscard >= 4 && numDeck < 4){
				newDeck = numDiscard + diff;
			}
			else if(numDeck + numDiscard > 4 && numDeck + numDiscard < 8){
				 newDeck = numDiscard + diff;
			}
			else if(numDeck + numDiscard <= 4){
				newDeck = 0;
			}

			if(newDeck == testGame.deckCount[0]){
				printf("\t\tTest Successful!\n");
			}
			else{
				printf("\t\tTest Failed. After shuffle, deck count is %d.\n", testGame.deckCount[0]);
			}
		}

		printf("\tTest: Number of Buy increases by 1\n");
		if(testGame.numBuys == 2){
			printf("\t\tTest Successful!\n");
		}
		else{
			 printf("\t\tTest Failed.  Num Buys = %d\n", testGame.numBuys);
		}

		printf("\tTest: Council Room is discarded\n");
		int k;
		int found = 0;
		for(k = 0; k < testGame.handCount[0]; k++){
			if(testGame.hand[0][k] == council_room){
				found = 1;
			}
		}
		if(found == 0){ //not found in hand
			for(k = 0; k < testGame.discardCount[0]; k++){
				if(testGame.discard[0][k] == council_room){
					found = 1;
				}
			}
			if(found == 1){//Found in discard
				printf("\t\tTest Successful!\n");
			}
			else{
				printf("\t\tTest Failed. Council Room was discarded incorrectly.\n");
			}
		}
		else{
			printf("\t\tTest Failed. Council Room is still in hand.\n");
		}

		printf("\tTest: Each Player Draws a Card\n");
		for(k =1; k < testGame.numPlayers; k++){
			if(numDeck + numDiscard >=1){
				if(numHand + 1 == testGame.handCount[k]){
					printf("\t\tTest Successful for Player %d!\n", k + 1);
				}
				else{
					printf("\t\tTest failed. Player %d did not draw a card.\n", k + 1);
				}
			}
			else{//if player does not have a card to draw
				if(numHand == testGame.handCount[k]){
                                        printf("\t\tTest Successful for Player %d!\n", k + 1);
                                }
                                else{
                                        printf("\t\tTest failed. Player %d did not draw a card like predicted.\n", k + 1);
                                }
			}
		}

		numTests++;
	}
	return 0;
}
