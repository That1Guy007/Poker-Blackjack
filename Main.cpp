/*********************************************************\\
Main.cpp
Carlos Hernandez
July 7, 2017
Poker & BlackJack
\\*********************************************************/

#include <iostream>
#include <cstdlib>
#include "Card.h" //may not need this
#include "Deck.h"

using namespace std;

main(){
    int choice = 1;
    int tempV;
    card cards;
    deck deckObj;
    while (choice != 0){
        std::cout<<"Working main file"<<std::endl;
        cin >> tempV;
        if(tempV < 1 || tempV > 52){
            cout<<"wrong input"<<endl;
        }
        else{
            deckObj.randomCardT(tempV);
        }
    }
}
