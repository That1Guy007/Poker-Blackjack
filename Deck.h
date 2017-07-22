/*********************************************************\\
Deck.h
Carlos Hernandez
July 7, 2017
Poker & BlackJack
\\*********************************************************/

#ifndef DECK_H
#define DECK_H

#include "Card.h"

class deck{
    private:
	card pHand[5];
      	int deckIndex;
        char spade; //unicode for the suits
        char club;
        char heart;
        char diamond;
        int tempValue[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
        //const char *tempSuit[4] = {"\u2660", "\u2663", "\u2764", "\u2666"};
	char tempSuit[4] = {'S', 'H', 'C', 'D'};        
	card cards[52];
    public:
           deck();
           ~deck();
           void randomCardT(int);
           void shuffle();
           void deal(int, int);//dealing card, idk what it should return
	int getVal(int);
	char getSuit(int);
	void setBool(int, bool);
	bool getBool(int);
	void counterUp(int);
	int getCounter(int);
	void reDeal(int, int);
	void organizeHand();

};
#endif
