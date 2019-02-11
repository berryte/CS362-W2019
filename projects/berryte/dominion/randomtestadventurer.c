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
		int temp[MAX_HAND]; //should be refactored out as a parameter
		int numPlayers = randomNum(2, MAX_PLAYERS); //can only accept 2-4 players
		printf("\tNumber of Players: %d\n", numPlayers);
		//start game
		struct gameState testGame;
		int game = initializeGame(numPlayers, cards, 1000, &testGame);
		
		//Random Card Numbers and how many in each pile
		int cardSize = 10; //we initially start with 10 cards 
		int numHand = randomNum(1, cardSize); //number of cards in hand (1 to cardSize)
		int numDeck = randomNum(0, cardSize - numHand) ; //num of cards in deck
		int numDiscard = cardSize - numHand - numDeck; //the rest	

		//Random Treasure
		int numTreasure = randomNum(0, cardSize); // 0 to cardsize
		int numCoppers = randomNum(0, numTreasure); //num of coppers (0 to cardSize)
		int numSilver =  (randomNum(0, numTreasure - numCoppers)); //num silver
		int numGold = numTreasure - numCoppers - numSilver; // rest
		int tHand = 0; //treasure in hand
		int tDeck = 0; //treasure in deck
		int tDiscard = 0; //treasure in discard
		printf("T: %d, C: %d, S: %d, G: %d\n", numTreasure, numCoppers, numSilver, numGold);

		//Set up deck with random information for all players  
		int i;
		for(i = 0; i < numPlayers; i++){
			int j;
			int co = 0; //copper
			int si = 0; //silver
			int go = 0; //gold
			
			//reset cards 
			for(j = 0; j <= cardSize; j++){
				testGame.hand[i][j] = province; //fill in the card
				testGame.deck[i][j] = province;
				testGame.discard[i][j] = province;
			}

			//Alter Hand
			testGame.handCount[i] = numHand;
			testGame.hand[i][0] = adventurer;
			for(j = 1; j < testGame.handCount[i]; j++){
				testGame.hand[i][j] = province; //fill in the card
				if(co != numCoppers){
					testGame.hand[i][j] = copper;
					co++;
				}
				else{
					if(si != numSilver){
                                        	testGame.hand[i][j] = silver;
                                        	si++;
					}
					else{
						if(go != numGold){
                                        		testGame.hand[i][j] = gold;
                                        		go++;
                                		}	
					}
				}
			}

			//Alter Deck
			testGame.deckCount[i] = numDeck;
			for(j = 0; j < testGame.deckCount[i]; j++){
				testGame.deck[i][j] = province; //fill in the card
                                if(co != numCoppers){
                                        testGame.deck[i][j] = copper;
                                        co++;
					tDeck++;
                                }
                                else if(si != numSilver){
                                        testGame.deck[i][j] = silver;
                                        si++;
					tDeck++;
                                }
                                else if(go != numGold){
                                        testGame.deck[i][j] = gold;
                                        go++;
					tDeck++;
                                }
			}

			//Alter Discard
			testGame.discardCount[i] = numDiscard;
			for(j = 0; j < testGame.discardCount[i]; j++){
				testGame.discard[i][j] = province; //fill in the card
                                if(co != numCoppers){
                                        testGame.discard[i][j] = copper;
                                        co++;
					tDiscard++;
                                }
                                else if(si != numSilver){
                                        testGame.discard[i][j] = silver;
                                        si++;
					tDiscard++;
                                }
                                else if(go != numGold){
                                        testGame.discard[i][j] = gold;
                                        go++;
					tDiscard++;
                                }
			}
	
		}		
		//PlayAdventurer for first player becaus it is the same as all the others
		//playAdventurer(&testGame, 0, temp);
		
		//Test if implemented correctly
		//Iterate though hand and see how many treasures there are	
		int k;
		int handTreasures = 0;
		for(k = 0; k < testGame.handCount[0]; k++){
			if(testGame.hand[0][k] == copper || testGame.hand[0][k] == silver || testGame.hand[0][k] == gold){
				handTreasures++;
			}
		}
		tHand = handTreasures;
		printf("Pre:%d \n", handTreasures);
		playAdventurer(&testGame, 0, temp);
		handTreasures = 0;
		for(k = 0; k < testGame.handCount[0]; k++){
                        if(testGame.hand[0][k] == copper || testGame.hand[0][k] == silver || testGame.hand[0][k] == gold){
                                handTreasures++;
                        }
                }
printf("Post:%d \n", handTreasures);
		//If there were 2 treasure cards not in the hand
		//they should have been added to the hand
		if((tDiscard + tDeck) >= 2){
			printf("\tTest: 2 Treasure cards added to hand\n");
			if(handTreasures == (tHand + 2)){
				printf("\t\tTest Successful!\n");
			}
			else{
				printf("\t\tTest Failed. 2 Treasure cards were not added to the hand.\n");
			}
		}
		else if((tDiscard + tDeck) == 1){
			printf("\tTest: Only 1 Treasure card outside of hand\n");
			if(handTreasures == (tHand + 1)){
				printf("\t\tTest Successful!\n");
			}
			else{
				printf("\t\tTest Failed. 1 Treasure cards was not added to the hand.\n");
			}
		}
		else if((tDiscard + tDeck) == 0){
			printf("\tTest: No More Treasure Cards to add to hand\n");
                        if(handTreasures == tHand){
                                printf("\t\tTest Successful!\n");
                        }
                        else{
                                printf("\t\tTest Failed. Pre-Treasures: %d and Post-Treasures: %d. Do not match.\n", tHand, handTreasures);
                        }
		}
		numTests++; //used to stop the tests
	}
	return 0;
}
