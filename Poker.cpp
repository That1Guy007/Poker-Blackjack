/*********************************************************\\
Poker.cpp
Carlos Hernandez
July 7, 2017
Poker & BlackJack
\\*********************************************************/

#include "Poker.h"
#include <iostream>

using namespace std;

Poker::Poker(){
	
}


void Poker::pokerGame(){

int keep, tempV, choice = 1;
    card cards;
    deck objD;
    objD.shuffle();
    objD.deal(5, -1);
    print objP(objD);//pass deck into the constructors of the print class by reference
    while (choice != 0){
		cout<<"Welcome to my new and improved poker game!"<<endl<<endl;
		cout<<"Your Hand:"<<endl;
        objP.printCard(objD);
        //resend object????
		cout<<endl<<"Would you like to keep the "<<objD.getVal(0)<< " of "<<objD.getSuit(0)<< endl<< endl<<"0 for no , 1 for yes"<<endl;
		cin>>keep;
		//adding a function to redeal the card or not
		objD.reDeal(keep, 0);
		cout<<endl<<"Would you like to keep the "<<objD.getVal(1)<< " of "<<objD.getSuit(1)<< endl<< endl<<"0 for no , 1 for yes"<<endl;
		cin>>keep;
		objD.reDeal(keep, 1);
		cout<<endl<<"Would you like to keep the "<<objD.getVal(2)<< " of "<<objD.getSuit(2)<< endl<< endl<<"0 for no , 1 for yes"<<endl;
		cin>>keep;
		objD.reDeal(keep, 2);
		cout<<endl<<"Would you like to keep the "<<objD.getVal(3)<< " of "<<objD.getSuit(3)<< endl<< endl<<"0 for no , 1 for yes"<<endl;
		cin>>keep;
		objD.reDeal(keep, 3);
		cout<<endl<<"Would you like to keep the "<<objD.getVal(4)<< " of "<<objD.getSuit(4)<< endl<< endl<<"0 for no , 1 for yes"<<endl;
		cin>>keep;
		objD.reDeal(keep, 4);
		objP.printCard(objD);//print needs the updated object sent to it? why idk but it works
		cin>>keep;
		//need to create function in deck class to redeal the cards chosen
		
	}
}
