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
    for(int i = 0; i < 52; i++){ 
        cards[i].value = tempValue[i %12];
        cards[i].suit = tempSuit[i/13]; //cool
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
//
void deck::deal( int cardsNeeded, int cardIndex){ //needs to be tested
  //need an index of the card in the deck whihc is next
   //need to make more for BJ
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

void deck::reDeal(int keep, int handIndex){
	if(keep == 0){
		deal(1, handIndex);//redeal
	}
}


