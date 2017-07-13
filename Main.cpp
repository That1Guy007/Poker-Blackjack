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

using namespace std;

main(){
    int choice = 1;
    int tempV;
    card cards;
    print objP;//may need to create the deck object here and pass it into the constructors of tother clsses by reference
    while (choice != 0){
		cout<<"Welcome to my new and improved poker game!"<<endl<<endl;
		cout<<"Your Hand:"<<endl;
        objP.printCard();
		cout<<endl<<"What would you like to do?: ";
		cin>>choice;
	/*cout<<"Would you like to keep the "<<
    		Ineed to share the deck object... how?*/
	}
}
