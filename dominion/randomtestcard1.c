#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

// smithy +3 actions 


int main (){
 int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,outpost,baron,tribute};
 int i,s,before,after,num,p,handpos,r;
 
 struct gameState g;
 
 
 // this is the random test for the smithy 
 
 // pick 100 be the test times
 
  printf("--------------random test for the smithy (start) ------------------------\n");
  
  
  // set num to get the numbers of the error
  num = 0;
  printf("before the test error number will be: %d\n ",num);
  
  
  for(i=0;i<100;i++){
	  
	srand(time(NULL));
	
  // pick random seed below 20
  
  s = rand() % 20;
  
  // pick random player make sure at least two 
  
  p = rand() % 5 + 2;
  
  // pick handpos below 3
  
  handpos = rand () % 3;
  
  r = initializeGame(p, k, s, &g);
  
  if (r!=0){
	num = num + 1;
  }
  // before is to get the number of cards in hand before use the card
  // it should be less than after using the card
  
  before = numHandCards(&g);
  
  // pick a random deckcount below 10
  
  
  g.deckCount[p] = rand() % 10; 
  
  
  // pick a random discardcount below 10
  
  
  g.discardCount[p] = rand() % 10;
  
  
  // pick a random handcount below 10
  
  
  g.handCount[p] = rand() % 10;
  
  
  r = cardEffect(smithy, 0, 0, 0, &g, handpos, 0);
  
  if (r!=0){
  
	num = num + 1;
	
  }
  
  
  // after is to get the number of cards in hand before use the card
  after = numHandCards(&g);
  
  // the effect of card village is to add 3 cards
  
  if (after - before != 3){
   
   num = num + 1;
   
  }
  
 }
 
 printf("after 100 times of test the error number will be: %d\n ",num);
 
 printf("------------------------random test for the adventurer(end)-----------------------\n");
 
 return 0;
  
 } 
 