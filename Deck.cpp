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
    for(int i = 0; i < 52; i++){
        cards[i].value = tempValue[i %12];
        //cards[i].suit = tempSuit[i/13]; //cool
    }
}

deck::~deck(){}

void deck::randomCardT(int data){
    std::cout<<"The card value is: "<< cards[data - 1].value <<std::endl<<
    "and the suit is: "<< cards[data -1].suit<<std::endl;
}

void deck::shuffle(){ // needs to be tested
  int indexTwo;
  srand(time(0));
  for(int indexCard = 0; indexCard < 52; indexCard++ ){
    indexTwo = rand() % 52 + 1;
    card temp = cards[indexCard]; //createsa temporary card object to hold the current card info
    cards[indexCard] = cards[indexTwo];
    cards[indexTwo] = temp;
  }
}

void deck::deal(){

}
