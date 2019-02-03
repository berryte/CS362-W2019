/*
 * Author: Terence Berry
 * Date: 1/29/19
 * File: unittest3.c
 * Description: Unit testing a function in dominion.c.  Function to test is
 * getCost. Function is used to get cost of a card to buy
 * Test: negative numbers, inside and outside bounds
 *
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int main(){
	
	printf("\n------------ Testing getCost Function -------------\n");

	printf("\n\nTest 1: Negative Number");
	int test1 = getCost(-5);
	assert(test1 == -1);
	printf("\nTest Pass");

/* Cannot have a mispelled card name
	printf("\n\nTest 2: Mispelled Card");
	int test2 = getCost(curses);
	assert(test2 == -1);
*/
	printf("\n\nTest 2: Copper Card");
	int test3 = getCost(copper);
	assert(test3 == 0);
	printf("\nTest Pass");

	printf("\n\nTest 3: High Positive Number");
	int test4 = getCost(50);
	assert(test4 == -1);
	printf("\nTest Pass");

	printf("\n\n--- Testing Complete for getCost Function ---\n\n");
	return 0;
}
