#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// here is the card test 4 for the council_room

// it calls drawcard function four times


int main(){

	struct gameState g;
	int r;
	int num_start;
	int nums;
  int k[10] = {smithy,adventurer,council_room,embargo,cutpurse,mine,ambassador,outpost,baron,tribute};
	
    initializeGame(2, k, 5, &g);
	// initialize game like the example
	
	printf ("----------------------unit test 4 for the council_room(start)----------------------------\n ");
	
	num_start = numHandCards(&g);

	printf("num_start: %d\n",num_start);

	r = cardEffect(council_room, 0, 0, 0, &g, 0, 0);

	nums = numHandCards(&g);
	
	printf("nums: %d\n",nums);

	// r should be 0 if it is correct	
	// nums should be 5 if it is correct

	if (r == 0){
		if(nums ==8){ // num_start = 5 + 4 drawcard - 1 = 8
			printf(" it is correct and test pass\n");
		}
		if(nums!= 8){
			printf("there have some bugs in council_room\n");
		}
	}
	if(r != 0){
		printf("it is not correct \n");
	
	}		
		
	
	
	
	
	printf ("----------------------unit test 4 for the village(end)----------------------------\n ");
	
	return 0;
}
	
	


















