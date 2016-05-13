#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>


int main (){
 int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,outpost,baron,tribute};
 int i,s,before,after,num,p,handpos,r;
 
 struct gameState g;
 
 
 // this is the random test for the adventure 
 
 // pick 100 be the test times
 
  printf("--------------random test for the adventurer(start) ------------------------\n");
  
  
  // set num to get the numbers of the error
  num = 0;
   printf("before the test error number will be: %d\n ",num);
  
  
  for(i=0; i<100; i++){
  // pick random seed below 20
  
 srand(time(NULL));
  
  s = rand() % 20;
  // pick random player make sure at least two 
  
  p = rand() % 5 + 2;
  
  // pick handpos below 3
  
  handpos = rand () % 3;
  
  r = initializeGame(p, k, s, &g);
  
  // before is to get the number of cards in hand before use the card
  // so the number of before should be less than after (after - before = 2)
  
  before = numHandCards(&g);
  
  if (r!=0){
	num = num + 1;
  }
  // pick a random deckcount below 10
  
  
  g.deckCount[p] = rand() % 10; 
  
  
  // pick a random discardcount below 10
  
  
  g.discardCount[p] = rand() % 10;
  
  
  // pick a random handcount below 10
  
  
  g.handCount[p] = rand() % 10;
  
  
  r = cardEffect(adventurer, 0, 0, 0, &g, handpos, 0);
  
  if (r!=0){
  
	num = num + 1;
	
  }
  
  
   // after is to get the number of cards in hand before use the card
  after = numHandCards(&g);
  
  
  if (after - before != 2){
   
   num = num + 1;
   
  }
  
 }
 
 printf("after test the error number will be: %d\n ",num);
 
 printf("------------------------random test for the adventurer(start)-----------------------\n");
 
 return 0;
  
 } 
 