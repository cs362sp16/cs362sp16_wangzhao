#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"
#include "dominion.h"
#include "dominion_helpers.h"

/* the unit test2 is for the int* kingdomCards(int k1, int k2, int k3, int k4, int k5, int k6, int k7,int k8, int k9, int k10) */


int main (){

	struct gameState g;
	int *k;
	
	
	printf("--------------------unit test 2  for kingdomCards( start) -------------------------------------- \n");
	
	k = kingdomCards(1,2,3,4,5,6,7,8,9,10);
	if ( k[0]== 1&& k[1] == 2&&k[2] == 3 &&k[3]== 4&&k[4] == 5&& k[5]== 6&&k[6]==7&&k[7]==8&&k[8]==9&&k[9]==10){
		printf(" the test pass and return is correct\n");
	}
	else{
		printf("it have some bugs \n");
	} 	
	

	printf("---------------unit test 2  for kingdomCards( end) -------------------------------------- \n");
	
	
	
	return 0;

	






}
