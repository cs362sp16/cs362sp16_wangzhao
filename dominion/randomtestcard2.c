#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

// village: +1 card and + 2 action 



int main (){
 int k[10] = {smithy,adventurer,village,embargo,cutpurse,mine,ambassador,outpost,baron,tribute};
 int i,s,before1,before2,after1,after2,num,p,handpos,r;
 
 struct gameState g;
 
 
 // this is the random test for the village
 
 // pick 100 be the test times
 
  printf("--------------random test for the village(start) ------------------------\n");
  
 
  
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
  // before1 is to get the number of cards in hand before use the card
  
  before1 = numHandCards(&g);
  
  // before2 is to take the numbers of action before use the card
// should be less than the numbers of action after using the card
  
  before2 = g.numActions;
  
  
  // pick a random deckcount below 10
  
  
  g.deckCount[p] = rand() % 10; 
  
  
  // pick a random discardcount below 10
  
  
  g.discardCount[p] = rand() % 10;
  
  
  // pick a random handcount below 10
  
  
  g.handCount[p] = rand() % 10;
  
  // start to use the effect and make sure it is correct
  r = cardEffect(adventurer, 0, 0, 0, &g, handpos, 0);
  
  if (r!=0){
  
	num = num + 1;
	
  }
  
 // after1 is to get the number of cards in hand after use the card
 // after2 is to get the number of actions after use card
 // the effect of card village is to add 1 card and add two actions
 
 after1 = numHandCards(&g);
  after2 = g.numActions;
  
  if (after1 - before1 != 1){// add 1 card so after1 - before 1 = 1
   
   num = num + 1;
   
  }
  
  if (after2 - before2 != 2){ // add two action so the after2-before2 =2
   
   num = num + 1;
   
  }
  
 }
 
 printf("after 100 times of test the error number will be: %d\n ",num);
 
 printf("------------------------random test for the village(end)-----------------------\n");
 
 return 0;
  
 } 
 