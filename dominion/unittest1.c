#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>



/* unit test1 is for the function called numHandCards(struct gameState *state) which should return 5 cards */


int main(){
	struct gameState g;
	int nums;
	

	int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,outpost,baron,tribute};
	 
	 
	 printf ("------ unit test 1 for the numHandCards and drawCard function.(start) ------\n");
	// initialize the game like what the example give 
	
	
  	int r = initializeGame(2, k, 5, &g);

	printf("test");

  
   nums = numHandCards(&g);
   
   // print out the card number
   printf("The card numbers in  hand are: %i\n", nums);
  
  // check if the nums equal to five 
  if(nums == 5){
	printf("this is correct and the unit test successfully completed \n");
  }
  else{
  printf("this is something incorrect in the function plz check again \n");
  }
   
  printf ("------ unit test 1 for the numHandCards and drawCard function.(end) ------\n");
 return 0;
}
