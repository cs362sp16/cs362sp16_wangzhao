#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"
#include "dominion.h"
#include "assert.h"
#include "dominion_helpers.h"

// smithy should gain 3 cards in the origin function


int main (){
	struct gameState g;
	int r;
	int num_start;
	int nums;

  int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador, outpost,baron,tribute};
   
   initializeGame(2, k, 5, &g);
  printf("-------------card test 1 for smithy (start) ----------------------\n");
  
	num_start = numHandCards(&g);

	printf("num_start: %d\n",num_start);

	r = cardEffect(smithy, 0, 0, 0, &g, 0, 0);

	nums = numHandCards(&g);

	// r should be 0 if it is correct	
	// nums should be 7 if it is correct
	printf("nums: %d\n",nums);

	if ( r == 0 ){
		if( nums == 7){ // 5 cards + call 3 times of drawcard function - 1	
			printf("test pass correctly \n");
        	}
		if( nums != 7){
			printf( "there have bugs in the smithy card\n" );
			printf( " smithy should get 3 cards because it calls drawcard three times\n");
		}

	}
	if (r != 0){
	
	printf( "it is not correct because r is not 0\n" );
	
	}

	printf("-------------card test 1 for smithy (end) ----------------------\n");
	

	return 0;

}
