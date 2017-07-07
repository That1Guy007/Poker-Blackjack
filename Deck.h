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
        int tempValue[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
        char tempSuit[4] = {spade, club, heart, diamond};
        const char spade = '\E299A0'; //unicode for the suits
        const char club = '\E299A3';
        const char heart = '\E299A5';
        const char diamond = '\E299A6';
        card cards[52];
    public:
           deck();
           ~deck();
           void randomCardT(int);
           void shuffle();
           void deal();//dealing card, idk what it should return
           
};
#endif
