/*********************************************************\\
Card.cpp
Carlos Hernandez
July 7, 2017
Poker & BlackJack
\\*********************************************************/

#include "Card.h"

card::card(){
    value = 1; //setting the default value of a card to 1
    suit = '\u2660'; //setting the default value of the suit to H . Will become unicode later
}
