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
    /*string spade1 = "|   \xE2\x99\xA0   |";
    string heart1 = "|   \xE2\x99\xA5   |";
    string diamond1 = "|   \xE2\x99\xA6   |";
    string club1 = "|   \xe2\x99\xa3   |";


    string spade2 = "| \xE2\x99\xA0   \xE2\x99\xA0 |";
    string heart2 = "| \xE2\x99\xA5   \xE2\x99\xA5 |";
    string diamond2 = "| \xE2\x99\xA6   \xE2\x99\xA6 |";
    string club2 = "| \xE2\x99\xA3   \xE2\x99\xA3 |";*/

    std::string cardDesign[2] = { "---------",/* values*/ "|       |"};

    /*string cardValue[13] = { "|A      |","|2      |", "|3      |",

      "|4      |", "|5      |", "|6      |", "|7      |",
      "|8      |", "|9      |", "|10     |", "|J      |",
      "|Q      |", "|K      |"
    }*/

  public:
	print();
    void printCard();
};

#endif
