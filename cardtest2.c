#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// here is the card test 2 for the village

// it calls drawcard function only one time

// it add  2 action

int main(){

	struct gameState g;
	int r;
	int num_start;
	int nums;
  int k[10] = {smithy,adventurer,village,embargo,cutpurse,mine,ambassador,outpost,baron,tribute};
	
    initializeGame(2, k, 5, &g);
	// initialize game like the example
	
	printf ("----------------------unit test 2 for the village(start)----------------------------\n ");
	
	num_start = numHandCards(&g);

	printf("num_start: %d\n",num_start);

	r = cardEffect(village, 0, 0, 0, &g, 0, 0);

	nums = numHandCards(&g);
	
	printf("nums: %d\n",nums);

	// r should be 0 if it is correct	
	// nums should be 5 if it is correct

	if (r == 0){
		printf("it is correct for effectfunction \n");
		if(nums ==5){ // num_start = 5 + 1 drawcard - 1 = 5
			printf(" it is correct and test pass\n");
		}
		if(nums!= 5){
			printf("there have some bugs in village\n");
		}
	}
	if(r != 0){
		printf("it is not correct \n");
	
	}		
		
	
	
	
	
	printf ("----------------------unit test 2 for the village(end)----------------------------\n ");
	
	return 0;
	
	

















}
