/* 
 * Author: Terence Berry
 * Date: 2/10/19
 * File: randomtestcard1.c
 * Description: Write an automated random test for smithy card function
 * Card function: playSmithy - Draw 3 cards from deck and discard.
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
	printf("\n------------ Testing Random Smithy Card Function -------------\n");
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
			testGame.hand[i][0] = smithy;
		}

		//Play Smithy
		playSmithy(&testGame, 0, 0);
		
		//Run Tests
		printf("\tTest: 3 cards removed from Deck\n");
		if(numDeck >= 3){
			if(numDeck - 3 == testGame.deckCount[0]){
				printf("\t\tTest Successful!\n");
			}
			else{
				printf("\t\tTest Failed. %d removed from deck.\n", numDeck - testGame.deckCount[0]);
			}
		}
		else{//account for shuffle of discard pile into deck
			int diff = numDeck - 3;
			int newDeck;
			if(numDiscard >= 3 && numDeck < 3){
				newDeck = numDiscard + diff;
			}
			else if(numDiscard == 2 && numDeck == 2){
				 newDeck = numDiscard + diff;
			}
			else if(numDeck + numDiscard <= 3){
				newDeck = 0;
			}

			if(newDeck == testGame.deckCount[0]){
				printf("\t\tTest Successful!\n");
			}
			else{
				printf("\t\tTest Failed. After shuffle, deck count is %d.\n", testGame.deckCount[0]);
			}
		}

		printf("\tTest: Hand Count Increased by 2. (Draw 3 - Discard Smithy)\n");
		if(numDeck + numDiscard >= 3){//more than3 cards available
			if(numHand + 2 == testGame.handCount[0]){
				printf("\t\tTest Successful!\n");
			}
			else{
				printf("\t\tTest Failed. %d added to hand.\n", testGame.handCount[0] - numHand);
			}
		}
		else{ //less than 3 cards available
			if(testGame.handCount[0] - numHand == numDeck + numDiscard){
				printf("\t\tTest Successful!\n");
			}
			else{
				printf("\t\tTest Failed. %d added to hand.\n", testGame.handCount[0] - numHand);		
			}
		}
		
		printf("\tTest: Smithy is discarded\n");
		int k;
		int found = 0;
		for(k = 0; k < testGame.handCount[0]; k++){
			if(testGame.hand[0][k] == smithy){
				found = 1;
			}
		}
		if(found == 0){ //not found in hand
			for(k = 0; k < testGame.discardCount[0]; k++){
				if(testGame.discard[0][k] == smithy){
					found = 1;
				}
			}
			if(found == 1){//Found in discard
				printf("\t\tTest Successful!\n");
			}
			else{
				printf("\t\tTest Failed. Smithy was discarded incorrectly.\n");
			}
		}
		else{
			printf("\t\tTest Failed. Smithy is still in hand.\n");
		}
		numTests++;
	}
	return 0;
}
