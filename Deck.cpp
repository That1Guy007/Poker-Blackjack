/*********************************************************\\
Deck.cpp
Carlos Hernandez
July 7, 2017
Poker & BlackJack
\\*********************************************************/

#include "Deck.h"
#include <iostream>
#include <cstdlib>

deck::deck(){
	deckIndex = 0;
        spade = '\u2660'; //unicode for the suits
        club = '\u2663';
        heart = '\u2764';
        diamond = '\u2666';
    for(int i = 1; i < 53; i++){
        cards[i-1].value = tempValue[i %13];
        cards[i-1].suit = tempSuit[(i-1)/13]; //cool
    }
}

deck::~deck(){}

void deck::randomCardT(int data){ //delete
    std::cout<<"The card value is: "<< cards[data - 1].value <<std::endl<<
    "and the suit is: "<< cards[data -1].suit<<std::endl;
}

void deck::shuffle(){ //CAUSING DUPLICATES, CREATE AN ARRAY TO KEEP TRACK OF THE ONES ALREADY MOVED.
  int indexTwo;
  srand(time(0));
  for(int indexCard = 0; indexCard < 52; indexCard++ ){
    indexTwo = rand() % 52;
    card temp = cards[indexCard]; //creates a temporary card object to hold the current card info
    cards[indexCard] = cards[indexTwo];
    cards[indexTwo] = temp;
  }
}

//Deals cards in order of how they are shuffled
void deck::deal( int cardsNeeded, int cardIndex){ 
  for( int i = 0; i < cardsNeeded; i++){
    if(deckIndex == 52){
      shuffle();
      deckIndex = 0;
      i--;
    }
    else if(cardIndex != -1){
    	//redeal
    	pHand[cardIndex] = cards[deckIndex];
    	deckIndex++;
    }
    else{
      	pHand[i] = cards[deckIndex];
		deckIndex++;
    }
  }
  organizeHand();
}

int deck::getVal(int cardIndex){
	return pHand[cardIndex].value;
}

char deck::getSuit(int cardIndex){
	return pHand[cardIndex].suit;
}

void deck::setBool(int cardIndex, bool value){
	pHand[cardIndex].doubleDone = value;
}

bool deck::getBool(int cardIndex){
	return pHand[cardIndex].doubleDone;
}

void deck::counterUp(int cardIndex){
	pHand[cardIndex].counter++;
}

int deck::getCounter(int cardIndex){
	return pHand[cardIndex].counter;
}

//redeal
void deck::reDeal(int keep, int handIndex){
	if(keep == 0){
		deal(1, handIndex);
		organizeHand();
	}
}

void deck::organizeHand(){ 
	card tempC;
	int min, max;
	for (int i = 0; i < 5; i++){
		min = i;
		for(int j = i +1; j < 5; j++){
			if(pHand[j].value < pHand[min].value){
				min = j;
			}
		}
		if(min != i){
			tempC = pHand[i];
			pHand[i] = pHand[min];
			pHand[min] = tempC;
		}
	}
}

card deck::riggedH(int i){
	switch(i){
		case 1://royal straight flush
			for(int x = 0; x < 5; x++){
				if(x+10 != 14){
					pHand[x].value = x+10;
				}
				else{
					pHand[x].value = 1;
				}
				pHand[x].suit = 'S';
			}
			organizeHand();
			break;
		
		case 2: //straight flush
			for(int x = 0; x < 5; x++){
				pHand[x].value = x+9;
				pHand[x].suit = 'C';
			}
			organizeHand();
			break;
		case 3://Full house
			for(int x = 0; x < 5; x++){
				pHand[x].value = (x+3)/3;
				pHand[x].suit = tempSuit[x % 4];
			}
			organizeHand();
			break;
		case 4://straight
			for(int x = 0; x < 5; x++){
				pHand[x].value = x+9;
				pHand[x].suit = tempSuit[x%4];
			}
			organizeHand();
			break;
		case 5://flush
			for(int x = 0; x < 5; x++){
				if(x<2){
					pHand[x].value = x+1;
				}
				else{
					pHand[x].value = x + 9;
				}
				pHand[x].suit = 'S';
			}
			organizeHand();
			break;
		case 6://two pair
			for(int x = 0; x < 5; x++){
				pHand[x].value = (x+2)/2;
				pHand[x].suit = tempSuit[x%4];
			}
			organizeHand();
			break;
		case 7: //Pair
			for(int x = 0; x < 5; x++){
				if(x < 2){
					pHand[x].value = (x+6)/2;
				}
				else{
					pHand[x].value = x+9;
				}
				pHand[x].suit = tempSuit[x%4];
			}
			organizeHand();
			break;
		case 8: // High card
			for(int x = 0; x < 5; x++){
				if(x < 1){
					pHand[x].value = 13;
				}
				else{
					pHand[x].value = x+3;
				}
				pHand[x].suit = tempSuit[x%4];
			}
			organizeHand();
			break;
		default:
			std::cout<<"Error";
			break;
	}
}





