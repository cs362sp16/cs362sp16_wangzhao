/************************************
**program: testdominion.c
** author : wang,zhaoheng
** 5/24/2016
************************************/
#include <stdio.h>
#include <stdlib.h>
#include "rngs.h"
#include "dominion.h"
#include "math.h"
#include <time.h>
#include "assert.h"
#include "dominion_helpers.h"



int getnumberofaction(struct gameState *g){
	int i;
	int number = 0; // number of action
	
	for (i=0;i<numHandCards(g);i++){
		
		if(g->hand[g->whoseTurn][i] >= adventurer && g->hand[g->whoseTurn][i] <= treasure_map){
			
		
			number = number + 1; 
		}
		
		return number;
	}
}

void getthevalue(struct gameState *g, int numPlayers) {
    printf("the number of player are: %d\n", g->numPlayers);
	
	
    printf("the turn of player : %d\n", g->whoseTurn);
	
	
    printf("number of action are: %d\n", g->numActions);
	
    printf("the number of coins: %d\n", g->coins);
	
    printf("number of Buys: %d\n", g->numBuys);
	
    printf("the card count: %d\n", g->playedCardCount);
    
}



int main (int argc, char* argv[]) {
	
	
	int s; // seed

	int k[10] = {smithy,adventurer,gardens,embargo,cutpurse,mine,ambassador,outpost,baron,tribute};
	
	int acount = 0;
	
	int r = 0;
	
	int S = -1; // position of smithy
	
	int A = -1; // position of adventurer
	
	int i=0;
	
	int turn;
	

	int num2 = 0;
	
	int num3 = 0;
	
	int numc = 0; // number of cards
	
	struct gameState g;
	
	
	int num1;

	printf ("---------------------------------Starting game--------------------------------\n");
    
    srand(time(NULL));
	
    int players = (rand() % 3) + 2; // 2-4players (rand() % (max+1-min))+min
	
	// argv[1] for the seed assign
	if (argc > 2){
	

	printf("/usage: argv[1] is for the seed, there are too many argument");
	
	
	}

	if(argv[1] != NULL){
	

	s = atoi(argv[1]);
	
	
	}
	if (argv[1] == NULL){
		
		s = rand()% 20;
	
	}
   
    
	r = initializeGame(players, k, s, &g);
	
	if (r == 0){
		
		printf("initialize game successful \n");
	}
    
    
	 getthevalue(&g, players);
	
	

	
	

	while (!isGameOver(&g)) {
		
		S = -1;
		
		A = -1;
		
		numc = numHandCards(&g);
		
		if (numc !=0){
			
			printf("get the number of cards on hand\n");
		}
		
		for (i = 0; i < numc; i++) {
            
			getthevalue(&g, players);
			
			
			
			if (handCard(i, &g) == copper){
				
				acount = acount + 1;
				
			}
			
			if (handCard(i, &g) == silver){
				
				acount = acount + 2;
			}
			
			if (handCard(i, &g) == gold){
				
				acount = acount + 3;
			}
			
			if (handCard(i, &g) == smithy){
				
				S = i;
			}	
			
			if (handCard(i, &g) == adventurer){
				
				A = i;
			}
		}
		
		turn = whoseTurn(&g);

		if (turn == 0) {
			
			if (S != -1) {
				printf("player 0 \n");
				
				printf("smithy played from position %d\n", S);
				
				r = playCard(S, -1, -1, -1, &g);
				
				if (r == 0){
		
				printf("play card successful \n");
				
				}
				
				
				acount = 0;
				
				i=0;
				
				num1 = numHandCards(&g);
				
				while(i < num1) {
					
					if (handCard(i, &g) == copper) {
						
						r = playCard(i, -1, -1, -1, &g);
						
						if (r == 0){
		
							printf("play card successful \n");
				
						}
						
						acount = acount + 1;
					}
					
					if (handCard(i, &g) == silver) {
						
						r = playCard(i, -1, -1, -1, &g);
						
						if (r == 0){
		
							printf("play card successful \n");
				
						}
						
						acount = acount + 2;
					}
					if (handCard(i, &g) == gold) {
						
						r = playCard(i, -1, -1, -1, &g);
						
						if (r == 0){
		
							printf("play card successful \n");
				
						}
						
						acount = acount + 3;
					}
					
					i = i + 1;
				}
			}

			if (acount >= 8) {
				
				printf("player 0 is going to buy the province\n");
				
				r = buyCard(province, &g);
				
				if (r == 0){
		
							printf("buy card successful \n");
				
						}
				
			}
			
			if (acount >= 6) {
				
				printf("player 0 is going to buy gold\n");
				
				r = buyCard(gold, &g);
				
				if (r == 0){
		
							printf("buy card successful \n");
				
						}
				
			}
			
			if ((acount >= 4) && (num2 < 2)) {
				
				printf("player 0 is going to buy smithy\n");
				
				r = buyCard(smithy, &g);
				
				if (r == 0){
		
							printf("buy card successful \n");
				
						}
				
				num2 = num2 + 1;
			}
			if (acount >= 3) {
				
				printf("player 0 is going to buy silver\n");
				
				r = buyCard(silver, &g);
				
				if (r == 0){
		
							printf("buy card successful \n");
				
						}
			}

			
			endTurn(&g);
		}
		else {
			if (A != -1) {
				
				printf("player 1: adventurer played from position %d\n", A);
				
				playCard(A, -1, -1, -1, &g);
				
				acount = 0;
				
				i=0;
				num1 = numHandCards(&g);
				
				while(i<num1) {
					
					if (handCard(i, &g) == copper) {
						
						r = playCard(i, -1, -1, -1, &g);
						
						if (r == 0){
		
							printf("play card successful \n");
				
						}
						
						acount = acount + 1;
						
					}
					
					if (handCard(i, &g) == silver) {
						
						r = playCard(i, -1, -1, -1, &g);
						
						if (r == 0){
		
							printf("play card successful \n");
				
						}
						
						acount = acount + 2;
						
					}
					if (handCard(i, &g) == gold) {
						
						r = playCard(i, -1, -1, -1, &g);
						
						if (r == 0){
		
							printf("play card successful \n");
				
						}
						acount = acount + 3;
						
					}
					
					i = i + 1;
				}
			}

			if (acount >= 8) {
				
				printf("player 1 is going to buy province\n");
				
				r = buyCard(province, &g);
				
				if (r == 0){
		
							printf("buy card successful \n");
				
				    }
				
			}
			if ((acount>= 6) && (num3< 2)) {
				
				printf("player 0 is going to buy adventurer\n");
				
				r = buyCard(adventurer, &g);
				
				if (r == 0){
		
							printf("buy card successful \n");
				
				    }
				
				num3 = num3 + 1;
			}
			
			if (acount >= 6) {
				
				printf("player 0 is going to buy gold\n");
				
				r = buyCard(gold, &g);
				
				if (r == 0){
		
							printf("buy card successful \n");
				
				    }
			}
			
			
			if (acount >= 3) {
				
				
				printf("player 0 is going to buy silver\n");
				
				r = buyCard(silver, &g);
				
				if (r == 0){
		
							printf("buy card successful \n");
				
				    }
				
			}

			endTurn(&g);
		}

		
	} 
	printf("game score:\n");
	
	printf ("Player 0: %d\n", scoreFor(0, &g));
	
	printf ("Player 1: %d\n",scoreFor(1, &g));

	printf ("--------------------------------------game end ----------------------------------------");
	

	return 0;
}