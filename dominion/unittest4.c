#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>

/* here is unit test 4 for the shuffle(int player, struct gameState *state) function */

int main(){
	struct gameState g;
	int r;

  int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,outpost,baron,tribute};
  
  initializeGame(2, k, 5, &g);
  
  printf("---------------unit test 4 for the shuffle function (start)---------------------");
  
  // check when state->deckCount[player] < 1
  
  g.deckCount[1] = 0;
  r = shuffle(1,&g);
  if (r == -1){
  printf(" when state->deckCount[player] < 1, it returns -1");
  }
  g.deckCount[1] = 5;
  
  r = shuffle(1, &g);
  // 5>1 so should return 0
  
  if (r == 0){
  printf(" it is correct");
  }
  else{
  printf(" there is something wrong");
  }
  
  printf("---------------unit test 4 for the shuffle function (end)---------------------");
	return 0;
}