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
#include <assert.h>
#include <stdlib.h>


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
		playCRoom(&testGame, 0, rand() % testGame.handCount[0]); //randomly generate hand position

		numTests++;
	}
	return 0;
}