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
#include "Print.h"
#include "Poker.h"


using namespace std;

main(){
	Poker pObj;
	int choice;
    cout<<"Would you like to playa a game?"<<endl<<"Yes (1) or no(0):";
    cin>>choice;
    if(choice){
  	  	pObj.pokerGame();
    }
}
