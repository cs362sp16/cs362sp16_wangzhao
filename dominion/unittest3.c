#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

/*  unit test3 is for the whoseTurn(struct gameState *state) function */

int main() {

	struct gameState g;
	int current;

  int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,outpost,baron,tribute};

  int r = initializeGame(2, k, 5, &g);
   // initialize game like what example do
   printf("----------unit test 3 for whose Turn(start) --------------------------");
  
	//start at 0
	current = whoseTurn(&g);
	if (current == 0){
	printf("start at 0 initialized correctly.\n");
	}
	else{
	printf("there is something wrong with the function.\n");
	}
	
	g.whoseTurn = 1;
	current = whoseTurn(&g);
	
	if (current == 1){
	printf(" change to 1 is correct.\n");
	}
	else{
	printf("there is something wrong with the function.\n");
	}
	
	printf("----------unit test 3 for whose Turn(end) --------------------------");
	return 0;
}