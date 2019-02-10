/* 
 * Author: Terence Berry
 * Date: 2/10/19
 * File: randomtestadventurer.c
 * Description: Write an automated random test for adventurer card function
 * Card function: playAdventurer - look up to 2 treasure cards.  Discard all
 * others.  
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
	int rNum; //random number to return;
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
		int temp[MAX_HAND]; //should be refactored out as a parameter
		int numPlayers = randomNum(2, 4); //can only accept 2-4 players
		printf("\tNumber of Players: %d\n", numPlayers);
		//start game
		struct gameState testGame;
		int game = initializeGame(numPlayers, cards, 1000, &testGame);
		int cardSize = 10; //we initially start with 10 cards
		int numHand = rand() % cardSize; //number of cards in hand (0 to cardSize)
		int numCoppers = rand() % cardSize; //num of coppers (0 to cardSize)
		int numSilver;// = rand() % 10;
		int numGold;// = rand() % 10;
		int numDeck; //number in deck
		int numDiscard; //number of cards in discard
		
		numTests++; //used to stop the tests
	}
	return 0;
}
