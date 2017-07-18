/*********************************************************\\
Print.h
Carlos Hernandez
July 7, 2017
Poker & BlackJack
\\*********************************************************/

#ifndef PRINT_H
#define PRINT_H

#include "Deck.h"
#include "Card.h"
#include <string>

class print{
  private:
	deck deckObj;
    std::string cardDesign[2] = { "---------",/* values*/ "|       |"};

  public:
	print(deck&);
    void printCard(deck&);
};

#endif
