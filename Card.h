/*********************************************************\\
Card.h
Carlos Hernandez
July 7, 2017
Poker & BlackJack
\\*********************************************************/

#ifndef CARD_H
#define CARD_H

//includes??

class card{
    public:
        card();
        int value;
        char suit;
        bool doubleDone;//once counter hits a certain number, set to true
        int counter; //count the lines needed for a double suit
};
#endif
